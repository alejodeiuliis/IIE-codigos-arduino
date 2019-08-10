/**
 *****************************************
 *            6-DAC_R2R
 ****************************************
 * 
 *  En este ejemplo se generará un valor constante "analógico" (6 bits de resolución) a la salida del circuito R2R
 **/

// DAC significa digital to analog converter. La función como su nombre lo indica es la de convertir la señal HIGH/LOW disponible en varios pines digitales en un valor analógico a la salida.
// Esto se logra combinando "inteligentemente" las salidas, para ello se arma el circuito R2R. 

// En este ejemplo no utilizaremos el Shield. Necesitaremos una tira de 6 cables con pines macho/macho (y dos cables más por lo menos).
// Armar en una protoboard el circuito R2R que se muestra en "tpg-etapasalida-86.pdf" página 3/7 disponible en el campus de la materia.
// R=2.2kOhm. OUT0 se conectará a D2 y OUT5 a D7. Emplear un valor de capacitancia del orden de los uF (electrolítico). Respetar la polaridad.

// En este código se creará la función printR2R. Se pueden crear funciones como se vió en el ejemplo "1-BlinkLED-v2" que se escribe la función completa antes de la inicialización.
// O bien se puede escribir en la declaración de variables el prototipo de la función: Esto es el nombre de la función, con los tipos de dato de los argumentos y el tipo de dato de salida
// (esto es porque estaremos utilizando la función en el código, y el compilador necesita saber que espera recibir dicha función y que devolverá).
// Finalmente luego del loop podemos escribir la función, de manera tal que cuando la función sea llamada pueda ser ejecutada.

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Variables globales

int i,j; // Variables para contadores
const int cantidadResistores=6; // DAC de 6 bits
const int r[cantidadResistores]={2,3,4,5,6,7}; // Pines D2 a D7 de Arduino UNO
int valor; // Variable para almacenar el valor de salida

void printR2R (int); // Prototipo de la función que genera el valor de salida

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Inicialización:

void setup() {
  for(i=0;i<cantidadResistores;i++){
    pinMode(r[i],OUTPUT);  // Se define como salidas a los pines D2 hasta D7
  }
  valor=17; // Valor de salida, entre 0 y 63 (6 bits)
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Bucle infinito:

void loop() {
  printR2R(valor); // Se invoca sucesivamente a una función para generar el valor de salida
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Función R2R:

void printR2R (int numero){
  for(i=0;i<cantidadResistores;i++){ // Se itera sobre cada pin de salida
    if(numero&(1<<i)){
      digitalWrite(r[i],HIGH);  // Si la representación en 6 bits del número tiene un 1 en la
                                // posición i, entonces se enciende el pin i-ésimo de salida
    } else {
      digitalWrite(r[i],LOW);  // Si la representación en 6 bits del número tiene un 0 en la
                                // posición i, entonces se apaga el pin i-ésimo de salida
    }
  }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Actividades:

// 1 - Armar el R2R en una protoboard. Conectar un multímetro en modo DC entre la salida reconstruida y GND y cargar el programa.
// 2 - Colocar distintos valores a la variable valor y visualizar la lectura del instrumento

// Preguntas

// a - ¿Qué tensión se visualiza cuando se escribe valor=0? ¿Y cuando valor=63? ¿Llega a los 5V? Si la respuesta es no, ¿Por qué?
// b - ¿Por qué la variable valor solo puede tomar valores entre 0 y 63? (Pista: Escribir el número 63 en binario)
// c - ¿Cuál es la resolución en mV de este conversor DAC?
