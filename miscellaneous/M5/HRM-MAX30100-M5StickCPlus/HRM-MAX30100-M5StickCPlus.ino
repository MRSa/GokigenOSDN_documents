/*
    M5stickC Plus : ScreenShow.ino / 
    addr: https://github.com/oxullo/Arduino-MAX30100
    https://raw.githubusercontent.com/m5stack/M5StickC-Plus/master/examples/Unit/HEART/ScreenShow/ScreenShow.ino

    https://shop.m5stack.com/products/mini-heart-unit
    https://www.hackster.io/ghibi/pulse-oximeter-with-alert-function-518897
*/

#include <M5StickCPlus.h>
/*************************
#include "MAX30100.h"
#include <math.h>

#define SAMPLING_RATE MAX30100_SAMPRATE_50HZ

// The LEDs currents must be set to a level that avoids clipping and maximises
// the dynamic range
#define IR_LED_CURRENT  MAX30100_LED_CURR_11MA
#define RED_LED_CURRENT MAX30100_LED_CURR_11MA

// The pulse width of the LEDs driving determines the resolution of
// the ADC (which is a Sigma-Delta).
// set HIGHRES_MODE to true only when setting PULSE_WIDTH to
// MAX30100_SPC_PW_1600US_16BITS
#define PULSE_WIDTH  MAX30100_SPC_PW_400US_14BITS
#define HIGHRES_MODE true

#define ERROR_DUR_MS   1000

TFT_eSprite Disbuff = TFT_eSprite(&M5.Lcd);
MAX30100 sensor;

uint8_t Heart_rate = 0;
uint8_t Spo2 = 0;

uint64_t realTime[4], time_count = 0;
bool k_ready = false;


void setup()
{
    M5.begin(true, true, true);

    // ----- Initialize serial port 
    Serial.begin(115200);
    while(!Serial) delay(10);
    Serial.println("--- PROGRAM START ---");
    
    M5.Lcd.setRotation(3);
    M5.Lcd.setSwapBytes(false);
    Disbuff.createSprite(240, 135);
    Disbuff.setSwapBytes(true);

    Disbuff.createSprite(240, 135);

    Wire.begin(32, 33);    // Grove >> SDA(Yellow): G32, SCL(White): G33

    if (!sensor.begin())
    {
        Serial.println("FAILED");
        M5.Lcd.setRotation(3);
        M5.Lcd.setTextSize(2);
        M5.Lcd.setCursor(0, 0);
        M5.Lcd.println("Heart Rate MONITOR");
        M5.Lcd.println("");
        M5.Lcd.println("Initialize Failed.");
        for (;;)
            ;   // ----- STOP EXECUTE -----
    }
    else
    {
        Serial.println("SUCCESS");
    }

    sensor.setMode(MAX30100_MODE_SPO2_HR);
    sensor.setLedsCurrent(IR_LED_CURRENT, RED_LED_CURRENT);
    sensor.setLedsPulseWidth(PULSE_WIDTH);
    sensor.setSamplingRate(SAMPLING_RATE);
    sensor.setHighresModeEnabled(HIGHRES_MODE);
    sensor.resetFifo();
}

uint16_t line[2][320] = {0};
int16_t k_number[320] = {0};
int16_t raw_data[512];
int16_t k_min;
int16_t k_threshold;
uint32_t k_pos_buff[32];
double k_pos_time[32];
double k_standard_deviation, k_sumdata;
uint32_t k_pos, k_pos_count = 0;

uint32_t led_pos = 0, ir_Pos = 0;
uint16_t ir_max = 0, led_max = 0, ir_min = 0, led_min = 0, ir_last = 0,
         led_last    = 0;
int16_t k_number_min = 0, k_number_max = 0, k_last = 0;
uint16_t ir_last_raw = 0, led_last_raw = 0, k_last_raw = 0;
uint16_t ir_disdata, led_disdata, k_disdata;
uint16_t Alpha     = 0.3 * 256;
uint16_t count_min = 0, count_max = 0;

void loop()
{
    uint16_t ir, red;

    // Serial.printf("raed fifo Length :%d\n", read_length);
    while (sensor.getRawValues(&ir, &red) == false)
    {
        delay(10);
        sensor.update();
    }

    while (1)
    {
        line[0][(led_pos + 240) % 320] =
            (led_last_raw * (256 - Alpha) + red * Alpha) / 256;
        line[1][(ir_Pos + 240) % 320] =
            (ir_last_raw * (256 - Alpha) + ir * Alpha) / 256;

        k_number[(led_pos + 240) % 320] =
            line[0][(led_pos + 240) % 320] - led_last_raw;

        led_last_raw = line[0][(led_pos + 240) % 320];
        ir_last_raw  = line[1][(led_pos + 240) % 320];
        led_pos++;
        ir_Pos++;
        if (sensor.getRawValues(&ir, &red) == false)
        {
            break;
        }
    }

    sensor.resetFifo();

    for (int i = 0; i < 240; i++)
    {
        if (i == 0)
        {
            led_max = led_min = line[0][(led_pos + i) % 320];
            ir_max = ir_min = line[1][(ir_Pos + i) % 320];
            k_number_min = k_number_max = k_number[(ir_Pos + i) % 320];
        } else {
            led_max = (line[0][(led_pos + i) % 320] > led_max)
                          ? line[0][(led_pos + i) % 320]
                          : led_max;
            led_min = (line[0][(led_pos + i) % 320] < led_min)
                          ? line[0][(led_pos + i) % 320]
                          : led_min;

            ir_max = (line[1][(ir_Pos + i) % 320] > ir_max)
                         ? line[1][(ir_Pos + i) % 320]
                         : ir_max;
            ir_min = (line[1][(ir_Pos + i) % 320] < ir_min)
                         ? line[1][(ir_Pos + i) % 320]
                         : ir_min;

            k_number_max = (k_number[(ir_Pos + i) % 320] > k_number_max)
                               ? k_number[(ir_Pos + i) % 320]
                               : k_number_max;
            k_number_min = (k_number[(ir_Pos + i) % 320] < k_number_min)
                               ? k_number[(ir_Pos + i) % 320]
                               : k_number_min;
        }
    }

    Disbuff.fillRect(0, 0, 240, 135, BLACK);

    for (int i = 0; i < 240; i++) {
        led_disdata =
            map(line[0][(led_pos + i) % 320], led_max, led_min, 0, 135);
        ir_disdata = map(line[1][(ir_Pos + i) % 320], ir_max, ir_min, 0, 135);
        k_disdata  = map(k_number[(ir_Pos + i) % 320], k_number_max,
                        k_number_min, 0, 135);
        {
            Disbuff.drawLine(i, led_last, i + 1, led_disdata, WHITE);
            Disbuff.drawLine(i, ir_last, i + 1, ir_disdata, RED);
            Disbuff.drawLine(i, k_last, i + 1, k_disdata, GREEN);
        }
        ir_last  = ir_disdata;
        led_last = led_disdata;
        k_last   = k_disdata;
    }

    Disbuff.setTextSize(2);
    Disbuff.setTextColor(WHITE);
    Disbuff.setCursor(5, 5);
    Disbuff.printf("HEART RATE MONITOR");

    Disbuff.setTextSize(1);
    Disbuff.setTextColor(WHITE);
    Disbuff.setCursor(5, 25);
    Disbuff.printf("led:%d,%d,%d", led_max, led_min, led_max - led_min);
    Disbuff.setCursor(5, 35);
    Disbuff.printf("ir:%d,%d,%d", ir_max, ir_min, ir_max - ir_min);

    Disbuff.pushSprite(0, 0);

    delay(10);
}

*************************/

/*************************/
#include "MAX30100_PulseOximeter.h"
#define REPORTING_PERIOD_MS     1000

PulseOximeter pox;
uint8_t Heart_rate = 0;
uint8_t Spo2 = 0;
uint32_t tsLastReport = 0;

//TFT_eSprite Disbuff = TFT_eSprite(&M5.Lcd);

// Callback (registered below) fired when a pulse is detected
void onBeatDetected()
{
  printHRandSPO2(true);
}

void setup()
{
    M5.begin(true, true, true);

    // ----- Initialize serial port 
    Serial.begin(115200);
    while(!Serial) delay(10);
    Serial.println("--- PROGRAM START ---");
    
    M5.Lcd.setRotation(3);
    M5.Lcd.setSwapBytes(false);

    Wire.begin(32, 33);    // Grove >> SDA(Yellow): G32, SCL(White): G33

    // Initialize a sensor
    if (!pox.begin())
    {
        Serial.println("FAILED");
        M5.Lcd.setRotation(3);
        M5.Lcd.setTextSize(2);
        M5.Lcd.setCursor(0, 0);
        M5.Lcd.println("Heart Rate MONITOR");
        M5.Lcd.println("");
        M5.Lcd.println("Initialize Failed.");
        for (;;)
            ;   // ----- STOP EXECUTE -----
    }
    else
    {
        Serial.println("SUCCESS");
    }

    //LED Configuration
    pox.setIRLedCurrent(MAX30100_LED_CURR_7_6MA);
    
    //Register a callback for the beat detection
    pox.setOnBeatDetectedCallback(onBeatDetected);
}

void loop()
{
  M5.update();  //update button state
  pox.update(); //update pulse oximeter

  if (millis() - tsLastReport > REPORTING_PERIOD_MS)
  {
    Heart_rate = (int)pox.getHeartRate();
    Spo2 = pox.getSpO2();
    printHRandSPO2(false);
    tsLastReport = millis();
  }
}


void printHRandSPO2(bool beat)
{
  M5.Lcd.fillScreen(BLACK);
  //M5.Lcd.clear(BLACK);
  if (beat)
  {
    M5.Lcd.setTextColor(GREEN);
  }
  else
  {
    M5.Lcd.setTextColor(WHITE);
  }
  M5.Lcd.setTextSize(3);
  M5.Lcd.setCursor(0,10);
  M5.Lcd.println("- MAX30100 -");
  M5.Lcd.setCursor(0,45);
  M5.Lcd.print("HR:   "); M5.Lcd.println(Heart_rate);
  M5.Lcd.print("SPO2: "); M5.Lcd.println(Spo2); 
}

/*************************/
