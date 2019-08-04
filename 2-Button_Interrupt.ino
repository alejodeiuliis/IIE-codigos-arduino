/**
 *************************************************
 *                    2-Button_Interrupt
 *************************************************
 * Uso del pulsador con interrupción
 **/

// Arduino Shield

static const int LED_0 = A3;
static const int LED_1 = A2;
static const int LED_2 = 7; 
static const int LED_3 = 4;
static const int PULSADOR = 2;

// definicion de la función interrupciónBoton()

const int Tiempo_Espera_ms = 1000; // Tiempo en ms para filtrar el rebote del botón

void interrupcionBoton(void)
{
  delayMicroseconds(Tiempo_Espera_ms);  
       
// Espero Tiempo_Espera_ms para filtrar rebote del botón
// delay() no funciona dentro de una rutina de servicio de interrupcion, hay que usar delayMicroseconds()
// Admite hasta 16383 como argumento. Referencia en https://www.arduino.cc/en/Reference/DelayMicroseconds
  
  if(digitalRead(PULSADOR)==HIGH) // si el boton sigue apretado, es porque no fue un rebote
    digitalWrite(LED_0, !digitalRead(LED_0)); // cambia estado del pin
}

// Se denomina función de interrupción porque dicha función interrumpe (valga la redundancia) el flujo normal del programa. 

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
  
  pinMode(PULSADOR, INPUT_PULLUP); // Inicializa el pin del boton como entrada
  attachInterrupt(digitalPinToInterrupt(PULSADOR),interrupcionBoton,RISING); // Referencia en https://www.arduino.cc/en/Reference/AttachInterrupt
} 
   
// El microcontrolador estará continuamente sensando el pin "PULSADOR", al detectar un flanco ascendente se ejecutará la función de interrupción
// Dicha función de interrupción cambia el estado de LED_0. Luego de finalizar la función de interrupción continuará ejecutándose el loop infinito 
// (y las variables locales dentro de la función interrupción perderán el alcance)

// bucle infinito
void loop() {
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Actividades:

// 1 - Cargar el programa. Presionar el botón y ver que pasa. 
// 2 - ¿Responde bien el pulsador? Si no es el caso, modificar el valor de la variable Tiempo_Espera_ms

// Preguntas:

// a - ¿Cuál es la ventaja de hacer una función de interrupción para detectar si se presiona el pulsador frente a hacer un if(digitalRead(PULSADOR)) en el loop del programa?
// b - Qué significa la frase "las variables locales dentro de la función interrupción perderán el alcance?"
// c - ¿Se puede establecer más de una función de interrupción? Si este fuera el caso ¿Qué pasaría si se "triggerea" una función de interrupción mientras se está ejecutando otra función de interrupción?
