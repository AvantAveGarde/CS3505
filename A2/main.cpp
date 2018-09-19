//Colton Lee, u1014761
//CS3505, David Johnson

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <string>

#include "haruPDF.h"
#include "spiral.h"

// Our main function, creates a HaruPDF object and a CreateSpiral object
// calls the HaruPDF object's printLetterOnPage function and receives values
// from the spiral object such as the text's X & Y positions as well as the text angle.
// At the end, calls the pdf's save function to create the document.
int main(int argc, char** argv){
  //const char* SAMP_TXT = " Fukan Fuukei, Satsujin Kousatsu, Tsuukaku Zanryuu (Zen), Garan no Dou, Mujun Rasen, Boukyaku Roukuon, Satsujin Kousatsu (Kou), Shuushou";
  cout << "Please enter text to turn into a pdf Page: " << endl;
  char SAMP_TXT[250];
  cin.getline(SAMP_TXT, sizeof(SAMP_TXT));

  HaruPDF pdf = HaruPDF(argc, argv);

  //CenterX, CenterY, StartRadius, StartAngle
  CreateSpiral spiral = CreateSpiral(210, 300, 100, 90);

  for (int i = 0; i < strlen (SAMP_TXT); i++) {
    pdf.printLetterOnPage(SAMP_TXT[i - 1], spiral.getTextX(), spiral.getTextY(), spiral.getTextAngle());
    spiral++;
  }

  pdf.saveFile();

  return 0;
}
