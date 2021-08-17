//#include <WiFiNINA.h>
#include <SPI.h>
#include <WiFi.h>
#include <Servo.h>

//MPU6050
#include <Wire.h>
#include <MPU6050.h>

char ssid[] = "icirauqui";        // your network SSID (name)
char pass[] = "password1!";    // your network password (use for WPA, or use as key for WEP)
int status = WL_IDLE_STATUS;     // the Wifi radio's status

Servo ESC1;
Servo ESC2;
Servo ESC3;
Servo ESC4;


void setup() {
  //Initialize serial and wait for port to open:
  Serial.begin(9600);
  while (!Serial);


  //Attempt to connect to Wifi network:
  while (status != WL_CONNECTED) {
    Serial.print("Attempting to connect to network: ");
    Serial.println(ssid);
    // Connect to WPA/WPA2 network:
    status = WiFi.begin(ssid, pass);
    delay(10000);
  }
  Serial.println("You're connected to the network");
  Serial.println("----------------------------------------");
  printData();
  Serial.println("----------------------------------------");

  
  ESC1.attach(6,1000,2000);
  ESC2.attach(7,1000,2000);
  ESC3.attach(8,1000,2000);
  ESC4.attach(9,1000,2000);  
}


void loop() {
  printData();
  delay(1000);
  //ESC1.write(pwd);
  //ESC2.write(pwd);
  //ESC3.write(pwd);
  //ESC4.write(pwd);
}



void printData() {
  Serial.println("Board Information:");
  // print your board's IP address:
  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());
  long rssi = WiFi.RSSI();
  Serial.print("signal strength (RSSI):");
  Serial.println(rssi);
  byte encryption = WiFi.encryptionType();
  Serial.print("Encryption Type:");
  Serial.println(encryption, HEX);
}
