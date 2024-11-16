from tkinter import *

window = Tk()
window.title("My First GUI Program")
window.minsize(width=500, height=300)
window.config(padx=100, pady=100)

#label
my_label = Label(text = "I am a label", font = ("Arial", 24, "bold"))
my_label.config(text="New Text")
# my_label.place(x=100, y=0)
my_label.grid(column=0, row=0)

#button
# button = Button(text="Click me")
# button.pack()
def button_clicked():
    my_label.config(text=input.get())
button = Button(text="Click Me", command=button_clicked)
# button.place(x=100, y=100)
button.grid(column=2, row=0)
new_button = Button(text="Click Me", command=button_clicked)
new_button.grid(column=1, row=1)

#Entry
input = Entry(width=10)
# input.place(x=200, y=200)
input.grid(column=3, row=2)
print(input.get())




window.mainloop()
