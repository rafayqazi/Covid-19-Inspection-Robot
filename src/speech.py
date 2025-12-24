import pyttsx3
import time
# ---- voice engine setup---
engine = pyttsx3.init('sapi5')
voices= engine.getProperty('voices') 
engine.setProperty('voice', voices[0].id)
engine.setProperty('rate',140)

def speak(audio):
    engine.say(audio) 
    engine.runAndWait() 
# ---- voice engine setup end-----