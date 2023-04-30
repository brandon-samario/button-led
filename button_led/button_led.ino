/*
  The program is designed to control a set of LEDs using a push button.
  The program uses two classes, Button and LED, to control the behavior of the button and the LEDs.
  The Button class is used for reading the state of the push button and debouncing the signal to prevent certain readings.
  The constructor for the Button class takes two arguments: the pin number of the push button and the debounce delay in milliseconds.
  The read() method of the Button class reads the current state of the button and debounces the signal by waiting for a certain period of time before registering a state change.
  If the button is pressed, the read() method returns a value of 1, indicating that a button press has been detected and recieved.
  The LED class is used for controlling the behavior of the LEDs.
  The constructor for the LED class takes the pin number of the LED as an argument, and sets the pin mode to OUTPUT.
  The on() and off() methods of the LED class turn the LED on and off.
  The main, provides an array of LED objects, and the Button object is set with the pin number of the push button and a debounce delay.
  The program then enters the loop() function, which reads the state of the push button using the read() method of the Button class.
  If a button press is detected and recieved, the program rasies a variable that tracks the current LED that should be turned on, and then turns on the corresponding LED using the on() method of the LED class.
  The program then turns off all other LEDs.
  The program continues to loop and check for button presses, turning on the next LED in the sequence each time the button is pressed.
*/

#include "button_led.h" //include library

Button button(2, 50); //pb button pin and debounce time
LED leds[] = {LED(3), LED(4), LED(5), LED(6)}; //leds
int numLeds = sizeof(leds) / sizeof(LED); //number of leds
int currentLed = 0; //current led

void setup() {
  // put your setup code here once:
  Serial.begin(9600); //start serial monitor
}

void loop() {
  // put your main code here, to run repeatedly:
  int buttonState = button.read(); //read button state
  if (buttonState == 1) { //button state
    currentLed = (currentLed + 1) % numLeds; //selected led
    Serial.print("Current LED: "); //current led being used
    Serial.println(currentLed); //read led in use
  }
  for (int i = 0; i < numLeds; i++) { //number of leds
    if (i == currentLed) { //current led being used
      leds[i].on(); //turn led on
    } else {
      leds[i].off(); //turn led of
    }
  }
  delay(10); //delay time
}
