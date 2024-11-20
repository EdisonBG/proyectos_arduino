void createBuffer() {

  //char basura[5];


  if (primerDato == 0) {

    //Si es el primer dato de la SD se envia con la fecha y hora registrada con el RTC del datalogger
    displaytime();
    
    

    strcpy(buf, fecha_reloj);  //Primer dato
    strcat(buf, ";");         // concatena el resto de datos y unidades.

    strcat(buf, hora_reloj);
    strcat(buf, ";");  

    char omega1[7]; // Gasificador
    dtostrf(SV_OM1, 4, 0, omega1);
    strcat(buf, omega1);
    strcat(buf, ";");

    char omega2[7]; //Generador de vapor
    dtostrf(SV_OM2, 4, 0, omega2);
    strcat(buf, omega2);
    strcat(buf, ";");

    char omega3[7]; //Reformador
    dtostrf(SV_OM3, 4, 0, omega3);
    strcat(buf, omega3);
    strcat(buf, ";");

    char tempe1[7];//Tolva
    dtostrf(temp1, 4, 0, tempe1);
    strcat(buf, tempe1);
    strcat(buf, ";");

    char tempe2[7]; // Entrada aire
    dtostrf(temp2, 4, 0, tempe2);
    strcat(buf, tempe2);
    strcat(buf, ";");

    char tempe3[7]; //Cenizas
    dtostrf(temp3, 4, 0, tempe3);
    strcat(buf, tempe3);
    strcat(buf, ";");

    char tempe4[10]; //Aire
    dtostrf(temp4, 4, 0, tempe4);
    strcat(buf, tempe4);
    strcat(buf, ";");

    Serial.println(buf);
    primerDato++;
    return;
  }

  strcpy(buf, "");   //Primer dato
  strcat(buf, ";");  // concatena el resto de datos y unidades.

  strcat(buf, "");
  strcat(buf, ";");

  char omega1[7];
  dtostrf(SV_OM1, 4, 0, omega1);
  strcat(buf, omega1);
  strcat(buf, ";");

  char omega2[7];
  dtostrf(SV_OM2, 4, 0, omega2);
  strcat(buf, omega2);
  strcat(buf, ";");

  char omega3[7];
  dtostrf(SV_OM3, 4, 0, omega3);
  strcat(buf, omega3);
  strcat(buf, ";");

  char tempe1[7];
  dtostrf(temp1, 4, 0, tempe1);
  strcat(buf, tempe1);
  strcat(buf, ";");

  char tempe2[7];
  dtostrf(temp2, 4, 0, tempe2);
  strcat(buf, tempe2);
  strcat(buf, ";");

  char tempe3[7];
  dtostrf(temp3, 4, 0, tempe3);
  strcat(buf, tempe3);
  strcat(buf, ";");

  char tempe4[10];
  dtostrf(temp4, 4, 0, tempe4);
  strcat(buf, tempe4);
  strcat(buf, ";");

  Serial.println(buf);
}