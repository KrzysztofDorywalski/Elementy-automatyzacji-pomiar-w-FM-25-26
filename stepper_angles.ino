int IN1 = 8;
int IN2 = 9;
int IN3 = 10;
int IN4 = 11;

int krokiNaObrot = 200;

int krok[4][4] = {
  {1,0,1,0},
  {0,1,1,0},
  {0,1,0,1},
  {1,0,0,1}
};

void zrobKroki(int ile) {
  for (int i = 0; i < ile; i++) {
    for (int j = 0; j < 4; j++) {
      digitalWrite(IN1, krok[j][0]);
      digitalWrite(IN2, krok[j][1]);
      digitalWrite(IN3, krok[j][2]);
      digitalWrite(IN4, krok[j][3]);
      delay(5);
    }
  }
}

void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}

void loop() {
  zrobKroki(krokiNaObrot * 0.25); // 90°
  delay(1000);

  zrobKroki(krokiNaObrot * 0.5);  // 180°
  delay(1000);

  zrobKroki(krokiNaObrot * 0.125); // 45°
  delay(2000);
}
