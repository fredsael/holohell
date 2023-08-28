import serial
import pygame
import time

# Serial configuration
arduino_port = "/dev/ttyUSB0"  # Change this to your Arduino port
baud_rate = 9600

# Initialize serial connection
connected = False
while connected != True:
    try:    
        print("Trying to listen to serial")
        ser = serial.Serial(arduino_port, baud_rate, timeout=1)
        connected = True
               
    except Exception as e:
       print("An error: " + str(e) + "has occurred")
       time.sleep(5)

# Initialize pygame mixer
pygame.mixer.init()

# Load the audio file
audio_file = "/home/pi/Desktop/Ring01.wav"
sound = pygame.mixer.Sound(audio_file)

try:
    while True:
        line = ser.readline().decode("utf-8").strip()
        if line == "Activity":
            print("Received play command from Arduino.")
            sound.play()
            while pygame.mixer.get_busy():
                time.sleep(0.1)  # Wait for audio to finish playing

except KeyboardInterrupt:
    ser.close()
