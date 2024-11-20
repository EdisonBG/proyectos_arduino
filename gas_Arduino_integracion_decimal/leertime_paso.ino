int leertime_paso(ModbusMaster& modbus, int paso) {
  direccionTime = baseAddressTime + paso;
  uint8_t result_time_rampa = modbus.readHoldingRegisters(direccionTime, 1);
  delay(10);
  if (result_time_rampa == modbus.ku8MBSuccess) {
    uint16_t TimePaso_rampa = modbus.getResponseBuffer(0x00);
    modbus.clearResponseBuffer();
    return TimePaso_rampa;
  } else {
    //getResultMsg(modbus, result_time_rampa);
    return -1;
  }
}
