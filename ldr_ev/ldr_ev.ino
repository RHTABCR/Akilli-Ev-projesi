#define led0 3
#define led1 4
#define led2 5
#define led3 6
void setup() {

    pinMode(led0,OUTPUT);
    pinMode(led1,OUTPUT);
    pinMode(led2,OUTPUT);
    pinMode(led3,OUTPUT);
    
    Serial.begin(9600);

}

void loop() {

  int isik = analogRead(A0);
  Serial.println(isik);
  delay(50);

  if(isik > 100){
    digitalWrite(led0,LOW);
    digitalWrite(led1,LOW);
    digitalWrite(led2,LOW);
    digitalWrite(led3,LOW);
  }

  if(isik < 90){
    digitalWrite(led0,HIGH);
    digitalWrite(led1,HIGH);
    digitalWrite(led2,HIGH);
    digitalWrite(led3,HIGH);
    
  }

}
