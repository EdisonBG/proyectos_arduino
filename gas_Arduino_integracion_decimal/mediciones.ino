void mediciones() {
  char svom[6];  // Variable para conversion de valores a char, esto debido a que al iniciar, si no se ha abierto la ventana de lecturas, el valor enviado como int no toma formato y lo toma como float con el max de decimales por defecto
  unsigned long currentMillis = millis();

  SV_OM1 = obtenerSV_omega(omega1);


  if (SV_OM1 - SV_OM1_ant > 0.5 || SV_OM1 - SV_OM1_ant < -0.5) {  //gasificador
    itoa(SV_OM1, svom, 10);
    snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_text\",\"type\":\"label\",\"widget\":\"label80\",\"text\":\"%s\"}>ET"), svom);
    SerialPort.write(TxData);
    delay(10);

    snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_text\",\"type\":\"label\",\"widget\":\"label7\",\"text\":\"%s\"}>ET"), svom);
    SerialPort.write(TxData);
    delay(10);

    SV_OM1_ant = SV_OM1;

    if (SV_OM1 <= 60) {
      snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_xy\",\"type\":\"widget\",\"widget\":\"image2\",\"x\":216,\"y\":216 }>ET"));
      SerialPort.write(TxData);
      delay(50);

      snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_xy\",\"type\":\"widget\",\"widget\":\"image3\",\"x\":216 ,\"y\":480}>ET"));
      SerialPort.write(TxData);
      delay(50);
    }

    if ((SV_OM1 >= 61) && (SV_OM1 <= 350)) {
      snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_xy\",\"type\":\"widget\",\"widget\":\"image3\",\"x\":216,\"y\":216}>ET"));
      SerialPort.write(TxData);
      delay(50);

      snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_xy\",\"type\":\"widget\",\"widget\":\"image2\",\"x\":216,\"y\":480}>ET"));
      SerialPort.write(TxData);
      delay(50);
      snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_xy\",\"type\":\"widget\",\"widget\":\"image4\",\"x\":216,\"y\":480}>ET"));
      SerialPort.write(TxData);
      delay(50);
    }

    if ((SV_OM1 >= 351) && (SV_OM1 <= 600)) {
      snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_xy\",\"type\":\"widget\",\"widget\":\"image4\",\"x\":216,\"y\":216}>ET"));
      SerialPort.write(TxData);
      delay(50);

      snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_xy\",\"type\":\"widget\",\"widget\":\"image3\",\"x\":216,\"y\":480}>ET"));
      SerialPort.write(TxData);
      delay(50);
      snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_xy\",\"type\":\"widget\",\"widget\":\"image5\",\"x\":216,\"y\":480}>ET"));
      SerialPort.write(TxData);
      delay(50);
    }

    if (SV_OM1 > 600) {
      snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_xy\",\"type\":\"widget\",\"widget\":\"image5\",\"x\":216,\"y\":216 }>ET"));
      SerialPort.write(TxData);
      delay(50);

      snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_xy\",\"type\":\"widget\",\"widget\":\"image4\",\"x\":216 ,\"y\":480}>ET"));
      SerialPort.write(TxData);
      delay(50);
    }
  }

  SV_OM2 = obtenerSV_omega(omega2);

  if (SV_OM2 - SV_OM2_ant > 0.5 || SV_OM2 - SV_OM2_ant < -0.5) {  //vapor
    itoa(SV_OM2, svom, 10);
    snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_text\",\"type\":\"label\",\"widget\":\"label81\",\"text\":\"%s\"}>ET"), svom);
    SerialPort.write(TxData);
    delay(10);

    snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_text\",\"type\":\"label\",\"widget\":\"label19\",\"text\":\"%s\"}>ET"), svom);
    SerialPort.write(TxData);
    delay(10);


    SV_OM2_ant = SV_OM2;

    if (SV_OM2 <= 60) {
      snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_xy\",\"type\":\"widget\",\"widget\":\"image6\",\"x\":177,\"y\":355}>ET"));
      SerialPort.write(TxData);
      delay(50);
      snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_xy\",\"type\":\"widget\",\"widget\":\"image7\",\"x\":177,\"y\":480}>ET"));
      SerialPort.write(TxData);
      delay(50);
    }

    if ((SV_OM2 >= 61) && (SV_OM2 <= 200)) {
      snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_xy\",\"type\":\"widget\",\"widget\":\"image7\",\"x\":177,\"y\":355}>ET"));
      SerialPort.write(TxData);
      delay(50);

      snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_xy\",\"type\":\"widget\",\"widget\":\"image6\",\"x\":177,\"y\":480}>ET"));
      SerialPort.write(TxData);
      delay(50);
      snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_xy\",\"type\":\"widget\",\"widget\":\"image8\",\"x\":177,\"y\":480}>ET"));
      SerialPort.write(TxData);
      delay(50);
    }

    if ((SV_OM2 >= 201) && (SV_OM2 <= 350)) {
      snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_xy\",\"type\":\"widget\",\"widget\":\"image8\",\"x\":177,\"y\":355}>ET"));
      SerialPort.write(TxData);
      delay(50);

      snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_xy\",\"type\":\"widget\",\"widget\":\"image7\",\"x\":177,\"y\":480}>ET"));
      SerialPort.write(TxData);
      delay(50);
      snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_xy\",\"type\":\"widget\",\"widget\":\"image9\",\"x\":177,\"y\":480}>ET"));
      SerialPort.write(TxData);
      delay(50);
    }

    if (SV_OM2 > 351) {
      snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_xy\",\"type\":\"widget\",\"widget\":\"image9\",\"x\":177,\"y\":355 }>ET"));
      SerialPort.write(TxData);
      delay(50);

      snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_xy\",\"type\":\"widget\",\"widget\":\"image8\",\"x\":177 ,\"y\":480}>ET"));
      SerialPort.write(TxData);
      delay(50);
    }
  }

  SV_OM3 = obtenerSV_omega(omega3);

  if (SV_OM3 - SV_OM3_ant > 0.5 || SV_OM3 - SV_OM3_ant < -0.5) {  //reactor
    itoa(SV_OM3, svom, 10);
    snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_text\",\"type\":\"label\",\"widget\":\"label82\",\"text\":\"%s\"}>ET"), svom);
    SerialPort.write(TxData);
    delay(10);

    snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_text\",\"type\":\"label\",\"widget\":\"label21\",\"text\":\"%s\"}>ET"), svom);
    SerialPort.write(TxData);
    delay(10);

    SV_OM3_ant = SV_OM3;

    if (SV_OM3 <= 60) {
      snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_xy\",\"type\":\"widget\",\"widget\":\"image10\",\"x\":317,\"y\":124}>ET"));
      SerialPort.write(TxData);
      delay(50);
      snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_xy\",\"type\":\"widget\",\"widget\":\"image11\",\"x\":317,\"y\":480}>ET"));
      SerialPort.write(TxData);
      delay(50);
    }

    if ((SV_OM3 >= 61) && (SV_OM3 <= 350)) {
      snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_xy\",\"type\":\"widget\",\"widget\":\"image11\",\"x\":317,\"y\":124}>ET"));
      SerialPort.write(TxData);
      delay(50);

      snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_xy\",\"type\":\"widget\",\"widget\":\"image10\",\"x\":317,\"y\":480}>ET"));
      SerialPort.write(TxData);
      delay(50);
      snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_xy\",\"type\":\"widget\",\"widget\":\"image12\",\"x\":317,\"y\":480}>ET"));
      SerialPort.write(TxData);
      delay(50);
    }

    if ((SV_OM3 >= 351) && (SV_OM3 <= 600)) {
      snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_xy\",\"type\":\"widget\",\"widget\":\"image12\",\"x\":317,\"y\":124}>ET"));
      SerialPort.write(TxData);
      delay(50);

      snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_xy\",\"type\":\"widget\",\"widget\":\"image11\",\"x\":317,\"y\":480}>ET"));
      SerialPort.write(TxData);
      delay(50);
      snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_xy\",\"type\":\"widget\",\"widget\":\"image13\",\"x\":317,\"y\":480}>ET"));
      SerialPort.write(TxData);
      delay(50);
    }

    if (SV_OM3 > 600) {
      snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_xy\",\"type\":\"widget\",\"widget\":\"image13\",\"x\":317,\"y\":124 }>ET"));
      SerialPort.write(TxData);
      delay(50);

      snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_xy\",\"type\":\"widget\",\"widget\":\"image12\",\"x\":317 ,\"y\":480}>ET"));
      SerialPort.write(TxData);
      delay(50);
    }
  }

  temp1 = leerTransmisor(transm1);  //A0 tolva

  if (temp1 - temp1_ant > 3 || temp1 - temp1_ant < -3) {
    itoa(temp1, svom, 10);
    snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_text\",\"type\":\"label\",\"widget\":\"label2\",\"text\":\"%s\"}>ET"), svom);
    SerialPort.write(TxData);
    delay(10);
    snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_text\",\"type\":\"label\",\"widget\":\"label9\",\"text\":\"%s\"}>ET"), svom);
    SerialPort.write(TxData);
    //Serial.println(temp1);
    temp1_ant = temp1;
  }



  temp2 = leerTransmisor(transm2);  // // A1 (aire entrada)

  if (temp2 - temp2_ant > 3 || temp2 - temp2_ant < -3) {
    itoa(temp2, svom, 10);
    snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_text\",\"type\":\"label\",\"widget\":\"label1\",\"text\":\"%s\"}>ET"), svom);
    SerialPort.write(TxData);
    delay(10);
    snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_text\",\"type\":\"label\",\"widget\":\"label11\",\"text\":\"%s\"}>ET"), svom);
    SerialPort.write(TxData);
    //Serial.println(temp2);
    temp2_ant = temp2;
  }

  temp3 = leerTransmisor(transm3);  // A2 cenizas
  if (temp3 - temp3_ant > 3 || temp3 - temp3_ant < -3) {
    itoa(temp3, svom, 10);
    snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_text\",\"type\":\"label\",\"widget\":\"label4\",\"text\":\"%s\"}>ET"), svom);
    SerialPort.write(TxData);
    delay(10);
    snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_text\",\"type\":\"label\",\"widget\":\"label13\",\"text\":\"%s\"}>ET"), svom);
    SerialPort.write(TxData);
    //Serial.println(temp3);
    temp3_ant = temp3;
  }

  temp4 = leerTransmisor(transm4);  //A3 ciclon
  if (temp4 - temp4_ant > 3 || temp4 - temp4_ant < -3) {
    itoa(temp4, svom, 10);
    snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_text\",\"type\":\"label\",\"widget\":\"label3\",\"text\":\"%s\"}>ET"), svom);
    SerialPort.write(TxData);
    delay(10);
    snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_text\",\"type\":\"label\",\"widget\":\"label15\",\"text\":\"%s\"}>ET"), svom);
    SerialPort.write(TxData);
    //Serial.println(temp4);
    temp4_ant = temp4;
  }

  flujoActual = leerFlujo(pinFlujo);  //MFC flujo

  /*if (flujoActual < umbralMinimo) {
    flujoActual = 0;
  }

  flujoFiltrado = (alpha * flujoActual) + ((1 - alpha) * flujoFiltrado);*/

  //if (abs(flujoActual - flujo_ant) < 0.3)
  //if (!(flujoActual - flujo_ant > 0.3) || !(flujoActual - flujo_ant < -0.3))

  if (valveClose && (currentMillis - tCierre >= 20000)) {
    
    snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_text\",\"type\":\"label\",\"widget\":\"label83\",\"text\":\"0.0\"}>ET"));
    SerialPort.write(TxData);
    delay(10);
  } else {
    dtostrf(flujoActual, 5, 1, svom);
    snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_text\",\"type\":\"label\",\"widget\":\"label83\",\"text\":\"%s\"}>ET"), svom);
    SerialPort.write(TxData);
    delay(10);
  }






  /*int sumaLecturas = 0;
  int promedio = 0;

  for (int i = 0; i < 10; i++) {
    int lectura = analogRead(pinFlujo); // Leer voltaje en bits (0 a 1023)
    Serial.println(lectura);                // Imprimir cada lectura
    sumaLecturas += lectura;                // Acumular las lecturas
    delay(100);                             // Pequeña espera entre lecturas
  }

  // Calcular el promedio
  promedio = sumaLecturas / 10;

  // Imprimir el promedio
  Serial.print("Promedio de las lecturas: ");
  Serial.println(promedio);

  delay(1000);*/


  /*if (flujoActual - flujo_ant > 1 || flujoActual - flujo_ant < -1) {
    itoa(flujoActual, svom, 10);
    snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_text\",\"type\":\"label\",\"widget\":\"label83\",\"text\":\"%s\"}>ET"), svom);
    SerialPort.write(TxData);
    delay(10);
    flujo_ant = flujoActual;

  }*/
}