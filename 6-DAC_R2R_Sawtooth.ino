/**
 *****************************************
 *            6-DAC_R2R_Sawtooth
 ****************************************
 * 
 *  En este ejemplo se generará una señal dientes de sierra en el R2R de 6 bits.
 **/

// La función dientes de sierra nos permite hacer un correcto debugging del circuito R2R.

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Variables globales

int i,j; // Variables para contadores
const int cantidadResistores=6; // DAC de 6 bits
const int r[cantidadResistores]={2,3,4,5,6,7}; // Pines D2 a D7 de Arduino UNO
int valor=0; // Variable para almacenar el valor de salida

int delay_ms,period_s = 1; // Periodo aproximado en segundos

void printR2R (int); // Prototipo de la función que genera el valor de salida

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Inicialización:

void setup() {
  for(i=0;i<cantidadResistores;i++){
    pinMode(r[i],OUTPUT);  // Se define como salidas a los pines D2 hasta D7
  }
  delay_ms= 1000*period_s/64; // Se calcula el retardo entre valores 
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Bucle infinito:

void loop() {
  for(valor=0;valor<64;valor++){
    delay(delay_ms);
    printR2R(valor); // Se invoca sucesivamente a una función para generar el valor de salida
  }
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
// 2 - Colocar un osciloscopio en lugar de un multímetro y comprobar que la pendiente no tenga ruido.
// 3 - Cambiar el periodo de la función y volver a medir.

// Preguntas:

// a - ¿Hay en alguno de los 64 saltos alguna diferencia? ¿Es alguno más grande (o pequeño) que otro?
