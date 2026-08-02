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

float calculate_altitude(const float pressure, const float seaLvhPa = 1013.25f)
{
    return 44330.f * (1.0f - pow((pressure / 100.f) / seaLvhPa, 0.1903f));
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
    M5.Display.setRotation(1);
    M5.Display.setTextSize(1);
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
        int posY = 0;
        M5.Display.setCursor(0, 0);
        M5.Display.printf(" = センサ値 =\n");

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

    sendSerialValue(temperature, temperature2, temperature2, pressure);
    showDisplay(temperature, temperature2, temperature2, pressure);

}


void loop() {
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
