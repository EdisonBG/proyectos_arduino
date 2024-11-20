void enviarcantejec_paso(ModbusMaster& modbus, int dato_cantidad) {
  //ENVÍA el valor correspondiente sobre cuantas veces se va a ejecutar el patrón o rampa
  uint16_t dato_cantidadHex;
  if (dato_cantidad < 0 || dato_cantidad > 199) {  //máximo 199 veces
    dato_cantidadHex = 1000;                       // al enviar un valor fuera de rango, la comunicacion falla y no genera cambios en el valor que ya tenía escrito
    snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_text\",\"type\":\"edit\",\"widget\":\"ze33\",\"text\":\"Err\"}>ET"));  // Cantidad de pasos que se van a ejecutar
    SerialPort.write(TxData);
    delay(1000);
    //Serial.println("error");

  } else {
    dato_cantidadHex = map(dato_cantidad, 0, 199, 0, 0x00C7);
  }

  uint8_t result_cant_paso = modbus.writeSingleRegister(0x1050, dato_cantidadHex);
  Serial2.flush();
  delay(10);
}