///// Funcion relacionada con el estado del controlador: RUN o STOP //////
int obtenerRUNSTOP_omega(ModbusMaster& modbus) {
  // RECIBE si el omega se encuentra en modo RUN O STOP
  uint8_t result_estado_RUNSTOP = modbus.readDiscreteInputs(0x0814, 1);
  Serial2.flush();
  delay(10);
  if (result_estado_RUNSTOP == modbus.ku8MBSuccess) {
    uint16_t estado_RUNSTOP = modbus.getResponseBuffer(0x00);
    //String estado_AT = String(estado_AT_uint);
    return estado_RUNSTOP;
  } else {
    //getResultMsg(modbus, result_estado_RUNSTOP);
    return -1;
  }
}