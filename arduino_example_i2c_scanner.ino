#include <Wire.h>

void setup() {
//  Using serial communication 
  Serial.begin(9600);
  
//  Waiting until serial connection is available
  while (!Serial){
  }

  Serial.println ("I2C scanner. Scanning ...");
  byte count = 0;  
  Wire.begin();
  for (byte i = 1; i < 120; i++)
  {
    Wire.beginTransmission (i);
    if (Wire.endTransmission () == 0){
      Serial.print ("Found address: ");
      Serial.print (i, DEC);
      Serial.print (" (0x");
      Serial.print (i, HEX);
      Serial.println (")");
      count++;
      delay (10);
    }
  }
  
  Serial.println ("Done.");
  Serial.print ("Found ");
  Serial.print (count, DEC);
  Serial.println (" device(s).");
}  // end of setup

void loop() {

}
