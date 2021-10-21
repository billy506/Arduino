// ButtonDim Program
// By Talon Huang
// AT Computer Science
// constants won't change. They're used here to set pin numbers:
const int buttonPin = 4;     // the number of the pushbutton pin
const int ledPin1 =  8;      // the number of the LED pin 1
const int ledPin2 =  9;      // the number of the LED pin 2
const int ledPin3 =  10;     // the number of the LED pin 3
const int ledPin4 =  11;     // the number of the LED pin 4
boolean ledOn = false;
boolean lastButton = LOW;
boolean currentButton = LOW;

// variables will change:
void setup() {
  // initialize the LED pins as an output:
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin4, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
}

void dims(int i)//create an analog method to dim the light
{
  analogWrite(ledPin1, i);   // turn the LED on (HIGH is the voltage level)
  analogWrite(ledPin2, i);
  analogWrite(ledPin3, i);
  analogWrite(ledPin4, i);
  delay(10);
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

  /*ButtonCheck*/           currentButton = debounce(lastButton);
                            if (currentButton == HIGH && lastButton == LOW ) 
                            {
                               ledOn = true;
                            }

                            lastButton = currentButton;
                            
  while(ledOn){
  
      /*Increasing Loop*/ for(int a=0; a<255; a++)
                          {
                            currentButton = debounce(lastButton);
                            if (!ledOn || debounce(lastButton) == HIGH)
                            {
                               ledOn=!ledOn;
                               lastButton = currentButton;
                               break;
                            }
                              dims(a);
                          }

                          
      /*Decreasing Loop*/ for(int a=255; a>0; a--)
                          {
                            currentButton = debounce(lastButton);
                            if (!ledOn || debounce(lastButton) == HIGH)
                            {
                               ledOn=!ledOn;
                               lastButton = currentButton;
                               break;
                            }
                              dims(a);
                          }

  }
 }
