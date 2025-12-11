// Piny sterujące L298N
int IN1 = 8;
int IN2 = 9;
int IN3 = 10;
int IN4 = 11;

// Liczba kroków na pełen obrót silnika
int krokiNaObrot = 200; // <-- zmień jeśli Twój silnik ma inną wartość

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
    delay(5); // prędkość — można zmieniać
  }
}

void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}

void loop() {

  // Przykłady:
  obrocKat(90, 1);   // obrót 90° w prawo
  delay(1000);

  obrocKat(180, -1); // obrót 180° w lewo
  delay(1000);

  obrocKat(360, 1);  // pełny obrót
  delay(2000);
}
