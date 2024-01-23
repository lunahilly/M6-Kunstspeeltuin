//deze code zorgt ervoor dat als iemand langs de beweging sensor gaat, de led lampjes 1 voor 1 gaan branden.

  bool lamps = false;

void setup()
{
  Serial.begin(115200);
  pinMode(7, INPUT); //beweging sensor
  pinMode(6, INPUT); //beweging sensor
  pinMode(2, OUTPUT); //led 1
  pinMode(3, OUTPUT); //led 2
  pinMode(4, OUTPUT); //led 3
  pinMode(5, OUTPUT); //led 4
  bool lamps = false;
}

void loop() {
    if(digitalRead(7)== HIGH && lamps == false) {
      lamps = true;
    Serial.println("Movement detected sensor back.");
    digitalWrite(5, HIGH);  
        delay(1000);  
    digitalWrite(4, HIGH);  
        delay(1000);
    digitalWrite(3, HIGH); 
    delay(1000);
    digitalWrite(2, HIGH); 
    delay(10000);

  }

  else if(digitalRead(6)== HIGH && lamps == false) {
    lamps = true;
    Serial.println("Movement detected sensor front.");
    digitalWrite(2, HIGH);  
        delay(1000);  
    digitalWrite(3, HIGH);  
        delay(1000);
    digitalWrite(4, HIGH); 
    delay(1000);
    digitalWrite(5, HIGH); 
    delay(10000);
  }
  else if( digitalRead(6)== HIGH && lamps == true){
    lamps = false;
      Serial.println("Lamps off front.");
      digitalWrite(2, LOW);
      digitalWrite(3, LOW);
      digitalWrite(4, LOW);
      digitalWrite(5, LOW);
      delay(3000);
  }
    else if( digitalRead(7)== HIGH && lamps == true){
      lamps = false;
      Serial.println("Lamps off back.");
      digitalWrite(2, LOW);
      digitalWrite(3, LOW);
      digitalWrite(4, LOW);
      digitalWrite(5, LOW);
      delay(3000);
  }
  else {
    Serial.println("Did not detect movement.");
      delay(1000);
  }
}
