/**
 *****************************************
 *            3-LDR_ADC
 ****************************************
 * 
 * Prueba del ADC midiendo el LDR del Shield y mostrar el valor con los 4 LEDs.
 **/

// Arduino Shield

static const int LDR = A0;
static const int LED_0 = A3;
static const int LED_1 = A2;
static const int LED_2 = 7; 
static const int LED_3 = 4;

// En LDR_valor guardaremos el valor actual del LDR, y en LDR_max el valor máximo que puede tomar
// como el Arduino Uno tiene 10bits de resolución, el valor máximo que puede tomar LDR_max=(2^10)-1=1023
// Más información en: https://www.arduino.cc/reference/en/language/functions/analog-io/analogread/

int LDR_valor=0;
static const int LDR_max=1023;

void setup() {

  // Inicializo los pines de los leds como salida.
  pinMode(LED_0, OUTPUT); 
  digitalWrite(LED_0, HIGH);
  pinMode(LED_1, OUTPUT);
  digitalWrite(LED_1, HIGH);
  pinMode(LED_2, OUTPUT);
  digitalWrite(LED_2, HIGH);
  pinMode(LED_3, OUTPUT);
  digitalWrite(LED_3, HIGH);

  // Inicializo el LDR como entrada
  pinMode(LDR, INPUT);
}

void loop() {
  LDR_valor = analogRead(LDR);  // Guarda en la variable "LDR_valor" lo sensado por el sensor de luz, digitalizado a traves del adc 

  if (LDR_valor > LDR_max/5) digitalWrite(LED_0,LOW); else digitalWrite(LED_0,HIGH);    // si el valor sensado es mayor a un quinto de la escala, enciende el primer led, caso contrario lo apaga
  if (LDR_valor > LDR_max/5*2) digitalWrite(LED_1,LOW); else digitalWrite(LED_1,HIGH);  // si el valor sensado es mayor a dos quintos de la escala, enciende el segundo led, caso contrario lo apaga
  if (LDR_valor > LDR_max/5*3) digitalWrite(LED_2,LOW); else digitalWrite(LED_2,HIGH);  // si el valor sensado es mayor a tres quintos de la escala, enciende el tercer led, caso contrario lo apaga
  if (LDR_valor > LDR_max/5*4) digitalWrite(LED_3,LOW); else digitalWrite(LED_3,HIGH);  // si el valor sensado es mayor a cuatro quintos de la escala, enciende el cuarto led, caso contrario lo apaga
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Actividades:

// 1 - Cargar el código en la placa con el Shield. Intentar hacer encender los 4 LEDs con una fuente de luz sobre el LDR.

// Preguntas:

// a - ¿Qué valor máximo puede devolver la función analogRead? ¿A qué valor de tensión equivale?
