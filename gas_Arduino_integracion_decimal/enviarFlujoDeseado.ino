void enviarFlujoDeseado(int pinSalida, float flujoDeseado) {
    //flujo deseado esta en el rango de 0-100 LPM? --- Esta limitado por el label edit de la pantalla pero se deja para evitar fallas inesperadas 
    if (flujoDeseado < 0) flujoDeseado = 0;
    if (flujoDeseado > 100) flujoDeseado = 100;

    // Convertir LPM a valor analógico (0-5V corresponde a 0-255 para PWM)
    float valorAnalogico = (flujoDeseado * 255.0) / 100.0;
    Serial.println(valorAnalogico);
    analogWrite(pinSalida, (int)valorAnalogico); // Enviar el valor al pin
}