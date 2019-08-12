/**
 *****************************************
 *            5-UART_Arduino-Arduino
 ****************************************
 * 
 *  En este ejemplo se comunicarán 2 Arduinos con el protocolo UART, invirtiendo el estado de los LEDs remotamente.
 **/

// En este ejemplo se realizará comunicación serie entre dos Arduinos. Un Arduino estará sensando si hay algo disponible en el buffer del puerto Serie.
// Si se lee un caracter determinado, se realizará la inversión del LED_0.

// Se requieren dos Arduinos con sus respectivos Shields.
// Si no se dispone de un segundo Shield se puede armar la parte de LED_0 y del pulsador en una protoboard y realizar las conexiones de acuerdo a "shield_arduino_esquematico.pdf".

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Variables globales:

// Arduino Shield:
static const int LED_0 = A3;

static const int PULSADOR = 2;

// Variables:

const int Tiempo_Espera_ms = 500; // Tiempo de espera en ms
int input=0;

// Prototipos:
void InvertirEstadoLED(const int);
void interrupcionBoton0(void);

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Inicialización:

void setup() {
  pinMode(LED_0, OUTPUT); 
  digitalWrite(LED_0, HIGH); 

  pinMode(PULSADOR, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(PULSADOR),interrupcionBoton0,RISING);
  
  Serial.begin(9600); // Inicialización de puerto Serie
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Bucle infinito:

void loop() {

  if (Serial.available()) {    // Si hay algo, lo leo.
    input=Serial.read();   
    if (input=='x') {
      Serial.flush();
      InvertirEstadoLED(LED_0);
    } 
  }

}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Funciones:

void InvertirEstadoLED(const int LED){
    digitalWrite(LED, !digitalRead(LED));
}
            
void interrupcionBoton0(void)
{
  delayMicroseconds(Tiempo_Espera_ms);  
       
// Espero Tiempo_Espera_ms para filtrar rebote del botón

  if(digitalRead(PULSADOR)==HIGH) // si el boton sigue apretado, es porque no fue un rebote
    Serial.print('x');
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Actividades:

// 1 - Realizar la carga del programa: Primero se debe cargar el programa en ambos Arduinos. Luego alimentar a ambos Arduinos mediante el Jack de alimentación.
// 2 - Finalmente interconectar TX de un Arduino con el RX del otro (y viceversa) e interconectar ambos GND.
// 3 - Comprobar el correcto funcionamiento.

// Preguntas:

// a - ¿ Por qué Tx con Rx deben estar intercambiados ? ¿ Qué pasa si se conecta Rx-Rx y Tx-Tx ?
// b - ¿ Qué pasa si se modifica la velocidad del puerto Serie en uno de los dos Arduinos ?
// c - ¿ Por qué hay que interconectar las masas ? 
