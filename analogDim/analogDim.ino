// Dimming Light Program
// Talon Huang
// AT Computer Science

void setup() 
{
   pinMode(9, OUTPUT); //Set up Pin 9 to be our output
}

const int ledPin = 9;//set the pin number of the LED

void dims(int i)//create an analog method to dim the light
{
  analogWrite(ledPin, i);   // turn the LED on (HIGH is the voltage level)
  delay(15);
}

void loop() 
{
  // put your main code here, to run repeatedly:
  for(int a=0; a<256; a++)
  {
    dims(a); //Increasing Loop
  }
  for(int a=255; a>0; a--)
  {
    dims(a); //Decreasing Loop
  }
}
