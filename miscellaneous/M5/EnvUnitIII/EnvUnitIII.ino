//
//   Unit Env III (https://docs.m5stack.com/ja/unit/envIII)
//
//    * 不快指数、WBGT（熱中症指数）の計算を行う
//
#include <M5Unified.h>
#include <M5UnitUnified.h>
#include <M5UnitUnifiedENV.h>

#define SERIAL_BAUDRATE_PC 115200
#define LOOP_DURATION 1500

#define USING_ENV3

m5::unit::UnitUnified Units;
#if defined(USING_ENV3)
    m5::unit::UnitENV3 unitENV;
    auto& sht30   = unitENV.sht30;
    auto& qmp6988 = unitENV.qmp6988;
#elif defined(USING_ENV4)
    m5::unit::UnitENV4 unitENV;
    auto& sht40  = unitENV.sht40;
    auto& bmp280 = unitENV.bmp280;
#endif


int count = 0;

//  高度の計算
float calculate_altitude(const float pressure, const float seaLvhPa = 1013.25f)
{
    return 44330.f * (1.0f - pow((pressure / 100.f) / seaLvhPa, 0.1903f));
}

//  不快指数の計算
float calculate_discomfort_index(const float humidity, const float temperature1, const float temperature2)
{
    float temperature = (temperature1 + temperature2) / 2.0f;
      
    return 0.81f * temperature + 0.01f * humidity * (0.99f * temperature - 14.3f) + 46.3f;
}

//  湿球温度 Tw の計算 (Stull の式)
float calculateWetBulb(float temperature, float humidity) {
    float Tw = temperature * atan(0.151977 * sqrt(humidity + 8.313659)) 
             + atan(temperature + humidity) 
             - atan(humidity - 1.676331) 
             + 0.00391838 * pow(humidity, 1.5) * atan(0.023101 * humidity) 
             - 4.686035;
    return Tw;
}

//  屋外用 WBGT 推定計算
float calculate_wbgt_outdoor(float Td1, float Td2, float RH, float pressure_hPa)
{
    float Td = (Td1 + Td2) / 2.0f;
    float Tw = calculateWetBulb(Td, RH);

    // 日射による黒球温度上昇分の補正（標準的な日光直射下を仮定）
    float deltaT = 3.0 * (1013.25 / pressure_hPa); 
    float Tg = Td + deltaT; // 黒球温度の推定
    
    // 屋外 WBGT 式: 0.7*Tw + 0.2*Tg + 0.1*Td
    float wbgt = 0.7 * Tw + 0.2 * Tg + 0.1 * Td;
    return wbgt;
}

//  室内用 WBGT 推定計算
float calculate_wbgt_indoor(const float humidity, const float temperature1, const float temperature2)
{
    float temperature = (temperature1 + temperature2) / 2.0f;
    float Tw = calculateWetBulb(temperature, humidity);
    float wbgt = 0.7 * Tw + 0.3 * temperature;    // 屋内では Tg ≒ temperature

    return wbgt;
}

// WBGTの色表現
int getWBGTColor(float wbgt)
{
    if (wbgt >= 31.0f)
    {
        return TFT_MAGENTA;
    }
    else if (wbgt >= 28.0f)
    {
        return TFT_RED;
    }
    else if (wbgt >= 25)
    {
        return TFT_ORANGE;
    }
    else if (wbgt >= 21.0f)
    {
        return TFT_GREENYELLOW;
    }
    else
    {
        return TFT_WHITE;
    }
}

//  不快指数の色表現
int getComfortColor(float discomfortIndex)
{
    if (discomfortIndex >= 85.0f)
    {
        return TFT_MAGENTA;      
    }
    else if (discomfortIndex >= 80.0f)
    {
        return TFT_RED;
    }
    else if (discomfortIndex >= 75.0f)
    {
        return TFT_ORANGE;
    }
    else if (discomfortIndex >= 70.0f)
    {
        return TFT_GREENYELLOW;
    }
    else if (discomfortIndex >= 65.0f)
    {
        return TFT_GREEN;
    }
    else if (discomfortIndex >= 60.0f)
    {
        return TFT_WHITE;
    }
    else if (discomfortIndex >= 55.0f)
    {
        return TFT_SKYBLUE;
    }
    else if (discomfortIndex >= 50.0f)
    {
        return TFT_BLUE;
    }
    else
    {
        return TFT_NAVY;
    }
}

//  不快指数の目安メッセージ
char *getComfort(float discomfortIndex)
{
    if (discomfortIndex >= 85.0f)
    {
        return "(すごく暑い)";      
    }
    else if (discomfortIndex >= 80.0f)
    {
        return "(暑い)";      
    }
    else if (discomfortIndex >= 75.0f)
    {
        return "(やや暑い)";      
    }
    else if (discomfortIndex >= 70.0f)
    {
        return "(暑いかも)";      
    }
    else if (discomfortIndex >= 65.0f)
    {
        return "(快適)";      
    }
    else if (discomfortIndex >= 60.0f)
    {
        return "(普通)";      
    }
    else if (discomfortIndex >= 55.0f)
    {
        return "(肌寒い)";      
    }
    else if (discomfortIndex >= 50.0f)
    {
        return "(寒い)";      
    }
    else
    {
        return "(すごく寒い)";      
    }
}


void setup()
{
    auto cfg = M5.config();
    cfg.serial_baudrate = SERIAL_BAUDRATE_PC;
    cfg.internal_imu = false;
    cfg.external_imu = false;
    M5.begin(cfg);

    M5.Display.init();
    M5.Display.setFont(&fonts::lgfxJapanGothicP_16);
    M5.Display.setRotation(2);  // 表示を180度回転させる
    M5.Display.setTextSize(1);
    M5.Display.setTextColor(TFT_LIGHTGREY, TFT_BLACK);
    M5.Display.println("初期化中");
  

    //// I2Cバスの初期化 (M5AtomS3RのPortA: SDA=2, SCL=1)
    //Wire.begin(2, 1, 400000U);
    // --- Auto-detect the standardized Port A I2C pins for your specific M5 Core
    auto sda = M5.getPin(m5::pin_name_t::port_a_sda);
    auto scl = M5.getPin(m5::pin_name_t::port_a_scl);
    M5_LOGI("getPin: SDA:%u SCL:%u", sda, scl);
    
    // Initialize the primary Wire bus with safe frequencies
    Wire.end(); 
    Wire.begin(sda, scl, 400000U);

    // ユニットの登録と初期化
    if (!Units.add(unitENV, Wire) || !Units.begin()) {
        M5_LOGE("Failed to connect or initialize the ENV Unit!");
        while (true) { delay(1000); }
    }

    delay(2000); // 少し待つ
    M5.Display.clear();
    Serial.println("Program Start!");
    M5.Display.println("開始！");
}


void showDisplay(float temperature, float temperature2, float humidity, float pressure)
{
    int marginY = 16;
    if ((temperature > -273.0f)||
        (temperature2 > -273.0f)||
        (humidity > 0.0f)||
        (pressure > 0.0f))
    {
        // ---- 値が更新されたときにはクリアする
        M5.Display.setCursor(0, 0);
        M5.Display.fillRect(0, 0, 128, 128, TFT_BLACK);

        // --- 現在のセンサ値を表示する ---
        M5.Display.setCursor(0, 0);
        M5.Display.setTextColor(TFT_WHITE, TFT_BLACK);
        //M5.Display.printf(" = センサ値 =\n");

        int posY = -15;
        posY = posY + marginY;
        M5.Display.setCursor(0, posY);
        if (temperature > -273.0f)
        {
            M5.Display.printf("温度1: %.1f℃\n", temperature);      
        }
        posY = posY + marginY;
        M5.Display.setCursor(0, posY);
        if (temperature2 > -273.0f)
        {
            M5.Display.printf("温度2: %.1f℃\n", temperature2);
        }
        posY = posY + marginY;
        M5.Display.setCursor(0, posY);
        if (humidity > 0.0f)
        {
            M5.Display.printf("湿度: %.1f%%\n", humidity);
        }
        posY = posY + marginY;
        M5.Display.setCursor(0, posY);
        if (pressure > 0.0f)
        {
            M5.Display.printf("気圧:%.1fhPa\n", pressure * 0.01f);
        }

        float thi = 0.0f;
        float wbgt_outdoor = 0.0f;
        float wbgt_indoor = 0.0f;
        if ((humidity > 0.0f)&&(temperature > -273.0f)&&(temperature2 > -273.0f))
        {
            thi = calculate_discomfort_index(humidity, temperature, temperature2);
            wbgt_outdoor = calculate_wbgt_outdoor(temperature, temperature2, humidity, (pressure * 0.01f));
            wbgt_indoor = calculate_wbgt_indoor(humidity, temperature, temperature2);
        }

        if (wbgt_indoor > 0.0f)
        {
            M5.Display.setTextColor(getWBGTColor(wbgt_indoor), TFT_BLACK);
            posY = posY + marginY + 4;
            M5.Display.setCursor(0, posY);
            M5.Display.printf("WGBT: %.0f\n", wbgt_indoor);
        }

        if (thi > 0.0f)
        {
            M5.Display.setTextColor(getComfortColor(thi), TFT_BLACK);
            posY = posY + marginY + 4;
            M5.Display.setCursor(0, posY);
            M5.Display.printf("不快指数:%.0f\n", thi);

            posY = posY + marginY;
            M5.Display.setCursor(0, posY);
            M5.Display.printf("%s\n", getComfort(thi));
        }
    }
}

void sendSerialValue(float temperature, float temperature2, float humidity, float pressure)
{
    if (temperature > -273.0f)
    {
        Serial.printf("温度(1): %.2f ℃\n", temperature);      
    }
    if (temperature2 > -273.0f)
    {
        Serial.printf("温度(2): %.2f ℃\n", temperature2);      
    }
    if (humidity > 0.0f)
    {
        Serial.printf("湿度   : %.2f %%\n", humidity);
    }
    if (pressure > 0.0f)
    {
        Serial.printf("気圧   : %.2f hPa\n", pressure * 0.01f);
    }
    if ((humidity > 0.0f)&&(temperature > -273.0f)&&(temperature2 > -273.0f))
    {
        float thi = calculate_discomfort_index(humidity, temperature, temperature2);
        Serial.printf("不快指数 : %.0f\n", thi);

        float wbgt_outdoor = calculate_wbgt_outdoor(temperature, temperature2, humidity, (pressure * 0.01f));
        float wbgt_indoor = calculate_wbgt_indoor(humidity, temperature, temperature2);
        Serial.printf("WGBT(屋外) : %.0f\n", wbgt_outdoor);
        Serial.printf("WGBT(日陰) : %.0f\n", wbgt_indoor);
    }
    Serial.println("");
}


void parseSensorValue()
{
    float temperature = -273.0f;
    float temperature2 = -273.0f;
    float humidity = 0.0f;
    float pressure = 0.0f;

#if defined(USING_ENV3)
    if (sht30.updated())
    {
        temperature = sht30.temperature();
        humidity = sht30.humidity();
    }
    if (qmp6988.updated())
    {
        pressure = qmp6988.pressure();
        temperature2 = qmp6988.temperature();
    }
#elif defined(USING_ENV4)
    if (sht40.updated())
    {
        temperature = sht40.temperature();
        humidity = sht40.humidity();
    }
    if (bmp280.updated()) {
        pressure = bmp280.pressure();
        temperature2 = bmp280.temperature();
    }
#endif

    sendSerialValue(temperature, temperature2, humidity, pressure);
    showDisplay(temperature, temperature2, humidity, pressure);

}


void loop()
{
    M5.update();
    Units.update(); // 登録された全ユニットの値を一括更新

    //  センサ値を取得しシリアルに出力
    parseSensorValue();

    //  10回に1回、空行をシリアルに出力
    count++;
    if ((count % 10) == 0)
    {
        Serial.println("");
        count = 0;
    }
    delay(LOOP_DURATION);
}
