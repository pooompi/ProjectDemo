#include <spark-dallas-temperature.h>
#include <OneWire.h>

OneWire oneWire(D3);

// Pass oneWire reference to Temperature Sensor.
DallasTemperature dallas(&oneWire);

void setup()
{
    Serial.begin(9600); 
    Serial.println("Temperature Sensor!");
    // setup the library
    dallas.begin();
}

void loop()
{
// Request temperature from sensor
  dallas.requestTemperatures();
// Store temperature as a float
  float celsius = dallas.getTempCByIndex(0);
// Declare string
  String celsiusd;
// Convert to string
  celsiusd = String(celsius);
// Publish temperature
  Serial.printlnf("Temperature = %1.3f *C", celsius);
  Particle.publish("celsiusd", celsiusd, PRIVATE);
  delay(5000);

}
