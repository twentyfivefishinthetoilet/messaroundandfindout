#include <IRremote.h>
#include <Servo.h>

#define ON 0xFFA25D
#define TIMER 0xFF629D
#define OFF 0xFFE21D
#define BTN_1 0xFF22DD
#define BTN_2 0xFFC23D
#define BTN_3 0xFFE01F
#define BTN_4 0xFF906F
#define BTN_5 0xFF6897
#define BTN_6 0xFFB04F
#define BTN_7 0xFF30CF
#define BTN_8 0xFF7A85
#define DIM 0xFF10EF
#define BRIGHTEN 0xFF5AA5
#define REPEATED_VALUE 0xFFFFFFFF

const int servoPin = 3;
const int RECV_PIN = 13;
int pos = 0;
IRrecv irrecv(RECV_PIN);
decode_results results;
Servo servo;

void setup() {
  Serial.begin(9600);
  servo.attach(servoPin);
  servo.write(0);
  irrecv.enableIRIn();
}

void loop() {
  if (irrecv.decode(&results)) { // ALL FUNCTIONS GO IN HERE!!
    Serial.println(results.value, HEX);

    if (results.value == BRIGHTEN || results.value == REPEATED_VALUE) {
      Serial.println("ADDING TO POS...");
      pos += 5;
      if (pos > 180) pos = 180;
      servo.write(pos);
    } else {
      Serial.println("UNKNOWN SIGNAL...");
    }
    irrecv.resume();
  }

  delay(100);
}
