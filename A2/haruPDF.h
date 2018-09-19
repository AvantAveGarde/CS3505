//Colton Lee, u1014761
//CS3505, David Johnson

#ifndef HARUPDF_H
#define HARUPDF_H
#include "hpdf.h"

class HaruPDF{
  private:
    HPDF_Doc  pdf;
    HPDF_Page page;
    char fname[256];
    HPDF_Font font;
    float rad1;
  public:
    void printLetterOnPage(char i_letter, double i_x, double i_y, float i_angle);
    void saveFile();
    HaruPDF(int argc, char **argv);

};

#endif
