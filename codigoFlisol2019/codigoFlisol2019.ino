#include <DHT.h>   // Se deben agregar 2 librerias DHT sensor library by Adafruit y Adafriut Unified Sensor by Adafruit
#include <DHT_U.h>
#include <Servo.h>

const int SENSOR= 2;
const int PIN_TEMP = 5;
const int PIN_HUM = 6;
int temperatura;
int humedad;
int anguloT;
int anguloH;

DHT dht(SENSOR, DHT11);

Servo servoT;
Servo servoH;


void setup() {
  
  Serial.begin(9600);
  dht.begin();

  servoT.attach(PIN_TEMP);
  servoH.attach(PIN_HUM);
 }

void loop() {
 
  temperatura = dht.readTemperature();
  humedad = dht.readHumidity();

  anguloT = map(temperatura, 0, 80, 180, 0);
  anguloH = map(humedad, 0, 100, 180, 0);

 servoT.write(anguloT);
 servoH.write(anguloH);

 
  Serial.print("Temp: ");
  Serial.print(temperatura);
  Serial.print(" H: ");
  Serial.println(humedad);

  delay(2000);
  
 }
