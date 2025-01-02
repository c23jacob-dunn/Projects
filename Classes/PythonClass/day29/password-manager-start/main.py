from tkinter import *
from tkinter import messagebox
import random
import pyperclip

letters = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z']
numbers = ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9']
symbols = ['!', '#', '$', '%', '&', '(', ')', '*', '+']

FONT_NAME = "Courier"

# ---------------------------- PASSWORD GENERATOR ------------------------------- #
def generate_password():
    entry_password.delete(0, END)
    password_letters = [random.choice(letters) for _ in range(random.randint(8, 10))]
    password_symbols = [random.choice(symbols) for _ in range(random.randint(2, 4))]
    password_numbers = [random.choice(numbers) for _ in range(random.randint(2, 4))]
    password_list = password_letters + password_symbols +password_numbers
    random.shuffle(password_list)
    gen_password ="".join(password_list)
    entry_password.insert(0, gen_password)
    pyperclip.copy(gen_password)

# ---------------------------- SAVE PASSWORD ------------------------------- #
def save_info():
    website = entry_website.get()
    username = entry_username.get()
    password = entry_password.get()

    if website == "" or password == "":
        messagebox.showinfo(title="Error", message="Please don't leave any fields empty!")
    else:
        is_ok = messagebox.askokcancel(title=website, message=f"These are the details entered:\n"
                                                      f"Username: {username}\nPassword: {password}\n"
                                                      f"Is it okay to save?")

        if is_ok:
            with open("passwords.txt", "a") as file:
                file.write(f"{website} | {username} | {password}\n")
                entry_website.delete(0, END)
                entry_password.delete(0, END)

# ---------------------------- UI SETUP ------------------------------- #
window = Tk()
window.title("Password Manager")
window.config(padx=50, pady=50)

canvas = Canvas(width=200, height=200)
logo_img = PhotoImage(file="logo.png")
canvas.create_image(100, 100, image=logo_img)
canvas.grid(column=1, row=0)

label_website = Label(text = "Website:", font = (FONT_NAME, 14))
label_website.grid(column=0, row=1)

label_username = Label(text = "Email/Username:", font = (FONT_NAME, 14))
label_username.grid(column=0, row=2)

label_password = Label(text = "Password:", font = (FONT_NAME, 14))
label_password.grid(column=0, row=3)

entry_website = Entry(width=40)
entry_website.grid(column=1, row=1, columnspan=2)
entry_website.focus()

entry_username = Entry(width=40)
entry_username.insert(0, "jdunn1101@gmail.com")
entry_username.grid(column=1, row=2, columnspan=2)

entry_password = Entry(width=25)
entry_password.grid(column=1, row=3)

button_generate_password = Button(text="Generate Password", command=generate_password, width=15)
button_generate_password.grid(column=2, row=3)

button_add = Button(text="Add", width=36, command=save_info)
button_add.grid(column=1, row=4, columnspan=2)


window.mainloop()
