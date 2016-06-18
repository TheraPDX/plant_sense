int humidSensor = A0;
int soilSensor = A1;

float humid;
float soil;

int store[1000];

void setup()
{
    Serial.begin(9600);

    pinMode(humidSensor, INPUT);
    pinMode(soilSensor, INPUT);
}

void loop()
{
    int i = 0;

    for(i = 0; i <= 1000 ; i++)
    {
      humid = analogRead(humidSensor);
      soil = analogRead(soilSensor);

      store[i] = soil;
    }


    for(i = 0; i <= 1000; i++)
    {
      Serial.println(store[i]);
    }
    
    delay(3600000);
}
