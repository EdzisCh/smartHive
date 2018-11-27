#include "Wire.h"

void setup() {
  Wire.begin();
  Wire.begin();        // подключиться к шине i2c (адрес для мастера не обязателен)
  Serial.begin(9600);  // настроить последовательный порт для вывода
}

void loop() {
  Wire.requestFrom(2, 6); //length of bytes   // запросить 6 байтов от ведомого устройства #2

  while(Wire.available())    // ведомое устройство может послать меньше, чем запрошено
  { 
    //byte to float 
    char c = Wire.read();    // принять байт как символ
    Serial.print(c);         // напечатать символ
  }

  delay(1000);
}
