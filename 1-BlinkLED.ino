/**
 **************************************
 *            1-BlinkLED
 **************************************
 * Probar la placa encendiendo un led.
 * Hacemos parpadear un led.
 **/

// En este ejemplo emplearemos haremos titilar a un LED mediante un delay configurable.

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Variables globales: 

// LEDs del Shield:
// Agregamos los modificadores "const" y "static" a las variables. 
// "const" permite que las variables no sean modificadas en tiempo de ejecución y "static" que no pierdan su valor debido a una llamada a función (no sería este el caso).

static const int LED_0 = A3;
static const int LED_1 = A2;
static const int LED_2 = 7; 
static const int LED_3 = 4;

static const int DELAY = 1000; // En milisegundos.

// Inicialización:

void setup() {
  pinMode(LED_0, OUTPUT); 
  pinMode(LED_1, OUTPUT);
  pinMode(LED_2, OUTPUT);
  pinMode(LED_3, OUTPUT);
  digitalWrite(LED_0, HIGH); // apagamos el Led 0
  digitalWrite(LED_1, HIGH); // apagamos el Led 1
  digitalWrite(LED_2, HIGH); // apagamos el Led 2
}    

// Bucle infinito:

void loop() {
  digitalWrite(LED_3, LOW); // encendemos el Led 1
  delay(DELAY);   			// espera de tiempo definido
  digitalWrite(LED_3, HIGH); // apagamos el Led 1
  delay(DELAY);  			 // espera de tiempo definido
}

// Actividades:
// 1 - Cargar el programa y observar que es lo que pasa. 
// 2 - Probar cambiar el DELAY por otro y hacer papadear otro LED. 
// Preguntas:
// a - ¿Qué LEDs se encienden? ¿A qué pines corresponden del Arduino (ver el archivo "shield_arduino_esquematico.jpg").
// b - ¿Cuál es el inconveniente de usar esta función "delay" para hacer parpadear un LED? 
// c - ¿Es posible emplear esta función para hacer parpadear dos o más LEDs a frecuencias independientes?
