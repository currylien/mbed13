#include "mbed.h"
#include "bbcar.h"

Ticker servo_ticker;
Ticker encoder_ticker;
PwmOut pin5(D5), pin6(D6);
DigitalIn pin3(D3);

BBCar car(pin5, pin6, servo_ticker);
int main() {
   parallax_encoder encoder0(pin3, encoder_ticker);
   encoder0.reset();
   car.goStraight(100);
   while(encoder0.get_cm()<30) ThisThread::sleep_for(50ms);
   car.stop();
}