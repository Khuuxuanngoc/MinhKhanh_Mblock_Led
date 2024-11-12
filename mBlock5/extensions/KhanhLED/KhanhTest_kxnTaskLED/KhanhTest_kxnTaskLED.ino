//
#include "kxnTaskLED.h"

kxnTaskLED LED_pin_10;
kxnTaskLED LED_pin_13;

void _delay(float seconds) {
  long endTime = millis() + seconds * 1000;
  while(millis() <= endTime) {
      _loop();
  }
}

void setup(){
    LED_pin_10.setup(10);
    LED_pin_13.setup(13);
    LED_pin_10.write(100,100,10);
    

}

void loop(){

  if(LED_pin_10.isRunning()){
      LED_pin_13.stop();
    }
    else {
      LED_pin_13.write(100,500,5);

    }
    _loop();
}

void _loop(){
    delay(0);
    kxnTaskManager.run(millis());
}

#define _delay     M_DELAY_S