// === Pin Definitions ===

// Driver 1 (X coil)
const int IN1_X = 12;
const int IN2_X = 13;
const int EN_X  = 11;

// Driver 1 (Y coil)
const int IN1_Y = 9;
const int IN2_Y = 8;
const int EN_Y  = 10;

// Driver 2 (Motor)
const int IN1_MOTOR = 7;
const int IN2_MOTOR = 4;
const int EN_MOTOR  = 6;

// Driver 2 (Z coil)
const int IN1_Z = 3;
const int IN2_Z = 2;
const int EN_Z  = 5;

void setup() {
  // Setup all pins
  pinMode(IN1_X, OUTPUT);
  pinMode(IN2_X, OUTPUT);
  pinMode(EN_X, OUTPUT);

  pinMode(IN1_Y, OUTPUT);
  pinMode(IN2_Y, OUTPUT);
  pinMode(EN_Y, OUTPUT);

  pinMode(IN1_MOTOR, OUTPUT);
  pinMode(IN2_MOTOR, OUTPUT);
  pinMode(EN_MOTOR, OUTPUT);

  pinMode(IN1_Z, OUTPUT);
  pinMode(IN2_Z, OUTPUT);
  pinMode(EN_Z, OUTPUT);

  // Set coil directions and disable them (no current)
  digitalWrite(IN1_X, LOW); digitalWrite(IN2_X, LOW); analogWrite(EN_X, 0);
  digitalWrite(IN1_Y, LOW); digitalWrite(IN2_Y, LOW); analogWrite(EN_Y, 0);
  digitalWrite(IN1_Z, LOW); digitalWrite(IN2_Z, LOW); analogWrite(EN_Z, 0);

  // Set motor direction
  digitalWrite(IN1_MOTOR, HIGH);
  digitalWrite(IN2_MOTOR, LOW);
}

void loop() {
  // Sinusoidal modulation for motor
  static unsigned long tStart = millis();
  float t = (millis() - tStart) / 1000.0; // Time in seconds

  // Parameters for sine wave
  float frequency = 0.2;  // 0.2 Hz = 1 cycle every 5 sec
  float amplitude = 127;  // Half of 255 (max PWM)
  float offset = 127;     // Center point of sine wave

  // Calculate sinusoidal PWM value
  int pwmValue = (int)(amplitude * sin(2 * PI * frequency * t) + offset);
  pwmValue = constrain(pwmValue, 0, 180); // Ensure within PWM range

  // Apply PWM to motor
  analogWrite(EN_MOTOR, pwmValue);
}
