/**
 * Author: Phillip Abell
 * Date: 5/29/2019
 * 
 * Upload this sketch to an ESP32 to test its functionality. 
 * The wifi capabilities will be tested and each IO pin is tested individually.
 * 
 * Pins are only tested once WiFi is connected
 * 
 * Use with ESP32 Unit Testing Board.
 */

#include <Preferences.h>
#include <WiFi.h>
#include <SimplePacketComs.h>
#include <Esp32SimplePacketComs.h>
#include <wifi/WifiManager.h>
WifiManager manager;
int pins[] = {23,22,21,19,18,5,17,16,4,0,2,15,32,33,25,26,27,14,12,13};

void setup() {
	Preferences preferences;
	preferences.begin("wifi", false);
	preferences.end();
	manager.setup();
}

void loop() {
	// read the serial port for new passwords and maintain connections
	manager.loop();
	if (manager.getState() == Connected) {
    for(int i = 0; i<20; i++){
      pinMode(pins[i],OUTPUT);
      digitalWrite(pins[i],LOW);
      Serial.println(pins[i]);
      delay(200);
    }
	  for(int i = 0; i<20; i++){
       Serial.print("looping...");
       Serial.println(pins[i]);
       delay(250);
       digitalWrite(pins[i],HIGH);
       if(i!=0){
         digitalWrite(pins[i-1],LOW);
       }
     }
     delay(250);
     digitalWrite(13,LOW);
     Serial.print("Wifi Functional: ");
     if(manager.getState() == Connected)
       Serial.println("TRUE");
     Serial.println("----TEST COMPLETE----");
     while(true){}
    }
	}
