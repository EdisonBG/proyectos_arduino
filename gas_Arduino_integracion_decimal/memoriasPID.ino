void memoriasPID() {
  char spPid[6];
  //Omega 3

  if (RxData2[2] == '9') {  //memoria 1

    SP_PID = obtenerSV_PID(omega3, 0);
    strcpy(spPid, SP_PID.c_str());

    snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_text\",\"type\":\"label\",\"widget\":\"label92\",\"text\":\"%s\"}>ET"), spPid);
    SerialPort.write(TxData);


    return;
  }

  if ((RxData2[2] == '1') && (RxData2[3] == '0')) {  //memoria 2

    SP_PID = obtenerSV_PID(omega3, 1);
    strcpy(spPid, SP_PID.c_str());

    snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_text\",\"type\":\"label\",\"widget\":\"label92\",\"text\":\"%s\"}>ET"), spPid);
    SerialPort.write(TxData);

    return;
  }

  if ((RxData2[2] == '1') && (RxData2[3] == '1')) {  //memoria 3

    SP_PID = obtenerSV_PID(omega3, 2);
    strcpy(spPid, SP_PID.c_str());

    snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_text\",\"type\":\"label\",\"widget\":\"label92\",\"text\":\"%s\"}>ET"), spPid);
    SerialPort.write(TxData);

    return;
  }

  if ((RxData2[2] == '1') && (RxData2[3] == '2')) {  //memoria 4

    SP_PID = obtenerSV_PID(omega3, 3);
    strcpy(spPid, SP_PID.c_str());

    snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_text\",\"type\":\"label\",\"widget\":\"label92\",\"text\":\"%s\"}>ET"), spPid);
    SerialPort.write(TxData);

    return;
  }

  // Omega 1

  if (RxData2[2] == '1') {  //memoria 1

    SP_PID = obtenerSV_PID(omega1, 0);
    strcpy(spPid, SP_PID.c_str());

    snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_text\",\"type\":\"label\",\"widget\":\"label35\",\"text\":\"%s\"}>ET"), spPid);
    SerialPort.write(TxData);


    return;
  }

  if (RxData2[2] == '2') {  // memoria 2

    SP_PID = obtenerSV_PID(omega1, 1);
    strcpy(spPid, SP_PID.c_str());

    snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_text\",\"type\":\"label\",\"widget\":\"label35\",\"text\":\"%s\"}>ET"), spPid);
    SerialPort.write(TxData);

    return;
  }

  if (RxData2[2] == '3') {  // memoria 3

    SP_PID = obtenerSV_PID(omega1, 2);
    strcpy(spPid, SP_PID.c_str());

    snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_text\",\"type\":\"label\",\"widget\":\"label35\",\"text\":\"%s\"}>ET"), spPid);
    SerialPort.write(TxData);

    return;
  }

  if (RxData2[2] == '4') {  //memoria 4

    SP_PID = obtenerSV_PID(omega1, 3);
    strcpy(spPid, SP_PID.c_str());

    snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_text\",\"type\":\"label\",\"widget\":\"label35\",\"text\":\"%s\"}>ET"), spPid);
    SerialPort.write(TxData);

    return;
  }

  //Omega 2

  if (RxData2[2] == '5') {  // memoria 1

    SP_PID = obtenerSV_PID(omega2, 0);
    strcpy(spPid, SP_PID.c_str());

    snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_text\",\"type\":\"label\",\"widget\":\"label70\",\"text\":\"%s\"}>ET"), spPid);
    SerialPort.write(TxData);

    return;
  }

  if (RxData2[2] == '6') {  //memoria 2

    SP_PID = obtenerSV_PID(omega2, 1);
    strcpy(spPid, SP_PID.c_str());

    snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_text\",\"type\":\"label\",\"widget\":\"label70\",\"text\":\"%s\"}>ET"), spPid);
    SerialPort.write(TxData);

    return;
  }

  if (RxData2[2] == '7') {  //memoria 3

    SP_PID = obtenerSV_PID(omega2, 2);
    strcpy(spPid, SP_PID.c_str());

    snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_text\",\"type\":\"label\",\"widget\":\"label70\",\"text\":\"%s\"}>ET"), spPid);
    SerialPort.write(TxData);

    return;
  }

  if (RxData2[2] == '8') {  // memoria 4

    SP_PID = obtenerSV_PID(omega2, 3);
    strcpy(spPid, SP_PID.c_str());

    snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_text\",\"type\":\"label\",\"widget\":\"label70\",\"text\":\"%s\"}>ET"), spPid);
    SerialPort.write(TxData);

    return;
  }
}