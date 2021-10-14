#include "src/BottangoCore.h"
#include "src/BasicCommands.h"
unsigned long interval = 30; // the time we need to wait
unsigned long previousMillis = 0; // millis() returns an unsigned long.
bool animationplay = false;
bool ledlatch = false;

#define btn1 12
#define btn2 11
#define btn3 10
#define btn4 9

void setup()
{
  BottangoCore::bottangoSetup();
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(btn1, INPUT_PULLUP);
  pinMode(btn2, INPUT_PULLUP);
  pinMode(btn3, INPUT_PULLUP);
  pinMode(btn4, INPUT_PULLUP);
}

void buttons_check() {
  if (!digitalRead(btn1)) {
    BottangoCore::commandStreamProvider.startCommandStream(0, false);
    ledlatch = true;
    digitalWrite(LED_BUILTIN, HIGH);
  }
  if (!digitalRead(btn2)) {
    BottangoCore::commandStreamProvider.startCommandStream(1, false);
    ledlatch = true;
    digitalWrite(LED_BUILTIN, HIGH);
  }
  if (!digitalRead(btn3)) {
    BottangoCore::commandStreamProvider.startCommandStream(2, false);
    ledlatch = true;
    digitalWrite(LED_BUILTIN, HIGH);
  }
  if (!digitalRead(btn4)) {
    BottangoCore::commandStreamProvider.startCommandStream(3, false);
    ledlatch = true;
    digitalWrite(LED_BUILTIN, HIGH);
  }
}

void loop()
{
  unsigned long currentMillis = millis();
  //Serial.println(BottangoCore::commandStreamProvider.streamIsInProgress());
  if ((unsigned long)(currentMillis - previousMillis) >= interval) {
    if (!BottangoCore::commandStreamProvider.streamIsInProgress()) {
      buttons_check();
    }
    previousMillis = millis();
  }

  if (animationplay) {
    if (!BottangoCore::commandStreamProvider.streamIsInProgress()) {
      digitalWrite(LED_BUILTIN, LOW);
      animationplay = false;
    }
  }

  if (ledlatch){
    digitalWrite(LED_BUILTIN, HIGH);
    ledlatch = false; 
    animationplay = true;
  }
  
  BottangoCore::bottangoLoop();
}
