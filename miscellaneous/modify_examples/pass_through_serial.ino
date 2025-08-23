// ----- pass_through_serial.ino -----
#include <M5Unified.h>

#define USB_BAUDRATE 115200
#define UART_BAUDRATE 38400

void setup()
{
  // Initialize M5
  auto cfg = M5.config();
  cfg.serial_baudrate = USB_BAUDRATE;
  M5.begin(cfg);

  // ----- Serial connection -----
  Serial.begin(USB_BAUDRATE);
  Serial2.begin(UART_BAUDRATE, SERIAL_8N1, 13, 14);
}

void loop()
{
    for (;;)
    {
        // ----- Read and Write -----
        if (Serial2.available() > 0)
        {
            Serial.write(Serial2.read());
        }
        if (Serial.available() > 0)
        {
            Serial2.write(Serial.read());
        }
    }
}
