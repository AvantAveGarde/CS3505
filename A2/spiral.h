//Colton Lee, u1014761
//CS3505, David Johnson

#ifndef SPIRAL_H
#define SPIRAL_H

#include <iostream>
using namespace std;
class CreateSpiral{
private:
  double radius;
  double centerX;
  double centerY;

  float textX;
  float textY;

  double angle;
  double rad2;

  int count = 0;
  
public:
  CreateSpiral(double i_centerX, double i_centerY, double i_radius, double i_angle);
  void operator ++();
  void operator++ (int);

  friend ostream& operator<<(ostream& os, const CreateSpiral& cs);

  double getTextX();
  double getTextY();
  double getTextAngle();
};

#endif
