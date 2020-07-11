#include <IRremote.h>
int y;
IRrecv irrecv(2);
 decode_results R;
  
void setup()
{ Serial.begin(9600);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  irrecv.enableIRIn();
}

void loop()
{
 int  x; 
 if(irrecv.decode(&R))
 {
     x =  R.value  ; 
     Serial.println(x); 
     irrecv.resume(); 
 }
  delay(100);
  
  switch(x)
  {
   case -32641 :  if(y < 225)
                    {
                      y = y+45;
                    }
            break;
      case -28561 :  if(y > 0)
                     {
                        y = y-45;
                     } 
                  break ;                  
    case  2295 : digitalWrite(3 , HIGH);
                 digitalWrite(4 , LOW);
                 digitalWrite(6 , LOW);
                 digitalWrite(7 , LOW);
                 digitalWrite(8 , LOW);
            break;
     case  12495 :digitalWrite(3 , LOW);
                 digitalWrite(4 , LOW);
                 digitalWrite(6 , LOW);
                 digitalWrite(7 , LOW);
                 digitalWrite(8 , LOW);
            break;
    case  -30601  : digitalWrite(3 , HIGH);
                 digitalWrite(4 , HIGH);
                 digitalWrite(6 , LOW);
                 digitalWrite(7 , LOW);
                 digitalWrite(8 , LOW); 
  
           break;
    case  18615  : digitalWrite(3 , HIGH);
                 digitalWrite(4 , HIGH);
                 digitalWrite(6 , HIGH);
                 digitalWrite(7 , LOW);
                 digitalWrite(8 , LOW);
            break;
    case  10455   : digitalWrite(3 , HIGH);
                 digitalWrite(4 , HIGH);
                 digitalWrite(6 , HIGH);
                 digitalWrite(7 , HIGH);
                 digitalWrite(8 , LOW); 
  break;
    case  -22441  : digitalWrite(3 , HIGH);
                 digitalWrite(4 , HIGH);
                 digitalWrite(6 , HIGH);
                 digitalWrite(7 , HIGH);
                 digitalWrite(8 , HIGH); 
  } 
 
 analogWrite(5, y);
}


