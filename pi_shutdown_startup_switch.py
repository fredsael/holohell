import RPi.GPIO as GPIO
import os
import time

# Set GPIO mode to BCM
GPIO.setmode(GPIO.BCM)

# Set up GPIO pin for the switch
switch_pin = 17
GPIO.setup(switch_pin, GPIO.IN, pull_up_down=GPIO.PUD_UP)

# Initial state of the switch
previous_state = GPIO.input(switch_pin)

while True:
    current_state = GPIO.input(switch_pin)
    
    # Check for a change in the switch state
    if current_state != previous_state:
        if current_state == GPIO.LOW:
            # Switch was turned OFF
            print("Switch turned OFF. Shutting down...")
            os.system("sudo shutdown -h now")
        else:
            # Switch was turned ON
            print("Switch turned ON. Powering on...")
            os.system("sudo poweron-command")  # Replace with your actual power-on command
        
    previous_state = current_state
    time.sleep(0.1)  # Polling interval
