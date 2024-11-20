#include <Arduino.h>
#include <stdio.h>
#include <SD.h>
#include <SPI.h>
#include <ModbusMaster.h>
#include <Wire.h>
#include "RTClib.h"

RTC_DS1307 reloj;  // Definicion de objeto "reloj" para el rtc de la memoria (guardado de datos de fecha y hora inicial)

#define SerialPort Serial3

ModbusMaster omega1;
ModbusMaster omega2;
ModbusMaster omega3;  // Inicio de objetos Modbus para omegas



int dia;
int mes;
int anno;
int hora;
int minuto;
int segundo;
char hora_reloj[15];
char fecha_reloj[15];  // Variables para almacenar el tiempo consultado en el RTC.


// Salida digital para activar rele con voltaje de potenciometro
int cw_rele = 2;

// Variables para manejar el tiempo del relé
unsigned long tiempoInicio = 0;
unsigned long tiempoActivo = 0;
unsigned long tiempoApagado = 0;
bool releActivado = false;

bool cicloIniciado = false;  // Indica si el ciclo de encendido/apagado está en curso
bool estadoEncendido = true; // Indica si el motor está encendido o apagado



//Salidas digitales para reles de mfc(on, off)

int mfc_positivo = 4;  //On
int mfc_negativo = 5;  //Off

bool valveClose = true;
unsigned long tCierre = 0;



/*float flujoFiltrado = 0.0;
float umbralMinimo = 1.7;
const float alpha = 0.5; // Valor entre 0 y 1 que define la suavidad del filtro*/

//Pines analogico y digital para funcionamiento de MFC

const int pinFlujo = A7, pinSalida = 6;
float flujoActual = 0.0, flujo_ant = 0.0;  // Variables para almacenar el flujo medido por el MFC

///////////////// CREACION DE VARIABLES /////////////////

String SP_OM1, SP_OM2, SP_OM3, SP_PID;                                                                                       //SP_PID: hace referencia al valor del SV que contiene cada una de las 4 memorias PID
int SV_OM1, SV_OM2, SV_OM3, SV_OM1_ant = 0, SV_OM2_ant = 0, SV_OM3_ant = 0;                                                  // SV_OM#_ant= Comparador de valor anterior para no hacer envio constante // SV_OM# = Valor actual de omegas
int temp1 = 0, temp2 = 15, temp3 = 25, temp4 = 18, temp5 = 646, temp1_ant = 0, temp2_ant = 0, temp3_ant = 0, temp4_ant = 0;  // Variables para guardar datos de temperatura adquiridos del transmisor verde 0-5vdc
int transm1 = A0, transm2 = A1, transm3 = A2, transm4 = A3;                                                                  // Entradas analogas con valores entre 0 y 1023


char RxData[25];
char rtc[30];
char RxData2[25];
char TxData[230];  // Vectores tipo char para almacenamiento de comandos enviados por la pantalla

int extractedNumber = 0;  // Variable para guardar el valor enviado por la pantalla para los setpoint de temperatura
float extractedNumber_f;  // Variable para guardar el valor enviado por la pantalla para los setpoint de mfc




int final_ejecucion, cantidad_ejecucion, temperatura_paso, tiempo_paso;

uint16_t baseAddressTemp = 0x2000;      //  dirección base de 0x2000 para las temperaturas
uint16_t baseAddressTime = 0x2080;      //  dirección base de 0x2080 para los tiempos de la rampa
uint16_t direccionTemp, direccionTime;  //  Direccion final calculada con el #paso ingresado por el usuario

bool grafica = false;  // Booleano para activación de grafica. Inicial False.

//Banderas para saber si el disp esta on u off
bool conectado_OM1 = true;
bool conectado_OM2 = true;
bool conectado_OM3 = true;

//Banderas y variables para grafica


bool graficar0 = false;
bool graficar1 = false;
bool graficar2 = false;
bool graficar3 = false;
bool graficar4 = false;
bool graficar5 = false;
bool graficar6 = false;

char x_axis[] = "--:--,--:--,--:--,--:--,--:--,--:--,--:--,--:--,--:--,--:--,--:--,--:--,--:--,--:--,--:--,--:--,--:--,--:--,--:--,--:--,--:--,--:--,--:--,--:--";  // Buffer para guardar el eje x de la grafica
char hora_s[6];                                                                                                                                                     // En este vector se almacena la hora destinada a la grafica

unsigned long previousMillis = 0;
unsigned long previousMillisDl = 0;
const long interval = 60000;
const long intervalDl = 10000;
int primer_dato = 0;  // Bandera para pedir la primer hora y almacenarla en el vector hora_s, después de la primera se vuelve 1 y deja graficar (función graph)



// Creación de buffer y asignación de pin de cs para datalogger
File dataLogger;
const int pinSD = 53;
char buf[150];


char titulos[] = "Fecha ;Hora ;Gasificador ;Gen. vapor ;Reformador ;Biomasa ;Entrada gases ; Cenizas ; Ciclon ;";  // Titulos para el archivo csv
char hora_buff[9];                                                                                                 //Vector para almacenar la hora, dentro de este se arma el formato que se envia al archivo
char fecha_buff[11];                                                                                               //Vector para almacenar la fecha, dentro de este se arma el formato que se envia al archivo
bool sd = false;
int contador = 0;
int primerDato = 0;
int fecha_bandera;


int pApagado = 0;
char flujoInicial[] = "0";  // Variable tipo char para enviar el valor del flujo al edit de la pantalla.

bool rOmega1 = false, rOmega2 = false, rOmega3 = false, pidOmega1 = false, pidOmega2 = false, pidOmega3 = false;


void setup() {
  // put your setup code here, to run once:

  //Inicialización de Seriales, puertos de comunicación SPI, I2C, objetos modbus y de pines como entrada o salida
  Serial.begin(115200);
  Wire.begin();
  reloj.begin();
  Serial2.begin(9600, SERIAL_8E1);
  Serial2.setTimeout(500);

  omega1.begin(3, Serial2);
  delay(10);
  SPI.begin();
  SD.begin(pinSD);
  omega2.begin(4, Serial2);
  delay(10);
  omega3.begin(5, Serial2);
  delay(100);

  Serial3.begin(115200);
  delay(10);


  delay(3500);

  inicial();  //Función inicial para configurar Omegas, reproducir video inicial y actualizacion de edits y labels
  pinMode(cw_rele, OUTPUT);
  pinMode(mfc_positivo, OUTPUT);
  pinMode(mfc_negativo, OUTPUT);

  pinMode(pinSalida, OUTPUT);

  //Inicio de los pines de salida como bajo (0)
  digitalWrite(cw_rele, LOW);
  digitalWrite(mfc_positivo, LOW);
  digitalWrite(mfc_negativo, LOW);


  //Recibe y borra cualquier información del buffer serial del arduino para evitar ruido en comandos posteriores.
  listenSerial();
  delay(10);
  memset(RxData, '\0', sizeof(RxData));

  snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_text\",\"type\":\"edit\",\"widget\":\"ze56\",\"text\":\"%s\"}>ET"), flujoInicial);  //Enviar 0 al flujo del mfc cuando se enciende
  SerialPort.write(TxData);
  delay(10);
  Serial.println("Inicio");

  //Habilita boton de inicio
  snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_enable\",\"type\":\"widget\",\"widget\":\"zb13\",\"enable\":true}>ET"));
  SerialPort.write(TxData);
  delay(10);
}

void loop() {
  // put your main code here, to run repeatedly:


  unsigned long currentMillis = millis();  //Guarda tiempo de ejecucion actual

  if (listenSerial()) {  // Si existe algun mensaje, entra a la función action.
    action();
  }




  if (grafica) {  // Si grafica es true entra a la funcion graph
    //Serial.println("grafica true");
    if ((currentMillis - previousMillis) >= (interval)) {
      previousMillis = currentMillis;
      graph();
    }
  }


  if (sd) {  // Si sd es true crea el buffer de datos medidos y los envia a la memoria sd
    if ((currentMillis - previousMillisDl) >= (intervalDl)) {
      previousMillisDl = currentMillis;
      createBuffer();
      printData();
    }
  }

  mediciones();  //Recibe los valores medidos por los transmisores, el mfc y el omega

  if (cicloIniciado) {
    ejecutarCicloEncendidoApagado();
  }


  //Bandera creada para tomar la fecha solo una vez al encender el arduino y la pantalla y guardarla en la variable que se imprime, esto debido a que si se toma la fecha recibida
  //en cada iteración se pueden recibir ruidos y caracteres originados por otras funciones como oprimir un boton por ejemplo
  /*if (fecha_bandera == 0) {

    if (RxData[4] == '2') {
      strcpy(rtc, RxData);
    }

    Serial.print(rtc);
    Serial.println(" rtc");


    for (int s = 4; s < 14; s++) {  //Posiciones en donde se almacena la fecha en rtc al recibir el return del reloj. Solo cambia la fecha al reiniciar la pantalla.
      fecha_buff[s - 4] = rtc[s];
    }

    fecha_bandera++;
  }*/
}
