#include <ESP8266WiFi.h>

const char* ssid = "";
const char* pass = "";

WiFiServer server(80);

void setup() {
  Serial.begin(9600);
  delay(10);

  int i = 0;
  for(i; i<8; i++) {
    pinMode(i, OUTPUT);
  }

  WiFi.begin(ssid, pass);
  while(WiFi.status() != WL_CONNECTED) {
    delay(250);
  }
  server.begin();
}

void loop() {
  WiFiClient client = server.available();
  if(!client) {
    return;
  }
  while(!client.available()){
    delay(10);
  }

  String req = client.readStringUntil('\r');
  Serial.println(req);
  client.flush();

  if(req.indexOf("/pin0on") != -1) {
    digitalWrite(0, HIGH);
  } else if(req.indexOf("/pin1on") != -1) {
    digitalWrite(1, HIGH);
  } else if(req.indexOf("/pin2on") != -1) {
    digitalWrite(2, HIGH);
  } else if(req.indexOf("/pin3on") != -1) {
    digitalWrite(3, HIGH);
  } else if(req.indexOf("/pin4on") != -1) {
    digitalWrite(4, HIGH);
  } else if(req.indexOf("/pin5on") != -1) {
    digitalWrite(5, HIGH);
  } else if(req.indexOf("/pin6on") != -1) {
    digitalWrite(6, HIGH);
  } else if(req.indexOf("/pin7on") != -1) {
    digitalWrite(7, HIGH);
  } else if(req.indexOf("/pin0off") != -1) {
    digitalWrite(0, LOW);
  } else if(req.indexOf("/pin1off") != -1) {
    digitalWrite(1, LOW);
  } else if(req.indexOf("/pin2off") != -1) {
    digitalWrite(2, LOW);
  } else if(req.indexOf("/pin3off") != -1) {
    digitalWrite(3, LOW);
  } else if(req.indexOf("/pin4off") != -1) {
    digitalWrite(4, LOW);
  } else if(req.indexOf("/pin5off") != -1) {
    digitalWrite(5, LOW);
  } else if(req.indexOf("/pin6off") != -1) {
    digitalWrite(6, LOW);
  } else if(req.indexOf("/pin7off") != -1) {
    digitalWrite(7, LOW);
  } else {
    client.stop();
    return;
  }
  client.flush();
}
