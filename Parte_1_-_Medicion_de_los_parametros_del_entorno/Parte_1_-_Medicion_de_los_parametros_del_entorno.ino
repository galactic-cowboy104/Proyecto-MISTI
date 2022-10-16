// MEDICIÓN DE LOS PARÁMETROS DEL ENTORNO: TEMPERATURA, HUMEDAD RELATIVA, PRESIÓN BAROMÉTRICA Y ALTITUD

#include <Adafruit_Sensor.h>
#include <Adafruit_BMP280.h>
#include <DHT.h>

Adafruit_BMP280 bmp; /* Declaramos nuestro objeto "bmp" de 
                        la libreria Adafruit_BMP280. */
                        
DHT dht(D5, DHT22); /* Declaramos nuestro objeto "dht" de 
                        la libreria DHT. */

float temp, hum, pref, pres, alt;

void leer_Temp_Hum() { /* Función para leer y mostrar en el monitor Serial
                          los valores de temperatura y humedad. */

  temp = dht.readTemperature(); // Método para leer temperatura integrada ya en la librería.
  hum = dht.readHumidity(); // Método para leer humedad relativa integrada ya en la librería.

  Serial.println(" Temperatura: " + String(temp) + "[°C]");
  Serial.println(" Humedad: " + String(hum) + "%");

}

void leer_Pres_Alt() { /* Función para leer y mostrar en el monitor Serial
                               los valores de presión barométrica y altitud. */

  pres = bmp.readPressure(); // Método para leer presión barométrica integrada ya en la librería.
  alt = bmp.readAltitude(pref); // Método para leer altitud acorde a una presión de referencia integrada ya en la la librería.

  Serial.println(" Presión: " + String(pres) + "[Pa]");
  Serial.println(" Altitud: " + String(alt) + "[m]\n");
  
}

void setup() {

  Serial.begin(115200); // Configurando puerto Serial a 115200 baudios.
  
   if(!bmp.begin()) { // Estructura if para checar el estado del sensor BMP280.
    
    Serial.println(" ¡Sensor BMP280 no encontrado!");
    while(1);
    
  }

  dht.begin(); // Inicializando el sensor DHT22.

  pref = bmp.readPressure() / 100; // Obteniendo la presión de referencia.

}

void loop() {

  leer_Temp_Hum(); /* Mandando a llamar la función de lectura y muestreo
                      de los parámetros de presión y altitud.*/

  leer_Pres_Alt(); /* Mandando a llamar la función de lectura y muestreo
                      de los parámetros de presión y altitud.*/

  delay(2000);

}
