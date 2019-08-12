/**
 *****************************************
 *            5-UART_PC-Arduino
 ****************************************
 * 
 *  En este ejemplo se creará una interfaz HMI por puerto serie, comunicando el Arduino con la PC. Se usarán los LEDs, el botón y el LDR del Shield.
 **/

// Este programa es un ensamble de los temas vistos anteriormente. 
// Se emplearán todos los perisféricos del Shield en una posible implementación de una máquina de estados.

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Variables globales:

// Arduino Shield: 
static const int LED_0 = A3;
static const int LED_1 = A2;
static const int LED_2 = 7; 
static const int LED_3 = 4; 
static const int LDR = A0;
static const int PULSADOR = 2;

// Mensajes:
const char Mensaje_inicio[50]="Bienvenido a la interfaz HMI de ejemplo :)\n";
const char Menu_inicio[40]="¿Qué acción desea realizar?\n";
const char Menu_1[40]="1-Des/Activar LEDs\n";
const char Menu_2[40]="2-Configurar Botón\n"; 
const char Menu_3[40]="3-Leer el LDR\n"; 
const char Invalid_msg[50]="Error. Ingrese una opción válida.\n"; 
const char Menu_11[40]="Elija LED a invertir estado:\n";
const char Menu_110[20]="0 - LED_0\n";
const char Menu_111[20]="1 - LED_1\n";
const char Menu_112[20]="2 - LED_2\n";
const char Menu_113[20]="3 - LED_3\n";
const char Menu_114[30]="S - Salir al menú anterior\n";
const char Menu_22[40]="Elija Función del botón:\n";
const char Menu_220[20]="0 - Invertir LED_0\n";
const char Menu_221[20]="1 - Invertir LED_1\n";
const char Menu_222[20]="2 - Invertir LED_2\n";
const char Menu_223[20]="3 - Invertir LED_3\n";
const char Menu_224[20]="4 - No hacer nada\n";
const char Menu_225[30]="S - Salir al menú anterior\n";

// Variables:
int input,init_msg=0;
const int Tiempo_Espera_ms = 500; // Tiempo de espera en ms
int LDR_valor=0;

// Prototipos:
void InvertirEstadoLED(const int);
void interrupcionBoton0(void);
void interrupcionBoton1(void);
void interrupcionBoton2(void);
void interrupcionBoton3(void);

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Inicialización:

void setup() {
  pinMode(LED_0, OUTPUT); 
  pinMode(LED_1, OUTPUT);
  pinMode(LED_2, OUTPUT);
  pinMode(LED_3, OUTPUT);
  digitalWrite(LED_0, HIGH); 
  digitalWrite(LED_1, HIGH); 
  digitalWrite(LED_2, HIGH); 
  digitalWrite(LED_3, HIGH); 
  pinMode(LDR, INPUT);
  pinMode(PULSADOR, INPUT_PULLUP);
  
  Serial.begin(9600); // Inicialización de puerto Serie
  
  delay(1000);
  Serial.write(Mensaje_inicio);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Bucle infinito:

void loop() {
  if (init_msg==0){
    Serial.write(Menu_inicio);
    Serial.write(Menu_1);
    Serial.write(Menu_2);
    Serial.write(Menu_3);

    init_msg=1;
    delay(1000);
  }
  
  if (Serial.available()) {    // Si hay algo, lo leo.
    input=Serial.read();
    
      switch (input) {
        
    case '1': // 1-Des/Activar LEDs
    
          Serial.write(Menu_1);
          init_msg=0;
          Serial.write(Menu_11);
          Serial.write(Menu_110);
          Serial.write(Menu_111);
          Serial.write(Menu_112);
          Serial.write(Menu_113);
          Serial.write(Menu_114);

       while(input!='S'){
         
          while (Serial.available()==0); // Espero
              input=Serial.read();

              switch(input){
                case '0': InvertirEstadoLED(LED_0);break;
                case '1': InvertirEstadoLED(LED_1);break;
                case '2': InvertirEstadoLED(LED_2);break;
                case '3': InvertirEstadoLED(LED_3);break;
                case 'S': continue;
                case '\n':Serial.flush();break;
                default: Serial.write(Invalid_msg);break;
              } 
            }
            
      break;
      
    case '2': // 2-Configurar Botón 
          Serial.write(Menu_2);
          init_msg=0;
          Serial.write(Menu_22);
          Serial.write(Menu_220);
          Serial.write(Menu_221);
          Serial.write(Menu_222);
          Serial.write(Menu_223);
          Serial.write(Menu_224);
          Serial.write(Menu_225); 

          while(input!='S'){
         
          while (Serial.available()==0); // Espero
              input=Serial.read();

              switch(input){
                case '0': attachInterrupt(digitalPinToInterrupt(PULSADOR),interrupcionBoton0,RISING);break;
                case '1': attachInterrupt(digitalPinToInterrupt(PULSADOR),interrupcionBoton1,RISING);break;
                case '2': attachInterrupt(digitalPinToInterrupt(PULSADOR),interrupcionBoton2,RISING);break;
                case '3': attachInterrupt(digitalPinToInterrupt(PULSADOR),interrupcionBoton3,RISING);break;
                case '4': detachInterrupt(digitalPinToInterrupt(PULSADOR));break;
                case 'S': continue;
                case '\n':Serial.flush();break;
                default: Serial.write(Invalid_msg);break;
              } 
            }
            
            
      break;
    case '3': // 3-Leer el LDR"
          Serial.write(Menu_3);
          init_msg=0;
          Serial.write(Menu_225);

          while(input!='S'){
          LDR_valor = analogRead(LDR);
          Serial.println(LDR_valor); 
           
              delay(Tiempo_Espera_ms);
              if (Serial.available()) {    // Si hay algo, lo leo.
              input=Serial.read();

              switch(input){
                case 'S': continue;
                case '\n':Serial.flush();break;
                default: Serial.write(Invalid_msg);break;
              } 
              }
            }

      break;
    case '\n':
      break;
    default:
      Serial.write(Invalid_msg);
      init_msg=0;
      break;
      }

  }
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Funciones:

void InvertirEstadoLED(const int LED){
    digitalWrite(LED, !digitalRead(LED));
}
            
void interrupcionBoton0(void)
{
  delayMicroseconds(Tiempo_Espera_ms);  
       
// Espero Tiempo_Espera_ms para filtrar rebote del botón
// delay() no funciona dentro de una rutina de servicio de interrupcion, hay que usar delayMicroseconds()
// Admite hasta 16383 como argumento. Referencia en https://www.arduino.cc/en/Reference/DelayMicroseconds
  
  if(digitalRead(PULSADOR)==HIGH) // si el boton sigue apretado, es porque no fue un rebote
    digitalWrite(LED_0, !digitalRead(LED_0)); // cambia estado del pin
}

void interrupcionBoton1(void)
{
  delayMicroseconds(Tiempo_Espera_ms);  
       
// Espero Tiempo_Espera_ms para filtrar rebote del botón
// delay() no funciona dentro de una rutina de servicio de interrupcion, hay que usar delayMicroseconds()
// Admite hasta 16383 como argumento. Referencia en https://www.arduino.cc/en/Reference/DelayMicroseconds
  
  if(digitalRead(PULSADOR)==HIGH) // si el boton sigue apretado, es porque no fue un rebote
    digitalWrite(LED_1, !digitalRead(LED_1)); // cambia estado del pin
}
void interrupcionBoton2(void)
{
  delayMicroseconds(Tiempo_Espera_ms);  
       
// Espero Tiempo_Espera_ms para filtrar rebote del botón
// delay() no funciona dentro de una rutina de servicio de interrupcion, hay que usar delayMicroseconds()
// Admite hasta 16383 como argumento. Referencia en https://www.arduino.cc/en/Reference/DelayMicroseconds
  
  if(digitalRead(PULSADOR)==HIGH) // si el boton sigue apretado, es porque no fue un rebote
    digitalWrite(LED_2, !digitalRead(LED_2)); // cambia estado del pin
}
void interrupcionBoton3(void)
{
  delayMicroseconds(Tiempo_Espera_ms);  
       
// Espero Tiempo_Espera_ms para filtrar rebote del botón
// delay() no funciona dentro de una rutina de servicio de interrupcion, hay que usar delayMicroseconds()
// Admite hasta 16383 como argumento. Referencia en https://www.arduino.cc/en/Reference/DelayMicroseconds
  
  if(digitalRead(PULSADOR)==HIGH) // si el boton sigue apretado, es porque no fue un rebote
    digitalWrite(LED_3, !digitalRead(LED_3)); // cambia estado del pin
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Actividades:

// 1 - Colocar el Shield. Cargar el código y abrir el monitor serie. Probar el programa.

// Preguntas:

// a - ¿Al pulsar el botón se interrumpe el programa sin importar donde esté? ¿Continúa el programa en el mismo estado luego del llamado a interrupción?
