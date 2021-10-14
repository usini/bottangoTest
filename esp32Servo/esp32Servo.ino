#include <PS4Controller.h>
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

#define SERVOMIN  150 // This is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX  600 // This is the 'maximum' pulse length count (out of 4096)
#define USMIN  600 // This is the rounded 'minimum' microsecond length based on the minimum pulse of 150
#define USMAX  2400 // This is the rounded 'maximum' microsecond length based on the maximum pulse of 600
#define SERVO_FREQ 50 // Analog servos run at ~50 Hz updates
#define deadzone 10

int lx = 0;
int ly = 0;
int rx = 0;
int ry = 0;

bool stop_servo0 = false;
int value_servo0 = 0;
bool stop_servo1 = false;
int value_servo1 = 0;

void setup() {
  Serial.begin(115200);

  // Replace the "03:03:03:03:03:03" with the MAC address
  // the controller wants to pair to
  PS4.begin("03:03:03:03:03:03");
  Serial.println("Ready.");
  pwm.begin();
  pwm.setOscillatorFrequency(27000000);
  pwm.setPWMFreq(SERVO_FREQ);  // Analog servos run at ~50 Hz updates
  PS4.setLed(0, 255, 0);
}

void loop() {
  if (PS4.isConnected()) {
    if (PS4.LStickX()) {
      if (lx != PS4.LStickX()) {
        lx = PS4.LStickX();
        if ((lx > deadzone) || (lx < -deadzone)) {
          Serial.printf("Left Stick x at %d\n", PS4.LStickX());
          if (PS4.LStickX() < 0) {
            PS4.setLed(255, 0, 0);
            //PS4.setRumble(lx, rx);
            PS4.sendToController();
            value_servo0 = map(lx, -128, 0, 400, 1520);
          } else {
            PS4.setLed(255, 255, 0);
            //PS4.setRumble(lx, rx);
            PS4.sendToController();
            value_servo0 = map(lx, 0, 128, 320, 50);
          }
          pwm.setPWM(0, 0, value_servo0);
          stop_servo0 = true;
          Serial.println(value_servo0);
        } else {
          if (stop_servo0) {
            PS4.setLed(0, 255, 0);
            //PS4.setRumble(0, rx);
            PS4.sendToController();
            stop_servo0 = false;
            pwm.setPWM(0, 0, 0);
            Serial.println(0);
          }
        }
      }
      if (rx != PS4.RStickX()) {
        rx = PS4.RStickX();
        if ((rx > deadzone) || (rx < -deadzone)) {
          Serial.printf("Left Stick x at %d\n", PS4.RStickX());
          if (PS4.RStickX() < 0) {
            //PS4.setRumble(lx, rx);
            PS4.setLed(0, 0, 255);
            PS4.sendToController();
            value_servo1 = map(rx, -128, 0, 400, 1520);
          } else {
            //PS4.setRumble(lx, rx);
            PS4.setLed(0, 255, 255);
            PS4.sendToController();
            value_servo1 = map(rx, 0, 128, 320, 50);
          }
          pwm.setPWM(2, 0, value_servo1);
          stop_servo1 = true;
          Serial.println(value_servo1);
        } else {
          if (stop_servo1) {
            PS4.setLed(0, 255, 0);
            //PS4.setRumble(lx, 0);
            PS4.sendToController();
            stop_servo1 = false;
            pwm.setPWM(2, 0, 0);
            Serial.println(0);
          }
        }
      }
    }


    /*
      if (PS4.LStickY()) {
      if (ly != PS4.LStickY()) {
        ly = PS4.LStickY();
        if ((ly > deadzone) || (ly < -deadzone)) {
          Serial.printf("Left Stick y at %d\n", PS4.LStickY());
          pwm.setPWM(2, 0, map(ly, -128, 128, 0, 2000));
        }
      }
      }
      if (PS4.RStickX()) {
      if (rx != PS4.RStickX()) {

        rx = PS4.RStickX();
        if ((rx > deadzone) || (rx < -deadzone)) {
          Serial.printf("Right Stick x at %d\n", PS4.RStickX());
          pwm.setPWM(2, 0, map(rx, -128, 128, SERVOMIN, SERVOMAX));
        }
      }
      }
      if (PS4.RStickY()) {
      if (ry != PS4.RStickY()) {

        ry = PS4.RStickY();
        if ((ry > deadzone) || (ry < -deadzone)) {
          Serial.printf("Right Stick y at %d\n", PS4.RStickY());
          pwm.setPWM(3, 0, map(ry, -128, 128, SERVOMIN, SERVOMAX));
        }
      }
      }
    */
  }

}
