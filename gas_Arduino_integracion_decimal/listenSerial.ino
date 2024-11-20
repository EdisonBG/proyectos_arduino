bool listenSerial() {

  // Leer datos disponibles de manera no bloqueante (no para la ejecucion)
  //Serial.println("Entre a listenSerial");
  //Serial.println(RxData);
  //Serial.println(extractedNumber);

  if (SerialPort.available() > 0) {  //Quedan 4 del resto despues de leer el 0x02 que indica funcion de boton
    Serial.println("Entre a condicional listenSerial");


    SerialPort.readStringUntil('z');
    SerialPort.readBytesUntil('E', RxData, 25);
    delay(50);
    Serial.println(RxData);




    if (SerialPort.available() > 4) {
      SerialPort.readStringUntil('z');
      SerialPort.readBytesUntil('E', RxData2, 25);
      //Serial.println(RxData2);
    }

    //Serial.println(RxData[0]);
    while (SerialPort.available() ) {
      SerialPort.read();
    }
    delay(100);
    return true;
  }



  return false;
}