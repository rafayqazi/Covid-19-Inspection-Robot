import serial
import re
from src.speech import speak
from src.gui import check_temperature_instruction, normal_temperature_instruction

try:
    arduino = serial.Serial(port='COM4', baudrate=9600, timeout=.1)
except serial.SerialException:
    print("Warning: Arduino not connected on COM4. Temperature check will fail.")
    arduino = None

def temperature_check():
    check_temperature_instruction()
    if arduino is None:
        speak("Arduino not connected.")
        return

    while True:
        try:
            ser = arduino.readline().decode()
            numbers = re.findall(r'\d+', ser)  # find numbers from strings
            if numbers:
                current_temp = int(numbers[1])
                print(f"Temperature (F) = {current_temp}")
                
                if current_temp <= 105:
                    speak("Thank you! Your Body Temperature Is Normal, please sanitize yourself.")
                    normal_temperature_instruction()
                    break

                else:
                    speak("Your Body temperature is not reliable!")
                    break
        except Exception as e:
            print(f"Error reading from Arduino: {e}")
            break