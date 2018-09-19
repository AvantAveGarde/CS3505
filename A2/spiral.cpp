//Colton Lee, u1014761
//CS3505, David Johnson

#include <math.h>
#include "spiral.h"

using namespace std;

//Operator ++ overload, allows us to increment the radius, thereby creating a spiral.
void CreateSpiral::operator ++() {
  rad2 = (angle / 180 * M_PI);
  textX = (centerX) + cos(rad2) * (100 + count);
  textY = (centerY) + sin(rad2) * (100 + count);
  count +=1;
  angle -= (10);
}

void CreateSpiral::operator++(int){
  ++*this;
}

//Operator << overloard to report on the text angle as well as the current radius.
ostream& operator<<(ostream& os, const CreateSpiral& cs){
  os << "angle: " << cs.angle << " " << "radius: " << cs.radius + cs.count;
  return os;
}

//Getters and Setters
double CreateSpiral::getTextX(){
  return textX;
}
double CreateSpiral::getTextY(){
  return textY;
}
double CreateSpiral::getTextAngle(){
  return angle;
}

//Default Constructor.
CreateSpiral::CreateSpiral(double i_centerX, double i_centerY, double i_radius, double i_angle){
  angle = i_angle;
  centerX = i_centerX;
  centerY = i_centerY;
  radius = i_radius;
}
