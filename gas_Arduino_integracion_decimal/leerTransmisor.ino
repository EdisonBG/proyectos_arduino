 int leerTransmisor(int transm){
 
  int valorLectura;
  float voltaje;

  valorLectura = analogRead(transm);  // Leer el valor del pin enviado
  voltaje = valorLectura * (5.0/1023.0); //Convertir lectura a voltaje
  return (int)((voltaje /5.0) *1300.0);  // Valor Convertido a temperatura y luego a entero para almacenar
}