/*
    This sketch sends a message to a TCP server

*/

#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>

ESP8266WiFiMulti WiFiMulti;


WiFiClient client;
void setup() {
  Serial.begin(115200);
  delay(10);

  // We start by connecting to a WiFi network
  WiFi.mode(WIFI_STA);
  WiFiMulti.addAP("think_13", "zzzzzzzz");

  Serial.println();
  Serial.println();
  Serial.print("Wait for WiFi... ");

  while (WiFiMulti.run() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  delay(500);

  const uint16_t port = 23;
  const char * host = "192.168.4.1"; // ip or dns



  Serial.print("connecting to ");
  Serial.println(host);

  // Use WiFiClient class to create TCP connections
  

  while (!client.connect(host, port)) {
    Serial.println("connection failed");
    Serial.println("wait 5 sec...");
    delay(5000);
    return;
  }


  
}


void loop() {
  

  // This will send the request to the server
  
  //read back one line from server
  if(client.available()){
   String line = client.readStringUntil('/');
//   char a = client.read();
   Serial.println(line);
   
  }
  if(Serial.available()){
    char a = Serial.read();
    client.println(a);
  }

//  Serial.println("closing connection");
//  client.stop();
//
//  Serial.println("wait 5 sec...");
//  delay(5000);
}

