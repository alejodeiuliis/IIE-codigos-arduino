/**
 *****************************************
 *            4-PWM
 ****************************************
 * 
 *  En este ejemplo realizaremos PWM sobre la salida D3 del Arduino, generando así un tren de pulsos de 5V a 490Hz con un "Duty Cycle" fijo y parametrizable.
 **/
 
// PWM significa Pulse Width Modulation o modulación de ancho de pulsos en Español.
// Esta técnica consiste en controlar el tiempo que está en alto (y tiempo que esté en bajo) un tren de pulsos. 
// 
// Normalmente se dispone de una fuente de tensión continua a la se le aplica PWM (a una cierta frecuencia), obteniendo así un valor medio distinto (y controlable).
// Esto se usa principalmente para modificar el valor de tensión eficaz sobre una determinada carga, o bien para realizar comunicaciones entre dispositivos.
// 
// Al cociente del tiempo en alto del tren de pulsos período entre el período de la señal se lo conoce como "Duty Cycle" (ciclo de trabajo).
// Para realizar el PWM en el código se emplea la función AnalogWrite(x,DC)
// Dicha función recibe como primer argumento el pin donde se realizará PWM y como segundo argumento el Duty Cycle. 
// "Duty Cycle" solo puede ser de tipo "int" y tomar un valor entre 0 (siempre en bajo) y 255 (siempre en alto).
// 
// En el Arduino UNO disponemos de ciertos pines que tienen la capacidad de emplear esta técnica. 
// Dichos pines están marcados en la placa con el caracter "~". Si miramos el Arduino UNO R3 veremos que son los seis pines: D3, D5, D6, D9, D10 y D11.
// El Arduino UNO solo tiene la capacidad de realizar PWM a 490Hz sobre D3, D9, D10 y D11 y a 980Hz sobre D5 y D6.
// (D5 y D6 últimos tienen un inconveniente con Duty Cycles pequeños, más información en: https://www.arduino.cc/reference/en/language/functions/analog-io/analogwrite/)
//
// En este ejemplo configuraremos el pin ~3 con un ancho de pulso configurable. 

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Variables globales:


static const int LED_0 = A3;

static const int PWM = 3;
int anchoPulso = 220;

static const int DelayParpadeo_ms = 100;  // hacemos parpadear LED_0 para asegurarnos que el programa esté corriendo

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Inicialización:

void setup() {
  pinMode(LED_0, OUTPUT); 
  digitalWrite(LED_0, HIGH);
  pinMode(PWM, OUTPUT);
  analogWrite(PWM,anchoPulso); // Se establece así el PWM sobre el pin 3
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Bucle infinito:

void loop() {  
  digitalWrite(LED_0, !digitalRead(LED_0));  
  delay(DelayParpadeo_ms);                                
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Actividades: 

// 1 - Medir el PWM generado en el pin 3 (4to pin del Shield) con un osciloscopio. Emplear otro ancho de pulso y verificar como varía la señal.
// 2 - Medir con un multímetro el valor medio de dicha señal. Emplear otro ancho de pulso y verificar su variación.
// 3 - Sacar el jumper sobre el pin D4 (correspondiente a LED_3 en códigos de ejemplo anteriores) y conectar la salida PWM a dicho pin. 
// 4 - Verificar que al cambiar el valor de DelayParpadeo_ms este no afecta al PWM sobre el pin 3.

// Preguntas:

// a - ¿Qué pasa al realizar lo dicho en el punto 3? ¿Por que varía la intensidad del LED inversamente a medida que aumentamos el valor de anchoPulso?
// b - ¿Resulta bloqueante la señal PWM creada en este programa o corre independientemente del bucle infinito?
