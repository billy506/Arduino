// Button Program
// By Talon Huang
// AT Computer Science
// constants won't change. They're used here to set pin numbers:
const int buttonPin = 8;     // the number of the pushbutton pin
const int ledPin =  9;      // the number of the LED pin
boolean lastButton = LOW;
int ledLevel = 0;
boolean currentButton = LOW;


// variables will change:
void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
}


boolean debounce(boolean last)
{
  boolean current = digitalRead(buttonPin);
  if(last!=current)
  {
    delay(50);
    current = digitalRead(buttonPin);   
  }
  return current;
}


void loop() {
  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  currentButton = debounce(lastButton);
  if (currentButton == HIGH && lastButton == LOW ) 
  {
    ledLevel = ledLevel + 51; //switch the brightness
    lastButton = HIGH;
  } 
  lastButton = currentButton; //alternatively, change lastButton to the current state.
  if(ledLevel>255)
  {
    ledLevel=0; 
  }
  analogWrite(ledPin, ledLevel);//output
}
