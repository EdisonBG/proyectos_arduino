float convertBytesToFloat(byte byteArray[]) {
    union {
        float value;
        uint8_t bytes[4];
    } converter;

    // Invertir el orden de los bytes si es necesario (LSB o MSB)
    converter.bytes[0] = byteArray[3];
    converter.bytes[1] = byteArray[2];
    converter.bytes[2] = byteArray[1];
    converter.bytes[3] = byteArray[0];

    // Retorna el valor reinterpretado como float.
    return converter.value;
}