#include <SoftwareSerial.h>
SoftwareSerial mySerial(10, 11);  //TX RX

byte led = 13;


void setup() 
{
  delay(2000);  
  pinMode(led, OUTPUT);
  digitalWrite(led, LOW);
  Serial.begin(115200);  
  mySerial.begin(115200);
  Serial.println("GSM NEOWAY Start");
  Serial.println();
}

void loop() 
{ 
 if(Serial.available()) //если в мониторе порта ввели что-то
  {  
    char ch = ' ';
    String val = "";
    
    while (Serial.available()) 
     {  
       ch = Serial.read();
       val += char(ch); //собираем принятые символы в строку
       delay(5);
     }

    if(val.indexOf("callmy") > -1) // своя команда
     {  
       sms(String("Hello")); // ВПИШИТЕ НОМЕР, с которого Вы будете звонить на модуль    
     }

    else mySerial.println(val);  // передача всего, что набрано в терминале в GSM модуль
  }


 while(mySerial.available()) 
  { 
    Serial.print((char)mySerial.read());
    delay(3);
  }
} 

void sms(String text)  // отправка СМС
{
  Serial.println("Start SMS send");
  mySerial.println("AT+CMGS=+375295577829");
  delay(500);
  mySerial.print(text);
  delay(500);
  mySerial.print((char)26);
  delay(500);
  Serial.println("SMS send OK");
  delay(2000);
}
