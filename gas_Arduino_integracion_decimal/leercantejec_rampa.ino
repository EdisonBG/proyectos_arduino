int leercantejec_rampa(ModbusMaster& modbus) {
  // RECIBE la cantidad de ejecuciones que se va a hacer de la rampa o patrón.
  uint8_t result_cantidad = modbus.readHoldingRegisters(0x1050, 1);
  if (result_cantidad == modbus.ku8MBSuccess) {
    uint16_t final_cantidad = modbus.getResponseBuffer(0x00);
    return final_cantidad;
  } else {
    return -1;
  }
}