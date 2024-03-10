# PR1_PD_XavierHidalgo

## PRACTICA 1: BLINK
1. Generar el programa y subir el codigo al github de cada uno
2. Modificar el programa para que incluya el envio de datos (ON y OFF) al puerto serie. Añadir la
iunicialización del puerto serie y el envio cada vez que cambia el estado del led
- Iniciar pin de led como salida
- Iniciar el terminal serie
- bucle infinito
    - encender led
    - sacar por puerto serie mensaje ON
    - espera de 1000 milisegundos
    - apagar led
    - sacar por puesto serie mensaje OFF
    - espera de 1000 milisegundos
``` cpp
#include <Arduino.h>

int led = 23; //pin de led como salida

void setup() {               
 pinMode(led, OUTPUT); 
 Serial.begin(115200);  
}

void loop() {
 digitalWrite(led, HIGH);   // turn the LED on
 ets_delay_us(500);
 Serial.println("ON"); //puerto serie sacar ON
 
 digitalWrite(led, LOW);    // turn the LED off
 ets_delay_us(500);
 Serial.println("OFF"); //puerto serie sacar OFF
}
```
