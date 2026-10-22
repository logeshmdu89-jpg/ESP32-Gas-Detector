#define MQ2_PIN 34
#define BUZZER_PIN 25

int gasValue;
int gasThreshold = 1800;  // You can adjust this value

void setup() {
  Serial.begin(115200);

  pinMode(MQ2_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  digitalWrite(BUZZER_PIN, LOW);

  Serial.println("Gas Sensor Starting...");
  delay(20000);  // MQ-2 warm-up
  Serial.println("Ready!");
}

void loop() {

  gasValue = analogRead(MQ2_PIN);

  Serial.print("Gas Value: ");
  Serial.println(gasValue);

  if (gasValue > gasThreshold) {
    digitalWrite(BUZZER_PIN, HIGH);
    Serial.println("⚠️ GAS DETECTED! BUZZER ON");
  } 
  else {
    digitalWrite(BUZZER_PIN, LOW);
    Serial.println("Normal");
  }

  delay(500);
}