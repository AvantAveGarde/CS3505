//Colton Lee, u1014761
//CS3505, David Johnson

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "haruPDF.h"

// This function takes our parameter values from the main.cpp call
// and then places the incomming "i_letter" on the page.
void HaruPDF::printLetterOnPage(char i_letter, double i_x, double i_y, float i_angle){
  char buf[2];

  rad1 = (i_angle - 80) / 180 * M_PI;
  HPDF_Page_SetTextMatrix(page,
                          cos(rad1), sin(rad1), -sin(rad1), cos(rad1),
                          i_x, i_y);

  // C-style strings are null-terminated. The last character must a 0.
  buf[0] = i_letter;
  buf[1] = 0;
  HPDF_Page_ShowText (page, buf);
}

//Saves the file into a pdf page. Must be called at the end of receiving letters.
void HaruPDF::saveFile(){
  HPDF_Page_EndText (page);

  /* save the document to a file */
  HPDF_SaveToFile (pdf, fname);

  /* clean up */
  HPDF_Free (pdf);
}

//Default constructor, sets properties such as the pdf name, size, font etc.
HaruPDF::HaruPDF(int argc, char **argv){
  strcpy (fname, argv[0]);
  strcat (fname, ".pdf");

  pdf = HPDF_New (NULL, NULL);
  /* add a new page object. */
  page = HPDF_AddPage (pdf);
  HPDF_Page_SetSize (page, HPDF_PAGE_SIZE_A5, HPDF_PAGE_PORTRAIT);
  //    print_grid  (pdf, page);
  font = HPDF_GetFont (pdf, "Helvetica", NULL);
  HPDF_Page_SetTextLeading (page, 20);
  HPDF_Page_BeginText (page);
  // Their example sets font twice. Probably some kind of mistake. Fix it or do what they do.
  font = HPDF_GetFont (pdf, "Courier-Bold", NULL);
  HPDF_Page_SetFontAndSize (page, font, 30);
}
