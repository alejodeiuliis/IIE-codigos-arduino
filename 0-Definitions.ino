/**
 ******************************************
 *               0-Definitions
 ******************************************
 * Este es un programa para Arduino
 **/

// Arduino es una plataforma hardware/software de código abierto. Es práctico y fácil de utilizar.
// Arduino dispone de múltiples tutoriales, referencias y documentación: https://www.arduino.cc/ . 
// En este código veremos una introducción más para acercarnos a esta plataforma.

// Respecto al Hardware, Arduino cuenta con un microcontrolador (ATMEGA328 para el caso de Arduino UNO/NANO).
// Arduino brinda algunos perisféricos y funcionalidades pero por lo general no son suficientes.
// Para seguir estos códigos de ejemplo, tendremos que armar un Shield provisto en https://campus.fi.uba.ar (materia IIE).
// ¿Qué es un Shield? Es una placa electrónica que nos permite ampliar las funcionalidades del Arduino.
// Por ejemplo pueden brindar conectividad inalámbrica, sensores de temperatura, teclados, displays, drivers para motores, etc.
// En este caso dicho Shield nos brinda 4 Leds, 1 pulsador y 1 LDR para poder realizar pruebas.

// Respecto al Software, para poder decirle al Arduino "que es lo que queremos hacer" empleamos el entorno de desarrollo: Arduino IDE (Integrated Development Environment).
// ¿Qué es un entorno de desarrollo? Es una aplicación de Software que nos brinda un editor de código fuente, herramientas para compilación y debugging.
// Para poder comunicarnos con el microcontrolador necesitamos un lenguaje de programación. En este caso el lenguaje de programación está basado en C/C++.
// Ahora nos encontramos en dicho entorno de programación, precisamente estamos editando el código fuente "0-Definitions".

// Para poder probar el código en el Arduino, debemos seleccionar en la barra superior del IDE > Herramientas > Placa y seleccionamos el Hardware de Arduino que vamos a utilizar (Uno/Nano/etc).
// Se debe conectar por un cable USB a la computadora. Seleccionar el puerto correspondiente. 
// Normalmente la computadora detecta automáticamente el Arduino conectado y el puerto USB se selecciona automáticamente. 
// En caso de que no lo detecte existe la posibilidad que el Arduino requiera un flasheo (fuera del alcance de esta guía).

// Comenzaremos con el código de ejemplo. En este ejemplo se enciende un LED del Shield.
// Dentro del código, al emplear el caracter "//" se escriben comentarios. Dichos comentarios no son tenidos en cuenta al realizar la compilación al microcontrolador
// Por lo que podremos escribir libremente comentarios a lo largo del código. 
// Los comentarios son de gran utilidad para que nuestro código sea entendible por las demás personas (y por nosotros mismos el día de mañana).

// En un código de Arduino se destacan tres secciones: Declaración de variables globales, setup (configuración) y loop.

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Declaraciṕon de variables globales:

// Se llaman variables globales porque pueden ser llamadas en cualquier parte del programa. 
// Se escribe primero el tipo de variable, por ejemplo: bool, int, char, string (con sus modificadores).
// Luego se escrible el nombre de la variable (o etiqueta) con la cual será llamada en el código.
// Finalmente, opcionalmente se la puede inicializar por medio del caracter "=" en un determinado valor.
// Vamos a declarar nuestra primer variable:

int LED_0 = A3;

// int es un tipo entero, es decir puede tomar un valor entre -32,768 a 32,767
// Más información en: https://www.arduino.cc/reference/en/language/variables/data-types/int/
// Luego colocamos el nombre de la variable, en este caso "LED_0". No se pueden colocar espacios en los nombres de variables.
// Finalmente la inicializamos con el valor A3.A3 es una variable predefinida que toma un valor en función de que placa Arduino estemos trabajando. Para el caso de Arduino UNO A3=17.
// Para más información, buscar el archivo pins_arduino.h en donde se realizó la instalación del IDE. Allí se definen estas variables predefinidas.
// Siempre terminar las sentencias con ";"

// En este código utilizaremos dos LEDS. LED_0 y LED_1. 

int LED_1 = A2;

// LED_1 está en el pin 16, LED_0 en el pin 17. Con estas sentencias quedan asignadas los número de pin a dichas variables globales.

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Configuración del setup:

// En este sector del código se inicializan los perisféricos, puertos y se realizan configuraciones. 
// El setup se ejecuta una sola vez, por lo que se debe tener en cuenta a la hora de la programación.

void setup() {

  pinMode(LED_0, OUTPUT); 
  
// Esta función inicializa el LED_0 como salida. Por default Arduino inicializa todos los pines como entradas.
// Los pines digitales pueden tener dos valores "HIGH" o "LOW", que equivalen a los 5V o 0v respectivamente. 
// Por default un pin de salida se encuentra en estado bajo, por lo que lo cambiamos de estado.
  
  digitalWrite(LED_0, HIGH);   
3
// Este LED queda en estado alto. Configuramos el otro LED para que quede en estado bajo.

  pinMode(LED_1, OUTPUT);
  digitalWrite(LED_1, LOW); // No sería necesario escribir esta sentencia, pero lo hacemos para que quede explícito que LED_1 queda en estado bajo.

}    

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Configuración del loop 

// Este loop se ejecuta infinitamente mientras el Arduino tenga alimentación. Salvo que se ejecute alguna interrupción, este código se seguirá ejecutando. 
// Si se quiere volver a ejecutar el setup, se puede o bien apretar el botón de RESET del Arduino o bien volver a cargar el código (CTRL+U)

void loop() {
}

// Actividades:
// 1- Compilar el programa (CTRL+R). Luego conectar el Arduino+Shield y ver que pasa.
// 2- Pensar por qué estos resultados.

// Preguntas: 
// a - ¿Por qué al establecer el LED_0 en estado alto el LED no se enciende? (Pista: Revisar el circuito del Shield).
// b - ¿Qué sentido tiene el loop vacío? ¿No se ejecuta nada?
