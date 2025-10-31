#pragma once

#include <stdint.h>

struct BedReading {
  uint8_t moisture_pct;
  bool window_open;
  uint16_t already_open_s;
  uint8_t zero_streak;
};

enum ValveDecision {
  VALVE_CLOSED = 0,
  VALVE_OPEN = 1,
  VALVE_FAULT = 2,
};

ValveDecision decide_valve(const BedReading& reading, uint8_t dry_line, uint16_t max_open_s);
