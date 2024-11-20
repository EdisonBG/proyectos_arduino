///// Funcion relacionada con el estado del controlador: RUN //////
void RUN_OMEGA(ModbusMaster& modbus, int num_omega) {
  // ENVIA el bit del modo RUN del omega.
  uint8_t result_activacionRUN = modbus.writeSingleCoil(0x0814, 1);  //En la dirección 0x0814 (bit register) envío un 1 para activar (RUN)
  Serial2.flush();
  delay(10);
  
}