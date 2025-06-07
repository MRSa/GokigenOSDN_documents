/////////////////////////////////////////////////////////////
//  Raspberry Pi Pico
//     w/Stepping Motor (28BYJ-48 + ULN2003)
//
//   Board: Raspberry Pi Pico W
//     * https://github.com/earlephilhower/arduino-pico
//
//   Pin
//     Motor: GP0 - IN1, GP1 - IN2, GP3 - IN3, GP4 - IN4
//     Switch:  GP16 - Green, GP17 - Yellow
/////////////////////////////////////////////////////////////

#include <WiFi.h>
#include <Stepper.h>
#include <WebServer.h>

// --- Control Switch
const int GREEN_SW_PIN = 16;
const int YELLOW_SW_PIN = 17;

// --- Motor I/O constants
const int PICO_GP0_MOTOR_IN1 = 0;
const int PICO_GP1_MOTOR_IN2 = 1;
const int PICO_GP2_MOTOR_IN3 = 2;
const int PICO_GP3_MOTOR_IN4 = 3;

const int MOTOR_MOVE_RPM = 10;
const int MOTOR_MOVE_STEP = 460;

Stepper stepper(2048, PICO_GP0_MOTOR_IN1, PICO_GP2_MOTOR_IN3, PICO_GP1_MOTOR_IN2, PICO_GP3_MOTOR_IN4);
WebServer webServer(8181);

void startWifiAsAccessPointMode()
{
    const char standalone_ssid[] = "PiPicoW";
    const char pass[] = "P1Pic0W0";
    const IPAddress ip(192,168,21,1);
    const IPAddress subnet(255,255,255,0);
    WiFi.mode(WIFI_AP);
    WiFi.softAPConfig(ip,ip,subnet);
    WiFi.softAP(standalone_ssid,pass);
    delay(100);
    IPAddress myIP = WiFi.softAPIP();
    delay(100);
    //Serial.println("");
    //Serial.print("Start WiFi Standalone : ");
    //Serial.println(myIP.toString().c_str());
    //Serial.println("");
}

void handleRoot()
{
  String message = "<html>";
  message += "<head><title>Raspberry Pi Pico W</title></head>";
  message += "<body>";
  message += "Now working!";
  message += "</body>";
  webServer.send(200, "text/HTML", message);
}

void handleMoveCw()
{
  String message = "<html>";
  message += "<head><title>Move motor (CW)</title></head>";
  message += "<body>";
  message += "Command accepted!";
  message += "</body>";
  webServer.send(200, "text/HTML", message);
  moveMotor(false, MOTOR_MOVE_STEP);
}

void handleMoveCcw()
{
  String message = "<html>";
  message += "<head><title>Move motor (CCW)</title></head>";
  message += "<body>";
  message += "Command accepted!";
  message += "</body>";
  webServer.send(200, "text/HTML", message);
  moveMotor(true, MOTOR_MOVE_STEP);
}

void handleNotFound()
{
  webServer.send(404, "text/plain", "Not found!");
}

void startWebServer()
{
  webServer.on("/", handleRoot);
  webServer.on("/movecw", handleMoveCw);
  webServer.on("/moveccw", handleMoveCcw);
  webServer.onNotFound(handleNotFound);
  webServer.begin();
}

void moveMotor(bool isCcw, int step)
{
  if (isCcw)
  {
    // counter clockwise
    stepper.step(step * (-1));
  }
  else
  {
    // clockwise
    stepper.step(step);
  }
}

void setup()
{
  //Serial.begin(115200);
  
  // ----- Set up Switch (Green / Yellow)
  pinMode(GREEN_SW_PIN, INPUT);
  pinMode(YELLOW_SW_PIN, INPUT);

  // ----- Set up built-in LED
  pinMode(LED_BUILTIN, OUTPUT);

  // ----- Set up Motor Board
  stepper.setSpeed(MOTOR_MOVE_RPM);

  // ----- Wi-Fi and Web Server
  startWifiAsAccessPointMode();
  startWebServer();

  //Serial.println("");
  //Serial.println(" ----- START Raspberry Pi PICO!");
}

void loop()
{
  bool isCcw = false;
  while (true)
  {
    webServer.handleClient();
    digitalWrite(LED_BUILTIN, LOW);
    if (digitalRead(GREEN_SW_PIN) == LOW)
    {
      // ----- Pushed Green Button
      digitalWrite(LED_BUILTIN, HIGH);
      isCcw = false;
      //Serial.println("Pushed Green.");
      break;      
    }
    
    if (digitalRead(YELLOW_SW_PIN) == LOW)
    {
      // ----- Pushed Yellow Button
      digitalWrite(LED_BUILTIN, HIGH);
      isCcw = true;
      //Serial.println("Pushed Yellow.");
      break;
    }
  }

  // ----- move motor
  moveMotor(isCcw, MOTOR_MOVE_STEP);
}
