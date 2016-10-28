/*

*/

// Blinking LED sleeves for a Halloween costume.

#define PUSH_BUTTON 3 // OFF or change mode
#define LED_LEFT 4 // left sleeve
#define LED_RIGHT 5 // right sleev

#define MODE_OFF 0
#define MODE_ON 1
#define MODE_ALTERNATING 2
#define MODE_ALTERNATING_SINE 3
#define MODE_COUNT 4 // the number of modes

int mode = MODE_OFF;
int delayTimeMs = 100;
bool previousPushState = false;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_LEFT, OUTPUT);
  pinMode(LED_RIGHT, OUTPUT);
}

void alternating()
{
  digitalWrite(LED_LEFT, HIGH);
  digitalWrite(LED_RIGHT, LOW);
  delay(delayTimeMs);                       // wait for a second
  digitalWrite(LED_LEFT, LOW);
  digitalWrite(LED_RIGHT, HIGH);
  delay(delayTimeMs);                       // wait for a second
}

// the loop function runs over and over again forever
void loop() {
  if (mode == MODE_OFF)
  {
    digitalWrite(LED_LEFT, LOW);
    digitalWrite(LED_RIGHT, LOW);
  }
  else if (mode == MODE_ON)
  {
    digitalWrite(LED_LEFT, HIGH);
    digitalWrite(LED_RIGHT, HIGH);
  }
  else if (mode == MODE_ALTERNATING)
  {
    delayTimeMs = 100;
    alternating();
  }
  else if (mode == MODE_ALTERNATING_SINE)
  {
    delayTimeMs = millis() % 100 + 100;
    alternating();
  }
  int pushButton = digitalRead(PUSH_BUTTON);
  if (pushButton == HIGH && previousPushState == false)
  {
    // Change mode
    mode = (mode + 1) % MODE_COUNT;
    previousPushState = true;
  }
  if (pushButton == LOW)
  {
    previousPushState = false;
  }
}
