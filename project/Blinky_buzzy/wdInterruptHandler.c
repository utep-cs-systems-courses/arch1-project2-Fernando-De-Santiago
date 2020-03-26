#include <msp430.h>
#include "stateMachines.h"
#include "led.h"

void __interrupt_vec(WDT_VECTOR) WDT(){/* 250 interrupts/sec */
  static char blink_count = 0;
  if (++blink_count==10)
  {//speed of lights to change color
    state_advance();
    blink_count = 0;
  }
}
