from tkinter import *

def button_clicked():
    user_input = int(input.get())
    temp = round(user_input*1.609)
    label_3.config(text=temp)

window = Tk()
window.title("My First GUI Program")
window.minsize(width=500, height=300)
window.config(padx=100, pady=100)

input = Entry(width=10)
input.grid(column=1, row=0)
label_1 = Label(text = "Miles", font = ("Arial", 14))
label_1.grid(column=2, row=0)
label_2 = Label(text = "is equal to", font = ("Arial", 14))
label_2.grid(column=0, row=1)
label_3 = Label(text = "", font = ("Arial", 14))
label_3.grid(column=1, row=1)
label_4 = Label(text = "Km", font = ("Arial", 14))
label_4.grid(column=2, row=1)
button = Button(text="Click Me", command=button_clicked)
button.grid(column=1, row=2)
window.mainloop()
