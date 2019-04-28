int TriggerPIN1 = 6;
int EchoPIN1 = 7;
int TriggerPIN2 = 9;
int EchoPIN2 = 8;
int TriggerPIN3 = 5;
int EchoPIN3 = 4;
void setup()
{
  pinMode(TriggerPIN1,OUTPUT);
  pinMode(EchoPIN2,INPUT);
  pinMode(TriggerPIN2,OUTPUT);
  pinMode(EchoPIN2,INPUT);
   pinMode(TriggerPIN3,OUTPUT);
  pinMode(EchoPIN3,INPUT);
  pinMode( 3 , OUTPUT);
  Serial.begin(9600); 
}
  void loop()
  {
   int ult1=loop1();
   int ult2=loop2();
   int ult3=loop3();
   delay(5000);
    if(ult1>ult2 && ult1>ult3)
    {
      Serial.println("Ultrasonic sensor1=");
      Serial.println(ult1);
      Serial.println("move left");
      analogWrite( 3 , 153 );  // 60% duty cycle
      delay(500);             // play for 0.5s
      analogWrite( 3 , 0 );    // 0% duty cycle (off)
      delay(40);
      
    //  delay(5000);
    }
    
    else if(ult2>ult3)
    {
    
       Serial.println("Ultrasonic sensor2=");
      Serial.println(ult2);
       Serial.println("move stright");
       analogWrite( 3 , 153 );  // 60% duty cycle
  delay(500);              // play for 0.5s

  analogWrite( 3 , 0 );    // 0% duty cycle (off)
  delay(80);
   analogWrite( 3 , 153 );  // 60% duty cycle
  delay(500);              // play for 0.5s

  analogWrite( 3 , 0 );    // 0% duty cycle (off)
  delay(80);
      //delay(5000);
    }
   else 
   {
   
     Serial.println("Ultrasonic sensor3=");
      Serial.println(ult3);
      Serial.println("move right");
      analogWrite( 3 , 153 );  // 60% duty cycle
  delay(500);              // play for 0.5s

  analogWrite( 3 , 0 );    // 0% duty cycle (off)
  delay(40);
   analogWrite( 3 , 153 );  // 60% duty cycle
  delay(500);              // play for 0.5s

  analogWrite( 3 , 0 );    // 0% duty cycle (off)
  delay(40);
   analogWrite( 3 , 153 );  // 60% duty cycle
  delay(500);              // play for 0.5s

  analogWrite( 3 , 0 );    // 0% duty cycle (off)
  delay(40);
      //delay(500);
   }
    
  }

int loop1(){  
  digitalWrite(TriggerPIN1,LOW);
  delayMicroseconds(2);
  digitalWrite(TriggerPIN1,HIGH);
  delayMicroseconds(15);
  digitalWrite(TriggerPIN1,LOW);
  delayMicroseconds(10);

  long timedelay = pulseIn(EchoPIN1,HIGH);
  int distance1 = 0.0343 * (timedelay/2);

  Serial.print("Distance1 = ");
  if (distance1 >= 20 || distance1 <= 2)   
  {
     Serial.println("Out of range");
  }
  else {   
    Serial.print(distance1);    
    Serial.println(" cm");

    return distance1;
    delay(500);
    
  }
  //loop2();
 
}
  //delayMicroseconds(2);
 int loop2()
  {
  digitalWrite(TriggerPIN2,LOW);
  delayMicroseconds(2);
  digitalWrite(TriggerPIN2,HIGH);
  delayMicroseconds(15);
  digitalWrite(TriggerPIN2,LOW);
  delayMicroseconds(10);

  long td = pulseIn(EchoPIN2,HIGH);
  int distance2 = 0.0343 * (td/2);

//  Serial.print("Sensor 2 : ");
//  Serial.println(distance2);
Serial.print("Distance2 = ");
  if (distance2 >= 20 || distance2 <= 2)       
  {
     
         Serial.println("Out of range");
  }
  else {  
     Serial.print(distance2);    
    Serial.println(" cm");
    
    return distance2;
    
    delay(5000);
  }
    //loop3();
    
  }

  int loop3(){  
  digitalWrite(TriggerPIN3,LOW);
  delayMicroseconds(2);
  digitalWrite(TriggerPIN3,HIGH);
  delayMicroseconds(15);
  digitalWrite(TriggerPIN3,LOW);
  delayMicroseconds(10);

  long timedelay = pulseIn(EchoPIN3,HIGH);
  int distance3 = 0.0343 * (timedelay/2);

//  Serial.print("Sensor 3 : ");
//  Serial.println(distance3);
Serial.print("Distance3 = ");
  if (distance3>= 20 || distance3<= 2)   
  {
     Serial.println("Out of range");
  }
  else {   
    Serial.print(distance3);    
    Serial.println(" cm");
   
    return distance3;
    delay(5000);
  }
  

  }
  
