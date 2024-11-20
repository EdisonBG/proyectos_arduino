void ejecutarCicloEncendidoApagado() {
  unsigned long tiempoActual = millis();

  if (estadoEncendido) {
    // Si el motor está encendido, comprobar si el tiempo de encendido ha terminado
    if (tiempoActual - tiempoInicio >= tiempoActivo) {
      digitalWrite(cw_rele, LOW);  // Apagar el motor
      estadoEncendido = false;     // Cambiar el estado a apagado
      tiempoInicio = tiempoActual; // Registrar el momento en que se apaga
    }
  } else {
    // Si el motor está apagado, comprobar si el tiempo de apagado ha terminado
    if (tiempoActual - tiempoInicio >= tiempoApagado) {
      digitalWrite(cw_rele, HIGH); // Encender el motor
      estadoEncendido = true;      // Cambiar el estado a encendido
      tiempoInicio = tiempoActual; // Registrar el momento en que se enciende
    }
  }
}