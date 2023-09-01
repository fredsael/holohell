const int soundSensorPin = A0;  // Analog pin to which the sensor is connected

void setup() {
  Serial.begin(9600);  // Initialize serial communication for debugging
}

void loop() {
  int sensorValue = analogRead(soundSensorPin);  // Read the analog value from the sensor
  
  Serial.println(sensorValue);


  if (sensorValue > 55) {
    Serial.println("Activity");
    delay(2000);
    Serial.println("Activity 2");
    delay(1000);
    Serial.println("Activity 3");
    delay(1000);
    Serial.println("Activity 4");
    delay(1000);
    Serial.println("Activity 5");
    delay(1000);
    Serial.println(sensorValue);
  }
  
  delay(50);  // Delay for 1 second before reading again
}
