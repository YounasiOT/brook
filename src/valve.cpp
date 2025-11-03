#include "brook/valve.h"

ValveDecision decide_valve(const BedReading& reading, uint8_t dry_line, uint16_t max_open_s) {
  if (reading.moisture_pct == 0 && reading.zero_streak >= 3) return VALVE_FAULT;
  if (!reading.window_open) return VALVE_CLOSED;
  if (reading.moisture_pct >= dry_line) return VALVE_CLOSED;
  if (reading.already_open_s >= max_open_s) return VALVE_CLOSED;
  return VALVE_OPEN;
}
