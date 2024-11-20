///// Funcion relacionada los valores deseados o SetPoints SP //////
String obtenerSP_omega(ModbusMaster& modbus) {
  // RECIBE el valor deseado SP del omega correspondiente
  uint8_t resultSP_omega = modbus.readHoldingRegisters(0x1001, 1);
  Serial2.flush();
  delay(10);

  if (resultSP_omega == modbus.ku8MBSuccess) {
    uint16_t SP_omega_uint = (modbus.getResponseBuffer(0x00)) / 10;
    String SP_omega = String(SP_omega_uint);
    return SP_omega;
  } else {
    //getResultMsg(modbus, resultSP_omega);
    return "Err";
  }
  modbus.clearTransmitBuffer();
  modbus.clearResponseBuffer();
}