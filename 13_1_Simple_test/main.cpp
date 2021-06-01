#include "mbed.h"
#include "bbcar.h"
DigitalIn button(USER_BUTTON);
Ticker servo_ticker;
PwmOut pin5(D5), pin6(D6);
BBCar car(pin5, pin6, servo_ticker);

int main() {
   while (1){
   if (button == 0){
      //car.goStraight(100);
      //ThisThread::sleep_for(544ms);
      car.turn(-50,1);
      ThisThread::sleep_for(940ms);
      //car.goStraight(-100);
      //ThisThread::sleep_for(618ms);
      //car.turn(50,1);
      //ThisThread::sleep_for(970ms);
      car.stop();
      //ThisThread::sleep_for(1s);
   }
   }
}