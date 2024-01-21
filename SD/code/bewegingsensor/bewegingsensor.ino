//deze code zorgt ervoor dat als iemand langs de beweging sensor gaat, de led lampjes 1 voor 1 gaan branden.



void setup()
{
  Serial.begin(115200);
  pinMode(7, INPUT); //beweging sensor
  pinMode(6, INPUT); //beweging sensor
  pinMode(2, OUTPUT); //led 1
  pinMode(3, OUTPUT); //led 2
  pinMode(4, OUTPUT); //led 3
  pinMode(5, OUTPUT); //led 4
}

void loop() {
  if(digitalRead(7)==HIGH || digitalRead(6)== HIGH) {
    Serial.println("Movement detected.");
    digitalWrite(2, HIGH);  
        delay(1000);  
    digitalWrite(3, HIGH);  
        delay(1000);
    digitalWrite(4, HIGH); 
    delay(1000);
    digitalWrite(5, HIGH); 
    delay(3000);
    digitalWrite(2,LOW);
    digitalWrite(3,LOW);
    digitalWrite(4,LOW);
    digitalWrite(5,LOW);
    delay(3000);

  } else {
    Serial.println("Did not detect movement.");
      delay(3000);
  }
}
