import time
import win32com.client

###Shell Connection
shell = win32com.client.Dispatch("WScript.Shell")
shell.Run("notepad")
time.sleep(1)
shell.AppActivate("Notepad")

###Message
msg="""Hello World 


elena@****.com
12:50 PM : 10 minutes ago
to me

To create is to recombine said the molecular biologist Francois Jacob. 

From The Rational Optimist
by Matt Ridley
"""  

###For Loop for sending characters in sequence with a delay
delay=0.01
for i in msg:
    time.sleep(delay)
    shell.SendKeys(i, 0)