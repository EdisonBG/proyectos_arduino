//// Funcion relacionada con el SP de las memorias PID /////
String obtenerSV_PID(ModbusMaster& modbus, int mem_PID) {
  // RECIBE el valor de SV o SP de la memoria PID correspondiente (0 - 3)
  uint8_t resultSV_PID, resultSELEC_PID;
  resultSELEC_PID = modbus.writeSingleRegister(0x101C, mem_PID);
  Serial2.flush();
  delay(10);

  if (resultSELEC_PID == modbus.ku8MBSuccess) {
    modbus.clearTransmitBuffer();
    delay(10);
    resultSV_PID = modbus.readHoldingRegisters(0x101D, 1);
    Serial2.flush();
    delay(10);
    if (resultSV_PID == modbus.ku8MBSuccess) {
      uint16_t SV_PID_uint = (modbus.getResponseBuffer(0x00)) / 10;
      String SV_PID = String(SV_PID_uint);
      return SV_PID;
    } else {
      //getResultMsg(modbus, resultSV_PID);
      return "Err";
    }
  } else {
    //getResultMsg(modbus, resultSELEC_PID);
    return "Err";
  }
}