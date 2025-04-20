#include <Servo.h>
#include <SoftwareSerial.h>

SoftwareSerial mySerial(10, 11); // RX, TX

String readString;
Servo ms,door;


void setup()
{
  Serial.begin(9600);           //Set rate for communicating with phone
  ms.attach(9)  ; 
  door.attach(11);
  ms.write(0);
  door.write(0)  ; 
}
void loop()
{
  while(Serial.available())    //Check if there are available bytes to read
  {
    delay(10);                 //Delay to make it stable
    char c = Serial.read();    //Conduct a serial read
    if (c == '#'){
      break;                   //Stop the loop once # is detected after a word
    }
    readString += c;                //Means readString = readString + c
  }
    if (readString.length() >0)
    {
      Serial.println(readString);
                  
     if(readString == "f success"){
       ms.write(90);
       delay(1000);
       door.write(90);
        delay(3000);
        
        door.write(0);
        delay(1000);
        ms.write(0);
      }
      readString="";
    }
}

