// Library for the DHT11 sensor by Scott Piette
#include "PietteTech_DHT.h"

// System Definitions for the DHT11 Sensor
// Sensor Type
#define DHTTYPE  DHT11
// Digital Pin Sensor is connected to
#define DHTPIN   3
// The sample interval (2 seconds)
#define DHT_SAMPLE_INTERVAL   2000

// Decleration for the library
void dht_wrapper();

// Library Instantiation using System Definitions
PietteTech_DHT DHT(DHTPIN, DHTTYPE, dht_wrapper);
//------------------------------------------------------------------------------

// Sensor Pins
int soilSensor = A0;

// Sensor Values
int soil;
int tempC;
int tempF;
int humidity;

// Flag for watering plant
// Is the soil dry?
bool dry = false;

void setup()
{
    // Cloud variables
    Particle.variable("soil", &soil, INT);
    Particle.variable("tempF", &tempF, INT);
    Particle.variable("humidity", &humidity, INT);

    // Pin Initialization
    pinMode(soilSensor, INPUT);
}


// Wrapper for DHT11 Library
void dht_wrapper() {
    DHT.isrCallback();
}

void loop()
{
      // Read Soil Sensor Values
      soil = analogRead(soilSensor);

      // Read Humidity from DHT11
      humidity = DHT.readHumidity();

      // Read Temperature (in celsius) from DHT11
      tempC = DHT.readTemperature();
      // Convert from Celsius to Fahernheit
      tempF = (tempC * 1.8) + 32;


      // Logic to publish whether or not the plant
      // needs to be watered
      if (soil > 100)
      {
        if (dry == true)
        {
            Particle.publish("soilStatus", "Plant is Hydrated!");
            dry = false;
        }
        else
        {
            // Do nothing
        }
      }
      else
      {
        if (dry == false)
        {
            Particle.publish("soilStatus", "Please Water!");
            dry = true;
        }
        else
        {
            // Do nothing
        }
      }

}
