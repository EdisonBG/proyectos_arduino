void printData() {

  if (!SD.begin(pinSD)) {
    Serial.println("SD desconectada");  // Si detecta que esta desconectada no hace nada
  } else {

    if (!SD.exists("DATALOG.CSV")) {  //Si no existe el archivo lo crea
      dataLogger = SD.open("DATALOG.CSV", FILE_WRITE);
      if (dataLogger) {
        dataLogger.println(titulos);  // Envia el vector titulos.
        dataLogger.close();
        primerDato = 0;
      }

    } else {

      dataLogger = SD.open("DATALOG.CSV", FILE_WRITE);  //Si existe, abre el archivo
      Serial.println("D++");

      if (dataLogger) {
        dataLogger.println(buf); //Envia datos almacenados en el vecto buff
        dataLogger.close();
      } else {
        Serial.println("Archivo no disponible"); 
      }
    }
  }


  /*dataLogger = SD.open("DATALOG.CSV", FILE_WRITE);

  if (dataLogger) {
    dataLogger.println(buf);
    dataLogger.close();
  } else {
    Serial.println("Archivo no disponible");
  }*/
}