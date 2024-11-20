float leerFlujo(int pinFlujo) {
  float voltaje = 0.0;
  int valorAnalogico = analogRead(pinFlujo);  // Leer el valor analógico

  // Convertir el valor del ADC a voltaje
  voltaje = valorAnalogico * (5.0 / 1024.0);

  float flujoLPM = voltaje * 20.0;  // Como la relacion es lineal (100LPM/5v = 20LPM/V) - Resolución en voltios (5v/1024 = 0.00488v por paso) - Cada paso en v a LPM (0.00488v x20lpm/v = 0.1lpm) 

  return flujoLPM;
}