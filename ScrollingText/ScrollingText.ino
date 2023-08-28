/*
https://majicdesigns.github.io/MD_Parola/_m_d___parola_8h.html#acf3b849a996dbbe48ca173d2b0b82eda Parola documentation

https://pjrp.github.io/MDParolaFontEditor Sprite creator

*/
#include <MD_Parola.h>
#include <MD_MAX72xx.h>
#include <SPI.h>

 
#define HARDWARE_TYPE MD_MAX72XX::FC16_HW
//#define HARDWARE_TYPE MD_MAX72XX::GENERIC_HW
 
#define MAX_DEVICES 4
#define CS_PIN 10
 
MD_Parola myDisplay = MD_Parola(HARDWARE_TYPE, CS_PIN, MAX_DEVICES);
 
const uint8_t Smile[] = { 8, 60, 66, 149, 161, 161, 149, 66, 60 };// Smile



void setup() {

  myDisplay.begin();
  myDisplay.addChar('$', Smile);
 
  myDisplay.setIntensity(4);
  myDisplay.displayClear();
  //myDisplay.displayScroll("$", PA_CENTER, PA_SCROLL_LEFT, 200);
  myDisplay.displayScroll("$", PA_LEFT, PA_PRINT, 200);
}
 
void loop() {
  if (myDisplay.displayAnimate()) {
    myDisplay.displayReset();
  }
}
