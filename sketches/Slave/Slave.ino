#include "HX711.h" 
#include "Wire.h"

#define ID 1
#define DOUT  3 //!
#define CLK  2  //!
 
HX711 scale(DOUT, CLK);
float calibration_factor = -144;

int timeCount=0;

void setup() {
  Serial.begin(9600);
  Wire.begin(2); 
  Wire.onRequest(getWeight);
  scale.set_scale(calibration_factor);
  scale.tare();
  long zero_factor = scale.read_average();
  Serial.println("OK");
}

void loop() {
  Serial.println(scale.get_units());
  scale.get_units();
  delay(1000);  
}

byte getWeight(){
  //float to string need
  Wire.write();
}

