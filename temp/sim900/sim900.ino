#include <SoftwareSerial.h>
 
SoftwareSerial mySerial(7,8); 
 
void setup()
{
  Serial.begin(57600);
  Serial.println("Begin");
  mySerial.begin(57600);
  mySerial.print("AT+CPIN=9930");
  delay(1000);
mySerial.print("AT+CMGF=1\r");  //режим кодировки СМС - обычный (для англ.)
  delay(300);
  mySerial.println("AT+CSCS=\"GSM\"");  //режим кодировки текста
  delay(300);
   mySerial.println("AT+CMGS=\"+375295580855\"");
  delay(300);
  mySerial.print("hello");
  delay(300);
  mySerial.print((char)26);
}
 
void loop()
{
 /* if (mySerial.available())
    Serial.write(mySerial.read());
  if (Serial.available())
    mySerial.write(Serial.read());*/
}

void Sim900_SendSMS ()
{
   delay(1000);
  mySerial.print("AT+CMGF=1\r");  //режим кодировки СМС - обычный (для англ.)
  delay(300);
  mySerial.println("AT+CSCS=\"GSM\"");  //режим кодировки текста
  delay(300);
   mySerial.println("AT+CMGS=\"+375259616884\"");
  delay(300);
  mySerial.print("hello");
  delay(300);
  mySerial.print((char)26);
 
}
