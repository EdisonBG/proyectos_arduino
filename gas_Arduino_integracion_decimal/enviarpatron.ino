///// Funcion relacionada con el modo de control: RAMPA //////
void enviarpatron(ModbusMaster& modbus) {
  // ENVÍA el patrón que se va a modificar al escoger el modo de control por RAMPA. Como sólo se necesita 1 patrón o rampa, se escoge por defecto el #0
  uint8_t result_sendpatron = modbus.writeSingleRegister(0x1030, 0x0000);
  Serial2.flush();
  delay(10);
  if (result_sendpatron == modbus.ku8MBSuccess) {
    Serial.println("Enviado a 1030 el patron1");
  }
  //Serial.println("Enviado");
}