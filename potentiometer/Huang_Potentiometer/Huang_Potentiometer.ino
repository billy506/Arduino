//Talon Huang
//Advanced Topics CS
const int potPin = 0;

void setup() {
  // put your setup code here, to run once:
  analogReference(DEFAULT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i=0;i<5;i++)
  {
  int value = analogRead(potPin);
  Serial.print(value);
  Serial.print("   ");
  delay(500);
  }
  Serial.println("");
}
