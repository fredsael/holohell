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

 
#define HARDWARE_TYPE MD_MAX72XX::FC16_HW
//#define HARDWARE_TYPE MD_MAX72XX::GENERIC_HW
 
#define MAX_DEVICES 8
#define CS_PIN 10
 
MD_Parola myDisplay = MD_Parola(HARDWARE_TYPE, CS_PIN, MAX_DEVICES);

// Define custom characters
const uint8_t Smile[] = {8, 60, 66, 149, 145, 145, 149, 66, 60 };// Smile 8x8
//default smile
const uint8_t default_SmileTR[] = {8, 224, 240, 28, 12, 6, 115, 115, 3}; //default smile top right
const uint8_t default_SmileTL[] = {8, 3, 115, 115, 6, 12, 28, 240, 224}; //default smile top left
const uint8_t default_SmileBR[] = {8, 7, 15, 56, 51, 103, 206, 204, 204}; //default smile Bottom right
const uint8_t default_SmileBL[] = {8, 204, 204, 206, 103, 51, 56, 15, 7}; //default smile Bottom left
//Talk mouth closed. The top half of the animation remains the same 
const uint8_t TMC_SmileBR[] = {8, 7, 15, 56, 48, 102, 198, 198, 198, };
const uint8_t TMC_SmileBL[] = {8, 198, 198, 198, 102, 48, 56, 15, 7};
//Talk mouth open
const uint8_t TMO_SmileBR[] = {8, 7, 15, 56, 48, 96, 198, 207, 207,};
const uint8_t TMO_SmileBL[] = {8, 207, 207, 198, 96, 48, 56, 15, 7,};
// Speech bubble
const uint8_t SB_LEFT[] = {8, 0, 78, 127, 123, 49, 17, 17, 17,};
const uint8_t SB_RIGHT[] = {8, 17, 17, 17, 27, 31, 14, 0, 0, };

// Create structures
typedef struct
{
  uint8_t spacing;  // character spacing
  const char *msg;  // message to display
} msgDef_t;

//Create Animation and default frame
msgDef_t IdleFace[] = 
{
  {0, "!#        $%"}
};

msgDef_t Animation[] = // Each line is a "frame" of animation
 {
  {0, "!#+-&/"},
  {0, "!#+-=?"},
};

#define MAX_STRINGS  (sizeof(Animation)/sizeof(Animation[0]))

// General variables

int x = 0;
const int soundSensorPin = A0;  // Analog pin to which the sensor is connected
bool SoundActivity = false;


void setup() {
  Serial.begin(9600);
  myDisplay.begin();

  //Add characters to be used in animation
  // Default idle smile
  myDisplay.addChar('!', default_SmileTR);
  myDisplay.addChar('#', default_SmileTL);
  myDisplay.addChar('$', default_SmileBR);
  myDisplay.addChar('%', default_SmileBL);

  //Talk Anim mouths
  myDisplay.addChar('&', TMC_SmileBR);
  myDisplay.addChar('/', TMC_SmileBL);
  myDisplay.addChar('=', TMO_SmileBR);
  myDisplay.addChar('?', TMO_SmileBL);
  
  //Text bubble
  myDisplay.addChar('+', SB_LEFT);
  myDisplay.addChar('-', SB_RIGHT);
  
  myDisplay.setIntensity(4);

  
  if (SoundActivity == true) {
    myDisplay.setCharSpacing(Animation[0].spacing);
    myDisplay.displayText(Animation[0].msg, PA_LEFT, 200, 200, PA_PRINT);
  }
  else{
    myDisplay.setCharSpacing(IdleFace[0].spacing);
    myDisplay.displayText(IdleFace[0].msg, PA_LEFT, 200, 200, PA_PRINT);
  };
  //myDisplay.displayText(Animation[0].msg, PA_LEFT, 200, 200, PA_PRINT);
};

void loop() {
  static uint8_t	n = 1;
  int sensorValue = analogRead(soundSensorPin);
  int i = 0;
  

Serial.println("write the thing");
while(Serial.available() == 0) {
}
String boop = Serial.readString();
Serial.println(boop);

  ///Serial.println("Activity");
  //Serial.println(sensorValue);
  //if (sensorValue > 100) {
  String r = "r";
  if (boop ==r){
    //Serial.println("Activity");
    //Serial.println(sensorValue);
    SoundActivity = true;
    //delay(3000);
  }
  else{
    SoundActivity = false;
  }
  Serial.print(SoundActivity);
    if (myDisplay.displayAnimate()) {
    if (SoundActivity == true){
      for (i = 0; i <=8; i++){
        myDisplay.setTextBuffer(Animation[n].msg);
        myDisplay.setCharSpacing(Animation[n].spacing);
        Serial.println(i);
        Serial.println("Animation Forloop");
        
        
      }
    }
    else {
      myDisplay.setTextBuffer(IdleFace[n].msg);
      myDisplay.setCharSpacing(IdleFace[n].spacing);

    }; 
    myDisplay.displayReset();
    n = (n + 1) % MAX_STRINGS;
  
  };
}
    