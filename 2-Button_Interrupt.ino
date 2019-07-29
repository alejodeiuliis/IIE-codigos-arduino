/**
 *************************************************
 *                    2-Button_Interrupt
 *************************************************
 * Uso del pulsador con interrupción
 **/

static const int LED_0 = A3;
static const int LED_1 = A2;
static const int LED_2 = 7; 
static const int LED_3 = 4;
static const int PULSADOR = 2;

// definicion de la función interrupciónBoton()
void interrupcionBoton(void)
{
  delayMicroseconds(5000);       // Espero 5 ms para filtrar el rebote del boton 
                                 // delay() no funciona dentro de una rutina de servicio de interrupcion, hay que usar delayMicroseconds()
                                 // Admite hasta 16383 como argumento. Referencia en https://www.arduino.cc/en/Reference/DelayMicroseconds
  
  if(digitalRead(PULSADOR)==HIGH) // si el boton sigue apretado, es porque no fue un rebote
    digitalWrite(LED_0, !digitalRead(LED_0)); // cambia estado del pin
}


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

// bucle infinito
void loop() {
}
