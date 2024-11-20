void deleteRx(){

  //Elimina el contenido del buffer de recepçion del puerto del arduino al leerlo.
  while(SerialPort.available() > 0){
    SerialPort.read();
  }
}