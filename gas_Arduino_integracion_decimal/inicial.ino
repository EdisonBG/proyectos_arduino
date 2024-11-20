void inicial() {
  char spPid[6], spOm[6], finalEjecucion[6], cantidadEjecucion[6], tempPaso[6], timepaso[6];  // Vectores char para conversion de datos tipo String e int a char

  char aChar[4];
  char nombre[] = "ze";
  char comb[6];



  int paso = 0;

  modo_control(omega1, 0);  // Siempre empieza con el omega en modo PID
  modo_control(omega2, 0);
  modo_control(omega3, 0);


  STOP_OMEGA(omega1, 1);
  delay(10);
  STOP_OMEGA(omega2, 2);
  delay(10);
  STOP_OMEGA(omega3, 3);
  delay(10);






  snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_video_play\",\"type\":\"system\",\"x\":50,\"y\":50,\"video\":\"eia_ok1.mp4\"}>ET"));
  SerialPort.write(TxData);
  //Serial.println(TxData);


  delay(8500);


  snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"open_win\",\"type\":\"window\",\"widget\":\"zconfig\"}>ET"));
  SerialPort.write(TxData);
  //Serial.println(TxData);
  delay(10);





  //Setpoint Omega 1 gasificador
  SP_OM1 = obtenerSP_omega(omega1);  // obtiene el valor de SP configurado en el omega
  strcpy(spOm, SP_OM1.c_str());      // Convierte tipo string a vector char debido a que no se puede incluir una variable char en el TxData

  snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_text\",\"type\":\"edit\",\"widget\":\"ze13\",\"text\":\"%s\"}>ET"), spOm);  //Envio de trama al edit de config
  SerialPort.write(TxData);
  delay(10);
  snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_text\",\"type\":\"edit\",\"widget\":\"ze15\",\"text\":\"%s\"}>ET"), spOm);  //Envio de trama al al edit de PID
  SerialPort.write(TxData);
  delay(10);
  snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_text\",\"type\":\"label\",\"widget\":\"label22\",\"text\":\"%s\"}>ET"), spOm);  //Envio de trama al label de lectura
  SerialPort.write(TxData);
  delay(10);



  //Setpoint Omega 2
  SP_OM2 = obtenerSP_omega(omega2);  // obtiene el valor de SP configurado en el omega
  strcpy(spOm, SP_OM2.c_str());      // Convierte tipo string a vector char debido a que no se puede incluir una variable char en el TxData

  snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_text\",\"type\":\"edit\",\"widget\":\"ze14\",\"text\":\"%s\"}>ET"), spOm);  //Envio de trama al edit de config
  SerialPort.write(TxData);
  delay(10);
  snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_text\",\"type\":\"edit\",\"widget\":\"ze54\",\"text\":\"%s\"}>ET"), spOm);  //Envio de trama al edit de PID
  SerialPort.write(TxData);
  delay(10);
  snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_text\",\"type\":\"label\",\"widget\":\"label23\",\"text\":\"%s\"}>ET"), spOm);  //Envio de trama al label de lectura
  SerialPort.write(TxData);
  delay(10);


  //Setpoint Omega 3
  SP_OM3 = obtenerSP_omega(omega3);  // obtiene el valor de SP configurado en el omega
  strcpy(spOm, SP_OM3.c_str());      // Convierte tipo string a vector char debido a que no se puede incluir una variable char en el TxData

  snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_text\",\"type\":\"edit\",\"widget\":\"ze55\",\"text\":\"%s\"}>ET"), spOm);  //Envio de trama al edit de config
  SerialPort.write(TxData);
  delay(10);
  snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_text\",\"type\":\"edit\",\"widget\":\"ze57\",\"text\":\"%s\"}>ET"), spOm);  //Envio de trama al edit de PID  // cambiar por edit que es
  SerialPort.write(TxData);
  delay(10);
  snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_text\",\"type\":\"label\",\"widget\":\"label24\",\"text\":\"%s\"}>ET"), spOm);  //Envio de trama al label de lectura
  SerialPort.write(TxData);
  delay(10);



  //Valores de memoria PID 0 en omega 1 debido a que empieza con este valor seleccionado

  SP_PID = obtenerSV_PID(omega1, 0);
  strcpy(spPid, SP_PID.c_str());

  snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_text\",\"type\":\"label\",\"widget\":\"label35\",\"text\":\"%s\"}>ET"), spPid);
  SerialPort.write(TxData);
  delay(10);



  //Valores de memoria PID 0 en omega 2 debido a que empieza con este valor seleccionado

  SP_PID = obtenerSV_PID(omega2, 0);
  strcpy(spPid, SP_PID.c_str());

  snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_text\",\"type\":\"label\",\"widget\":\"label70\",\"text\":\"%s\"}>ET"), spPid);
  SerialPort.write(TxData);
  delay(10);


  //Valores de memoria PID 0 en omega 3 debido a que empieza con este valor seleccionado


  SP_PID = obtenerSV_PID(omega3, 0);
  strcpy(spPid, SP_PID.c_str());

  snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_text\",\"type\":\"label\",\"widget\":\"label92\",\"text\":\"%s\"}>ET"), spPid);
  SerialPort.write(TxData);
  delay(10);

  //Rampa omega 1

  final_ejecucion = leerejecucion_rampa(omega1);
  itoa(final_ejecucion, finalEjecucion, 10);

  snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_text\",\"type\":\"edit\",\"widget\":\"ze32\",\"text\":\"%s\"}>ET"), finalEjecucion);  // Cantidad de pasos que se van a ejecutar
  SerialPort.write(TxData);
  delay(10);

  cantidad_ejecucion = leercantejec_rampa(omega1);
  itoa(cantidad_ejecucion, cantidadEjecucion, 10);
  snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_text\",\"type\":\"edit\",\"widget\":\"ze33\",\"text\":\"%s\"}>ET"), cantidadEjecucion);  // Cantidad de ejecuciones
  SerialPort.write(TxData);
  delay(10);

  // Valores de SP omega 1
  for (int x = 16; x <= 30; x = x + 2) {  // Ciclo de temperatura
    //Serial.println(paso);
    temperatura_paso = leertemp_paso(omega1, paso);
    itoa(temperatura_paso, tempPaso, 10);

    itoa(x, aChar, 10);
    strcpy(comb, nombre);
    strcat(comb, aChar);


    snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_text\",\"type\":\"edit\",\"widget\":\"%s\",\"text\":\"%s\"}>ET"), comb, tempPaso);
    SerialPort.write(TxData);
    //Serial.println(TxData);
    delay(10);
    deleteRx();
    paso++;
  }

  paso = 0;

  for (int x = 17; x <= 31; x = x + 2) {  // Ciclo de tiempo
    //Serial.println(paso);
    tiempo_paso = leertime_paso(omega1, paso);
    itoa(tiempo_paso, timepaso, 10);

    itoa(x, aChar, 10);
    strcpy(comb, nombre);
    strcat(comb, aChar);


    snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_text\",\"type\":\"edit\",\"widget\":\"%s\",\"text\":\"%s\"}>ET"), comb, timepaso);
    SerialPort.write(TxData);
    //Serial.println(TxData);
    delay(10);
    deleteRx();
    paso++;
  }

  paso = 0;

  //Rampa omega 2

  final_ejecucion = leerejecucion_rampa(omega2);
  itoa(final_ejecucion, finalEjecucion, 10);

  snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_text\",\"type\":\"edit\",\"widget\":\"ze52\",\"text\":\"%s\"}>ET"), finalEjecucion);  // Cantidad de pasos que se van a ejecutar
  SerialPort.write(TxData);
  delay(10);

  cantidad_ejecucion = leercantejec_rampa(omega2);
  itoa(cantidad_ejecucion, cantidadEjecucion, 10);
  snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_text\",\"type\":\"edit\",\"widget\":\"ze53\",\"text\":\"%s\"}>ET"), cantidadEjecucion);  // Cantidad de ejecuciones
  SerialPort.write(TxData);
  delay(10);

  // Valores de SP omega 2
  for (int x = 36; x <= 50; x = x + 2) {  // Ciclo de temperatura
    //Serial.println(paso);
    temperatura_paso = leertemp_paso(omega2, paso);
    itoa(temperatura_paso, tempPaso, 10);

    itoa(x, aChar, 10);
    strcpy(comb, nombre);
    strcat(comb, aChar);


    snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_text\",\"type\":\"edit\",\"widget\":\"%s\",\"text\":\"%s\"}>ET"), comb, tempPaso);
    SerialPort.write(TxData);
    //Serial.println(TxData);
    delay(10);
    deleteRx();
    paso++;
  }

  paso = 0;

  for (int x = 37; x <= 51; x = x + 2) {  // Ciclo de tiempo
    //Serial.println(paso);
    tiempo_paso = leertime_paso(omega2, paso);
    itoa(tiempo_paso, timepaso, 10);

    itoa(x, aChar, 10);
    strcpy(comb, nombre);
    strcat(comb, aChar);


    snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_text\",\"type\":\"edit\",\"widget\":\"%s\",\"text\":\"%s\"}>ET"), comb, timepaso);
    SerialPort.write(TxData);
    //Serial.println(TxData);
    delay(10);
    deleteRx();
    paso++;
  }

  paso = 0;

  //Rampa omega 3

  final_ejecucion = leerejecucion_rampa(omega3);
  itoa(final_ejecucion, finalEjecucion, 10);

  snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_text\",\"type\":\"edit\",\"widget\":\"ze74\",\"text\":\"%s\"}>ET"), finalEjecucion);  // Cantidad de pasos que se van a ejecutar
  SerialPort.write(TxData);
  delay(10);

  cantidad_ejecucion = leercantejec_rampa(omega3);
  itoa(cantidad_ejecucion, cantidadEjecucion, 10);
  snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_text\",\"type\":\"edit\",\"widget\":\"ze75\",\"text\":\"%s\"}>ET"), cantidadEjecucion);  // Cantidad de ejecuciones
  SerialPort.write(TxData);
  delay(10);

  // Valores de SP omega 1
  for (int x = 58; x <= 72; x = x + 2) {  // Ciclo de temperatura
    //Serial.println(paso);
    temperatura_paso = leertemp_paso(omega3, paso);
    itoa(temperatura_paso, tempPaso, 10);

    itoa(x, aChar, 10);
    strcpy(comb, nombre);
    strcat(comb, aChar);


    snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_text\",\"type\":\"edit\",\"widget\":\"%s\",\"text\":\"%s\"}>ET"), comb, tempPaso);
    SerialPort.write(TxData);
    //Serial.println(TxData);
    delay(10);
    deleteRx();
    paso++;
  }

  paso = 0;

  for (int x = 59; x <= 73; x = x + 2) {  // Ciclo de tiempo
    //Serial.println(paso);
    tiempo_paso = leertime_paso(omega3, paso);
    itoa(tiempo_paso, timepaso, 10);

    itoa(x, aChar, 10);
    strcpy(comb, nombre);
    strcat(comb, aChar);


    snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_text\",\"type\":\"edit\",\"widget\":\"%s\",\"text\":\"%s\"}>ET"), comb, timepaso);
    SerialPort.write(TxData);
    //Serial.println(TxData);
    delay(10);
    deleteRx();
    paso++;
  }


  // Estado ON/OFF OMEGAS


  if (obtenerRUNSTOP_omega(omega1) != 1) {


    snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_value\",\"type\":\"switch\",\"widget\":\"zs2\",\"value\":false}>ET"));
    SerialPort.write(TxData);
    delay(10);
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
  }
  //Serial.println(conectado_OM2);


  if (obtenerRUNSTOP_omega(omega2) != 1) {
    snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_value\",\"type\":\"switch\",\"widget\":\"zs3\",\"value\":false}>ET"));
    SerialPort.write(TxData);
    delay(10);

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
  }


  if (obtenerRUNSTOP_omega(omega3) != 1) {
    snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_value\",\"type\":\"switch\",\"widget\":\"zs4\",\"value\":false}>ET"));
    SerialPort.write(TxData);
    delay(10);

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
  }
}