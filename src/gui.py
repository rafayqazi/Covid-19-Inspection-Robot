from tkinter import *
from PIL import Image, ImageTk

def check_temperature_instruction():
    root = Tk()
    root.wm_overrideredirect(True)
    root.geometry("600x250+450+250")  # to set windows size and opening position
    image = Image.open("images/temperaturecheck.png")
    photo = ImageTk.PhotoImage(image)
    varun_label = Label(image=photo)
    varun_label.pack()
    root.after(3000, lambda: root.destroy())
    root.mainloop()

def normal_temperature_instruction():
    root = Tk()
    root.wm_overrideredirect(True)
    root.geometry("600x250+450+250")  # to set windows size and opening position
    image = Image.open("images/NormalTemperature.png")
    photo = ImageTk.PhotoImage(image)
    varun_label = Label(image=photo)
    varun_label.pack()
    root.after(5000, lambda: root.destroy())
    root.mainloop()
