import requests
from datetime import datetime
import smtplib
import time

MY_LAT = 51.507351
MY_LNG = -0.127758

parameters = {
    "lat": MY_LAT,
    "lng": MY_LNG,
    "formatted": 0,
}


iss_response = requests.get(url="http://api.open-notify.org/iss-now.json")
iss_response.raise_for_status()
iss_longitude = float(iss_response.json()["iss_position"]["longitude"])
iss_latitude = float(iss_response.json()["iss_position"]["latitude"])

ss_response = requests.get(url="https://api.sunrise-sunset.org/json", params = parameters)
ss_response.raise_for_status()
sunrise = int(ss_response.json()["results"]["sunrise"].split("T")[1].split(":")[0])
sunset = int(ss_response.json()["results"]["sunset"].split("T")[1].split(":")[0])

time_now = datetime.now().hour

if (MY_LAT-5 <= iss_latitude <= MY_LAT+5) and (MY_LNG-5 <= iss_longitude <= MY_LNG+5):
    if time_now <= sunrise or time_now >= sunset:
        print("Look Up")

while True:
    time.sleep(60)
    #SEND EMAIL (prev lesson)
