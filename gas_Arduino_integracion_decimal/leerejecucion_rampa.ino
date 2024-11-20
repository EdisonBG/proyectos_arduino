int leerejecucion_rampa(ModbusMaster& modbus) {
  // RECIBE la cantidad de pasos que se van a ejecutar. "La rampa se ejecutará desde el paso 0 hasta el paso ingresado"
  uint8_t result_ejecucion = modbus.readHoldingRegisters(0x1040, 1);
  if (result_ejecucion == modbus.ku8MBSuccess) {
    uint16_t final_ejecucion = modbus.getResponseBuffer(0x00);
    return final_ejecucion;
  } else {
    //getResultMsg(modbus, result_ejecucion);
    return -1;
  }
}