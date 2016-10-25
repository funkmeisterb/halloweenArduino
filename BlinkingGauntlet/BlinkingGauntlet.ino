/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO 
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN takes care 
  of use the correct LED pin whatever is the board used.
  If you want to know what pin the on-board LED is connected to on your Arduino model, check
  the Technical Specs of your board  at https://www.arduino.cc/en/Main/Products
  
  This example code is in the public domain.

  modified 8 May 2014
  by Scott Fitzgerald
  
  modified 2 Sep 2016
  by Arturo Guadalupi
*/

#define LED_SLIDER 2
#define LED_BLINK 3

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BLINK as an output.
  pinMode(LED_SLIDER, INPUT);
  pinMode(LED_BLINK, OUTPUT);
  Serial.begin(9600);
}

// the loop function runs over and over again forever
void loop() {
  int val = analogRead(LED_SLIDER);
  float valNorm = val / 1023.0;
  int periodMaxMs = 650;
  int sleepMs = 25 + periodMaxMs * valNorm;
  analogWrite(LED_BLINK, 255);   // turn the LED on (HIGH is the voltage level)
  delay(sleepMs/2);                       // wait for a second
  analogWrite(LED_BLINK, 0);    // turn the LED off by making the voltage LOW
  delay(sleepMs/2);                       // wait for a second
  
  Serial.print("Slider value: ");
  Serial.print(valNorm);
  Serial.print("\t\tperiod: ");
  Serial.print(sleepMs);
  Serial.print(" ms\n");
}
