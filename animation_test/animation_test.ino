/*
pins:
CS = 10
CLK = 13
DIN = 11
SOUND PIN =A0
*/

#include <MD_Parola.h>
#include <MD_MAX72xx.h>
#include <SPI.h>



#define HARDWARE_TYPE MD_MAX72XX::FC16_HW //What device
#define MAX_DEVICES 8 //How many 8x8 you have
#define CS_PIN 10 // What pin CS is in the Arduino
#define  delay_t  50  // in milliseconds

MD_MAX72XX mx = MD_MAX72XX(HARDWARE_TYPE, CS_PIN, MAX_DEVICES);
MD_Parola myDisplay = MD_Parola(HARDWARE_TYPE, CS_PIN, MAX_DEVICES);

//sprites
// Default smile.
byte Bdefault_SmileTR[8] = {0x07,0x0F,0x38,0x30,0x66,0xC6,0xC6,0xC0};
byte Bdefault_SmileTL[8] = {0xE0,0xF0,0x1C,0x0C,0x66,0x63,0x63,0x03};
byte Bdefault_SmileBR[8] = {0xD8,0xDC,0xCF,0x67,0x30,0x38,0x0F,0x07};
byte Bdefault_SmileBL[8] = {0x1B,0x3B,0xF3,0xE6,0x0C,0x1C,0xF0,0xE0};
byte Bdefault_Blank[8] = {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
//Mouth talking open
byte mOpen_Left[8] = {0xe0, 0xf0, 0x1c, 0x0c, 0x06, 0x63, 0xf3, 0xf3};
byte mOpen_Right[8] = {0xf3, 0xf3, 0x63, 0x06, 0x0c, 0x1c, 0xf0, 0xe0};
//Mouth talking closed
byte mClosed_Left[8] = {0xe0, 0xf0, 0x1c, 0x0c, 0x66, 0x63, 0x63, 0x63};
byte mClosed_Right[8] = {0x63, 0x63, 0x63, 0x66, 0x0c, 0x1c, 0xf0, 0xe0};

byte face1[8] = {0x3c, 0x42, 0x95, 0x91, 0x91, 0x95, 0x42, 0x3c};
byte face2[8] = {0x3c, 0x42, 0x85, 0xb1, 0xb1, 0x85, 0x42, 0x3c};
byte face3[8] = {0x3c, 0x42, 0x95, 0xa1, 0xa1, 0x95, 0x42, 0x3c};

int x =0;
float test = sin(x);



void draw1(){
for (int i = 0; i <= 7; i++) {
    mx.setRow(0, 0, i, face1[i]);
}}
void draw2(){
  for (int i = 0; i <= 7; i++) {
    mx.setRow(0, 0, i, face2[i]);
}}
void draw3(){
  for (int i = 0; i <= 7; i++) {
    mx.setRow(0, 0, i, face3[i]);
}}


void setup() {
  Serial.begin(9600);
  Serial.println("started");
   mx.begin(); //Hardwire startup
  mx.control(MD_MAX72XX::INTENSITY, 2); //how strong the lights are
  mx.clear();
}

void loop(){
  Serial.println(test);
  draw1();
  if (test >= 0){
    draw1();
    delay(500);
    draw2();
    delay(500);
    draw1();
    delay(500);
    draw2();
    delay(500);
  }
  else{
    draw3();
    delay(1000)
  }
  x = x+1;
  test = sin(0.1*x);

}







/*
void loop() {
  
  drawDefault();


  delay(500);

  drawMouthClosed();
  
  delay(500);
  drawMouthOpen();

}

//Draw default face
void drawDefault() {
  for (int i = 0; i <= 7; i++) {
    mx.setRow(0, 0, i, Bdefault_SmileBR[i]);
  }
  delay(delay_t);
  for (int i = 0; i <= 7; i++) {
    mx.setRow(1, 1, i, Bdefault_SmileBL[i]);
  }
  delay(delay_t);
  for (int i = 0; i <= 7; i++) {
    mx.setRow(2, 2, i, Bdefault_Blank[i]);
  }
  delay(delay_t);
  for (int i = 0; i <= 7; i++) {
    mx.setRow(3, 3, i, Bdefault_Blank[i]);
  } 
  delay(delay_t); 
  for (int i = 0; i <= 7; i++) {
    mx.setRow(4, 4, i, Bdefault_SmileTR[i]);
  }
  delay(delay_t);
  for (int i = 0; i <= 7; i++) {
    mx.setRow(5, 5, i, Bdefault_SmileTL[i]);
  }
  delay(delay_t);
  for (int i = 0; i <= 7; i++) {
    mx.setRow(6, 6, i, Bdefault_Blank[i]);
  }
  delay(delay_t);
  for (int i = 0; i <= 7; i++) {
    mx.setRow(7, 7, i, Bdefault_Blank[i]);
  }
  delay(delay_t); }

//Draw the first frame of animation. *_*
void drawMouthClosed() {
  for (int i = 0; i <= 7; i++) {
    mx.setRow(0, 0, i, mClosed_Right[i]);
  }
  delay(delay_t);
  for (int i = 0; i <= 7; i++) {
    mx.setRow(1, 1, i, mClosed_Left[i]);
  }
  delay(delay_t);
  for (int i = 0; i <= 7; i++) {
    mx.setRow(2, 2, i, Bdefault_Blank[i]);
  }
  delay(delay_t);
  for (int i = 0; i <= 7; i++) {
    mx.setRow(3, 3, i, Bdefault_Blank[i]);
  } 
  delay(delay_t); 
  for (int i = 0; i <= 7; i++) {
    mx.setRow(4, 4, i, Bdefault_SmileTR[i]);
  }
  delay(delay_t);
  for (int i = 0; i <= 7; i++) {
    mx.setRow(5, 5, i, Bdefault_SmileTL[i]);
  }
  delay(delay_t);
  for (int i = 0; i <= 7; i++) {
    mx.setRow(6, 6, i, Bdefault_Blank[i]);
  }
  delay(delay_t);
  for (int i = 0; i <= 7; i++) {
    mx.setRow(7, 7, i, Bdefault_Blank[i]);
  }
  delay(delay_t); }

//Draw second frame of animation. *O*
void drawMouthOpen() {
  for (int i = 0; i <= 7; i++) {
    mx.setRow(0, 0, i, mOpen_Right[i]);
  }
  delay(delay_t);
  for (int i = 0; i <= 7; i++) {
    mx.setRow(1, 1, i, mOpen_Left[i]);
  }
  delay(delay_t);
  for (int i = 0; i <= 7; i++) {
    mx.setRow(2, 2, i, Bdefault_Blank[i]);
  }
  delay(delay_t);
  for (int i = 0; i <= 7; i++) {
    mx.setRow(3, 3, i, Bdefault_Blank[i]);
  } 
  delay(delay_t); 
  for (int i = 0; i <= 7; i++) {
    mx.setRow(4, 4, i, Bdefault_SmileTR[i]);
  }
  delay(delay_t);
  for (int i = 0; i <= 7; i++) {
    mx.setRow(5, 5, i, Bdefault_SmileTL[i]);
  }
  delay(delay_t);
  for (int i = 0; i <= 7; i++) {
    mx.setRow(6, 6, i, Bdefault_Blank[i]);
  }
  delay(delay_t);
  for (int i = 0; i <= 7; i++) {
    mx.setRow(7, 7, i, Bdefault_Blank[i]);
  }
  delay(delay_t); } 
  */
