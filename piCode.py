# Import the Requests Library for API
import requests
# Import the SMTP library for email
import smtplib


# Function to get soil status
def getSoilStatus():
    api = requests.get('https://api.particle.io/v1/devices/440030000347343337373738/dry?access_token=78c471be2e3f8f65e0e9c662d7e35d5b2a31448a')
    soilText = api.text[53:54]

    soil = int(soilText)
    print(soil)
    return soil

# Function to get soil sensor value
def getSoil():
    api = requests.get('https://api.particle.io/v1/devices/440030000347343337373738/soil?access_token=78c471be2e3f8f65e0e9c662d7e35d5b2a31448a')
    soilText = api.text[54:58]

    soil = int(soilText)
    print(soilText)
    return soil

# Function to get temp sensor value
def getTemp():
    api = requests.get('https://api.particle.io/v1/devices/440030000347343337373738/tempF?access_token=78c471be2e3f8f65e0e9c662d7e35d5b2a31448a')
    tempText = api.text[54:57]

    temp = int(tempText)
    print(temp)
    return temp

# Function to get humidity sensor value
def getHumidity():
    api = requests.get('https://api.particle.io/v1/devices/440030000347343337373738/humidity?access_token=78c471be2e3f8f65e0e9c662d7e35d5b2a31448a')
    HumidityText = api.text[57:60]

    humidity = int(HumidityText)
    print(humidity)
    return humidity 

# Function to send email when plant needs to be watered
def sendEmail():
    server = smtplib.SMTP('smtp.gmail.com', 587)
    server.starttls()
    server.login("awkwardpenguin317@gmail.com", "Cougar1890!")

    msg = "Water Your Plant!"
    server.sendmail("awkwardpenguin317@gmail.com", "irfanw.hossain@gmail.com", msg)
    server.quit()
    return

# MAIN FUNCTION
def main():

    # Flag for infinite loop  
    flag = True

    # Infinite Loop
    while flag == True:

        # Get soil status
        dry = getSoilStatus()
        # Get soil sensor value
        soil = getSoil()
        int

        # This logic is used to pervent multiple emails during a single event
        if (soil > 2000):         # If the soil is wet, and the status before was dry, change the status to wet
            if (dry == 1):
                dry = 0
            else:
                flag = True       # Dummy 
        else:
            if (dry == 0):        # If the soil is dry, and the status before was wet, change te status to dry
                sendEmail()       # Send email to water plant
                dry = 1
            else:
                flag = True       # Dummy
                
    
            
                
