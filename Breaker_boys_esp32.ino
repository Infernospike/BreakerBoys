/*********
  Rui Santos
  Complete project details at https://randomnerdtutorials.com
*********/

// Load libraries
#include "BluetoothSerial.h"

// Check if Bluetooth configs are enabled
#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

// Bluetooth Serial object
BluetoothSerial SerialBT;

// GPIO where LED is connected to
const int OUTPUT1 =  4;

// GPIO where the DS18B20 is connected to
const int OUTPUT2 = 5;          

// Handle received and sent messages
String message = "";
char incomingChar;

void setup() {
  pinMode(OUTPUT1, OUTPUT);
  pinMode(OUTPUT2, OUTPUT);
  digitalWrite(OUTPUT1, LOW);
  digitalWrite(OUTPUT2, LOW);
  delay(5000);
  digitalWrite(OUTPUT1, HIGH);
  digitalWrite(OUTPUT2, HIGH);
  
  Serial.begin(115200);
  // Bluetooth device name
  SerialBT.begin("ESP32test");
  Serial.println("The device started, now you can pair it with bluetooth!");
}

void loop() {
 
  // Read received messages (LED control command)
  if (SerialBT.available()){
    char incomingChar = SerialBT.read();
    if (incomingChar != '\n'){
      message += String(incomingChar);
    }
    else{
      message = "";
    }
    Serial.write(incomingChar);  
  }
  // Check received message and control output accordingly
  if (message == "OFF" || message == "off" || message == "Off"){
    digitalWrite(OUTPUT1, HIGH);
    digitalWrite(OUTPUT2, LOW);
    Serial.println("\n Turning Off");
    
  }
  else if (message == "ON" || message == "on" || message == "On"){
    digitalWrite(OUTPUT1, LOW);
    digitalWrite(OUTPUT2, HIGH);
    Serial.println(" \n Turning On");
    
  }
  else{
    digitalWrite(OUTPUT1, LOW);
    digitalWrite(OUTPUT2, LOW);
  }
   
  delay(20);
}
