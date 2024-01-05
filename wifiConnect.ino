#include<WiFi.h>


#define LED 2
//network credentials
const char* ssid = "iAM-RnD";
const char* pass = "1234567890";

void blink(){

  digitalWrite(LED,HIGH);
  delay(500);
  digitalWrite(LED, LOW);
  delay(500);
  digitalWrite(LED,HIGH);
  delay(500);
  digitalWrite(LED, LOW);
  delay(500);
  digitalWrite(LED,HIGH);
  delay(500);
  digitalWrite(LED, LOW);
  delay(500); }

void initWiFi(){

    WiFi.mode(WIFI_AP_STA);
    WiFi.begin(ssid,pass);
    Serial.print("Connecting to WiFi ..");
    while (WiFi.status() != WL_CONNECTED) {
    Serial.print('.');
    delay(1000);
  }
  Serial.print("Connected to ");
  Serial.print(ssid);
  Serial.println(WiFi.localIP());

}

void WifiAP(){
WiFi.softAP("ESP32","abcdefgh");

}
void setup() {
  // put your setup code here, to run once:
  pinMode(LED,OUTPUT);
  Serial.begin(115200);
  blink();
  initWiFi();
  Serial.print("RRSI: ");
  Serial.println(WiFi.RSSI());
  delay(3000);
  WiFi.disconnect();
  blink();
  Serial.print("\n WiFi Disconnected");
  delay(3000);
  /*
  WiFi.reconnect();
  blink();
  Serial.print("\n WiFi reconnected");
  */


  /* Setup as Access Point*/
  Serial.print("Setting up as AP");
  digitalWrite(LED,HIGH);
  WifiAP();
}

void loop() {
  // put your main code here, to run repeatedly:

}
