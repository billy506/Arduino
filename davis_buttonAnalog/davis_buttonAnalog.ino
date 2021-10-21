int switchPin = 4;
int ledPin = 9;
boolean lastButton = LOW;
boolean currentButton = LOW;
boolean ledOn = false;

void setup()
{
  pinMode(switchPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

boolean debounce(boolean last)
{
  boolean current = digitalRead(switchPin);
  if (last != current)
  {
    delay(5);
    current = digitalRead(switchPin);
  }
  return current;
}

void loop()
{
  currentButton = debounce(lastButton);
  if (lastButton == LOW && currentButton == HIGH)
  {
    ledOn = !ledOn;
  }
 lastButton = currentButton;
  while (ledOn && lastButton == LOW){
  for (int i = 1; i < 255; i++)
  {
    if (!ledOn || debounce(lastButton) == HIGH)
    {
      ledOn = false;
      lastButton = currentButton;
      break;
    }
    analogWrite(5, i);
    delay(15);
  }
  for (int j = 255; j > 0; j--)
  {
    if (!ledOn || debounce(lastButton) == HIGH)
    {
      ledOn = false;
      lastButton = currentButton;
      break;
    }
    analogWrite(5, j);
    delay(15);
  }
  analogWrite(5,0);
  lastButton = HIGH;
  }

}
