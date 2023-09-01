/*
pins:
CS = 10
CLK = 13
DIN = 11
SOUND PIN =A0
*/

// Libraries
#include <MD_Parola.h>
#include <MD_MAX72xx.h>
#include <SPI.h>

// Definitions
#define HARDWARE_TYPE MD_MAX72XX::FC16_HW //What device
#define MAX_DEVICES 8 //How many 8x8 you have
#define CS_PIN 10 // What pin CS is in the Arduino
#define  delay_t  50  // in milliseconds

// Hardware setup
MD_MAX72XX mx = MD_MAX72XX(HARDWARE_TYPE, CS_PIN, MAX_DEVICES);
MD_Parola myDisplay = MD_Parola(HARDWARE_TYPE, CS_PIN, MAX_DEVICES);
const int soundSensorPin = A0;  // Analog pin to which the sensor is connected
const int ear = 150; // threshold level, can be adjusted

// SPRITES START
// Default smile. All here are made with PixelMaker the right way up
byte Bdefault_SmileTR[8] = {0xE0,0xF0,0x1C,0x0C,0x66,0x63,0x63,0x03};  
byte Bdefault_SmileTL[8] = {0x07,0x0F,0x38,0x30,0x66,0xC6,0xC6,0xC0};  
byte Bdefault_SmileBR[8] = {0x03,0x33,0xF3,0xE6,0x0C,0x1C,0xF0,0xE0};
byte Bdefault_SmileBL[8] = {0xC0,0xCC,0xCF,0x67,0x30,0x38,0x0F,0x07};
byte Bdefault_Blank[8] = {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}; // Blank does need to be made upside down

// Default smile. Same as above, but made upside down 
byte UPdefault_SmileTR[8] = {0x07,0x0F,0x38,0x30,0x67,0xCF,0xCC,0xC0};  
byte UPdefault_SmileTL[8] = {0xC0,0xC6,0xC6,0x66,0x30,0x38,0x0F,0x07};  
byte UPdefault_SmileBR[8] = {0xE0,0xF8,0x0C,0x0C,0xE6,0xF3,0x33,0x03}; 
byte UPdefault_SmileBL[8] = {0x07,0x0F,0x38,0x30,0x67,0xCF,0xCC,0xC0}; // remake and rename

// Talk bobble
byte BobbleR[8] = {0x07,0x08,0x10,0x10,0x10,0x08,0x07,0x00};
byte BobbleL[8] = {0xE0,0x10,0x08,0x08,0x08,0x08,0xE4,0x1E};

//Mouth talking open
byte mOpen_Left[8] = {0xC3,0xC4,0xC4,0x64,0x33,0x38,0x0F,0x07};
byte mOpen_Right[8] = {0xC3,0x23,0x23,0x26,0xCC,0x1C,0xF0,0xE0};
byte mOpenUP_Left[8] = {0x07,0x0F,0x38,0x33,0x64,0xC4,0xC4,0xC3};
byte mOpenUP_Right[8] = {0xE0,0xF0,0x1C,0xCC,0x26,0x23,0x23,0xC3};

//Mouth talking closed
byte mClosed_Left[8] = {0xC0,0xC0,0xC4,0x67,0x33,0x38,0x0F,0x07};
byte mClosed_Right[8] = {0x03,0x03,0x23,0xE6,0xCC,0x1C,0xF0,0xE0};
byte mClosedUP_Left[8] = {0x07,0x0F,0x38,0x33,0x67,0xC4,0xC0,0xC0}; 
byte mClosedUP_Right[8] = {0xE0,0xF0,0x1C,0xCC,0xE6,0x23,0x03,0x03}; 

/* 8x8 test face
byte face1[8] = {0x3c, 0x42, 0x95, 0x91, 0x91, 0x95, 0x42, 0x3c};
byte face2[8] = {0x3c, 0x42, 0x85, 0xb1, 0xb1, 0x85, 0x42, 0x3c};
byte face3[8] = {0x3c, 0x42, 0x95, 0xa1, 0xa1, 0x95, 0x42, 0x3c};
*/
// SPRITES END

// for clean animations and loop switches
int x = 0;
float test = sin(x); 


void setup() {
  Serial.begin(9600);
  Serial.println("started");
   mx.begin(); //Hardwire startup
  mx.control(MD_MAX72XX::INTENSITY, 4); //how strong the lights are
  mx.clear();
}
/* 
void loop(){  // Test for single 8x8 face shift animations
  Serial.println(test);
  drawDefault();
  if (test >= 0){
    drawMouthOpen();
    delay(2000);
    drawMouthClosed();
    delay(2000);
  }
  else{
    drawDefault();
    delay(1000);
  }
  x = x+1;
  test = sin(0.1*x);
}

void loop()
{
  drawDefault();
    delay(100);
  // when characters arrive over the serial port...
  if (Serial.available()) {
    // wait a bit for the entire message to arrive
    delay(100);
    // read all the available characters
    while (Serial.available() > 0) {
      // display each character to the LCD
      Serial.write(Serial.read());
    }
    drawMouthOpen();
    delay(200);
    drawMouthClosed();
    delay(200);
    drawMouthOpen(); // repeat because need for loop later
    delay(200);
    drawMouthClosed();
    delay(200);
    drawMouthOpen();
    delay(200);
    drawMouthClosed();
    delay(200);
    drawMouthOpen();
    delay(200);
    drawMouthClosed();
    delay(200);
  }
 }
*/

void loop() {
  int sensorValue = analogRead(soundSensorPin);  // Read the analog value from the sensor
  
  // For printing sound levels
  Serial.println(sensorValue);
  // Basic face first
  drawDefault();
 // When sound becomes loud enought
  if (sensorValue > ear) {
    drawMouthOpen();
    delay(200);
    drawMouthClosed();
    delay(200);
    drawMouthOpen(); // repeat because need for loop later
    delay(200);
    drawMouthClosed();
    delay(200);
    drawMouthOpen();
    delay(200);
    drawMouthClosed();
    delay(200);
    drawMouthOpen();
    delay(200);
    drawMouthClosed();
    delay(200);
  }
  
  delay(50);  // Delay for x msecond before reading again
}



/* Test different settings
void loop() {
  drawDefault();
  delay(5000);
  drawMouthOpen();
  delay(100);
  drawMouthClosed();
  delay(100);
  drawMouthOpen();
  delay(100);
  drawMouthClosed();
  delay(100);
  drawMouthOpen();
  delay(100);
  drawMouthClosed();
  delay(100);
  drawMouthOpen();
  delay(100);
  drawMouthClosed();
  delay(100);
}
*/
// Draw functions, remember that the drawings will be mirrored when placing compared to on screen.
//Draw default face
void drawDefault() {
  for (int i = 0; i <= 7; i++) {
    mx.setRow(0, 0, i, Bdefault_SmileTR[i]);
  }
  delay(delay_t);
  for (int i = 0; i <= 7; i++) {
    mx.setRow(1, 1, i, Bdefault_SmileTL[i]);
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
    mx.setRow(4, 4, i, Bdefault_Blank[i]);
  }
  delay(delay_t);
  for (int i = 0; i <= 7; i++) {
    mx.setRow(5, 5, i, Bdefault_Blank[i]);
  }
  delay(delay_t);
  for (int i = 0; i <= 7; i++) {
    mx.setRow(6, 6, i, UPdefault_SmileBR[i]);
  }
  delay(delay_t);
  for (int i = 0; i <= 7; i++) {
    mx.setRow(7, 7, i, UPdefault_SmileBL[i]);
  }
  delay(delay_t); }

//Draw the first frame of animation. *_*
void drawMouthClosed() {
  for (int i = 0; i <= 7; i++) {
    mx.setRow(0, 0, i, Bdefault_SmileTR[i]);
  }
  delay(delay_t);
  for (int i = 0; i <= 7; i++) {
    mx.setRow(1, 1, i, Bdefault_SmileTL[i]);
  }
  delay(delay_t);
  for (int i = 0; i <= 7; i++) {
    mx.setRow(2, 2, i, BobbleL[i]);
  }
  delay(delay_t);
  for (int i = 0; i <= 7; i++) {
    mx.setRow(3, 3, i, BobbleR[i]);
  } 
  delay(delay_t); 
  for (int i = 0; i <= 7; i++) {
    mx.setRow(4, 4, i, Bdefault_Blank[i]);
  }
  delay(delay_t);
  for (int i = 0; i <= 7; i++) {
    mx.setRow(5, 5, i, Bdefault_Blank[i]);
  }
  delay(delay_t);
  for (int i = 0; i <= 7; i++) {
    mx.setRow(6, 6, i, mClosedUP_Right[i]); // closed mouth
  }
  delay(delay_t);
  for (int i = 0; i <= 7; i++) {
    mx.setRow(7, 7, i, mClosedUP_Left[i]); // shfit
  }
  delay(delay_t); }

//Draw second frame of animation. *O*
void drawMouthOpen() {
  for (int i = 0; i <= 7; i++) {
    mx.setRow(0, 0, i, Bdefault_SmileTR[i]);
  }
  delay(delay_t);
  for (int i = 0; i <= 7; i++) {
    mx.setRow(1, 1, i, Bdefault_SmileTL[i]);
  }
  delay(delay_t);
  for (int i = 0; i <= 7; i++) {
    mx.setRow(2, 2, i, BobbleL[i]);
  }
  delay(delay_t);
  for (int i = 0; i <= 7; i++) {
    mx.setRow(3, 3, i, BobbleR[i]);
  } 
  delay(delay_t); 
  for (int i = 0; i <= 7; i++) {
    mx.setRow(4, 4, i, Bdefault_Blank[i]);
  }
  delay(delay_t);
  for (int i = 0; i <= 7; i++) {
    mx.setRow(5, 5, i, Bdefault_Blank[i]);
  }
  delay(delay_t);
  for (int i = 0; i <= 7; i++) {
    mx.setRow(6, 6, i, mOpenUP_Right[i]); // closed mouth
  }
  delay(delay_t);
  for (int i = 0; i <= 7; i++) {
    mx.setRow(7, 7, i, mOpenUP_Left[i]); // shfit
  }
  delay(delay_t); }
  
