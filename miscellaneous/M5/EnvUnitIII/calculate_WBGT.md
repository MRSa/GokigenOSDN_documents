# WBGT（熱中症指数）の計算

## プロンプト

SHT30 と QMP6988 で WGBT の計算を行いたいです。 黒球温度 を推定する必要があると思いますが、どのように計算式を組み立てればよいでしょうか？

## Geminiによる回答

SHT30（温湿度センサ）とQMP6988（気圧センサ）から得られるデータを用いて、簡易的に**黒球温度（$T_g$）を推定し、WBGT（熱中症指数）を算出する計算式と手順**を解説します。

屋外（直射日光下）での正確な黒球温度の測定には、本来日射量（Solar Radiation）**と**風速（Wind Speed）**のデータが不可欠です。しかし、これらのセンサのみを使用する場合は、**「室内・日陰」という前提を置くか、気圧データ等を用いた高度な環境モデルから概算（近似）することになります。

---

### 1. WBGT の基本計算式

屋外・屋内を問わず、WBGT は以下の公式で定義されます。

$$\text{WBGT} = 0.7 \times T_w + 0.2 \times T_g + 0.1 \times T_d \quad (\text{屋外・日射あり})$$

$$\text{WBGT} = 0.7 \times T_w + 0.3 \times T_g \quad (\text{屋内・日陰})$$

* **$T_d$**：乾球温度（SHT30 の測定温度）
* **$T_w$**：湿球温度（SHT30 の温度と相対湿度から算出）
* **$T_g$**：黒球温度（**推定が必要**）

---

### 2. 各要素の計算手順

#### Step 1: 湿球温度（$T_w$）の計算

SHT30 の測定温度 $T_d$（℃）と相対湿度 $RH$（%）から、Stull の近似式を用いて湿球温度 $T_w$ を算出します。

$$T_w = T_d \cdot \arctan\left(0.151977 \cdot (RH + 8.313659)^{1/2}\right) + \arctan(T_d + RH) - \arctan(RH - 1.676331) + 0.00391838 \cdot RH^{3/2} \cdot \arctan(0.023101 \cdot RH) - 4.686035$$

*(※ $\arctan$ の引数はラジアン角)*

#### Step 2: 黒球温度（$T_g$）の推定

センサ構成に応じた黒球温度 $T_g$ の推定モデルを選択します。

**パターン A: 屋内・直射日光がない日陰（最も現実的・高精度）**
直射日光や強い放射熱がない環境では、**黒球温度 $T_g$ は乾球温度 $T_d$ とほぼ等しくなります ($T_g \approx T_d$)**。

$$\text{WBGT} = 0.7 \times T_w + 0.3 \times T_d$$

この場合、湿球温度 $T_w$ と乾球温度 $T_d$ のみで高い精度で算出可能です（環境省等の簡易計算表もこのモデルに基づいています）。

---

**パターン B: 屋外・日射がある環境（推定モデル）**
直射日光下では、日射による放射加熱で $T_g > T_d$ となります。
気圧 $P$（QMP6988の hPa）から高度や大気透過度を簡易推計し、日射による上昇分 $\Delta T$ を補正項目として足し合わせるモデルを用います。

$$T_g = T_d + \Delta T_{\text{solar}}$$

一般的な簡易推定法として、**日射による温度上昇分 $\Delta T_{\text{solar}}$** は環境条件に応じて以下のように近似します：

* **直射日光下（穏やかな風速 1 m/s 前後想定）：**

$$T_g \approx T_d + (2.0 \sim 4.0\,^\circ\text{C})$$

* **気圧（QMP6988）を活用した高度補正を組み込む場合：**
海抜高度が高く気圧が低いほど大気透過率が上がり、日射加熱の影響を受けやすくなります。標準大気圧 $P_0 = 1013.25\,\text{hPa}$ との比率を用いて補正項を補う例：

$$\Delta T_{\text{solar}} \approx 3.0 \times \left( \frac{P_0}{P} \right)$$

（※標高が高く気圧 $P$ が下がるほど補正幅が僅かに大きくなります）

---

### 3. C言語 / C++（Arduino等）実装コード例

```cpp
#include <math.h>

// 湿球温度 Tw の計算 (Stull の式)
float calculateWetBulb(float Td, float RH) {
    float Tw = Td * atan(0.151977 * sqrt(RH + 8.313659)) 
             + atan(Td + RH) 
             - atan(RH - 1.676331) 
             + 0.00391838 * pow(RH, 1.5) * atan(0.023101 * RH) 
             - 4.686035;
    return Tw;
}

// 屋外用 WBGT 推定計算
float calculateWBGT_Outdoor(float Td, float RH, float pressure_hPa) {
    float Tw = calculateWetBulb(Td, RH);
    
    // 日射による黒球温度上昇分の補正（標準的な日光直射下を仮定）
    float deltaT = 3.0 * (1013.25 / pressure_hPa); 
    float Tg = Td + deltaT; // 黒球温度の推定
    
    // 屋外 WBGT 式: 0.7*Tw + 0.2*Tg + 0.1*Td
    float wbgt = 0.7 * Tw + 0.2 * Tg + 0.1 * Td;
    return wbgt;
}

// 屋内・日陰用 WBGT 計算
float calculateWBGT_Indoor(float Td, float RH) {
    float Tw = calculateWetBulb(Td, RH);
    // 屋内では Tg ≒ Td
    float wbgt = 0.7 * Tw + 0.3 * Td;
    return wbgt;
}

```

---

### 実装上の注意点と精度向上のアドバイス

1. **SHT30 の自己加熱（Self-Heating）防止**
SHT30 は連続で読み出すと素子が自熱し、$T_d$ が高め・$RH$ が低めに出力される傾向があります。測定間隔は **5〜10秒以上に1回** に留めるか、低電力モードを使用してください。
2. **QMP6988（気圧）の主要用途**
気圧そのものは WBGT に直接与える影響が微小です。QMP6988 は主に「設置場所の高度算出」や「天候変化（急激な気圧低下＝雨天/日射なし）の検知」のフラグとして活用するのが最も効果的です。日照がない雨天・曇天時は $\Delta T_{\text{solar}} = 0$ とすることで補正精度が向上します。
