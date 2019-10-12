/**
 **************************************
 *            1-BlinkLED
 **************************************
 * 
 * En este ejemplo haremos titilar a un LED mediante un delay configurable y otro LED que cambia de estado cuando parpadeó el primero.
 **/

// Variables globales:    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

static const int LED_0 = A3;
static const int LED_1 = A2;
static const int LED_2 = 7; 
static const int LED_3 = 4;

static int DELAY = 1000; // En milisegundos.

// Inicialización:   //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void setup() {
  pinMode(LED_0, OUTPUT); 
  pinMode(LED_1, OUTPUT);
  pinMode(LED_2, OUTPUT);
  pinMode(LED_3, OUTPUT);
  digitalWrite(LED_0, HIGH); 
  digitalWrite(LED_1, HIGH); 
  digitalWrite(LED_2, HIGH); 
}    

// Bucle infinito:   //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void loop() {

// En esta parte del loop hacemos titilar el LED_3. Un tiempo DELAY va a estar encendido y un tiempo DELAY va a estar apagado.

  digitalWrite(LED_3, LOW); // encendemos el Led 1
  delay(DELAY);   			// espera de tiempo definido
  digitalWrite(LED_3, HIGH); // apagamos el Led 1
  delay(DELAY);  			 // espera de tiempo definido

// En esta parte del loop, realizamos una inversión del estado del LED_2 de una manera compacta. Notar que se llaman a dos funciones de una manera anidada.

  digitalWrite(LED_2, !digitalRead(LED_2)); 
  
  // El "truco" para leer como se leen las sentencias más complicadas está en conocer el orden de precedencia de los operadores y entender como se llaman las funciones.
  // Para recordarlo, se ve de adentro hacia afuera, como desde el centro de una cebolla!
  // Más precisamente, primero se ejecuta la función digitalRead(). Dicha función lee el estado del pin LED_2 y devuelve HIGH o LOW.
  // Luego se ejecuta la inversión mediante el operador "!". Todo esto será el segundo argumento de nuestro digitalWrite que ya vimos anteriormente. 
  // Por lo cual se va a escribir en el pin LED_2 lo contrario al estado en el que ya se encontraba.
  
}

// Actividades:   /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// 1 - Cargar el programa y observar que es lo que pasa. 
// 2 - Probar cambiar el DELAY por otro y hacer papadear otros LEDs. 

// Preguntas:

// a - ¿Qué LEDs se encienden? ¿A qué pines corresponden del Arduino? (Pista: ver el archivo "shield_arduino_esquematico.jpg")
// b - ¿Cómo se puede hacer para cambiar el "Duty Cycle" de la señal en LED_3?
// c - ¿Es posible emplear esta función (delay) para hacer parpadear dos o más LEDs a frecuencias independientes?
// d - ¿Qué diferencia hay en la declaración de variables globales respecto al ejemplo anterior? ¿Qué acción tienen sobre las variables los prefijos const y static?
