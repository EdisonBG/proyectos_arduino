void displaytime() {
  DateTime now = reloj.now();
  dia = now.day();
  Serial.print(dia);
  Serial.print("/");
  mes = now.month();
  Serial.print(mes);
  Serial.print("/");
  anno = now.year();
  Serial.print(anno);
  Serial.print("   ");

  hora = now.hour();
  Serial.print(hora);
  Serial.print(":");
  minuto = now.minute();
  Serial.print(minuto);
  Serial.print(":");
  segundo = now.second();
  Serial.println(segundo);

  snprintf_P(hora_reloj, sizeof(hora_reloj), PSTR("%d:%d:%d"), hora, minuto,segundo);
  delay(10);
  Serial.println(hora_reloj);
  snprintf_P(fecha_reloj, sizeof(fecha_reloj), PSTR("%d/%d/%d"), dia, mes,anno);
  delay(10);
  Serial.println(fecha_reloj);
}