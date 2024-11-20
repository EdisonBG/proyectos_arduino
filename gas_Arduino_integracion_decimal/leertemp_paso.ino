 int leertemp_paso(ModbusMaster& modbus, int paso) {
  // Para saber las direcciones donde se encuentra la informacion de ese paso
  direccionTemp = baseAddressTemp + paso;
  //Verifica que el paso se encuentre en el rango
  uint8_t result_temp_rampa = modbus.readHoldingRegisters(direccionTemp, 1);
  delay(10);
  if (result_temp_rampa == modbus.ku8MBSuccess) {
    uint16_t TempPaso_rampa = (modbus.getResponseBuffer(0x00)) / 10;
    modbus.clearResponseBuffer();
    return TempPaso_rampa;
  } else {
    //getResultMsg(modbus, result_temp_rampa);
    return -1;
  }
}