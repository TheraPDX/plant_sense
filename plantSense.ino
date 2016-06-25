// Sensor Pins
int soilSensor = A0;

// Sensor Values
int soil;

// Flag for watering plant
// Is the soil dry?
bool dry = false;

void setup()
{
    // Cloud variables
    Particle.variable("soil", &soil, INT);

    // Pin Initialization
    pinMode(soilSensor, INPUT);
}

void loop()
{
      soil = analogRead(soilSensor);

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
