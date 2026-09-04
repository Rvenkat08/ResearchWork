 // === Pin Definitions ===

// Driver 1 (Motor and Z coil)
const int IN1_MOTOR = 7;
const int IN2_MOTOR = 4;
const int EN_MOTOR  = 6;

const int IN1_Z = 3;   // Z coil IN3 on driver (confirmed)
const int IN2_Z = 2;   // Z coil IN4 on driver (confirmed)
const int EN_Z  = 5;   // ENB for Z coil

// Driver 2 (X and Y coils)
const int IN1_X = 12;  // X coil IN1
const int IN2_X = 13;  // X coil IN2
const int EN_X  = 11;  // ENA for X coil

const int IN1_Y = 9;   // Y coil IN3
const int IN2_Y = 8;   // Y coil IN4
const int EN_Y  = 10;  // ENB for Y coil

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
}

void loop() {
  // Sinusoidal modulation for all outputs
  static unsigned long tStart = millis();
  float t = (millis() - tStart) / 1000.0; // Time in seconds

  // Parameters for sine wave
  float frequency = 0.2;  // 0.2 Hz = 1 cycle every 5 sec
  float amplitude = 127;  // Half of 255 (max PWM)
  float offset = 127;     // Center point of sine wave

  // Calculate sinusoidal PWM value
  int pwmValue = (int)(amplitude * sin(2 * PI * frequency * t) + offset);
  pwmValue = constrain(pwmValue, 0, 85); // Ensure within PWM range 85, 170, 255

  // Apply PWM to all outputs
  analogWrite(EN_X, pwmValue);
  analogWrite(EN_Y, pwmValue);
  analogWrite(EN_Z, pwmValue);
  analogWrite(EN_MOTOR, 0);
}
