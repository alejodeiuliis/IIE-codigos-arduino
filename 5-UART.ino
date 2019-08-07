/**
 *****************************************
 *            5-UART
 ****************************************
 * 
 *  En este ejemplo se empleará el monitor serie del IDE para visualizar comunicación entre la PC y el Arduino
 **/

// El Arduino UNO dispone de un puerto USB tipo B con 4 pines. Con dos de esos pines recibe 5V y GND. 
// Los otros dos pines se utilizan para realizar la comunicación con la PC mediante el protocolo de transmisión serie UART (Universal Asynchronous Receiver-Transmitter).
// Esta comunicación se emplea a la hora de cargar un programa en la placa, o bien se puede emplear (en tiempo de ejecución) para debugging o como una interfaz HMI del programa.

// Es importante aclarar que mientras se está empleando la comunicación Arduino-PC no se aconseja emplear los pines de comunicación:
// (si es para cargar el programa, se puede desconectar el cable USB y brindar alimentación al Arduino con el Jack de alimentación)
// Los dos pines de comunicación se denominan TX/RX (Transmisión/Recepción) y corresponde con los pines D0 y D1.
// Dichos pines están conectados al Bridge UART-USB del Arduino.
// Ambos pines disponen de LEDs soldados a la placa del Arduino por SMD. Dichos LEDs indican cuando se está realizando comunicación en uno u otro sentido.

// ¿Qué se transfiere durante la comunicación? Símbolos. Un símbolo puede ser representado con un conjunto de bits.
// Por default en la comunicación Serie se tiene un bit de inicio, 8 bits de datos y 1 bit de stop.
// A la tasa de símbolos/s se lo conoce como baudio (baud o baud rate en inglés).
// Dicha configuración de velocidad es vital para que los dos dispositivos puedan comunicarse.
// Normalmente se emplea la velocidad de 9600 baud. Velocidades muy altas pueden presentar problemas y muy bajas no resultan útiles por ser lentas.
// En el Arduino lo configuramos en el setup del código, por medio de la función Serial.begin() y entre paréntesis se coloca el baud rate.
// (Opcionalmente se pueden modificar parámetros respecto a la comunicación como cantidad de bits de datos, bit de paridad y bit de stop, pero queda fuera del alcance de esta guía).

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Variables globales:
 
int LED_0 = A3; // LED para confirmar que el programa está corriendo

const int Byte = '*'; // Caracter a mostrar en el monitor serie

const int Delay_ms = 500; // Tiempo de espera en ms

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Inicialización:

void setup() {
  pinMode(LED_0, OUTPUT); 
  digitalWrite(LED_0, HIGH);

  Serial.begin(9600); // Inicialización de puerto Serie
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Bucle infinito:

void loop() {

  if (Serial.available()) {    // mientras el puerto serie este funcionando, manda el caracter fijado en la constante "Byte"
    Serial.write(Byte);
  }
  
  digitalWrite(LED_0, !digitalRead(LED_0));   // Setea el estado del led en lo contrario a lo que estaba
  delay(Delay_ms);                       

}

// Actividades:

// 1 - Cargar el programa y abrir el monitor serie. Visualizar la salida en el monitor y ver los leds TX/RX.
// (En la PC debemos abrir en el menú del IDE > Herramientas > Monitor Serie y en el combo box marcar la velocidad correspondiente, luego presionar ENTER)
// 2 - Modificar el estado del pin 0 o 1 en el código (con un digitalWrite(1,HIGH) por ejemplo) y comprobar que sucede con la comunicación
// 3 - Probar configurar una velocidad diferente en la PC o en el Arduino y ver que se visualiza en el monitor serie

// Preguntas:

// a - ¿Qué LED se enciende en la placa del Arduino al visualizar el monitor serie? ¿TX ó RX? ¿Por qué?
// b - Para una velocidad de 9600baud, 8 bits de datos, 1 bit de start y 1 bit de stop (sin bits de paridad) ¿Cuál es la velocidad en bit/s?
