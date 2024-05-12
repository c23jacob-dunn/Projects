import webbrowser
import time
import win32com.client

### Creating the Shell Connection for Sending Keys
shell = win32com.client.Dispatch("WScript.Shell")

tweet = """Hello World @World #Coding #Python"""

### Opening Twitter on Default Browser
webbrowser.open("https://twitter.com")
time.sleep(7)

### New Tweet Window
shell.SendKeys("n", 0)
time.sleep(1)

### Typing the new tweet
shell.SendKeys(tweet, 0)
time.sleep(1)

### Sending the new tweet
shell.SendKeys("^{ENTER}", 0)
time.sleep(1)