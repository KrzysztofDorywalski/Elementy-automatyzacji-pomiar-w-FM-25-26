int IN1 = 8;
int IN2 = 9;
int IN3 = 10;
int IN4 = 11;

int krok[4][4] = {
  {1,0,1,0},
  {0,1,1,0},
  {0,1,0,1},
  {1,0,0,1}
};

void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}

void loop() {
  for(int i = 0; i < 4; i++){
    digitalWrite(IN1, krok[i][0]);
    digitalWrite(IN2, krok[i][1]);
    digitalWrite(IN3, krok[i][2]);
    digitalWrite(IN4, krok[i][3]);
    delay(50); // prędkość
  }
}
