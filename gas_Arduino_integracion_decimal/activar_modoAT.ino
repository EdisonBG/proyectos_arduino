//// Funcion relacionada con el modo AT /////
void activar_modoAT(ModbusMaster& modbus) {
  // ENVIA el bit de activación del moto auto tunning AT

  uint8_t result_activacionAT = modbus.writeSingleCoil(0x0813, 1);  //En la dirección 0x0813 (bit register) envío un 1 para activar (ON) el modo de Auto Tunning AT
  Serial2.flush();
  delay(10);
  
  if (result_activacionAT == modbus.ku8MBSuccess) {
    Serial.println("comando AT enviado");
  } else {
    //getResultMsg(modbus,result_activacionAT);
  }

}