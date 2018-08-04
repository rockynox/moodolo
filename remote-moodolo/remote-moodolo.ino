#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

// -------- WIFI -----------

const char *ouiFi = "Pierre_qui_roule";
const char *motSecret = "n amasse pas mousse";

// -------- PUSH_BUTTON -----------

int pushButtonGreen = 16; //D0
int pushButtonBlueGreen = 5; //D1
int pushButtonBlueRed = 4; //D2
int pushButtonRed = 0; //D3

// -------- LED -----------

int ledPin = 2; //D4
bool ledState = LOW;

// -------- SERVER -----------

WiFiServer server(80);

String status;

void setup() {
  Serial.begin(115200);
  delay(10);

  pinMode(ledPin, OUTPUT);
  pinMode(pushButtonGreen, INPUT);

  digitalWrite(ledPin, LOW);

  // Connect to WiFi network
  Serial.print("Connecting to ");
  Serial.println(ouiFi);
  WiFi.begin(ouiFi, motSecret);

  while (WiFi.status() != WL_CONNECTED) {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(300);
    digitalWrite(LED_BUILTIN, LOW);
    delay(300);
    Serial.print(".");

  }
  Serial.println("WiFi connected");
  digitalWrite(LED_BUILTIN, HIGH);

  // Start the server
  server.begin();
  Serial.println("Server started");

  // Print the IP address
  Serial.print("Use this URL to connect: ");
  Serial.print("http://");
  Serial.print(WiFi.localIP());
  Serial.println("/");

  delay(2000);

}

void loop() {

  digitalWrite(ledPin, ledState);

  int buttonState = digitalRead(pushButtonGreen);
  //Serial.println(buttonState);

  if (buttonState == 1) {
    ledState = !ledState;
    HTTPClient http;
    http.begin("http://172.20.10.3:1880/mood");
    //http.addHeader("Content-Type", "application/json");
    //http.POST("moodValue=10");
    int httpCode = http.POST("12");

    // httpCode will be negative on error
    if (httpCode > 0) {
      // HTTP header has been send and Server response header has been handled
      Serial.printf("[HTTP] GET... code: %d\n", httpCode);

      // file found at server
      if (httpCode == HTTP_CODE_OK) {
        String payload = http.getString();
        Serial.println(payload);
      }
    } else {
      Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
    }

    http.end();
  }






}

