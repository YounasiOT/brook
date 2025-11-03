#include <Arduino.h>

#include "brook/valve.h"

namespace {
constexpr uint8_t kValvePin = 4;
constexpr uint8_t kDryLine = 35;
constexpr uint16_t kMaxOpenS = 12 * 60;
}

void setup() {
  pinMode(kValvePin, OUTPUT);
  digitalWrite(kValvePin, LOW);
}

void loop() {
  BedReading reading{28, true, 0, 0};
  ValveDecision decision = decide_valve(reading, kDryLine, kMaxOpenS);
  digitalWrite(kValvePin, decision == VALVE_OPEN ? HIGH : LOW);
  delay(1000);
}
