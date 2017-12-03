#include <SoftwareSerial.h>
SoftwareSerial myserial(2,3); //bluetooth connected to 2,3(Rx,Tx). Rx connected to Tx, Tx connected to Rx
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  myserial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(myserial.available())
    {
    String read1=myserial.readString();//directly reads the serial buffer and converts it all to string
    Serial.print("mobile>>"+read1+"\n");
  }
  if(Serial.available())
  {
    String read2=Serial.readString();
    Serial.print("you>>"+read2+"\n");
    myserial.print(read2);    
  }
}
