void enviartime_paso(ModbusMaster& modbus, int paso, int dato_time) {
  //Serial.println("Entre a mod time");
  direccionTime = baseAddressTime + paso;
  //ENVÍA el valor de temperatura ingresado para el paso que deseo modificar

  uint16_t dato_timeHex;
  if (dato_time < 0 || dato_time > 900) {  //Tiempo en minutos

    delay(1000);
    //Serial.println("error");
  } else {
    dato_timeHex = map(dato_time, 0, 900, 0, 0x0384);
  }
  uint8_t result_time_paso = modbus.writeSingleRegister(direccionTime, dato_timeHex);
  Serial2.flush();
  delay(10);
  if (result_time_paso == modbus.ku8MBSuccess) {
    //Serial.println("Enviadosp time paso");
  } else {
    //getResultMsg(modbus, result_time_paso);
  }
}