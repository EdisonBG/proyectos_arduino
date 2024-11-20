void enviarSP_omega(ModbusMaster& modbus, int valorint) {
  // ENVIA el valor deseado SP de temperatura al omega correspondiente
  uint16_t valorHex;
  //Verifica que el valor de temperatura se encuentre en el rango del omega
  if (valorint <= -200 || valorint >= 1000) {
    //tft.print("Error:Rango");
    delay(1000);
    //Serial.println("error, fuera de rango SPomega");
  } else {
    valorHex = map(valorint, 0, 1000, 0, 0x2710);  // Convierte el valor entero de temperatura a valor hexadecimal
  }

  uint8_t result_SP_omega = modbus.writeSingleRegister(0x1001, valorHex);
  Serial2.flush();
  delay(10);
  if (result_SP_omega == modbus.ku8MBSuccess) {
    //Serial.println("Enviado");
  } 
}