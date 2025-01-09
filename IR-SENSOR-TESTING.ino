/*
 * WRITTEN BY @twentyfivefishinthetoilet
 * GITHUB: https://github.com/twentyfivefishinthetoilet
 * WRITTEN FOR FWC'S SCIENCE FAIR IN 2025.
 *
 * COMMENTS ARE SPREAD THROUGHOUT THE CODE FOR ANYONE WHO WOULD WANT A BETTER UNDERSTANDING.
 */

#include <IRremote.h>
#include <Servo.h>

#define MACRO_NAME(name) #name // GET THE NAME OF A MACRO

// EVERYTHING STARTED WITH DEFINE BELOW THIS LINE IS A BUTTON ON THE REMOTE.
// -------------------------------------------------------------------------
#define ON 0xFFA25D
#define TIMER 0xFF629D
#define OFF 0xFFE21D
// ------------------------------
// WILL BE USED FOR PRESET ANGLES
// ------------------------------
#define BTN_1 0x36113D
#define BTN_2 0x37111D
#define BTN_3 0x36912D
#define BTN_4 0x37910D
#define BTN_5 0x365135
#define BTN_6 0x375115
#define BTN_7 0x36D125
#define BTN_8 0x37D105
#define BTN_9 0x363139
#define BTN_0 0x373119
#define CENTER_BTN 0x36C127
// ------------------------------
// USED FOR PRECISE ANGLES
// ------------------------------
#define DOWN 0x37A10B
#define UP 0x36812F
#define LEFT 0x37810F
#define RIGHT 0x364137
#define REPEATED_SIGNAL 0xFFFFFFFF
// ------------------------------
// DEBUGGING
// ------------------------------
#define BTN_C 0x37191C
#define SEL 0x366133
// ------------------------------
// -------------------------------------------------------------------------


double buttons[50] = {BTN_1, BTN_2, BTN_3, BTN_4, BTN_5, BTN_6, BTN_7, BTN_8, BTN_9, BTN_0, UP, DOWN, LEFT, RIGHT, CENTER_BTN}; // ALL OF THE BUTTONS IN A LIST

// DEFINING VARIABLES USED IN THE CODE. PIN INIT, SERVOS AND THEIR POSITIONS, AND IR VARIABLES
const uint8_t leftPin = 3;
const uint8_t rightPin = 4;
const uint8_t centerPin = 5;
const uint8_t RECV_PIN = 13;

uint8_t pos = 0;
int posc = 0;
uint8_t resetPos = 0;
uint8_t add_sub_val = 5;
bool jefferybool = false;

IRrecv irrecv(RECV_PIN);
decode_results results;
Servo servo_left;
Servo servo_right;
Servo servo_c;

// WHEN YOU START THE CODE, IMMEDIATELY DO THIS.
void setup() {
  Serial.begin(9600); // DEBUG WINDOW INIT
  
  // INITIALIZING THE SERVOS
  servo_left.attach(leftPin);
  servo_right.attach(rightPin);
  servo_c.attach(centerPin);
  
  // WRITING STARTING POSITIONS TO THE SERVOS
  servo_left.write(pos);
  servo_right.write(180 - pos); 
  servo_c.write(90);

  // IR RECIEVER INITIALIZATION
  irrecv.enableIRIn();
}

// KEEP REPEATING THIS WHILE THE ARDUINO IS RUNNING.
void loop() {
  if (irrecv.decode(&results)) { // ALL FUNCTIONS GO IN HERE!!
    Serial.println(results.value, HEX); // PRINTING TEXT TO THE DEBUG WINDOW

    // IN ENGLISH: IF THIS BUTTON IS PRESSED, INCREASE THE ANGLE BY 5.
    //             IF THE POSITION IS ABOVE OR EQUAL TO 90, THEN LOCK SERVO IN PLACE, DON'T LET IT OPEN ANYMORE.
    if (results.value == buttons[10]) { // UP
      if (pos >= 90) {
        pos = 90;
        Serial.println("MAX POS REACHED!");
      } else {
        Serial.println("ADDING TO POS...");
        pos += add_sub_val;
        servo_left.write(pos);
        servo_right.write(180 - pos); 
      }
      Serial.print("UP (");
      Serial.print(pos);
      Serial.println(")");
    }

    
    // IN ENGLISH: IF THIS BUTTON IS PRESSED, DECREASE THE ANGLE BY 5.
    //             IF THE POSITION IS BELOW OR EQUAL TO 0, THEN LOCK SERVO IN PLACE, DON'T LET IT CLOSE ANYMORE.
    else if (results.value == buttons[11]) { // DOWN
      if (pos <= 0) {
        pos = 0;
        Serial.println("MIN POS REACHED!");
      } else {
        Serial.println("SUBTRACTING FROM POS...");
        pos -= add_sub_val;
        servo_left.write(pos);
        servo_right.write(180 - pos);
      }
      Serial.print("DOWN (");
      Serial.print(pos);
      Serial.println(")");
    }

    
    // IN ENGLISH: IF THIS BUTTON IS PRESSED, SNAP THE CLAW OPEN OR SHUT, DEPENDING ON THE BOOLEAN.
    else if (results.value == buttons[14]){
      if (jefferybool){
        Serial.println("CLOSED!");
        Serial.print(MACRO_NAME(jefferybool));
        Serial.print(": ");
        Serial.println(jefferybool);
        pos = 0;
        servo_left.write(pos);
        servo_right.write(180 - pos);
        jefferybool = false;
        delay(500);
      } 
      else if (jefferybool == false){
        Serial.println("OPEN!");
        Serial.print(MACRO_NAME(jefferybool));
        Serial.print(": ");
        Serial.println(jefferybool);
        pos = 90;
        servo_left.write(pos);
        servo_right.write(180 - pos);
        jefferybool = true;
        delay(500);
      }
    }

    else {
      Serial.println("UNKNOWN SIGNAL.");
    }
    irrecv.resume(); // CONTINUE RECEIVING BUTTON SIGNALS 
  }

  
  // IN ENGLISH: IF THIS BUTTON IS PRESSED, SPIN THE SERVO BY 1 EVERY MILLISECOND.
  //             IF THE POSITION IS GREATER THAN 500, STOP SPINNING THE SERVO.
  if (results.value == LEFT) { 
    if (posc < 500) {
      servo_c.write(75);
      posc++;
      Serial.println(posc);
    } else {
      servo_c.write(90);
    }
  }
   
  // IN ENGLISH: IF THIS BUTTON IS PRESSED, SPIN THE SERVO BY -1 EVERY MILLISECOND.
  //             IF THE POSITION IS LESS THAN 100, STOP SPINNING THE SERVO.
  else if (results.value == RIGHT) { 
    if (posc > 100) {
      servo_c.write(110);
      posc--;
      Serial.println(posc);
    } else {
      servo_c.write(90);
    }
  } else if (results.value == SEL) {
    servo_c.write(90); 
    posc = 300; 
  }

}
