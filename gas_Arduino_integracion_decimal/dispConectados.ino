void dispConectados() {




  if (RxData[1] == '2') {  //Switch para omega 1 (Gasificador)
    if (conectado_OM1 == true) {

      conectado_OM1 = false;


      /*snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_enable\",\"type\":\"widget\",\"widget\":\"zb2\",\"enable\":false}>ET"));
      SerialPort.write(TxData);
      delay(10);
      Serial.println(TxData);
      snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_enable\",\"type\":\"widget\",\"widget\":\"zb3\",\"enable\":false}>ET"));
      SerialPort.write(TxData);
      delay(10);
      Serial.println(TxData);
      snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_enable\",\"type\":\"widget\",\"widget\":\"zb4\",\"enable\":false}>ET"));
      SerialPort.write(TxData);
      delay(10);
      Serial.println(TxData);
      snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_enable\",\"type\":\"widget\",\"widget\":\"ze13\",\"enable\":false}>ET"));
      SerialPort.write(TxData);
      delay(10);
      Serial.println(TxData);*/

      STOP_OMEGA(omega1, 1);
      delay(10);
      memset(RxData, '\0', sizeof(RxData));

    } else {
      conectado_OM1 = true;


      /*snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_enable\",\"type\":\"widget\",\"widget\":\"zb2\",\"enable\":true}>ET"));
      SerialPort.write(TxData);
      delay(10);
      Serial.println(TxData);

      snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_enable\",\"type\":\"widget\",\"widget\":\"zb3\",\"enable\":true}>ET"));
      SerialPort.write(TxData);
      Serial.println(TxData);

      delay(10);
      snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_enable\",\"type\":\"widget\",\"widget\":\"zb4\",\"enable\":true}>ET"));
      SerialPort.write(TxData);
      Serial.println(TxData);

      delay(10);
      snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_enable\",\"type\":\"widget\",\"widget\":\"ze13\",\"enable\":true}>ET"));
      SerialPort.write(TxData);
      Serial.println(TxData);

      delay(10);*/

      RUN_OMEGA(omega1, 1);
      delay(10);
      memset(RxData, '\0', sizeof(RxData));
    }
    return;
  }

  if (RxData[1] == '3') { //Switch para omega 2 (Generador de vapor)
    if (conectado_OM2 == true) {
      conectado_OM2 = false;


      /*snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_enable\",\"type\":\"widget\",\"widget\":\"zb5\",\"enable\":false}>ET"));
      SerialPort.write(TxData);
      delay(10);
      snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_enable\",\"type\":\"widget\",\"widget\":\"zb6\",\"enable\":false}>ET"));
      SerialPort.write(TxData);
      delay(10);
      snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_enable\",\"type\":\"widget\",\"widget\":\"zb7\",\"enable\":false}>ET"));
      SerialPort.write(TxData);
      delay(10);
      snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_enable\",\"type\":\"widget\",\"widget\":\"ze14\",\"enable\":false}>ET"));
      SerialPort.write(TxData);
      delay(10);*/

      STOP_OMEGA(omega2, 2);
      delay(10);
      memset(RxData, '\0', sizeof(RxData));
    } else {
      conectado_OM2 = true;


      /*snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_enable\",\"type\":\"widget\",\"widget\":\"zb5\",\"enable\":true}>ET"));
      SerialPort.write(TxData);
      delay(10);
      snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_enable\",\"type\":\"widget\",\"widget\":\"zb6\",\"enable\":true}>ET"));
      SerialPort.write(TxData);
      delay(10);
      snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_enable\",\"type\":\"widget\",\"widget\":\"zb7\",\"enable\":true}>ET"));
      SerialPort.write(TxData);
      delay(10);
      snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_enable\",\"type\":\"widget\",\"widget\":\"ze14\",\"enable\":true}>ET"));
      SerialPort.write(TxData);
      delay(10);*/

      RUN_OMEGA(omega2, 2);
      delay(10);
      memset(RxData, '\0', sizeof(RxData));
    }
    return;
  }

  if (RxData[1] == '4') { //Switch para omega 3 (Reformador)
    if (conectado_OM3 == true) {
      conectado_OM3 = false;


      /*snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_enable\",\"type\":\"widget\",\"widget\":\"zb10\",\"enable\":false}>ET"));
      SerialPort.write(TxData);
      delay(10);
      snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_enable\",\"type\":\"widget\",\"widget\":\"zb11\",\"enable\":false}>ET"));
      SerialPort.write(TxData);
      delay(10);
      snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_enable\",\"type\":\"widget\",\"widget\":\"zb12\",\"enable\":false}>ET"));
      SerialPort.write(TxData);
      delay(10);
      snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_enable\",\"type\":\"widget\",\"widget\":\"ze55\",\"enable\":false}>ET"));
      SerialPort.write(TxData);
      delay(10);*/

      STOP_OMEGA(omega3, 3);
      delay(10);
      memset(RxData, '\0', sizeof(RxData));
    } else {
      conectado_OM3 = true;


      /*snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_enable\",\"type\":\"widget\",\"widget\":\"zb10\",\"enable\":true}>ET"));
      SerialPort.write(TxData);
      delay(10);
      snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_enable\",\"type\":\"widget\",\"widget\":\"zb11\",\"enable\":true}>ET"));
      SerialPort.write(TxData);
      delay(10);
      snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_enable\",\"type\":\"widget\",\"widget\":\"zb12\",\"enable\":true}>ET"));
      SerialPort.write(TxData);
      delay(10);
      snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_enable\",\"type\":\"widget\",\"widget\":\"ze55\",\"enable\":true}>ET"));
      SerialPort.write(TxData);
      delay(10);*/

      RUN_OMEGA(omega3, 3);
      delay(10);
      memset(RxData, '\0', sizeof(RxData));
    }
    return;
  }


  if (RxData[1] == '5') { //Switch para activar o desactivar guardado de datos en SD
    if (sd == true) {
      sd = false;
      memset(RxData, '\0', sizeof(RxData));
      Serial.println("sd false, no esta grabando");
    } else {
      sd = true;
      primerDato = 0;
      snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"open_win\",\"type\":\"window\",\"widget\":\"popup1\"}>ET"));
      SerialPort.write(TxData);
      Serial.println(TxData);
      delay(10);
      memset(RxData, '\0', sizeof(RxData));
      Serial.println("sd true, esta grabando");
    }
    return;
  }
}