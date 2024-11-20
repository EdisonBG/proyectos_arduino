void enviartemp_paso(ModbusMaster& modbus, int paso, int dato_temp) {
  //Serial.println("Entre a mod temp");
  direccionTemp = baseAddressTemp + paso;
  //ENVÍA el valor de temperatura ingresado para el paso que deseo modificar

  uint16_t dato_tempHex;
  if (dato_temp <= -200 || dato_temp >= 1000) {

    delay(1000);
    //Serial.println("error");
  } else {
    dato_tempHex = map(dato_temp, 0, 1000, 0, 0x2710);
  }
  uint8_t result_temp_paso = modbus.writeSingleRegister(direccionTemp, dato_tempHex);
  Serial2.flush();
  delay(10);
  if (result_temp_paso == modbus.ku8MBSuccess) {
    //Serial.println("Enviadosp temp paso");
  } else {
    //getResultMsg(modbus, result_temp_paso);
  }
}