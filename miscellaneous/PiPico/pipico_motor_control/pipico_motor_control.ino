//////////////////////////////////////////////////
//  Raspberry Pi Pico
//    w/Stepping Motor (28BYJ-48 + ULN2003)
//     
//////////////////////////////////////////////////

#include <Stepper.h>

// --- Control Switch
const int GREEN_SW_PIN = 16;
const int YELLOW_SW_PIN = 17;

// --- Motor I/O
const int PICO_GP0_MOTOR_IN1 = 0;
const int PICO_GP1_MOTOR_IN2 = 1;
const int PICO_GP2_MOTOR_IN3 = 2;
const int PICO_GP3_MOTOR_IN4 = 3;

Stepper stepper(2048, PICO_GP0_MOTOR_IN1, PICO_GP1_MOTOR_IN2, PICO_GP2_MOTOR_IN3, PICO_GP3_MOTOR_IN4);

void setup()
{
 // Serial.begin(115200);
  
  // ----- Set up Switch (Green / Yellow)
  pinMode(GREEN_SW_PIN, INPUT);
  pinMode(YELLOW_SW_PIN, INPUT);

  // ----- Set up built-in LED
  pinMode(LED_BUILTIN, OUTPUT);

  // ----- Set up Motor Board
  stepper.setSpeed(14);    //  14rpm

  //Serial.println("");
  //Serial.println(" ----- START Raspberry Pi PICO!");
}

void loop()
{
  bool isCcw = false;
  while (true)
  {
    digitalWrite(LED_BUILTIN, LOW);
    if (digitalRead(GREEN_SW_PIN) == LOW)
    {
      // ----- Pushed Green Button
      digitalWrite(LED_BUILTIN, HIGH);
      isCcw = false;
      break;      
    }
    
    if (digitalRead(YELLOW_SW_PIN) == LOW)
    {
      // ----- Pushed Yellow Button
      digitalWrite(LED_BUILTIN, HIGH);
      isCcw = true;
      break;
    }
  }

  // ----- move motor
  if (isCcw)
  {
      stepper.step(-512);  // move -90 degree
  }
  else
  {
      stepper.step(512);  // move 90 degree
  }

}
