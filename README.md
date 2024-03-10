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
 delay(1000); //espera de 1 segundo
 Serial.println("ON"); //puerto serie sacar ON
 
 digitalWrite(led, LOW);    // turn the LED off
 delay(1000); //espera de 1 segundo
 Serial.println("OFF"); //puerto serie sacar OFF
}
```
4. Eliminar los delay modificar el pin de salida a uno cualquiera de los que estan disponibles i medir con
el osciloscopio cual es la màxima frecuencia de apagado encendido que permite el microcontrolador.
Medir la frecuencia en estos cuatro casos:
- Con el envio por el puerto série del mensaje i utilizando las funciones de Arduino

**PROGRAMA (loop):**
  ``` cpp
  void loop() {
     digitalWrite(led, HIGH);   // turn the LED on
     Serial.println("ON"); //puerto serie sacar ON
     digitalWrite(led, LOW);    // turn the LED off
     Serial.println("OFF"); //puerto serie sacar OFF
    }

  ```
**FRECUENCIA aprox 50 us (1/50 MHz)**
- Con el envio por el puerto série y accedirendo directamente a los registros

**PROGRAMA (loop):**
  ``` cpp
  uint32_t *gpio_out = (uint32_t *)GPIO_OUT_REG;
  
  void loop() {
     Serial.println("ON");
     *gpio_out |= (1 << led);
     Serial.println("OFF");      
     *gpio_out ^= (1 << led);
    }

  ```
**FRECUENCIA aprox 50 us (1/50 MHz)**
- Sin el envio por el puerto série del mensaje i utilizando las funciones de Arduino

**PROGRAMA (loop):**
  ``` cpp
  void loop() {
     digitalWrite(led, HIGH);   // turn the LED on
     digitalWrite(led, LOW);    // turn the LED off
    }

  ```
**FRECUENCIA aprox 0,6 us (1/0,6 MHz)**
- Sin el envio por el puerto série y accedirendo directamente a los registros

**PROGRAMA (loop):**
  ``` cpp
  uint32_t *gpio_out = (uint32_t *)GPIO_OUT_REG;

  void loop() {
     *gpio_out |= (1 << led);
     *gpio_out ^= (1 << led);
    }

  ```
**FRECUENCIA aprox 0,6 us (1/0,6 MHz)**


CONCLUSIÓN:

    -En el primer y segundo experimento el tiempo de apagado y encendido es mucho mayor que en los dos siguentes, lógicamente es debido a que el MP tiene que enviar los mensajes de ON y OFF por el puerto série, hecho que ralentza la ejecucuión de la orden de apagado o encendido.
    
    -El tercer y cuarto experimento son muy interesantes ya que el MP solo debe ejecutar las ordenes de encendido y apagado del led. Son interesantes ya que de esta forma podemos calcular el tiempo que tarda el MP en ejecutar dichas ordenes. Evidentenmente el MP tarda distinto tiempo en ejecutar distintas ordenes; no es lo mismo ejecutar una orden para encender un led que una que envie un mensaje por el puerto série. Así que con estos experimentos simplemente vemos el tiempo las ordenes de encendido y apagado del led.
    
    -En último lugar, no hemos sido capaces de ver diferencias de tiempo entre enviar la orden de encendido y apagado mediante funciones Arduino o accediendo directamente a los registros. Seguramente la haya pero no hemos sido capaces de detectarlas con el osciloscopio.

```markdown
```mermaid
graph TD;
    inicio --> paso1;
    paso1 --> paso2;
    paso2 --> fin;
