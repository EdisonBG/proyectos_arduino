void check_button() {


  if (RxData[1] == '0') {
    if (graficar0 == true) {
      graficar0 = false;
      //Serial.println("Grafica SV_OM1 true");
    } else {
      graficar0 = true;
      //Serial.println("Grafica SV_OM1 false");
    }
  }

  if (RxData[1] == '1') {
    if (graficar1 == true) {
      graficar1 = false;
      //Serial.println("Grafica SV_OM2 true");
    } else {
      graficar1 = true;
      //Serial.println("Grafica SV_OM2 false");
    }
  }

  if (RxData[1] == '2') {
    if (graficar2 == true) {
      graficar2 = false;
      //Serial.println("Grafica SV_OM3 true");
    } else {
      graficar2 = true;
      //Serial.println("Grafica SV_OM3 false");
    }
  }

  if (RxData[1] == '3') {
    if (graficar3 == true) {
      graficar3 = false;
      //Serial.println("Grafica temp1 true");
    } else {
      graficar3 = true;
      //Serial.println("Grafica temp1 true");
    }
  }

  if (RxData[1] == '4') {
    if (graficar4 == true) {
      graficar4 = false;
      //Serial.println("Grafica temp2 true");
    } else {
      graficar4 = true;
      //Serial.println("Grafica temp2 true");
    }
  }

  if (RxData[1] == '5') {
    if (graficar5 == true) {
      graficar5 = false;
      //Serial.println("Grafica temp3 true");
    } else {
      graficar5 = true;
      //Serial.println("Grafica temp3 true");
    }
  }

  if (RxData[1] == '6') {
    if (graficar6 == true) {
      graficar6 = false;
      //Serial.println("Grafica temp4 true");
    } else {
      graficar0 = true;
      //Serial.println("Grafica temp4 true");
    }
  }
}