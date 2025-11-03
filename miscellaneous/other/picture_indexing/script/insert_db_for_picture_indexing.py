import os
import sys
from datetime import datetime
from typing import Dict, Any, Optional, Tuple, Union

# Piexif のインポート
try:
    import piexif
    from piexif import TAGS
    # Piexifのタグ辞書を結合
    ALL_TAGS = {**TAGS['0th'], **TAGS['Exif'], **TAGS['GPS'], **TAGS['1st'], **TAGS['Interop']}
except ImportError:
    sys.stderr.write("エラー: Piexif がインストールされていません。\n")
    sys.stderr.write("`pip install piexif` でインストールしてください。\n")
    sys.exit(1)

# PostgreSQLライブラリのインポート
try:
    import psycopg2
    from psycopg2 import connect
except ImportError:
    sys.stderr.write("エラー: psycopg2 がインストールされていません。\n")
    sys.stderr.write("`pip install psycopg2-binary` でインストールしてください。\n")
    sys.exit(1)

# ------ PostgreSQL接続情報 ------
DB_HOST = 'postgres'
DB_PORT = '5432'
DB_NAME = 'my_picture_db'
DB_USER = '(DB_USER_NAME)'
DB_PASSWORD = 'XXXXX' # ユーザー指定のパスワード

# ==============================================================================
# ヘルパー関数
# ==============================================================================

def ratio_to_float(ratio: Union[Tuple[int, int], bytes]) -> Optional[float]:
    """
    Piexifの有理数タプル (分子, 分母) を浮動小数点数に変換します。
    """
    # 既にバイト列や想定外の型の場合はNoneを返す
    if not isinstance(ratio, tuple) or len(ratio) != 2:
        return None
        
    numerator, denominator = ratio
    
    if denominator == 0:
        return None
    
    return numerator / denominator

def get_exif_data(image_path: str) -> Optional[Dict[str, Any]]:
    """
    Piexifを使ってEXIF情報を取得し、整形して返します。
    """
    try:
        exif_data_raw = piexif.load(image_path)
    except Exception as e:
        sys.stderr.write(f"警告: ファイル '{image_path}' から EXIF 情報を読み込めませんでした: {e}\n")
        return None

    if not any(exif_data_raw.values()):
        sys.stderr.write(f"警告: ファイル '{image_path}' に EXIF 情報がありません。\n")
        return None

    decoded_exif = {}
    
    for ifd_name, ifd_data in exif_data_raw.items():
        if ifd_name != "thumbnail":
            for tag_id, value in ifd_data.items():
                try:
                    #tag_name = ALL_TAGS.get(tag_id, (tag_id, ))[0] 
                    tag_info = ALL_TAGS.get(tag_id)
                    tag_name = tag_info['name']

                except Exception as ex:
                    sys.stderr.write(f"警告: ファイル '{image_path}' の EXIF 情報に不明なID{tag_id} がありました: {ex}\n")
                    tag_name = tag_id

                # ASCIIデータの場合、バイト列をデコードして終端のNULL文字を削除
                if isinstance(value, bytes) and tag_name in ['Make', 'Model', 'Software']:
                    try:
                        value = value.decode('ascii').strip('\0')
                    except UnicodeDecodeError:
                        value = str(value) # デコード失敗時はそのまま文字列化
                
                decoded_exif[tag_name] = value

    return decoded_exif

# ==============================================================================
# PostgreSQL処理関数
# ==============================================================================

def insert_to_postgres(file_info: Dict[str, Any], exif_data: Optional[Dict[str, Any]], conn):
    """
    取得したファイル情報とEXIF情報をPostgreSQLに挿入します。
    """
    
    # データベースに挿入するための値を整形
    if exif_data:
        # 'date_time' の部分を最初に披露
        date_time_raw = exif_data.get('DateTime')
        exif_values = {
            'make': exif_data.get('Make'),
            'model': exif_data.get('Model'),
            'software': exif_data.get('Software'),
            # 日時データは、バイト列からデコードしてタイムスタンプ型に変換
            'date_time': (
                datetime.strptime(date_time_raw.strip(b'\0').decode('ascii'), '%Y:%m:%d %H:%M:%S')
                if date_time_raw and isinstance(date_time_raw, bytes) 
                else None
            ),

            'iso': exif_data.get('ISOSpeedRatings'),
            
            # Rationalを計算可能なDOUBLE PRECISIONに変換
            'shutter': ratio_to_float(exif_data.get('ExposureTime')), # ExposureTime (シャッタースピードそのもの) を使用
            'aperture': ratio_to_float(exif_data.get('FNumber')),     # FNumber (F値) を使用
            'focal_length': ratio_to_float(exif_data.get('FocalLength')),
            
            'width': exif_data.get('PixelXDimension'),
            'height': exif_data.get('PixelYDimension'),
        }
    else:
        # EXIFデータがない場合はすべてNone
        exif_values = {k: None for k in ['make', 'model', 'software', 'date_time', 'iso', 'shutter', 'aperture', 'focal_length', 'width', 'height']}

    try:
        with conn.cursor() as cur:
            # プレースホルダ (%) を使用してSQLインジェクションを防ぐ
            sql = """
            INSERT INTO file_exif_info (
                file_name, file_extension, full_path, file_size, file_created,
                exif_make, exif_model, exif_software, exif_date_time,
                exif_iso, exif_shutter, exif_aperture, exif_focal_length, exif_width, exif_height
            ) VALUES (
                %s, %s, %s, %s, %s,
                %s, %s, %s, %s,
                %s, %s, %s, %s, %s, %s
            ) ON CONFLICT (full_path) DO NOTHING; -- フルパスが重複する場合はスキップ
            """
            
            # 挿入する値のタプルを作成
            values = (
                file_info['name'], file_info['extension'], file_info['path'], file_info['size'], file_info['creation_time'],
                exif_values['make'], exif_values['model'], exif_values['software'], exif_values['date_time'],
                exif_values['iso'], exif_values['shutter'], exif_values['aperture'], exif_values['focal_length'], exif_values['width'], exif_values['height']
            )

            cur.execute(sql, values)
        
        conn.commit()
        sys.stderr.write(f"DB挿入完了: ファイル '{file_info['path']}' の情報をデータベースに格納しました。\n")
        
    except psycopg2.Error as e:
        conn.rollback()
        sys.stderr.write(f"DBエラー: ファイル '{file_info['path']}' の挿入中にエラーが発生しました: {e}\n")
    except Exception as e:
        sys.stderr.write(f"予期せぬエラー: {e}\n")


# ==============================================================================
# メイン処理関数
# ==============================================================================

def display_exif_info(file_info: Dict[str, Any], exif_data: Optional[Dict[str, Any]]):
    """
    ファイル情報とEXIF情報を標準出力 (stdout) に表示します。(前回の実装を維持)
    """
    # 標準出力 (stdout) に出力
    sys.stdout.write("=" * 50 + "\n")
    sys.stdout.write(f"📂 ファイル名: {file_info['name']}\n")
    sys.stdout.write(f"➡️ パス名: {file_info['path']}\n")
    sys.stdout.write(f"📏 サイズ (バイト): {file_info['size']}\n")
    #
    #sys.stdout.write("=" * 50 + "\n\n")


def process_directory(directory_path: str):
    """
    指定されたディレクトリ内の全ファイルを処理し、DBに挿入します。
    """
    if not os.path.isdir(directory_path):
        sys.stderr.write(f"エラー: 指定されたパス '{directory_path}' はディレクトリではありません。\n")
        return

    # データベース接続を試行
    try:
        conn = connect(
            host=DB_HOST, 
            port=DB_PORT, 
            database=DB_NAME, 
            user=DB_USER, 
            password=DB_PASSWORD
        )
        sys.stderr.write(f"DB接続成功: {DB_NAME} に接続しました。\n")
    except Exception as e:
        sys.stderr.write(f"DB接続エラー: PostgreSQLへの接続に失敗しました。設定を確認してください。\n")
        sys.stderr.write(f"詳細: {e}\n")
        sys.exit(1)


    sys.stderr.write(f"開始: ディレクトリ '{directory_path}' の処理を開始します。\n")
    
    for root, _, files in os.walk(directory_path):
        for file_name in files:
            full_path = os.path.join(root, file_name)
            
            try:
                stat_info = os.stat(full_path)
                file_size = stat_info.st_size
                # st_ctime はファイル作成日時が取得できないOSでは最終変更日時になることに注意 (Linux, macOS)
                creation_time = datetime.fromtimestamp(stat_info.st_ctime)
                
                _, file_extension = os.path.splitext(file_name)
                
            except OSError as e:
                sys.stderr.write(f"エラー: ファイル '{full_path}' の統計情報取得中にエラーが発生しました: {e}\n")
                continue

            file_info = {
                'name': file_name,
                'path': full_path,
                'size': file_size,
                'extension': file_extension,
                'creation_time': creation_time
            }
            
            sys.stderr.write(f"処理中: ファイル '{full_path}' を読み込んでいます。\n")
            
            exif_data = get_exif_data(full_path)
            
            # 1. 画面表示 (stdoutに出力)
            display_exif_info(file_info, exif_data)
            
            # 2. データベース格納 (DBにINSERT)
            insert_to_postgres(file_info, exif_data, conn)
            
    conn.close()
    sys.stderr.write("完了: すべてのファイルの処理が終了し、DB接続を閉じました。\n")


if __name__ == '__main__':
    if len(sys.argv) < 2:
        sys.stderr.write("使用方法: python script_name.py <directory_path>\n")
        sys.exit(1)
        
    target_directory = sys.argv[1]
    process_directory(target_directory)
    sys.stdout.write("=" * 50 + "\n\n")


