void action() {

  //Serial.print(RxData[0]);
  //Serial.print(RxData[1]);
  //Serial.print(RxData[2]);
  //Serial.println(RxData[3]);


  switch (RxData[0]) {


    case 'r':

      memoriasPID();    //Función para los radius button usados en las memorias PID

      break;

    case 'b':

      botones(RxData); //Funcion para los botones destinados a alguna función diferente al cambio de ventana.


      break;

    case 'e':

      actValores(); // Funcion para los edits (labels editables), usados para actualizar valores o configuraciones

      break;

    case 's':

      dispConectados(); //Funcion para los switch, usados para activar o desactivar funciones como la grafica, guardado de datos u omegas.

      break;

    case 'c':
      check_button();  //Funcion para los check button usados en la grafica
      //Serial.println(RxData);
      break;

    case 'd':  // Este case es usado para almacenar las horas y minutos que se van a mostrar en el eje x de la grafica
      
      for (int s = 15; s < 23; s++) {  //Posiciones en donde se almacena la hora en Rxdata al recibir el return del reloj
        hora_s[s - 15] = RxData[s];  //Copia en el vector hora_s la hora enviada por la pantalla y almacenada por RxData
      }
      memset(RxData, '\0', sizeof(RxData));  // Funcion para vaciar el buffer RxData
      break;

    default:
      memset(RxData, '\0', sizeof(RxData));  // En caso de no ser ninguna de las opciones borra el buffer 
  }
}