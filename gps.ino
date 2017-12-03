//ERFINDER CODE

#include <SoftwareSerial.h>
#include <TinyGPS.h>
long lat,lon; 
SoftwareSerial GPS(2,3);
TinyGPS gps; 

String pilih;


SoftwareSerial mySerial(9, 10);

void setup()

{
  pinMode(13,OUTPUT);

mySerial.begin(9600); 
  GPS.begin(9600);
Serial.begin(9600);

RecieveMessage();

delay(100);

}

void loop()


{
  byte a;
  if(GPS.available())  
    {
   a=GPS.read();
   Serial window
   while(gps.encode(a))
   { 
    gps.get_position(&lat,&lon);
    Serial.print("Position: ");
    Serial.print("\n");
    Serial.print("lat");

    
    mySerial.print((lat*0.000001),8);
  

   mySerial.print((lon*0.000001),8); 
    Serial.print("\n"); 

    
}
}

  
  digitalWrite(13,HIGH);

if (Serial.available()>0)

switch(Serial.read())

{

case 's':

SendMessage();

break;

case 'r':

RecieveMessage();

break;

}

if (mySerial.available()>0)

{ Serial.write(mySerial.read());

pilih = mySerial.read();}

}

void SendMessage()

{

mySerial.println("AT+CMGF=1"); //Sets the GSM Module in Text Mode

delay(1000); // Delay of 1000 milli seconds or 1 second

mySerial.println("AT+CMGS=\"+917845434169\"\r"); 

delay(1000);

mySerial.print("latitude");
mySerial.print((lat*0.000001),8);
mySerial.print("   ");
mySerial.print("longitude");
 mySerial.print((lon*0.000001),8); 
mySerial.println(pilih);

delay(100);

mySerial.println((char)26);

delay(1000);

}

void RecieveMessage()

{

mySerial.println("AT+CNMI=2,2,0,0,0"); 

delay(1000);


}
