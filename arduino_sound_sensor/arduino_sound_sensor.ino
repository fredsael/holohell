const int soundSensorPin = A0;  // Analog pin to which the sensor is connected

void setup() {
  Serial.begin(9600);  // Initialize serial communication for debugging
}

void loop() {
  int sensorValue = analogRead(soundSensorPin);  // Read the analog value from the sensor
  
  if (sensorValue > 55) {
    Serial.println("Activity");
    Serial.println(sensorValue);
  }
  
  delay(20);  // Delay for 1 second before reading again
}
