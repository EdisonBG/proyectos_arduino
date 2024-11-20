#include <ModbusMaster.h>

#define STEP_PIN 26  // Pin de pasos para el TB6600
#define DIR_PIN 25   // Pin de dirección para el TB6600

// Pines para el Serial2 del ESP32 
#define TXD_PIN 17  // Pin TX para la comunicación Modbus
#define RXD_PIN 16  // Pin RX para la comunicación Modbus

const int stepsPerRevolution = 200;  // Número de pasos por revolución, es 200 porque vueltas= 360/(angulo de giro por paso) -- 360/1.8=200
int stepDelay = 1000;                // Retraso en microsegundos entre pasos  (velocidad de giro)
int currentSteps = 0;                // Posición actual del motor en pasos

ModbusMaster node;          // Instancia de Modbus como maestro
const int HMI_ID = 1;       // ID de la HMI (esclavo)
const int baudRate = 9600;  // Velocidad de comunicación serial

void setup() {
  Serial.begin(baudRate);
  Serial2.begin(baudRate, SERIAL_8N1, RXD_PIN, TXD_PIN);

  node.begin(HMI_ID, Serial2);  // Configura el ESP32 para comunicarse con la HMI por medio de conversot 485
  pinMode(STEP_PIN, OUTPUT);
  pinMode(DIR_PIN, OUTPUT);

}

void loop() {
  // Lee el valor del registro 0 de la HMI

  const int intentosMax = 2;
  int intentos = 0;
  uint8_t result; 
  
  while (intentos <= intentosMax) {
    result = node.readHoldingRegisters(0, 1); // Lee el registro 0 de la HMI
    if (result == node.ku8MBSuccess) {
      break; // Sale del bucle si la lectura es exitosa
    }
    intentos++;
    delay(100); // Espera antes de intentar nuevamente
  }
  
  if (result == node.ku8MBSuccess) {
    int aperturaPorcentaje = node.getResponseBuffer(0);  // Obtiene el valor del buffer de respuesta

    Serial.print("Apertura (porcentaje): ");
    Serial.println(aperturaPorcentaje);

    int targetSteps = map(aperturaPorcentaje, 0, 100, 0, stepsPerRevolution);  // Convierte a pasos
    Serial.print("Target Steps: ");
    Serial.println(targetSteps);

    if (targetSteps != currentSteps) {  // Verifica si hay un cambio en el objetivo
      if (targetSteps > currentSteps) {
        digitalWrite(DIR_PIN, HIGH);            // Configura la dirección en sentido horario
        moveSteps(targetSteps - currentSteps);  // Mueve en sentido horario
      } else {
        digitalWrite(DIR_PIN, LOW);             // Cambia la dirección a antihorario
        moveSteps(currentSteps - targetSteps);  // Mueve en sentido antihorario
      }
      currentSteps = targetSteps;  // Actualiza la posición actual
    }
  } else {
    Serial.println("Error de comunicación Modbus");
  }

  delay(1000);  // Espera antes de la siguiente lectura
}

// Función para generar pulsos y mover el motor
void moveSteps(int steps) {
  for (int i = 0; i < steps; i++) {
    digitalWrite(STEP_PIN, HIGH);
    delayMicroseconds(stepDelay);
    digitalWrite(STEP_PIN, LOW);
    delayMicroseconds(stepDelay);
  }
}
