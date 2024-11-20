void activarRelePorMinutos(int minutos) {
  if (!releActivado) {  // Solo activar si el relé no está ya activado
    tiempoActivo = minutos * 60000UL;  // Convertir minutos a milisegundos
    tiempoInicio = millis();           // Guardar el tiempo de inicio
    digitalWrite(cw_rele, HIGH);       // Activar el relé
    releActivado = true;               // Cambiar el estado del relé
  }
}