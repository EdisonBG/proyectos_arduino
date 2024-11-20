void graph() {
  //Tamaño del vector x_axis es de size 80
  // numero de elementos a eliminar remove = 9
  //Serial.println("Funcion graph");

  //Serial.println(x_axis);


 /* if (cont == 0) {

    snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"get_date\",\"type\":\"digit_clock\",\"widget\":\"zdc\"}>ET"));
    SerialPort.write(TxData);
    delay(10);
    // Serial.println(TxData);
    Serial.println("Primer condicional");
    //Serial.println(RxData);

    //sprintf(TxData, "ST<{\"cmd_code\":\"set_data\",\"type\":\"x_axis\",\"widget\":\"x_axis1\",\"data\":\"[%s]\"}>ET", x_axis);
    //SerialPort.write(TxData);
    //Serial.println(TxData);
    cont++;
    return;
  }*/

  //Ciclo para correr hacia la izquierda una posicion la hora en el eje X
  for (int s = 0; s < 137; s++) {  // s = 0; s = size - remove; s++  -- s = 0; s = 143- 6 ;s++        (s=0; s<71;s++) ---> para 9 datos formato --:--:--
    x_axis[s] = x_axis[s + 6];
  }
  //hora = random(10000000, 99999999);
  //itoa(hora, hora_s, 10);


  //Comando para pedir hora a la pantalla
  snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"get_date\",\"type\":\"digit_clock\",\"widget\":\"zdc\"}>ET"));
  SerialPort.write(TxData);
  delay(10);

  Serial.println(hora_s);

  //Si se pidio la hora al menos una vez entra a este condicional, esto debido a que si entra directo el buffer RxData no tendria nada porque no se ha activado la función ListenSerial
  //Si se pone ListenSerial justo despues de enviarle el comando por alguna razón no guarda una respuesta. Se intento poner un delay mas grande de 10 pero no funciono. --- ver como se mejora 
  if (primer_dato == 1) {

    x_axis[137] = ',';

    //Se envia al vector del eje x la hora almacenada en el ciclo en la función action. Esta hora se almacena en la ultima posición del vector 
    for (int s = 138; s < 143; s++) {  // s = size - (remove-1); s < size ; s++ --- La coma se pone manual debido a que en la variable hora_s no esta incluida
      x_axis[s] = hora_s[s - (138)];   // s = 143 - 5; s 143; s++  .. x_axis[s] = hora_s[size - (remove-1)]
    }

    //Si la bandera correspondiente a cada medicion esta activa se grafica el valor, si es false se grafica un 0
    if (graficar0) { //Gasificador
      snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_value\",\"type\":\"line_series\",\"widget\":\"line_series1\",\"mode\":\"push\",\"value\":%d}>ET"), SV_OM1);
      SerialPort.write(TxData);
      Serial.println("grafica");
      delay(10);
    } else {
      snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_value\",\"type\":\"line_series\",\"widget\":\"line_series1\",\"mode\":\"push\",\"value\":0}>ET"));
      SerialPort.write(TxData);
      delay(10);
    }

    if (graficar1) { //Gen.vapor
      snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_value\",\"type\":\"line_series\",\"widget\":\"line_series2\",\"mode\":\"push\",\"value\":%d}>ET"), SV_OM2);
      SerialPort.write(TxData);
      delay(10);
    } else {
      snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_value\",\"type\":\"line_series\",\"widget\":\"line_series2\",\"mode\":\"push\",\"value\":0}>ET"));
      SerialPort.write(TxData);
      delay(10);
    }

    if (graficar2) { //Reformador
      snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_value\",\"type\":\"line_series\",\"widget\":\"line_series3\",\"mode\":\"push\",\"value\":%d}>ET"), SV_OM3);
      SerialPort.write(TxData);
      delay(10);
    } else {
      snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_value\",\"type\":\"line_series\",\"widget\":\"line_series3\",\"mode\":\"push\",\"value\":0}>ET"));
      SerialPort.write(TxData);
      delay(10);
    }

    if (graficar3) { //Tolva (Biomasa)
      snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_value\",\"type\":\"line_series\",\"widget\":\"line_series4\",\"mode\":\"push\",\"value\":%d}>ET"), temp1);
      SerialPort.write(TxData);
      delay(10);
    } else {
      snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_value\",\"type\":\"line_series\",\"widget\":\"line_series4\",\"mode\":\"push\",\"value\":0}>ET"));
      SerialPort.write(TxData);
      delay(10);
    }

    if (graficar4) { // Entrada gases
      snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_value\",\"type\":\"line_series\",\"widget\":\"line_series5\",\"mode\":\"push\",\"value\":%d}>ET"), temp2);
      SerialPort.write(TxData);
      delay(10);
    } else {
      snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_value\",\"type\":\"line_series\",\"widget\":\"line_series5\",\"mode\":\"push\",\"value\":0}>ET"));
      SerialPort.write(TxData);
      delay(10);
    }

    if (graficar5) { // Cenizas
      snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_value\",\"type\":\"line_series\",\"widget\":\"line_series6\",\"mode\":\"push\",\"value\":%d}>ET"), temp3);
      SerialPort.write(TxData);
    } else {
      snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_value\",\"type\":\"line_series\",\"widget\":\"line_series6\",\"mode\":\"push\",\"value\":0}>ET"));
      SerialPort.write(TxData);
    }

    if (graficar6) { //Ciclón
      snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_value\",\"type\":\"line_series\",\"widget\":\"line_series7\",\"mode\":\"push\",\"value\":%d}>ET"), temp4);
      SerialPort.write(TxData);
    } else {
      snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_value\",\"type\":\"line_series\",\"widget\":\"line_series7\",\"mode\":\"push\",\"value\":0}>ET"));
      SerialPort.write(TxData);
    }

    //Serial.println(RxData);

    //Comando para enviar el vector del eje x a la pantala y lo dibuje
    snprintf_P(TxData, sizeof(TxData), PSTR("ST<{\"cmd_code\":\"set_data\",\"type\":\"x_axis\",\"widget\":\"x_axis1\",\"data\":\"[%s]\"}>ET"), x_axis);
    SerialPort.write(TxData);
    //Serial.println(TxData);
  }

  primer_dato = 1; // Vuelve 1 la bandera despues de la primera iteración.
}