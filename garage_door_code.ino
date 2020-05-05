/*
  Garage Door Closer

  by Stuff Gets Built

  This program senses when a switch has been closed and monitors that it continues to be closed
  for 4 hours.  If, after 4 hours, the switch has been continuously closed, the program activates
  a relay through pin 3, causing the garage door to close.

  The circuit:
  - switch attached from pin 2 to ground
  - control input for solid state relay to pin 3

  This code was modified from the Arduino example "InputPullupSerial"
  created 14 Mar 2012
  by Scott Fitzgerald

  modified by Stuff Gets Built
  2 May 2020
  
*/
boolean closed ;
unsigned long start  ;
void setup() {
  //configure pin 2 as an input and enable the internal pull-up resistor
  pinMode(2, INPUT_PULLUP);
  pinMode(3, OUTPUT);

}

void loop() {
  //read the pushbutton value into a variable
  int sensorVal = digitalRead(2);
 
  // Keep in mind the pull-up means the pushbutton's logic is inverted. It goes
  // HIGH when it's open, and LOW when it's pressed. Turn on pin 3 when the
  // button's pressed, and off when it's not:
  if (sensorVal == HIGH) {
    closed = false ;
    digitalWrite(3, LOW);
  } else {
      if (closed == true){
        if (millis()-start> 14400000){   //14400000 = 4 hours
          digitalWrite(3, HIGH);
        }
       }
       else {
        closed = true  ;
        start = millis() ;
       }
    } 
}
