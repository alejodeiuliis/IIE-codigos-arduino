/**
 *****************************************
 *            7-DAC_R2R_ADC_LDR
 ****************************************
 * 
 *  En este ejemplo se enviará el valor del LDR (6 bits de resolución) a la salida del circuito R2R
 **/

// Emplear el circuito R2R del ejemplo anterior. Implementar el circuito conectado al pin A0 provisto en "shield_arduino_esquematico.pdf".
// Dicho circuito consiste en un LDR a +5V y conectada a una R de 1k (conectada a GND). Del punto medio conectar a A0.
// En el bucle infinito se llamará a la función analogRead() y luego a la función printR2R().
// Notar que el ADC tiene 10 bits de resolución (0 a 1023) y el DAC tiene 6 bits (0 a 63), por lo que se deberá "bajar la resolución" del dato obtenido por el ADC.
// Para realizar dicha conversión se emplea el operador ">>" Dicho operador de manejo de bits recibe dos operandos. 
// Sea x>>C, se escribe el número x en binario y luego se realiza un corrimiento de C bits hacia la derecha (eliminando así los bits menos significativos).

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Variables globales:

static const int LDR = A0;

int i,j; // Variables para contadores
const int cantidadResistores=6; // DAC de 6 bits
const int r[cantidadResistores]={2,3,4,5,6,7}; // Pines D2 a D7 de Arduino UNO
int valor; // Variable para almacenar el valor de salida

void printR2R (int); // Prototipo de la función que genera el valor de salida

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Inicialización:

void setup() {
  for(i=0;i<cantidadResistores;i++){
    pinMode(r[i],OUTPUT);  // Se define como salidas a los pines D2 hasta D7
  }
  valor=31; // Valor inicial de salida, entre 0 y 63 (6 bits)
  
  pinMode(A0,INPUT); // Se configura el ADC

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Bucle infinito:

void loop() {
  valor=analogRead(LDR); // Se lee el dato del ADC
  valor=valor>>4;       // Se convierte el dato de 10 bit a 6 bit
  printR2R(valor);      // Se invoca a una función para generar el valor de salida
}

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

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Actividades:

// 1 - Realizar el armado del circuito y probarlo. Para ello conectar un multímetro entre la salida de la señal reconstruida y GND para medir el nivel de tensión a la salida. 
// 2 - Iluminar y oscurecer el LDR para comprobar el correcto funcionamiento.

// Preguntas:

// a - ¿Es este código "bloqueante"? ¿Se puede leer el ADC y enviar el valor automáticamente al R2R sin bloquear el loop principal?
