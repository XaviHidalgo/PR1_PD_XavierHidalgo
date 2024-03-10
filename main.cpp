#include <Arduino.h>

int led = 23; //pin de led como salida

void setup() {               
 pinMode(led, OUTPUT); 
 Serial.begin(115200);  
}

void loop() {
 digitalWrite(led, HIGH);   // turn the LED on
 ets_delay_us(1000);
 Serial.println("ON"); //puerto serie sacar ON
 
 digitalWrite(led, LOW);    // turn the LED off
 ets_delay_us(1000);
 Serial.println("OFF"); //puerto serie sacar OFF
}
