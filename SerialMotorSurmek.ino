int E1=5;   //Enable pini (PWM sinyal için)
int E2=6;   

int MA1=12; // Motora Yönvermek için ayarlanana pinler
int MA2=11; // ileri-geri

int MB1=10; // Motora Yönvermek için ayarlanana pinler
int MB2=9;  // sag-sol



void setup() {
  Serial.begin(9600);//serial haberleşmeyi başlattık.
  analogWrite(E1,250); // Başlangıçta hızı 50 olacak 
  analogWrite(E2,250); // Başlangıçta hızı 50 olacak 
}

void loop() 
{
  if(Serial.available())
  {
   String s1 = Serial.readString();// s1 is String type variable.
 
    if(s1.indexOf("A1")>=0)
    {
      digitalWrite(MA1,HIGH);
      digitalWrite(MA2,LOW);
      Serial.println("Motor geri");
    }
    else if(s1.indexOf("A2")>=0)
    {
      digitalWrite(MA1,LOW); 
      digitalWrite(MA2,HIGH);
      Serial.println("Motor ileri");
    }

    else if(s1.indexOf("B1")>=0)
    {
      digitalWrite(MB1,HIGH);
      digitalWrite(MB2,LOW);
      Serial.println("Motor ileri");
    }
    else if(s1.indexOf("B2")>=0)
    {
      digitalWrite(MB1,LOW); 
      digitalWrite(MB2,HIGH);
      Serial.println("Motor geri");
    }

    else if(s1.indexOf("S")>=0)
    {
      digitalWrite(MA1,LOW); 
      digitalWrite(MA2,LOW);
      digitalWrite(MB1,LOW); 
      digitalWrite(MB2,LOW);
      Serial.println("Motor durdu");
    }
    else
    {
      Serial.print("S1:"); 
      Serial.println(s1.toInt());
      analogWrite(E1,s1.toInt());
      analogWrite(E2,s1.toInt());

    } 
  }
}
