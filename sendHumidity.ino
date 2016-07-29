//nodeMCU v1.0 (black) with Arduino IDE
//stream temperature data DS18B20 with 1wire on ESP8266 ESP12-E (nodeMCU v1.0)
//shin-ajaran.blogspot.com
//nodemcu pinout https://github.com/esp8266/Arduino/issues/584
#include <ESP8266WiFi.h>

/**
 * Définition du timer
 * permet d'éviter l'emploi de delay()
 * qui provoque souvent un blocage
 * du Arduino au bout d'un certain laps de temps
 */
unsigned long previousMillis = 0;
const long interval = 300000;

const char* MY_SSID = "my SSID"; 
const char* MY_PWD = "PASSWD";
int sent = 0;

int PinAnalogiqueHumidite=0;       //Broche Analogique de mesure d'humidité
int hsol;  //Humidite su sol, mesure analogique

const char* server = "my server.org";
String apiKey ="your API key here";

WiFiClient client;
   
void setup() {
  Serial.begin(115200);
  pinMode(PinAnalogiqueHumidite, INPUT);       //pin A0 en entrée analogique
  connectWifi();
}

void loop() {
  
  

  // nous conservons la valeur du nombre de ms
  unsigned long currentMillis = millis();

  // nous comparons avec la lecture précédente
  if(currentMillis - previousMillis >= interval) {

    hsol = analogRead(PinAnalogiqueHumidite); // Lit la tension analogique

    Serial.println(hsol); // afficher la mesure
   
    // save the last time you blinked the LED 
    previousMillis = currentMillis;
    sendHumidity(hsol);
 }
 
}

void connectWifi()
{
  Serial.print("Connecting to "+*MY_SSID);
  WiFi.begin(MY_SSID, MY_PWD);
  while (WiFi.status() != WL_CONNECTED) {
  delay(1000);
  Serial.print(".");
  }
  
  Serial.println("");
  Serial.println("Connected");
  Serial.println("");  
}//end connect

void sendHumidity(int value)
{  

  
   if (client.connect(server, 80)) { 
    Serial.println("WiFi Client connected ");
    String request = "GET " ;
    request = request + "/input/post.json?node=3&json={humidity:";
    request = request + value;
    request = request + "}&apikey=
    request = request + apikey
    request = request + "HTTP/1.1";

   

    client.println(tt);
    client.print("Host: ");
    client.println(*server);
    client.println("Connection: close");
    client.println();
   }
  
}
