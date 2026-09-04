// === Pin Definitions ===

// Driver 1 (Motor and Z coil)
const int IN1_MOTOR = 7;
const int IN2_MOTOR = 4;
const int EN_MOTOR  = 6;

const int IN1_Z = 3;   
const int IN2_Z = 2;   
const int EN_Z  = 5;   

// Driver 2 (X and Y coils)
const int IN1_X = 12;  
const int IN2_X = 13;  
const int EN_X  = 11;  

const int IN1_Y = 9;   
const int IN2_Y = 8;   
const int EN_Y  = 10;  

void setup() {
  // Setup all pins as outputs
  pinMode(IN1_X, OUTPUT); pinMode(IN2_X, OUTPUT); pinMode(EN_X, OUTPUT);
  pinMode(IN1_Y, OUTPUT); pinMode(IN2_Y, OUTPUT); pinMode(EN_Y, OUTPUT);
  pinMode(IN1_MOTOR, OUTPUT); pinMode(IN2_MOTOR, OUTPUT); pinMode(EN_MOTOR, OUTPUT);
  pinMode(IN1_Z, OUTPUT); pinMode(IN2_Z, OUTPUT); pinMode(EN_Z, OUTPUT);

  // Set direction for all outputs (forward)
  digitalWrite(IN1_X, HIGH); digitalWrite(IN2_X, LOW);
  digitalWrite(IN1_Y, HIGH); digitalWrite(IN2_Y, LOW);
  digitalWrite(IN1_Z, HIGH); digitalWrite(IN2_Z, LOW);
  digitalWrite(IN1_MOTOR, HIGH); digitalWrite(IN2_MOTOR, LOW);

  // Constant PWM value for all outputs
  int constantPWM = 0;  // Adjust this value (0–255) as desired we used 85 170 and 255

  analogWrite(EN_X, constantPWM);
  analogWrite(EN_Y, constantPWM);
  analogWrite(EN_Z, constantPWM);
  analogWrite(EN_MOTOR, constantPWM);
}

void loop() {
  // Nothing needed – outputs are constant
}
