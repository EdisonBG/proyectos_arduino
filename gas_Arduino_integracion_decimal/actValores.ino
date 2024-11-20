void actValores() {

  //Variables auxiliares de la función
  byte byteArray[4];
  int paso;
  char extractedNumber_c[8];

  // Creación de buffer con el numero recibido desde la pantalla. Se guarda como hexadecimal
  for (int l = 0; l < 4; l++) {
    byteArray[l] = RxData[l + 3];
  }

  /*Serial.print("Contenido de byteArray[]: ");    //Para visualizar el contenido del vector obtenido de la comunicación con la pantalla. 

    for (int i = 0; i < 4; i++) {
      // Imprime cada byte en hexadecimal
      Serial.print("0x");
      if (byteArray[i] < 0x10) {  // Añade un 0 si el valor es menor que 0x10 para que tenga siempre dos dígitos
        Serial.print("0");
      }
      Serial.print(byteArray[i], HEX);

      // Añade una coma y espacio entre los bytes, excepto después del último
      if (i < 4 - 1) {
        Serial.print(", ");
      }
    }

    // Nueva línea al final
    Serial.println();*/

  //Convierte el numero hexadecimal a float, para los casos en donde se usa int corta los decimales
  extractedNumber = convertBytesToFloat(byteArray);

  if (extractedNumber >= 1001) {
    extractedNumber = 1000;
  }

  itoa(extractedNumber, extractedNumber_c, 10);  //Convierte el numero recibido a una cadena de caracteres para poder ser enviado por comando a pantalla y actualizar el edit
  Serial.println(extractedNumber);

  //De aqui en adelante se comparan las posiciones del buffer con los numeros del edit correspondiente a cada función para saber que accion tomar
  //Rampa omega 1

  if ((RxData[1] == '1') && (RxData[2] == '6')) {
    paso = 0;
    //funcion paso, extractedNumber, omega 1 - temperatura
    snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_text\",\"type\":\"edit\",\"widget\":\"ze16\",\"text\":\"%s\"}>ET"), extractedNumber_c);
    SerialPort.write(TxData);
    delay(10);
    enviartemp_paso(omega1, paso, extractedNumber);
    memset(RxData, '\0', sizeof(RxData));
    return;
  }

  if ((RxData[1] == '1') && (RxData[2] == '7')) {
    paso = 0;
    //funcion paso, extractedNumber, omega 1 - tiempo
    //actualizarSetpoint(omega1, paso, extractedNumber);
    snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_text\",\"type\":\"edit\",\"widget\":\"ze17\",\"text\":\"%s\"}>ET"), extractedNumber_c);
    SerialPort.write(TxData);
    delay(10);
    enviartime_paso(omega1, paso, extractedNumber);
    memset(RxData, '\0', sizeof(RxData));
    return;
  }

  if ((RxData[1] == '1') && (RxData[2] == '8')) {
    paso = 1;
    //funcion paso, extractedNumber, omega 1 - temperatura
    //actualizarSetpoint(omega1, paso, extractedNumber);
    snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_text\",\"type\":\"edit\",\"widget\":\"ze18\",\"text\":\"%s\"}>ET"), extractedNumber_c);
    SerialPort.write(TxData);
    delay(10);
    enviartemp_paso(omega1, paso, extractedNumber);
    memset(RxData, '\0', sizeof(RxData));
    return;
  }

  if ((RxData[1] == '1') && (RxData[2] == '9')) {
    paso = 1;
    //funcion paso, extractedNumber, omega 1 - tiempo
    //actualizarSetpoint(omega1, paso, extractedNumber);
    snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_text\",\"type\":\"edit\",\"widget\":\"ze19\",\"text\":\"%s\"}>ET"), extractedNumber_c);
    SerialPort.write(TxData);
    delay(10);
    enviartime_paso(omega1, paso, extractedNumber);
    memset(RxData, '\0', sizeof(RxData));
    return;
  }

  if ((RxData[1] == '2') && (RxData[2] == '0')) {
    paso = 2;
    //funcion paso, extractedNumber, omega 1 - temperatura
    //actualizarSetpoint(omega1, paso, extractedNumber);
    snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_text\",\"type\":\"edit\",\"widget\":\"ze20\",\"text\":\"%s\"}>ET"), extractedNumber_c);
    SerialPort.write(TxData);
    delay(10);
    enviartemp_paso(omega1, paso, extractedNumber);
    memset(RxData, '\0', sizeof(RxData));
    return;
  }

  if ((RxData[1] == '2') && (RxData[2] == '1')) {
    paso = 2;
    //funcion paso, extractedNumber, omega 1 - tiempo
    //actualizarSetpoint(omega1, paso, extractedNumber);
    snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_text\",\"type\":\"edit\",\"widget\":\"ze21\",\"text\":\"%s\"}>ET"), extractedNumber_c);
    SerialPort.write(TxData);
    delay(10);
    enviartime_paso(omega1, paso, extractedNumber);
    memset(RxData, '\0', sizeof(RxData));
    return;
  }

  if ((RxData[1] == '2') && (RxData[2] == '2')) {
    paso = 3;
    //funcion paso, extractedNumber, omega 1 - temperatura
    //actualizarSetpoint(omega1, paso, extractedNumber);
    snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_text\",\"type\":\"edit\",\"widget\":\"ze22\",\"text\":\"%s\"}>ET"), extractedNumber_c);
    SerialPort.write(TxData);
    delay(10);
    enviartemp_paso(omega1, paso, extractedNumber);
    memset(RxData, '\0', sizeof(RxData));
    return;
  }

  if ((RxData[1] == '2') && (RxData[2] == '3')) {
    paso = 3;
    //funcion paso, extractedNumber, omega 1 - tiempo
    //actualizarSetpoint(omega1, paso, extractedNumber);
    snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_text\",\"type\":\"edit\",\"widget\":\"ze23\",\"text\":\"%s\"}>ET"), extractedNumber_c);
    SerialPort.write(TxData);
    delay(10);
    enviartime_paso(omega1, paso, extractedNumber);
    memset(RxData, '\0', sizeof(RxData));
    return;
  }

  if ((RxData[1] == '2') && (RxData[2] == '4')) {
    paso = 4;
    //funcion paso, extractedNumber, omega 1 - temperatura
    //actualizarSetpoint(omega1, paso, extractedNumber);
    snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_text\",\"type\":\"edit\",\"widget\":\"ze24\",\"text\":\"%s\"}>ET"), extractedNumber_c);
    SerialPort.write(TxData);
    delay(10);
    enviartemp_paso(omega1, paso, extractedNumber);
    memset(RxData, '\0', sizeof(RxData));
    return;
  }

  if ((RxData[1] == '2') && (RxData[2] == '5')) {
    paso = 4;
    //funcion paso, extractedNumber, omega 1 - tiempo
    //actualizarSetpoint(omega1, paso, extractedNumber);
    snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_text\",\"type\":\"edit\",\"widget\":\"ze25\",\"text\":\"%s\"}>ET"), extractedNumber_c);
    SerialPort.write(TxData);
    delay(10);
    enviartime_paso(omega1, paso, extractedNumber);
    memset(RxData, '\0', sizeof(RxData));
    return;
  }
  if ((RxData[1] == '2') && (RxData[2] == '6')) {
    paso = 5;
    //funcion paso, extractedNumber, omega 1 - temperatura
    //actualizarSetpoint(omega1, paso, extractedNumber);
    snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_text\",\"type\":\"edit\",\"widget\":\"ze26\",\"text\":\"%s\"}>ET"), extractedNumber_c);
    SerialPort.write(TxData);
    delay(10);
    enviartemp_paso(omega1, paso, extractedNumber);
    memset(RxData, '\0', sizeof(RxData));
    return;
  }

  if ((RxData[1] == '2') && (RxData[2] == '7')) {
    paso = 5;
    //funcion paso, extractedNumber, omega 1 - tiempo
    //actualizarSetpoint(omega1, paso, extractedNumber);
    snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_text\",\"type\":\"edit\",\"widget\":\"ze27\",\"text\":\"%s\"}>ET"), extractedNumber_c);
    SerialPort.write(TxData);
    delay(10);
    enviartime_paso(omega1, paso, extractedNumber);
    memset(RxData, '\0', sizeof(RxData));
    return;
  }

  if ((RxData[1] == '2') && (RxData[2] == '8')) {
    paso = 6;
    //funcion paso, extractedNumber, omega 1 - temperatura
    //actualizarSetpoint(omega1, paso, extractedNumber);
    snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_text\",\"type\":\"edit\",\"widget\":\"ze28\",\"text\":\"%s\"}>ET"), extractedNumber_c);
    SerialPort.write(TxData);
    delay(10);
    enviartemp_paso(omega1, paso, extractedNumber);
    memset(RxData, '\0', sizeof(RxData));
    return;
  }

  if ((RxData[1] == '2') && (RxData[2] == '9')) {
    paso = 6;
    //funcion paso, extractedNumber, omega 1 - tiempo
    //actualizarSetpoint(omega1, paso, extractedNumber);
    snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_text\",\"type\":\"edit\",\"widget\":\"ze29\",\"text\":\"%s\"}>ET"), extractedNumber_c);
    SerialPort.write(TxData);
    delay(10);
    enviartime_paso(omega1, paso, extractedNumber);
    memset(RxData, '\0', sizeof(RxData));
    return;
  }

  if ((RxData[1] == '3') && (RxData[2] == '0')) {
    paso = 7;
    //funcion paso, extractedNumber, omega 1 - temperatura
    //actualizarSetpoint(omega1, paso, extractedNumber);
    snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_text\",\"type\":\"edit\",\"widget\":\"ze30\",\"text\":\"%s\"}>ET"), extractedNumber_c);
    SerialPort.write(TxData);
    delay(10);
    enviartemp_paso(omega1, paso, extractedNumber);
    memset(RxData, '\0', sizeof(RxData));
    return;
  }

  if ((RxData[1] == '3') && (RxData[2] == '1')) {
    paso = 7;
    //funcion paso, extractedNumber, omega 1 - tiempo
    //actualizarSetpoint(omega1, paso, extractedNumber);
    snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_text\",\"type\":\"edit\",\"widget\":\"ze31\",\"text\":\"%s\"}>ET"), extractedNumber_c);
    SerialPort.write(TxData);
    delay(10);
    enviartime_paso(omega1, paso, extractedNumber);
    memset(RxData, '\0', sizeof(RxData));
    return;
  }

  if ((RxData[1] == '3') && (RxData[2] == '2')) {
    //funcion paso, extractedNumber, omega 1 - tiempo
    //actualizarSetpoint(omega1, paso, extractedNumber);
    snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_text\",\"type\":\"edit\",\"widget\":\"ze32\",\"text\":\"%s\"}>ET"), extractedNumber_c);
    SerialPort.write(TxData);
    delay(10);
    enviarejec_paso(omega1, extractedNumber);
    memset(RxData, '\0', sizeof(RxData));
    return;
  }

  if ((RxData[1] == '3') && (RxData[2] == '3')) {
    //funcion paso, extractedNumber, omega 1 - tiempo
    //actualizarSetpoint(omega1, paso, extractedNumber);
    snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_text\",\"type\":\"edit\",\"widget\":\"ze33\",\"text\":\"%s\"}>ET"), extractedNumber_c);
    SerialPort.write(TxData);
    delay(10);
    enviarcantejec_paso(omega1, extractedNumber);
    memset(RxData, '\0', sizeof(RxData));
    return;
  }

  //Rampa omega 2 ----------------------------------------------------------------------------------------------------------------------------------------------------------------

  if ((RxData[1] == '3') && (RxData[2] == '6')) {
    paso = 0;
    //Serial.println("extractedNumber");
    snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_text\",\"type\":\"edit\",\"widget\":\"ze36\",\"text\":\"%s\"}>ET"), extractedNumber_c);
    SerialPort.write(TxData);
    delay(10);
    enviartemp_paso(omega2, paso, extractedNumber);
    memset(RxData, '\0', sizeof(RxData));

    //funcion paso, extractedNumber, omega 2 - temperatura
    //actualizarSetpoint(omega2, paso, extractedNumber);
    return;
  }

  if ((RxData[1] == '3') && (RxData[2] == '7')) {
    paso = 0;
    //funcion paso, extractedNumber, omega 2 - tiempo
    //actualizarSetpoint(omega2, paso, extractedNumber);
    snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_text\",\"type\":\"edit\",\"widget\":\"ze37\",\"text\":\"%s\"}>ET"), extractedNumber_c);
    SerialPort.write(TxData);
    delay(10);
    enviartime_paso(omega2, paso, extractedNumber);
    memset(RxData, '\0', sizeof(RxData));
    return;
  }

  if ((RxData[1] == '3') && (RxData[2] == '8')) {
    paso = 1;
    //funcion paso, extractedNumber, omega 2 - temperatura
    //actualizarSetpoint(omega2, paso, extractedNumber);
    snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_text\",\"type\":\"edit\",\"widget\":\"ze38\",\"text\":\"%s\"}>ET"), extractedNumber_c);
    SerialPort.write(TxData);
    delay(10);
    enviartemp_paso(omega2, paso, extractedNumber);
    memset(RxData, '\0', sizeof(RxData));
    return;
  }

  if ((RxData[1] == '3') && (RxData[2] == '9')) {
    paso = 1;
    //funcion paso, extractedNumber, omega 2 - tiempo
    //actualizarSetpoint(omega2, paso, extractedNumber);
    snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_text\",\"type\":\"edit\",\"widget\":\"ze39\",\"text\":\"%s\"}>ET"), extractedNumber_c);
    SerialPort.write(TxData);
    delay(10);
    enviartime_paso(omega2, paso, extractedNumber);
    memset(RxData, '\0', sizeof(RxData));
    return;
  }

  if ((RxData[1] == '4') && (RxData[2] == '0')) {
    paso = 2;
    //funcion paso, extractedNumber, omega 2 - temperatura
    //actualizarSetpoint(omega2, paso, extractedNumber);
    snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_text\",\"type\":\"edit\",\"widget\":\"ze40\",\"text\":\"%s\"}>ET"), extractedNumber_c);
    SerialPort.write(TxData);
    delay(10);
    enviartemp_paso(omega2, paso, extractedNumber);
    memset(RxData, '\0', sizeof(RxData));
    return;
  }

  if ((RxData[1] == '4') && (RxData[2] == '1')) {
    paso = 2;
    //funcion paso, extractedNumber, omega 2 - tiempo
    //actualizarSetpoint(omega2, paso, extractedNumber);
    snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_text\",\"type\":\"edit\",\"widget\":\"ze41\",\"text\":\"%s\"}>ET"), extractedNumber_c);
    SerialPort.write(TxData);
    delay(10);
    enviartime_paso(omega2, paso, extractedNumber);
    memset(RxData, '\0', sizeof(RxData));
    return;
  }

  if ((RxData[1] == '4') && (RxData[2] == '2')) {
    paso = 3;
    //funcion paso, extractedNumber, omega 2 - temperatura
    //actualizarSetpoint(omega2, paso, extractedNumber);
    snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_text\",\"type\":\"edit\",\"widget\":\"ze42\",\"text\":\"%s\"}>ET"), extractedNumber_c);
    SerialPort.write(TxData);
    delay(10);
    enviartemp_paso(omega2, paso, extractedNumber);
    memset(RxData, '\0', sizeof(RxData));
    return;
  }

  if ((RxData[1] == '4') && (RxData[2] == '3')) {
    paso = 3;
    //funcion paso, extractedNumber, omega 2 - tiempo
    //actualizarSetpoint(omega2, paso, extractedNumber);
    snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_text\",\"type\":\"edit\",\"widget\":\"ze43\",\"text\":\"%s\"}>ET"), extractedNumber_c);
    SerialPort.write(TxData);
    delay(10);
    enviartime_paso(omega2, paso, extractedNumber);
    memset(RxData, '\0', sizeof(RxData));
    return;
  }

  if ((RxData[1] == '4') && (RxData[2] == '4')) {
    paso = 4;
    //funcion paso, extractedNumber, omega 2 - temperatura
    //actualizarSetpoint(omega2, paso, extractedNumber);
    snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_text\",\"type\":\"edit\",\"widget\":\"ze44\",\"text\":\"%s\"}>ET"), extractedNumber_c);
    SerialPort.write(TxData);
    delay(10);
    enviartemp_paso(omega2, paso, extractedNumber);
    memset(RxData, '\0', sizeof(RxData));
    return;
  }

  if ((RxData[1] == '4') && (RxData[2] == '5')) {
    paso = 4;
    //funcion paso, extractedNumber, omega 2 - tiempo
    //actualizarSetpoint(omega2, paso, extractedNumber);
    snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_text\",\"type\":\"edit\",\"widget\":\"ze45\",\"text\":\"%s\"}>ET"), extractedNumber_c);
    SerialPort.write(TxData);
    delay(10);
    enviartime_paso(omega2, paso, extractedNumber);
    memset(RxData, '\0', sizeof(RxData));
    return;
  }

  if ((RxData[1] == '4') && (RxData[2] == '6')) {
    paso = 5;
    //funcion paso, extractedNumber, omega 2 - temperatura
    //actualizarSetpoint(omega2, paso, extractedNumber);
    snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_text\",\"type\":\"edit\",\"widget\":\"ze46\",\"text\":\"%s\"}>ET"), extractedNumber_c);
    SerialPort.write(TxData);
    delay(10);
    enviartemp_paso(omega2, paso, extractedNumber);
    memset(RxData, '\0', sizeof(RxData));
    return;
  }

  if ((RxData[1] == '4') && (RxData[2] == '7')) {
    paso = 5;
    //funcion paso, extractedNumber, omega 2 - tiempo
    //actualizarSetpoint(omega2, paso, extractedNumber);
    snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_text\",\"type\":\"edit\",\"widget\":\"ze47\",\"text\":\"%s\"}>ET"), extractedNumber_c);
    SerialPort.write(TxData);
    delay(10);
    enviartime_paso(omega2, paso, extractedNumber);
    memset(RxData, '\0', sizeof(RxData));
    return;
  }

  if ((RxData[1] == '4') && (RxData[2] == '8')) {
    paso = 6;
    //funcion paso, extractedNumber, omega 2 - temperatura
    //actualizarSetpoint(omega2, paso, extractedNumber);
    snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_text\",\"type\":\"edit\",\"widget\":\"ze48\",\"text\":\"%s\"}>ET"), extractedNumber_c);
    SerialPort.write(TxData);
    delay(10);
    enviartemp_paso(omega2, paso, extractedNumber);
    memset(RxData, '\0', sizeof(RxData));
    return;
  }

  if ((RxData[1] == '4') && (RxData[2] == '9')) {
    paso = 6;
    //funcion paso, extractedNumber, omega 2 - tiempo
    //actualizarSetpoint(omega2, paso, extractedNumber);
    snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_text\",\"type\":\"edit\",\"widget\":\"ze49\",\"text\":\"%s\"}>ET"), extractedNumber_c);
    SerialPort.write(TxData);
    delay(10);
    enviartime_paso(omega2, paso, extractedNumber);
    memset(RxData, '\0', sizeof(RxData));
    return;
  }

  if ((RxData[1] == '5') && (RxData[2] == '0')) {
    paso = 7;
    //funcion paso, extractedNumber, omega 2 - temperatura
    //actualizarSetpoint(omega2, paso, extractedNumber);
    snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_text\",\"type\":\"edit\",\"widget\":\"ze50\",\"text\":\"%s\"}>ET"), extractedNumber_c);
    SerialPort.write(TxData);
    delay(10);
    enviartemp_paso(omega2, paso, extractedNumber);
    memset(RxData, '\0', sizeof(RxData));
    return;
  }

  if ((RxData[1] == '5') && (RxData[2] == '1')) {
    paso = 7;
    //funcion paso, extractedNumber, omega 2 - tiempo
    //actualizarSetpoint(omega2, paso, extractedNumber);
    snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_text\",\"type\":\"edit\",\"widget\":\"ze51\",\"text\":\"%s\"}>ET"), extractedNumber_c);
    SerialPort.write(TxData);
    delay(10);
    enviartime_paso(omega2, paso, extractedNumber);
    memset(RxData, '\0', sizeof(RxData));
    return;
  }

  if ((RxData[1] == '5') && (RxData[2] == '2')) {
    //funcion paso, extractedNumber, omega 1 - tiempo
    //actualizarSetpoint(omega1, paso, extractedNumber);
    snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_text\",\"type\":\"edit\",\"widget\":\"ze52\",\"text\":\"%s\"}>ET"), extractedNumber_c);
    SerialPort.write(TxData);
    delay(10);
    enviarejec_paso(omega2, extractedNumber);
    memset(RxData, '\0', sizeof(RxData));
    return;
  }

  if ((RxData[1] == '5') && (RxData[2] == '3')) {
    //funcion paso, extractedNumber, omega 1 - tiempo
    //actualizarSetpoint(omega1, paso, extractedNumber);
    snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_text\",\"type\":\"edit\",\"widget\":\"ze53\",\"text\":\"%s\"}>ET"), extractedNumber_c);
    SerialPort.write(TxData);
    delay(10);
    enviarcantejec_paso(omega2, extractedNumber);
    memset(RxData, '\0', sizeof(RxData));
    return;
  }



  //Rampa omega 3 ----------------------------------------------------------------------------------------------------------------------------------------------------------------

  if ((RxData[1] == '5') && (RxData[2] == '8')) {
    paso = 0;
    //Serial.println("extractedNumber");
    snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_text\",\"type\":\"edit\",\"widget\":\"ze58\",\"text\":\"%s\"}>ET"), extractedNumber_c);
    SerialPort.write(TxData);
    delay(10);
    enviartemp_paso(omega3, paso, extractedNumber);


    memset(RxData, '\0', sizeof(RxData));
    //funcion paso, extractedNumber, omega 2 - temperatura
    //actualizarSetpoint(omega2, paso, extractedNumber);
    return;
  }

  if ((RxData[1] == '5') && (RxData[2] == '9')) {
    paso = 0;
    //funcion paso, extractedNumber, omega 3 - tiempo
    //actualizarSetpoint(omega3, paso, extractedNumber);
    snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_text\",\"type\":\"edit\",\"widget\":\"ze59\",\"text\":\"%s\"}>ET"), extractedNumber_c);
    SerialPort.write(TxData);
    delay(10);
    enviartime_paso(omega3, paso, extractedNumber);
    memset(RxData, '\0', sizeof(RxData));
    return;
  }

  if ((RxData[1] == '6') && (RxData[2] == '0')) {
    paso = 1;
    //funcion paso, extractedNumber, omega 2 - temperatura
    //actualizarSetpoint(omega2, paso, extractedNumber);
    snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_text\",\"type\":\"edit\",\"widget\":\"ze60\",\"text\":\"%s\"}>ET"), extractedNumber_c);
    SerialPort.write(TxData);
    delay(10);
    enviartemp_paso(omega3, paso, extractedNumber);
    memset(RxData, '\0', sizeof(RxData));
    return;
  }

  if ((RxData[1] == '6') && (RxData[2] == '1')) {
    paso = 1;
    //funcion paso, extractedNumber, omega 2 - tiempo
    //actualizarSetpoint(omega2, paso, extractedNumber);
    snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_text\",\"type\":\"edit\",\"widget\":\"ze61\",\"text\":\"%s\"}>ET"), extractedNumber_c);
    SerialPort.write(TxData);
    delay(10);
    enviartime_paso(omega3, paso, extractedNumber);
    memset(RxData, '\0', sizeof(RxData));
    return;
  }

  if ((RxData[1] == '6') && (RxData[2] == '2')) {
    paso = 2;
    //funcion paso, extractedNumber, omega 2 - temperatura
    //actualizarSetpoint(omega2, paso, extractedNumber);
    snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_text\",\"type\":\"edit\",\"widget\":\"ze62\",\"text\":\"%s\"}>ET"), extractedNumber_c);
    SerialPort.write(TxData);
    delay(10);
    enviartemp_paso(omega3, paso, extractedNumber);
    memset(RxData, '\0', sizeof(RxData));
    return;
  }

  if ((RxData[1] == '6') && (RxData[2] == '3')) {
    paso = 2;
    //funcion paso, extractedNumber, omega 2 - tiempo
    //actualizarSetpoint(omega2, paso, extractedNumber);
    snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_text\",\"type\":\"edit\",\"widget\":\"ze63\",\"text\":\"%s\"}>ET"), extractedNumber_c);
    SerialPort.write(TxData);
    delay(10);
    enviartime_paso(omega3, paso, extractedNumber);
    memset(RxData, '\0', sizeof(RxData));
    return;
  }

  if ((RxData[1] == '6') && (RxData[2] == '4')) {
    paso = 3;
    //funcion paso, extractedNumber, omega 2 - temperatura
    //actualizarSetpoint(omega2, paso, extractedNumber);
    snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_text\",\"type\":\"edit\",\"widget\":\"ze64\",\"text\":\"%s\"}>ET"), extractedNumber_c);
    SerialPort.write(TxData);
    delay(10);
    enviartemp_paso(omega3, paso, extractedNumber);
    memset(RxData, '\0', sizeof(RxData));
    return;
  }

  if ((RxData[1] == '6') && (RxData[2] == '5')) {
    paso = 3;
    //funcion paso, extractedNumber, omega 2 - tiempo
    //actualizarSetpoint(omega2, paso, extractedNumber);
    snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_text\",\"type\":\"edit\",\"widget\":\"ze65\",\"text\":\"%s\"}>ET"), extractedNumber_c);
    SerialPort.write(TxData);
    delay(10);
    enviartime_paso(omega3, paso, extractedNumber);
    memset(RxData, '\0', sizeof(RxData));
    return;
  }

  if ((RxData[1] == '6') && (RxData[2] == '6')) {
    paso = 4;
    //funcion paso, extractedNumber, omega 2 - temperatura
    //actualizarSetpoint(omega2, paso, extractedNumber);
    snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_text\",\"type\":\"edit\",\"widget\":\"ze66\",\"text\":\"%s\"}>ET"), extractedNumber_c);
    SerialPort.write(TxData);
    delay(10);
    enviartemp_paso(omega3, paso, extractedNumber);
    memset(RxData, '\0', sizeof(RxData));
    return;
  }

  if ((RxData[1] == '6') && (RxData[2] == '7')) {
    paso = 4;
    //funcion paso, extractedNumber, omega 2 - tiempo
    //actualizarSetpoint(omega2, paso, extractedNumber);
    snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_text\",\"type\":\"edit\",\"widget\":\"ze67\",\"text\":\"%s\"}>ET"), extractedNumber_c);
    SerialPort.write(TxData);
    delay(10);
    enviartime_paso(omega3, paso, extractedNumber);
    memset(RxData, '\0', sizeof(RxData));
    return;
  }

  if ((RxData[1] == '6') && (RxData[2] == '8')) {
    paso = 5;
    //funcion paso, extractedNumber, omega 2 - temperatura
    //actualizarSetpoint(omega2, paso, extractedNumber);
    snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_text\",\"type\":\"edit\",\"widget\":\"ze68\",\"text\":\"%s\"}>ET"), extractedNumber_c);
    SerialPort.write(TxData);
    delay(10);
    enviartemp_paso(omega3, paso, extractedNumber);
    memset(RxData, '\0', sizeof(RxData));
    return;
  }

  if ((RxData[1] == '6') && (RxData[2] == '9')) {
    paso = 5;
    //funcion paso, extractedNumber, omega 2 - tiempo
    //actualizarSetpoint(omega2, paso, extractedNumber);
    snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_text\",\"type\":\"edit\",\"widget\":\"ze69\",\"text\":\"%s\"}>ET"), extractedNumber_c);
    SerialPort.write(TxData);
    delay(10);
    enviartime_paso(omega3, paso, extractedNumber);
    memset(RxData, '\0', sizeof(RxData));
    return;
  }

  if ((RxData[1] == '7') && (RxData[2] == '0')) {
    paso = 6;
    //funcion paso, extractedNumber, omega 2 - temperatura
    //actualizarSetpoint(omega2, paso, extractedNumber);
    snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_text\",\"type\":\"edit\",\"widget\":\"ze70\",\"text\":\"%s\"}>ET"), extractedNumber_c);
    SerialPort.write(TxData);
    delay(10);
    enviartemp_paso(omega3, paso, extractedNumber);
    memset(RxData, '\0', sizeof(RxData));
    return;
  }

  if ((RxData[1] == '7') && (RxData[2] == '1')) {
    paso = 6;
    //funcion paso, extractedNumber, omega 2 - tiempo
    //actualizarSetpoint(omega2, paso, extractedNumber);
    snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_text\",\"type\":\"edit\",\"widget\":\"ze71\",\"text\":\"%s\"}>ET"), extractedNumber_c);
    SerialPort.write(TxData);
    delay(10);
    enviartime_paso(omega3, paso, extractedNumber);
    memset(RxData, '\0', sizeof(RxData));
    return;
  }

  if ((RxData[1] == '7') && (RxData[2] == '2')) {
    paso = 7;
    //funcion paso, extractedNumber, omega 2 - temperatura
    //actualizarSetpoint(omega2, paso, extractedNumber);
    snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_text\",\"type\":\"edit\",\"widget\":\"ze72\",\"text\":\"%s\"}>ET"), extractedNumber_c);
    SerialPort.write(TxData);
    delay(10);
    enviartemp_paso(omega3, paso, extractedNumber);
    memset(RxData, '\0', sizeof(RxData));
    return;
  }

  if ((RxData[1] == '7') && (RxData[2] == '3')) {
    paso = 7;
    //funcion paso, extractedNumber, omega 2 - tiempo
    //actualizarSetpoint(omega2, paso, extractedNumber);
    snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_text\",\"type\":\"edit\",\"widget\":\"ze73\",\"text\":\"%s\"}>ET"), extractedNumber_c);
    SerialPort.write(TxData);
    delay(10);
    enviartime_paso(omega3, paso, extractedNumber);
    memset(RxData, '\0', sizeof(RxData));
    return;
  }

  if ((RxData[1] == '7') && (RxData[2] == '4')) {
    //funcion paso, extractedNumber, omega 1 - tiempo
    //actualizarSetpoint(omega1, paso, extractedNumber);
    snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_text\",\"type\":\"edit\",\"widget\":\"ze74\",\"text\":\"%s\"}>ET"), extractedNumber_c);
    SerialPort.write(TxData);
    delay(10);
    enviarejec_paso(omega3, extractedNumber);
    memset(RxData, '\0', sizeof(RxData));
    return;
  }



  if ((RxData[1] == '7') && (RxData[2] == '5')) {
    //funcion paso, extractedNumber, omega 1 - tiempo
    //actualizarSetpoint(omega1, paso, extractedNumber);
    snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_text\",\"type\":\"edit\",\"widget\":\"ze75\",\"text\":\"%s\"}>ET"), extractedNumber_c);
    SerialPort.write(TxData);
    delay(10);
    enviarcantejec_paso(omega3, extractedNumber);
    memset(RxData, '\0', sizeof(RxData));
    return;
  }

  //Tiempo de temporizador de motor
  if ((RxData[1] == '7') && (RxData[2] == '6')) {
    tiempoActivo = (extractedNumber * 60000UL) - 18000;  // Tiempo que el relé estará activo
    memset(RxData, '\0', sizeof(RxData));
    return;
  }

  if ((RxData[1] == '7') && (RxData[2] == '7')) {
    tiempoApagado = (extractedNumber * 60000UL) + 18000;  // Tiempo que el relé estará apagado
    memset(RxData, '\0', sizeof(RxData));
    return;
  }


  //Setpoint omega 1 PID y ON/OFF
  if ((RxData[1] == '1') && (RxData[2] == '5')) {


    enviarSP_omega(omega1, extractedNumber);  // Valor de SP leido en el edit widget  -- PID menu
    snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_text\",\"type\":\"edit\",\"widget\":\"ze13\",\"text\":\"%s\"}>ET"), extractedNumber_c);
    SerialPort.write(TxData);
    delay(10);
    snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_text\",\"type\":\"label\",\"widget\":\"label22\",\"text\":\"%s\"}>ET"), extractedNumber_c);  //Envio de trama al label de lectura
    SerialPort.write(TxData);
    delay(10);
    memset(RxData, '\0', sizeof(RxData));

    return;
  }

  if ((RxData[1] == '1') && (RxData[2] == '3')) {

    enviarSP_omega(omega1, extractedNumber);  // Valor de SP leido en el edit widget  -- PID config
    snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_text\",\"type\":\"edit\",\"widget\":\"ze15\",\"text\":\"%s\"}>ET"), extractedNumber_c);
    SerialPort.write(TxData);
    delay(10);
    snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_text\",\"type\":\"label\",\"widget\":\"label22\",\"text\":\"%s\"}>ET"), extractedNumber_c);  //Envio de trama al label de lectura
    SerialPort.write(TxData);
    delay(10);
    memset(RxData, '\0', sizeof(RxData));


    return;
  }

  if ((RxData[1] == '5') && (RxData[2] == '4')) {

    enviarSP_omega(omega2, extractedNumber);  // Valor de SP leido en el edit widget  -- PID menu
    snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_text\",\"type\":\"edit\",\"widget\":\"ze14\",\"text\":\"%s\"}>ET"), extractedNumber_c);
    SerialPort.write(TxData);
    delay(10);
    snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_text\",\"type\":\"label\",\"widget\":\"label23\",\"text\":\"%s\"}>ET"), extractedNumber_c);  //Envio de trama al label de lectura
    SerialPort.write(TxData);
    delay(10);
    memset(RxData, '\0', sizeof(RxData));

    return;
  }

  if ((RxData[1] == '1') && (RxData[2] == '4')) {

    enviarSP_omega(omega2, extractedNumber);  // Valor de SP leido en el edit widget  -- PID config
    snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_text\",\"type\":\"edit\",\"widget\":\"ze54\",\"text\":\"%s\"}>ET"), extractedNumber_c);
    SerialPort.write(TxData);
    delay(10);
    snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_text\",\"type\":\"label\",\"widget\":\"label23\",\"text\":\"%s\"}>ET"), extractedNumber_c);  //Envio de trama al label de lectura
    SerialPort.write(TxData);
    delay(10);
    memset(RxData, '\0', sizeof(RxData));

    return;
  }

  if ((RxData[1] == '5') && (RxData[2] == '7')) {

    enviarSP_omega(omega3, extractedNumber);  // Valor de SP leido en el edit widget  -- PID menu
    snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_text\",\"type\":\"edit\",\"widget\":\"ze55\",\"text\":\"%s\"}>ET"), extractedNumber_c);
    SerialPort.write(TxData);
    delay(10);
    snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_text\",\"type\":\"label\",\"widget\":\"label24\",\"text\":\"%s\"}>ET"), extractedNumber_c);  //Envio de trama al label de lectura
    SerialPort.write(TxData);
    delay(10);
    memset(RxData, '\0', sizeof(RxData));

    return;
  }

  if ((RxData[1] == '5') && (RxData[2] == '5')) {

    enviarSP_omega(omega3, extractedNumber);  // Valor de SP leido en el edit widget  -- PID config
    snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_text\",\"type\":\"edit\",\"widget\":\"ze57\",\"text\":\"%s\"}>ET"), extractedNumber_c);
    SerialPort.write(TxData);
    delay(10);
    snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_text\",\"type\":\"label\",\"widget\":\"label24\",\"text\":\"%s\"}>ET"), extractedNumber_c);  //Envio de trama al label de lectura
    SerialPort.write(TxData);
    delay(10);
    memset(RxData, '\0', sizeof(RxData));

    return;
  }

  if ((RxData[1] == '5') && (RxData[2] == '6')) {  //mfc



    extractedNumber_f = convertBytesToFloat(byteArray);  // en caso de que se requiera un valor flotante
    Serial.println(extractedNumber_f);

    if (extractedNumber_f == 0.0) {
      Serial.println("Valvula cerrada");
      valveClose = true;
      tCierre = millis();
    } else {
      valveClose = false;
    }

    dtostrf(extractedNumber_f, 5, 1, extractedNumber_c);  //Convierte float en cadena
    Serial.println(extractedNumber_c);


    snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_text\",\"type\":\"edit\",\"widget\":\"ze56\",\"text\":\"%s\"}>ET"), extractedNumber_c);
    SerialPort.write(TxData);
    delay(10);


    enviarFlujoDeseado(pinSalida, extractedNumber_f);  //Envia un valor de voltaje segun el valor deseado



    return;
  }

  delay(10);

  return;
}
