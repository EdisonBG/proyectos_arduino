///// Funcion relacionada con el estado del controlador: STOP //////
void STOP_OMEGA(ModbusMaster& modbus, int num_omega) {
  // ENVIA el bit del modo STOP del omega.
  uint8_t result_activacionSTOP = modbus.writeSingleCoil(0x0814, 0);  //En la dirección 0x0814 (bit register) envío un 0 para desactivar (STOP)
  Serial2.flush();
  delay(10);
  if (result_activacionSTOP == modbus.ku8MBSuccess) {  //cambia el color del botón indicando que se realizó el cambio satisfactoriamente, se envió el dato y el omega lo leyó
    //Hace algo con pantalla
  } 
}