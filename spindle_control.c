#include <Arduino.h>
#include <Servo.h>
Servo penServo;
#define SERVO_PIN 6
#define PEN_UP    90
#define PEN_DOWN  30

void spindle_init() {
  penServo.attach(SERVO_PIN);
  penServo.write(PEN_UP);   // Start with pen lifted
}
void spindle_set_state(uint8_t state, float rpm) {
  if (state == SPINDLE_STATE_DISABLE) {
    penServo.write(PEN_UP);    // M5 → Pen up
  } else if (state & SPINDLE_STATE_CW) {
    penServo.write(PEN_DOWN);  // M3 → Pen down
  } else {
    penServo.write(PEN_UP);    // Fallback
  }
}


void spindle_stop() {
  penServo.write(PEN_UP);      // Emergency stop = pen up
}


uint8_t spindle_get_state() {
  return SPINDLE_STATE_DISABLE; // Always say pen is up
}


void spindle_set_speed(uint8_t angle) {
  penServo.write(angle);       // Accept raw degree control (optional)
}
