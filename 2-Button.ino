/**
 *************************************************
 *                    2-Button
 *************************************************
 * Uso del pulsador con if()
 **/

// Variables globales:

// Arduino Shield

static const int LED_0 = A3;
static const int LED_1 = A2;
static const int LED_2 = 7; 
static const int LED_3 = 4;
static const int PULSADOR = 2;

// Variables auxiliares

const int Tiempo_Espera_us = 1000; // Tiempo en us para filtrar el rebote del botón
bool Estado_Anterior = HIGH; // Estado inicial del pulsador (lo declaramos HIGH pues declararemos el PIN como INPUT_PULLUP, leer más adelante)

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Inicializamos la placa

void setup() {
  pinMode(LED_0, OUTPUT); 
  digitalWrite(LED_0, HIGH);   
  pinMode(LED_1, OUTPUT);
  digitalWrite(LED_1, HIGH);
  pinMode(LED_2, OUTPUT);
  digitalWrite(LED_2, HIGH);
  pinMode(LED_3, OUTPUT);
  digitalWrite(LED_3, HIGH);
  
  pinMode(PULSADOR, INPUT_PULLUP); // Inicializa el pin del boton como entrada y activo el resistor de pullup.
  
// Existen dos maneras de definir un pin como entrada, una es INPUT y la otra es INPUT_PULLUP. La primera se encuentra en reposo en estado LOW y al variar la entrada (que tiene que estar correctamente cableada) a estado alto (+5V) cambia de estado a HIGH.
// La segunda manera es INPUT_PULLUP. La placa de arduino tiene unos resistores internos que son posibles de habilitar por medio del uso de esta declaración.
// Al declarar un pin como INPUT_PULLUP se conecta el pin en cuestión por medio de un resistor de entre 20kOhm a 50kOhm (depende la placa). Esto permite que el pin se modifique al recibir un estado LOW (GND) en dicho pin.
} 
   
// El microcontrolador estará continuamente sensando el pin "PULSADOR", al detectar un flanco ascendente se ejecutará la función de interrupción
// Dicha función de interrupción cambia el estado de LED_0. Luego de finalizar la función de interrupción continuará ejecutándose el loop infinito 
// (y las variables locales dentro de la función interrupción perderán el alcance)

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// bucle infinito

void loop(){

// La función if() permite la realización de una ramificación del flujo del programa en función del valor de verdad la sentencia entre paréntesis.
// Por lo general se realizan comparaciones dentro de dicha sentencia. En este caso se pregunta por una igualdad (se emplea el caracter '==' en lugar de el '=' que corresponde a una asignación).
// En este caso si la función digitalRead(PULSADOR) devuelve LOW (lo cual siginifica que alguien presionó el botón, entonces LOW==LOW devuelve TRUE lo que hace que se ejecute el código dentro de los corchetes.
// Si la función digitalRead(PULSADOR) devuelve HIGH (esto es, nadie apretó el botón), se ejecuta else{ }.

  if (digitalRead(PULSADOR)==LOW){
      delayMicroseconds(Tiempo_Espera_us);  
      if (digitalRead(PULSADOR)==LOW) Estado_Anterior = LOW;  // Este es un if() anidado, es decir que solo se hace esta pregunta luego de que el if() anterior sea TRUE. Si el boton sigue apretado, es porque no fue un rebote y en ese caso llevamos a LOW la variable auxiliar.
  }
  else{ // El botón está en la condición de reposo
    if (Estado_Anterior==LOW){ // Si la variable auxiliar fue establecida en LOW por el if() anterior significa que alguien presionó un botón y lo soltó.
      Estado_Anterior = HIGH;
      digitalWrite(LED_0, !digitalRead(LED_0)); // cambia estado del pin
    } 
  }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Actividades:

// 1 - Cargar el programa. Presionar el botón y ver que pasa. 
// 2 - ¿Responde bien el pulsador? Si no es el caso, modificar el valor de la variable Tiempo_Espera_us

// Preguntas:

// a - ¿Por qué es mejor emplear el else{} a que realizar un nuevo if() con la condición contraria (digitalRead(PULSADOR)==HIGH)?
