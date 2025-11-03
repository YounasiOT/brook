#include <stdio.h>

#include "brook/valve.h"

static int failures = 0;

static void expect(bool condition, const char* name) {
  if (condition) {
    printf("ok %s\n", name);
    return;
  }
  printf("FAIL %s\n", name);
  failures += 1;
}

int main() {
  BedReading dry{28, true, 0, 0};
  expect(decide_valve(dry, 35, 720) == VALVE_OPEN, "opens a dry bed inside the window");

  BedReading wet{48, true, 0, 0};
  expect(decide_valve(wet, 35, 720) == VALVE_CLOSED, "stays closed once the bed is wet enough");

  BedReading night{28, false, 0, 0};
  expect(decide_valve(night, 35, 720) == VALVE_CLOSED, "stays closed outside the window");

  BedReading long_open{28, true, 720, 0};
  expect(decide_valve(long_open, 35, 720) == VALVE_CLOSED, "closes after twelve minutes");

  BedReading unplugged{0, true, 0, 3};
  expect(decide_valve(unplugged, 35, 720) == VALVE_FAULT, "fails closed when the probe reads zero");

  return failures == 0 ? 0 : 1;
}
