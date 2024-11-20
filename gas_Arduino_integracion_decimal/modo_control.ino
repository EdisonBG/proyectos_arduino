void modo_control(ModbusMaster& modbus, int modo) {
  // ENVIA el comando del modo de control al omega: 0:PID, 1:ON/OFF, 3:RAMPAS
  uint8_t result_mode = modbus.writeSingleRegister(0x1005, modo);
  Serial2.flush();
  delay(10);
  /*if (result_mode == modbus.ku8MBSuccess) {
    if (modo == 0) {
      //Cambia el color del botón PID
      pid_btn.initButton(&tft, 120, 85, 150, 30, WHITE, OLIVE, WHITE, "PID", 2);
      pid_btn.drawButton(false);

    } else if (modo == 1) {
      //Cambia el color del botón ON/OFF
      onoff_btn.initButton(&tft, 120, 140, 150, 30, WHITE, OLIVE, WHITE, "ON/OFF", 2);
      onoff_btn.drawButton(false);

    } else {
      //Cambia el color del botón RAMPA
      rampa_btn.initButton(&tft, 120, 200, 150, 30, WHITE, OLIVE, WHITE, "RAMPA", 2);
      rampa_btn.drawButton(false);
    }

  } else {
    //getResultMsg(modbus,result_mode);
  }*/
}