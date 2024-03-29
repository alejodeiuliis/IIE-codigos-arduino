/**
 **************************************
 *            1-BlinkLED-v2
 **************************************
 * 
 * En este ejemplo haremos titilar a un LED mediante un delay configurable y otro LED que cambia de estado cuando parpadeó el primero (mediante una función).
 **/

// Variables globales: /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Arduino Shield: 
static const int LED_0 = A3;
static const int LED_1 = A2;
static const int LED_2 = 7; 
static const int LED_3 = 4;

static int DELAY = 1000; // En milisegundos.

// Definición de la función InvertirEstadoLED:

// En esta sección del código aparte de definir variables globales, podemos crear funciones. 
// Las funciones sirven para agrupar código y poder escribir código de una manera más limpia.
// En este caso la función es muy pequeña (una sola línea de código), pero resulta más intuitivo para el que lea el código más adelante. Veamos:

void InvertirEstadoLED(const int LED){
    digitalWrite(LED, !digitalRead(LED));
}

// "void" significa "vacío" y significa que la función no devuelve ningún valor. 
// Las funciones tienen dos maneras de devolver valores: Por función y por argumentos. 
// Cuando es por función significa que la función misma devuelve un "int", un "bool", etc. Normalmente se usa este número para realizar códigos de errores o funciones dentro de otras funciones.
// Para devolver por argumentos es necesario estudiar punteros. Algo que queda fuera del alcance de esta guía y del curso.
// "InvertirEstadoLED" es el nombre que elegimos para la función. Nos resulta simple y claro.
// Entre paréntesis se encuentra el tipo de dato que espera recibir la función y "LED" es una variable interna que solo tiene utilidad dentro de la función, delimitada entre "{".

// Inicialización:   ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void setup() {
  pinMode(LED_0, OUTPUT); 
  pinMode(LED_1, OUTPUT);
  pinMode(LED_2, OUTPUT);
  pinMode(LED_3, OUTPUT);
  digitalWrite(LED_0, HIGH); 
  digitalWrite(LED_1, HIGH); 
  digitalWrite(LED_2, HIGH); 
}    

// Bucle infinito:  ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void loop() {
  InvertirEstadoLED(LED_2);  // Llamada a la función: En este momento del programa se invoca a la función antes escrita. Se pasa como argumento la variable LED_2. 
  delay(DELAY);         // Luego de ser ejecutada la función el loop continua con la siguiente sentencia. En este caso se invoca a la función delay() que aguarda un tiempo de espera definido.
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Actividades:

// 1 - Cargar el programa y ver que sucede. 
// 2 - Probar invertir el estado de otro LED.

// Preguntas:

// 1 - Cómo modificaría usted el código (realizando la menor cantidad de modificaciones) para invertir los tres LED's en el loop?
