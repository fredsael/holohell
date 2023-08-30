/*
https://majicdesigns.github.io/MD_Parola/_m_d___parola_8h.html#acf3b849a996dbbe48ca173d2b0b82eda Parola documentation

https://pjrp.github.io/MDParolaFontEditor Sprite creator

https://how2electronics.com/8x32-max7219-dot-matrix-led-display-with-arduino/#Source_CodeProgram_for_TextNumber_Printing

Pins
CS = 10
CLK = 13
DIN = 11

*/
#include <MD_Parola.h>
#include <MD_MAX72xx.h>
#include <SPI.h>

 
#define HARDWARE_TYPE MD_MAX72XX::FC16_HW
//#define HARDWARE_TYPE MD_MAX72XX::GENERIC_HW
 
#define MAX_DEVICES 4
#define CS_PIN 10
 
MD_Parola myDisplay = MD_Parola(HARDWARE_TYPE, CS_PIN, MAX_DEVICES);
 
const uint8_t Smile[] = {8, 60, 66, 149, 145, 145, 149, 66, 60 };// Smile
const uint8_t Smile_open[] = { 8, 60, 66, 149, 169, 169, 149, 66, 60 };// Smile open mouth

typedef struct
{
  uint8_t spacing;  // character spacing
  const char *msg;  // message to display
} msgDef_t;

msgDef_t Animation[] =
 {
  {1, "$"},
  {0, "="}
};

#define MAX_STRINGS  (sizeof(Animation)/sizeof(Animation[0]))

void setup() {

  myDisplay.begin();
  myDisplay.addChar('$', Smile);
  myDisplay.addChar('=', Smile_open);
  
 
  myDisplay.setIntensity(4);
  //myDisplay.displayClear();

  myDisplay.setCharSpacing(Animation[0].spacing);
  //myDisplay.displayScroll("$", PA_CENTER, PA_SCROLL_LEFT, 200);
  //myDisplay.displayScroll("$", PA_LEFT, PA_PRINT, 200);
  //myDisplay.displayText("$", PA_LEFT, 200, 200, PA_PRINT);
  //myDisplay.displayText("=", PA_LEFT, 200, 200, PA_PRINT);
  myDisplay.displayText(Animation[0].msg, PA_LEFT, 200, 200, PA_PRINT);
}
 
void loop() {
  static uint8_t	n = 1;

  if (myDisplay.displayAnimate()) {
    myDisplay.setTextBuffer(Animation[n].msg);
    myDisplay.setCharSpacing(Animation[n].spacing);
    myDisplay.displayReset();
    n = (n + 1) % MAX_STRINGS;
  };
}
