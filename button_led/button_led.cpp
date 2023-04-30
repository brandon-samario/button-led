#include "button_led.h" //include button led

Button::Button(int p, unsigned long delay) { //button
  pin = p; //pin equal p
  debounceDelay = delay; //debounce delay equal delay value
  lastDebounceTime = 0; //previous debounce time
  state = LOW; //state value
  lastButtonState = LOW; //previous button state
}

int Button::read() { //read button
  int reading = digitalRead(pin); //read value of button
  if (reading != lastButtonState) { //read last button state (!=NOT)
    lastDebounceTime = millis(); //lasty debounce time in milli
  }
  if ((millis() - lastDebounceTime) > debounceDelay) { //check last debounce time if greater than debounce delay
    if (reading != state) { //read button state (!=NOT)
      state = reading; //reading button state
      if (state == HIGH) { //button state ast high
        return 1; //return value
      }
    }
  }
  lastButtonState = reading; //read last button state
  return 0; //return value
}

LED::LED(int p) { //led
  pin = p; //pin equal p
  pinMode(pin, OUTPUT); //pin set as output
}

void LED::on() { //led on
  digitalWrite(pin, HIGH); //set pin to high (on)
}

void LED::off() { //led off
  digitalWrite(pin, LOW); //set pin to low (off)
}
