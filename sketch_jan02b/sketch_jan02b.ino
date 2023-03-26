/*

*/
String data;
int ac=8;
int light=9;
int fan=6;
int tv=7;
void setup()
{
   Serial.begin(9600);
 //  mySerial.begin(9600);
   
   pinMode(ac, OUTPUT);
   pinMode(light, OUTPUT);
   pinMode(fan, OUTPUT);
   pinMode(tv, OUTPUT);
 
   digitalWrite(ac, LOW);
   digitalWrite(light, LOW);
   digitalWrite(fan, LOW);
   digitalWrite(tv, LOW);
}
void loop()
{
while(Serial.available()) //Check if there are available bytes to read
{
delay(10); //Delay to make it stable
char c = Serial.read(); //Conduct a serial read
if (c == '#'){
break; //Stop the loop once # is detected after a word
}
data += c; //Means inputs = inputs + c
}
if (data.length() >0)
{

Serial.println(data);
    
if(data=="*turn on AC")
    { 
      digitalWrite(ac,HIGH);
      Serial.println("ac on");
    }
else if(data=="*turn off AC")
    {
      digitalWrite(ac,LOW);
      Serial.println("ac off");
    }
else if(data=="*turn on light")
    {
      digitalWrite(light,HIGH);
      Serial.println("light on");
    }
else if(data=="*turn off light")
    {
      digitalWrite(light,LOW);
      Serial.println("light off");
    }
else if(data=="*turn on fan")
    {
      digitalWrite(fan,HIGH);
      Serial.println("fan on");
    }
else if(data=="*turn off fan")
    {
      digitalWrite(fan,LOW);
      Serial.println("fan off");
    }
else if(data=="*turn on TV")
    {
      digitalWrite(tv,HIGH);
      Serial.println("tv on");
    }
else if(data=="*turn on TV")
    {
      digitalWrite(tv,LOW);
      Serial.println("tv off");
    }
else if(data=="*turn on all")
    {
      digitalWrite(ac,HIGH);
      digitalWrite(light,HIGH);
      digitalWrite(fan,HIGH);
      digitalWrite(tv,HIGH);
      Serial.println("all on");
    }
else if(data=="*turn off all")
    {
      digitalWrite(ac,LOW);
      digitalWrite(light,LOW);
      digitalWrite(fan,LOW);
      digitalWrite(tv,LOW);
      Serial.println("all off");
    
    }
data="";
}
}
