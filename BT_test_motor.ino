/*
  Capitulo 25 de Arduino desde cero en Español.
  Programa que permite encender y apagar dos LEDs mediante el modulo Bluetooth HC-05
  y una App en el telefono movil. La configuracion del modulo se realizo en el
  capitulo 24.

  Autor: bitwiseAr  

*/

#include <SoftwareSerial.h> // libreria que permite establecer pines digitales
        // para comunicacion serie
  // pin 10 como RX, pin 11 como TX

char DATO = 0;      // variable para almacenar caracter recibido
int LEDROJO = 10;    // LED rojo a pin digital numero 2
int LEDVERDE = 11;   // LED verde a pin digital numero 3

void setup(){
  Serial.begin(9600);    // comunicacion serie entre Arduino y el modulo a 38400 bps
  pinMode(LEDROJO, OUTPUT); // pin 2 como salida
  pinMode(LEDVERDE, OUTPUT);  // pin 3 como salida
}

void loop(){
if (Serial.available()){      // si hay informacion disponible desde modulo
  DATO = Serial.read();   // almacena en DATO el caracter recibido desde modulo

  if( DATO == '1' ){    // si el caracter recibido es el numero 1
  digitalWrite(LEDROJO, HIGH);  // enciende LED rojo
  digitalWrite(LEDVERDE, LOW);  // apaga LED verde
}
  if( DATO == '2' ){// si el caracter recibido es el numero 2
  digitalWrite(LEDROJO, LOW); // apaga LED rojo
  digitalWrite(LEDVERDE, HIGH); // enciende LED verde
}
  if( DATO == '3' ){// si el caracter recibido es el numero 2
  digitalWrite(LEDROJO, LOW); // apaga LED rojo
  digitalWrite(LEDVERDE, LOW); // enciende LED verde
}

}
}                                                                                                                                                     
