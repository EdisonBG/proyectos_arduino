void enviarejec_paso(ModbusMaster& modbus, int dato_ejec) {
  //ENVÍA el valor correspondiente sobre hasta que paso se va a ejecutar el patrón o rampa

  uint16_t dato_ejecHex;
  if (dato_ejec < 0 || dato_ejec > 7) {  //El patrón sólo tiene 8 pasos
    //dato_ejecHex = 1000;                 // al enviar un valor fuera de rango, la comunicacion falla y no genera cambios en el valor que ya tenía escrito
    //tft.print("Error:Rango");
    snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_text\",\"type\":\"edit\",\"widget\":\"ze32\",\"text\":\"Err\"}>ET"));  // Cantidad de pasos que se van a ejecutar
    SerialPort.write(TxData);
    delay(1000);
    //Serial.println("error");
  }
  uint8_t result_ejec_paso = modbus.writeSingleRegister(0x1040, dato_ejec);
  Serial2.flush();
  delay(10);
  if (result_ejec_paso == modbus.ku8MBSuccess) {
    //Serial.println("Enviadosp time paso");
  } else {
    //getResultMsg(modbus, result_ejec_paso);
  }
}