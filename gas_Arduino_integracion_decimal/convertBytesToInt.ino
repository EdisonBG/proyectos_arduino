int convertBytesToInt(byte byteArray[]){
  int value;

  value = (byteArray[0] << 24) | (byteArray[1] << 16) | (byteArray[2] << 8) | byteArray[3];
  return value;
}