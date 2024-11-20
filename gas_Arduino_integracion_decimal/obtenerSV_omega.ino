///// Funcion para obtener el valor actual de temperatura de los omegas ////
int obtenerSV_omega(ModbusMaster& modbus) {
  // RECIBE el valor deseado SP del omega correspondiente
  uint8_t resultSV_omega = modbus.readHoldingRegisters(0x1000, 1);
  Serial2.flush();
  delay(10);

  if (resultSV_omega == modbus.ku8MBSuccess) {
    uint16_t SV_omega_uint = (modbus.getResponseBuffer(0x00)) / 10;
    //String SV_omega = String(SV_omega_uint);
    return SV_omega_uint;
  } else {
    //getResultMsg(modbus, resultSV_omega);
    return -1;
  }
  modbus.clearTransmitBuffer();
  modbus.clearResponseBuffer();
}