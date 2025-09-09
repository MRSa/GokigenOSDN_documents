/////// check_imu_magnet.ino : check IMU Magnet value.

#include <M5Unified.h>

// ----- USBシリアル通信
#define SERIAL_BAUDRATE_PC 115200

int count = 0;

void setup()
{
  auto cfg = M5.config();
  cfg.serial_baudrate = SERIAL_BAUDRATE_PC;
  cfg.internal_imu = true;
  cfg.external_imu = false;
  M5.begin(cfg);

  M5.Display.init();
  M5.Display.setRotation(1);
  M5.Display.setTextSize(1);
  M5.Display.println("Initializing...");

  // ----- IMU
  M5.Imu.loadOffsetFromNVS();
  auto imuResult = M5.Imu.begin();
  if (imuResult)
  {
    auto imuType = M5.Imu.getType(); 
    Serial.print("IMU is ready. : ");
    Serial.println(imuType, HEX); // m5::imu_t::imu_bmi270 == 6 
  }
  else
  {
    Serial.println("  IMU is disabled...");
  }

  delay(3000); // 少し待つ
  M5.Display.clear();
  Serial.println("Program Start!");
}

void loop()
{
  float imuTemperature = 0.0f;  // 温度(IMU)
  m5::imu_data_t imuData;       // IMUデータ

  M5.update();

  // IMUの情報を取得
  if (M5.Imu.update() > 0)
  {
    M5.Imu.getImuData(&imuData);
    M5.Imu.getTemp(&imuTemperature);
  }
  
  M5.Display.setCursor(0,0);
  M5.Display.setTextSize(1);
  M5.Display.setFont(&fonts::efontJA_10);
  M5.Display.setTextColor(TFT_WHITE, TFT_BLACK);
  M5.Display.printf(" === IMU TEST ===\r\n\r\n");
  M5.Display.printf("気温: %.1f ℃   \r\n\r\n", imuTemperature);
  M5.Display.printf("  重力   傾き   磁力\r\n");
  M5.Display.printf("x: %-2.1f %-3.1f %-3.1f   \r\n", imuData.accel.x, imuData.gyro.x, imuData.mag.x);
  M5.Display.printf("y: %-2.1f %-3.1f %-3.1f   \r\n", imuData.accel.y, imuData.gyro.y, imuData.mag.y);
  M5.Display.printf("z: %-2.1f %-3.1f %-3.1f   \r\n", imuData.accel.z, imuData.gyro.z, imuData.mag.z);

  count++;
  if ((count % 10) == 0)
  {
    // ----- およそ3秒に１回シリアルに出力
    Serial.print("気温: "); Serial.print(imuTemperature); Serial.println(" ℃");
    Serial.print("重力: "); Serial.print("X:"); Serial.print(imuData.accel.x); Serial.print(" Y:"); Serial.print(imuData.accel.y); Serial.print(" Z:"); Serial.println(imuData.accel.z);
    Serial.print("傾き: "); Serial.print("X:"); Serial.print(imuData.gyro.x); Serial.print(" Y:"); Serial.print(imuData.gyro.y); Serial.print(" Z:"); Serial.println(imuData.gyro.z);
    Serial.print("磁力: "); Serial.print("X:"); Serial.print(imuData.mag.x); Serial.print(" Y:"); Serial.print(imuData.mag.y); Serial.print(" Z:"); Serial.println(imuData.mag.z);
    Serial.println("");
    count = 0;
  }
  delay(300); // 少し待つ
}
