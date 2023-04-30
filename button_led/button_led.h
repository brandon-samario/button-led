#ifndef BUTTON_LED_H //if not defined
#define BUTTON_LED_H //define library

#include <Arduino.h> //include library

class Button { //pb class
  private: //private
    int pin; //pb button pin
    unsigned long lastDebounceTime; //previous debounce time
    unsigned long debounceDelay; //debounce delay
    int state; //button state
    int lastButtonState; //previous button state

  public: //public pin
    Button(int p, unsigned long delay); //button delay
    int read(); //read button
};

class LED { //led class
  private: //private
    int pin; //led pin

  public: //public
    LED(int p); //contructor
    void on(); //led on
    void off(); //led off
};

#endif
