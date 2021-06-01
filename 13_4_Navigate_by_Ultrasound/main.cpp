#include "mbed.h"
#include "bbcar.h"

DigitalOut led1(LED1);
Ticker servo_ticker;
PwmOut pin5(D9), pin6(D10);
DigitalInOut pin10(D12);

BBCar car(pin5, pin6, servo_ticker);

int main() {
   parallax_ping  ping1(pin10);
   car.goStraight(100);
   while(1) {
      if((float)ping1>10) led1 = 1;
      else {
         led1 = 0;
         car.stop();
         break;
      }
      ThisThread::sleep_for(10ms);
   }
}