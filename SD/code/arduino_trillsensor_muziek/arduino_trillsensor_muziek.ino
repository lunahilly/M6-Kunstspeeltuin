// Definieer de pinnummers
const int vibrationSensorPin = 2;
const int speakerPin = 8;

// Definieer de noten en duur van het nummer (Twinkel, twinkel, kleine ster)
#define NOOT_C4 261.63
#define NOOT_D4 293.66
#define NOOT_E4 329.63
#define NOOT_F4 349.23
#define NOOT_G4 392.00
#define NOOT_A4 440.00
#define NOOT_B4 493.88

// Melodie van "Twinkel, twinkel, kleine ster"
float melodie[] = {
  NOOT_C4, NOOT_C4, NOOT_G4, NOOT_G4, NOOT_A4, NOOT_A4, NOOT_G4,
  NOOT_F4, NOOT_F4, NOOT_E4, NOOT_E4, NOOT_D4, NOOT_D4, NOOT_C4,
  NOOT_G4, NOOT_G4, NOOT_F4, NOOT_F4, NOOT_E4, NOOT_E4, NOOT_D4,
  NOOT_G4, NOOT_G4, NOOT_F4, NOOT_F4, NOOT_E4, NOOT_E4, NOOT_D4,
  NOOT_C4, NOOT_C4, NOOT_G4, NOOT_G4, NOOT_A4, NOOT_A4, NOOT_G4,
  NOOT_F4, NOOT_F4, NOOT_E4, NOOT_E4, NOOT_D4, NOOT_D4, NOOT_C4
};

int nootDuren[] = {
  4, 4, 4, 4, 4, 4, 2,
  4, 4, 4, 4, 4, 4, 2,
  4, 4, 4, 4, 4, 4, 2,
  4, 4, 4, 4, 4, 4, 2,
  4, 4, 4, 4, 4, 4, 2,
  4, 4, 4, 4, 4, 4, 2
};

void setup() {
  pinMode(vibrationSensorPin, INPUT);
  pinMode(speakerPin, OUTPUT);
}

void loop() {
  // Lees de waarde van de trilsensor
  int trilWaarde = digitalRead(vibrationSensorPin);

  // Als trilling wordt gedetecteerd, speel het nummer af
  if (trilWaarde == LOW) {
    speelMelodie();
    delay(1000); // Voeg een vertraging toe om te snel triggeren te voorkomen
  }
}

void speelMelodie() {
  // Doorloop de noten en speel het nummer af
  for (int i = 0; i < sizeof(melodie) / sizeof(melodie[0]); i++) {
    int nootDuur = 1000 / nootDuren[i];
    tone(speakerPin, melodie[i], nootDuur);

    // Om de noten te onderscheiden, stel een minimale tijd tussen hen in
    int pauzeTussenNoten = nootDuur * 1.30;
    delay(pauzeTussenNoten);

    // Stop met het afspelen van de toon
    noTone(speakerPin);
  }
}
