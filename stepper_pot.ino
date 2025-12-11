// Piny sterujące L298N
int IN1 = 8;
int IN2 = 9;
int IN3 = 10;
int IN4 = 11;

// Liczba kroków na pełen obrót silnika
int krokiNaObrot = 200; 

// Pin potencjometru
int potPin = A0;

// Sekwencja pełnokrokowa (4 kroki)
int krok[4][4] = {
  {1,0,1,0},
  {0,1,1,0},
  {0,1,0,1},
  {1,0,0,1}
};

void wykonajKrok(int numer) {
  digitalWrite(IN1, krok[numer][0]);
  digitalWrite(IN2, krok[numer][1]);
  digitalWrite(IN3, krok[numer][2]);
  digitalWrite(IN4, krok[numer][3]);
}

// Funkcja obracająca o określony kąt
void obrocKat(float kat, int kierunek) {
  int liczbaKrokow = (int)((kat / 360.0) * krokiNaObrot);

  for (int i = 0; i < liczbaKrokow; i++) {
    int idx = kierunek == 1 ? i % 4 : (3 - (i % 4));
    wykonajKrok(idx);
    delay(5); 
  }
}

void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  pinMode(potPin, INPUT);
}

void loop() {

  // Odczyt potencjometru (0–1023)
  int val = analogRead(potPin);

  // zamiana 0–1023 na kąt 0–360°
  float kat = map(val, 0, 1023, 0, 360);

  // przykładowo obracamy się zawsze w prawo
  obrocKat(kat, 1);

  delay(300); // mała pauza, by nie ruszał za często
}
