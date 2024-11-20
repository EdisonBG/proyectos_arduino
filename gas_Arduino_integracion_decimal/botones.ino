void botones(char RxData[]) {
  char spOm1[6];

  if (RxData[1] == '0') {  //Boton para stop de grafica

    Serial.println("boton false");
    //rx[0]= RxData[1];

    grafica = false;  // Stop grafica
    snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_visible\",\"type\":\"widget\",\"widget\":\"label25\",\"visible\":false}>ET"));
    SerialPort.write(TxData);
    delay(10);
    memset(RxData, '\0', sizeof(RxData));
    return;
  }

  if (RxData[1] == '9') {  //Boton para inicio de grafica

    Serial.println("boton true");
    grafica = true;  // Inicio de grafica
    snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_visible\",\"type\":\"widget\",\"widget\":\"label25\",\"visible\":true}>ET"));
    SerialPort.write(TxData);
    delay(10);
    memset(RxData, '\0', sizeof(RxData));
    return;
  }

  if ((RxData[1] == '1') && (RxData[2] == '0')) {

    rOmega3 = false;                   // Bandera de modo rampa OFF

    if(pidOmega3 == false){
      pidOmega3 = true;
      modo_control(omega3, 0);           // Activar modo PID en Omega3
    }
    
    SP_OM3 = obtenerSP_omega(omega3);  // obtiene el valor de SP configurado en el omega
    strcpy(spOm1, SP_OM3.c_str());     // Convierte tipo string a vector char debido a que no se puede incluir una variable char en el TxData

    snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_enable\",\"type\":\"widget\",\"widget\":\"ze55\",\"enable\":true}>ET"));
    SerialPort.write(TxData);
    delay(10);

    snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_text\",\"type\":\"edit\",\"widget\":\"ze55\",\"text\":\"%s\"}>ET"), spOm1);  //Envio de trama al edit de config
    SerialPort.write(TxData);
    delay(10);
    snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_text\",\"type\":\"edit\",\"widget\":\"ze57\",\"text\":\"%s\"}>ET"), spOm1);  //Envio de trama al edit de PID
    SerialPort.write(TxData);
    delay(10);

    snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_xy\",\"type\":\"widget\",\"widget\":\"image31\",\"x\":709,\"y\":218}>ET"));
    SerialPort.write(TxData);
    delay(50);
    memset(RxData, '\0', sizeof(RxData));
    return;
  }

  if ((RxData[1] == '1') && (RxData[2] == '1')) {
    rOmega3 = false;                   // Bandera de modo rampa OFF
    pidOmega3 = false;
    modo_control(omega3, 1);           // Activar modo on/off en Omega3
    SP_OM3 = obtenerSP_omega(omega3);  // obtiene el valor de SP configurado en el omega
    strcpy(spOm1, SP_OM3.c_str());     // Convierte tipo string a vector char debido a que no se puede incluir una variable char en el TxData

    snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_enable\",\"type\":\"widget\",\"widget\":\"ze55\",\"enable\":true}>ET"));
    SerialPort.write(TxData);
    delay(10);

    snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_text\",\"type\":\"edit\",\"widget\":\"ze55\",\"text\":\"%s\"}>ET"), spOm1);  //Envio de trama al edit de config
    SerialPort.write(TxData);
    delay(10);

    snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_xy\",\"type\":\"widget\",\"widget\":\"image31\",\"x\":709,\"y\":267}>ET"));
    SerialPort.write(TxData);
    delay(50);
    memset(RxData, '\0', sizeof(RxData));
    return;
  }

  if ((RxData[1] == '1') && (RxData[2] == '2')) {

    pidOmega3 = false;

    if (rOmega3 == false) {
      rOmega3 = true;           // Bandera de modo rampa ON
      modo_control(omega3, 3);  // Activar modo rampa en Omega3
      enviarpatron(omega3);
    }


    snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_enable\",\"type\":\"widget\",\"widget\":\"ze55\",\"enable\":false}>ET"));
    SerialPort.write(TxData);
    delay(10);

    snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_xy\",\"type\":\"widget\",\"widget\":\"image31\",\"x\":709,\"y\":315}>ET"));
    SerialPort.write(TxData);
    delay(50);
    memset(RxData, '\0', sizeof(RxData));
    return;
  }

  if ((RxData[2] == '1') && (RxData[3] == '4')) { // Boton de Back / desactiva indicador de AT pid2
    snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_xy\",\"type\":\"widget\",\"widget\":\"image17\",\"x\":510 ,\"y\":480}>ET"));
    SerialPort.write(TxData);
    delay(50);
    memset(RxData, '\0', sizeof(RxData));
    return;
  }

  if ((RxData[2] == '1') && (RxData[3] == '3')) {  // Boton de home / desactiva indicador de AT  pid2
    snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_xy\",\"type\":\"widget\",\"widget\":\"image17\",\"x\":510 ,\"y\":480}>ET"));
    SerialPort.write(TxData);
    delay(50);
    memset(RxData, '\0', sizeof(RxData));
    return;
  }

  if ((RxData[2] == '2') && (RxData[3] == '6')) { // Boton de Back / desactiva indicador de AT pid3
    snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_xy\",\"type\":\"widget\",\"widget\":\"image19\",\"x\":510 ,\"y\":480}>ET"));
    SerialPort.write(TxData);
    delay(50);
    memset(RxData, '\0', sizeof(RxData));
    return;
  }

  if ((RxData[2] == '2') && (RxData[3] == '5')) { // Boton de home / desactiva indicador de AT pid2
    snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_xy\",\"type\":\"widget\",\"widget\":\"image19\",\"x\":510 ,\"y\":480}>ET"));
    SerialPort.write(TxData);
    delay(50);
    memset(RxData, '\0', sizeof(RxData));
    return;
  }

  if ((RxData[1] == '1') && (RxData[2] == '3')) { // Boton de inicio / arranque de programa
    snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_enable\",\"type\":\"widget\",\"widget\":\"zb13\",\"enable\":false}>ET"));
    SerialPort.write(TxData);
    Serial.println(TxData);
    delay(50);
    snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_visible\",\"type\":\"widget\",\"widget\":\"zb13\",\"visible\":false}>ET"));
    SerialPort.write(TxData);
    Serial.println(TxData);
    delay(50);
    snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_xy\",\"type\":\"widget\",\"widget\":\"image1\",\"x\":0,\"y\":-481}>ET"));
    SerialPort.write(TxData);
    Serial.println(TxData);
    delay(50);
    memset(RxData, '\0', sizeof(RxData));
    return;
  }


  if ((RxData[1] == '1') && (RxData[2] == '4')) {  //Temporizador de motor en On, rele low
    digitalWrite(cw_rele, LOW);
    memset(RxData, '\0', sizeof(RxData));
    return;
  }

  if ((RxData[1] == '1') && (RxData[2] == '5')) {  //Temporizador de motor en off, rele high
    digitalWrite(cw_rele, HIGH);
    memset(RxData, '\0', sizeof(RxData));
    return;
  }

  if ((RxData[1] == '1') && (RxData[2] == '6')) { // Boton de inicio de temporizador 
    tiempoInicio = millis();      // Registrar el momento en que comienza el ciclo
    estadoEncendido = true;       // Iniciar con el motor encendido
    digitalWrite(cw_rele, HIGH);  // Encender el motor
    cicloIniciado = true;         // Marcar que el ciclo ha comenzado
    memset(RxData, '\0', sizeof(RxData));
    return;
  }




  // No se usa por modelo del mfc
  if ((RxData[1] == '1') && (RxData[2] == '7')) {
    digitalWrite(mfc_negativo, LOW);  //-15 low
    delay(10);
    digitalWrite(mfc_positivo, HIGH);  //+15 high
    delay(10);
    memset(RxData, '\0', sizeof(RxData));
    Serial.println("Abierto");
    return;
  }
  //No se usa por modelo del mfc
  if ((RxData[1] == '1') && (RxData[2] == '8')) {
    digitalWrite(mfc_positivo, LOW);  //+15 low
    delay(10);
    digitalWrite(mfc_negativo, HIGH);  //-15 high
    delay(10);
    memset(RxData, '\0', sizeof(RxData));
    Serial.println("Cerrado");
    return;
  }


  if (RxData[1] == '1') {  // Set 0 todas las graficas


    snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_value\",\"type\":\"line_series\",\"widget\":\"line_series1\",\"index\":0,\"value\":[0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]}>ET"));
    SerialPort.write(TxData);
    snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_value\",\"type\":\"line_series\",\"widget\":\"line_series2\",\"index\":0,\"value\":[0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]}>ET"));
    SerialPort.write(TxData);
    snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_value\",\"type\":\"line_series\",\"widget\":\"line_series3\",\"index\":0,\"value\":[0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]}>ET"));
    SerialPort.write(TxData);
    snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_value\",\"type\":\"line_series\",\"widget\":\"line_series4\",\"index\":0,\"value\":[0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]}>ET"));
    SerialPort.write(TxData);
    snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_value\",\"type\":\"line_series\",\"widget\":\"line_series5\",\"index\":0,\"value\":[0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]}>ET"));
    SerialPort.write(TxData);
    snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_value\",\"type\":\"line_series\",\"widget\":\"line_series6\",\"index\":0,\"value\":[0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]}>ET"));
    SerialPort.write(TxData);
    snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_value\",\"type\":\"line_series\",\"widget\":\"line_series7\",\"index\":0,\"value\":[0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]}>ET"));
    SerialPort.write(TxData);
    Serial.println("hola");
    memset(RxData, '\0', sizeof(RxData));
    return;
  }

  if (RxData[1] == '2') {

    rOmega1 = false;                   // Bandera de modo rampa OFF

    if(pidOmega1 == false){
      pidOmega1 = true;
      modo_control(omega1, 0);           // Activar modo PID en Omega1
    }
    
    SP_OM1 = obtenerSP_omega(omega1);  // obtiene el valor de SP configurado en el omega
    strcpy(spOm1, SP_OM1.c_str());     // Convierte tipo string a vector char debido a que no se puede incluir una variable char en el TxData

    snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_enable\",\"type\":\"widget\",\"widget\":\"ze13\",\"enable\":true}>ET"));
    SerialPort.write(TxData);
    delay(10);

    snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_text\",\"type\":\"edit\",\"widget\":\"ze13\",\"text\":\"%s\"}>ET"), spOm1);  //Envio de trama al edit de config
    SerialPort.write(TxData);
    delay(10);
    snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_text\",\"type\":\"edit\",\"widget\":\"ze15\",\"text\":\"%s\"}>ET"), spOm1);  //Envio de trama al edit de PID
    SerialPort.write(TxData);
    delay(10);

    snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_xy\",\"type\":\"widget\",\"widget\":\"image29\",\"x\":196,\"y\":218}>ET"));
    SerialPort.write(TxData);
    delay(50);
    memset(RxData, '\0', sizeof(RxData));
    return;
  }

  if (RxData[1] == '3') {
    rOmega1 = false;  // Bandera de modo rampa OFF
    pidOmega1 = false;

    modo_control(omega1, 1);           // Activar modo on/off en Omega1
    SP_OM1 = obtenerSP_omega(omega1);  // obtiene el valor de SP configurado en el omega
    strcpy(spOm1, SP_OM1.c_str());     // Convierte tipo string a vector char debido a que no se puede incluir una variable char en el TxData

    snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_enable\",\"type\":\"widget\",\"widget\":\"ze13\",\"enable\":true}>ET"));
    SerialPort.write(TxData);
    delay(10);

    snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_text\",\"type\":\"edit\",\"widget\":\"ze13\",\"text\":\"%s\"}>ET"), spOm1);  //Envio de trama al edit de config
    SerialPort.write(TxData);
    delay(10);

    snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_xy\",\"type\":\"widget\",\"widget\":\"image29\",\"x\":196,\"y\":267}>ET"));
    SerialPort.write(TxData);
    delay(50);
    memset(RxData, '\0', sizeof(RxData));
    return;
  }

  if (RxData[1] == '4') {

    pidOmega1 = false;

    if (rOmega1 == false) {
      rOmega1 = true;           // Bandera de modo rampa ON
      modo_control(omega1, 3);  // Activar modo rampa en Omega1
      enviarpatron(omega1);
    }



    snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_enable\",\"type\":\"widget\",\"widget\":\"ze13\",\"enable\":false}>ET"));
    SerialPort.write(TxData);
    delay(10);

    snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_xy\",\"type\":\"widget\",\"widget\":\"image29\",\"x\":196,\"y\":315}>ET"));
    SerialPort.write(TxData);
    delay(50);
    memset(RxData, '\0', sizeof(RxData));
    return;
  }

  if (RxData[1] == '5') {
    rOmega2 = false;                   // Bandera de modo rampa OFF
    
    if(pidOmega2 == false){
      pidOmega2 = true;
      modo_control(omega2, 0);         // Activar modo PID en Omega2
    }

    
    SP_OM2 = obtenerSP_omega(omega2);  // obtiene el valor de SP configurado en el omega
    strcpy(spOm1, SP_OM2.c_str());     // Convierte tipo string a vector char debido a que no se puede incluir una variable char en el TxData

    snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_enable\",\"type\":\"widget\",\"widget\":\"ze14\",\"enable\":true}>ET"));
    SerialPort.write(TxData);
    delay(10);

    snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_text\",\"type\":\"edit\",\"widget\":\"ze14\",\"text\":\"%s\"}>ET"), spOm1);  //Envio de trama al edit de config
    SerialPort.write(TxData);
    delay(10);
    snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_text\",\"type\":\"edit\",\"widget\":\"ze54\",\"text\":\"%s\"}>ET"), spOm1);  //Envio de trama al edit de PID
    SerialPort.write(TxData);
    delay(10);

    snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_xy\",\"type\":\"widget\",\"widget\":\"image30\",\"x\":447,\"y\":218}>ET"));
    SerialPort.write(TxData);
    delay(50);
    memset(RxData, '\0', sizeof(RxData));
    return;
  }

  if (RxData[1] == '6') {
    rOmega2 = false;                   // Bandera de modo rampa OFF
    pidOmega2 = false;
    modo_control(omega2, 1);           // Activar modo on/off en Omega2
    SP_OM2 = obtenerSP_omega(omega2);  // obtiene el valor de SP configurado en el omega
    strcpy(spOm1, SP_OM2.c_str());     // Convierte tipo string a vector char debido a que no se puede incluir una variable char en el TxData

    snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_enable\",\"type\":\"widget\",\"widget\":\"ze14\",\"enable\":true}>ET"));
    SerialPort.write(TxData);
    delay(10);

    snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_text\",\"type\":\"edit\",\"widget\":\"ze14\",\"text\":\"%s\"}>ET"), spOm1);  //Envio de trama al edit de config
    SerialPort.write(TxData);
    delay(10);

    snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_xy\",\"type\":\"widget\",\"widget\":\"image30\",\"x\":447,\"y\":267}>ET"));
    SerialPort.write(TxData);
    delay(50);
    memset(RxData, '\0', sizeof(RxData));
    return;
  }

  if (RxData[1] == '7') {
    pidOmega2 = false;
    if (rOmega2 == false) {
      rOmega2 = true;           // Bandera de modo rampa ON
      modo_control(omega2, 3);  // Activar modo rampa en Omega2
      enviarpatron(omega2);
    }

    snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_enable\",\"type\":\"widget\",\"widget\":\"ze14\",\"enable\":false}>ET"));
    SerialPort.write(TxData);
    delay(10);

    snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_xy\",\"type\":\"widget\",\"widget\":\"image30\",\"x\":447,\"y\":315}>ET"));
    SerialPort.write(TxData);
    delay(50);
    memset(RxData, '\0', sizeof(RxData));
    return;
  }

  if (RxData[1] == '8') {

    activar_modoAT(omega1);  //Modo Autotunnig Omega 1
    snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_xy\",\"type\":\"widget\",\"widget\":\"image15\",\"x\":510 ,\"y\":438}>ET"));
    SerialPort.write(TxData);
    delay(50);
    memset(RxData, '\0', sizeof(RxData));
    return;
  }

  if (RxData[2] == '8') {  //Quita el indicador verde de autotuning al cambiar de ventana
    snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_xy\",\"type\":\"widget\",\"widget\":\"image15\",\"x\":510 ,\"y\":480}>ET"));
    SerialPort.write(TxData);
    delay(50);
    memset(RxData, '\0', sizeof(RxData));
    return;
  }

  if (RxData[2] == '7') {  //Quita el indicador verde de autotuning al cambiar de ventana
    snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_xy\",\"type\":\"widget\",\"widget\":\"image15\",\"x\":510 ,\"y\":480}>ET"));
    SerialPort.write(TxData);
    delay(50);
    memset(RxData, '\0', sizeof(RxData));
    return;
  }



  if (RxData[1] == 'a') {

    activar_modoAT(omega2);
    snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_xy\",\"type\":\"widget\",\"widget\":\"image17\",\"x\":510 ,\"y\":438}>ET"));
    SerialPort.write(TxData);
    delay(50);
    memset(RxData, '\0', sizeof(RxData));
    return;
  }



  if (RxData[1] == 'b') {

    activar_modoAT(omega3);
    snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_xy\",\"type\":\"widget\",\"widget\":\"image19\",\"x\":510 ,\"y\":438}>ET"));
    SerialPort.write(TxData);
    delay(50);
    memset(RxData, '\0', sizeof(RxData));
    return;
  }
}