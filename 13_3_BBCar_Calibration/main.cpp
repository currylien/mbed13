#include "mbed.h"
#include "bbcar.h"

Ticker servo_ticker;
PwmOut pin5(D9), pin6(D10);

BBCar car(pin5, pin6, servo_ticker);

int main() {
   // please contruct you own calibration table with each servo
   double pwm_table0[] = {-150, -120, -90, -60, -30, 0, 30, 60, 90, 120, 150};
   double speed_table0[] = {-7.973, -8.292, -7.973, -8.930, -5.422, 0.000, 5.740, 7.654, 7.335, 7.943, 7.654};
   double pwm_table1[] = {-150, -120, -90, -60, -30, 0, 30, 60, 90, 120, 150};
   double speed_table1[] = {-6.060, -5.422, -6.060, -5.741, -6.378, 0.000, 5.103, 5.741, 6.378, 6.378, 6.697};

   // first and fourth argument : length of table
   car.setCalibTable(11, pwm_table0, speed_table0, 11, pwm_table1, speed_table1);

   while (1) {
      car.goStraightCalib(5);
      ThisThread::sleep_for(5s);
      car.stop();
      ThisThread::sleep_for(5s);
   }
}