// motor controller pins
const int ENA = 6;
const int IN1 = 7;
const int IN2 = 9;
const int ENB = 3;
const int IN3 = 5;
const int IN4 = 4;


// different speeds
const int FAST = 255;
const int REGULAR = 127;
const int SLOW = 50;



void setup() {
  // setup motor pins
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}


void loop() {
  drive(FAST);
  delay(1000);
  
  turn(FAST);
  delay(500);
  
  drive(REGULAR);
  delay(1000);
  
  stop_all();
  
  delay(3000);
}



// drive both motors at speed
void drive(int speed) {
  go(0, speed);
  go(1, speed);
}


// 255 is turn right, -255 is turn left
void turn(int direction) {
  go(0, -direction);
  go(1, direction);
}


// turns on a motor gives the speed
// 1 is left, 0 is right
void go(int motor, int speed) {
  analogWrite((motor ? ENA : ENB), abs(speed));
  digitalWrite((motor ? IN1 : IN3), (speed>0 ? HIGH : LOW));
  digitalWrite((motor ? IN2 : IN4), (speed>0 ? LOW : HIGH));
}


// turns off a motor
void stop(int motor) {
    go(motor, 0);
}


// turns off all motors
void stop_all() {
    stop(0);
    stop(1);
}