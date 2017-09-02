#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>

const char* ssid = "makerspace";
const char* password = "makerspace";

ESP8266WebServer server(80);

const int led = 13;

void handleRoot() {
  digitalWrite(led, 1);
  server.send(200, "text/plain", "Hello. I am the Makerspace Robot.");
  digitalWrite(led, 0);
}

void handleNotFound(){
  digitalWrite(led, 1);
  String message = "Service Not Found\n\n";
  message += "URI: ";
  message += server.uri();
  message += "\nMethod: ";
  message += (server.method() == HTTP_GET)?"GET":"POST";
  message += "\nArguments: ";
  message += server.args();
  message += "\n";
  for (uint8_t i=0; i<server.args(); i++){
    message += " " + server.argName(i) + ": " + server.arg(i) + "\n";
  }
  server.send(404, "text/plain", message);
  digitalWrite(led, 0);
}

void send400(){
  server.send(400, "text/plain", "Please provide the value [-1..1]. Example: http//robot.ing.gl/set-left-wheel-velocity?value=0.65");
}

void getValue(){

}
void setup(void){
  pinMode(led, OUTPUT);
  digitalWrite(led, 0);
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  Serial.println("");

  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  if (MDNS.begin("esp8266")) {
    Serial.println("MDNS responder started");
  }

  server.on("/", handleRoot);

  server.on("/set-left-wheel-velocity", [](){
    if (server.arg("value")==""){     //Parameter not found
        return;
    }
    String valueAsString = server.arg("value");
    float value = valueAsString.toFloat();
    if(value > 1 || value < -1){
      send400();
      return;
    }
    Serial.print("set-left-wheel-velocity to ");
    Serial.println(value);
    server.send(200, "text/plain", "");
  });
  server.on("/set-right-wheel-velocity", [](){
    if (server.arg("value")== ""){     //Parameter not found
        return;
    }
    String valueAsString = server.arg("value");
    float value = valueAsString.toFloat();
    if(value > 1 || value < -1){
      send400();
      return;
    }
    Serial.print("set-right-wheel-velocity to ");
    Serial.println(value);
    server.send(200, "text/plain", "");
  });

  server.onNotFound(handleNotFound);

  server.begin();
  Serial.println("HTTP server started");
}

void loop(void){
  server.handleClient();
}
