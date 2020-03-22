#include <msp430.h>
#include "led.h"
#include "switches.h"
#include "buzzer.h"
static char redVal[] = {0, LED_RED}, greenVal[] = {0, LED_GREEN};


void led_init()
{
  P1DIR |= LEDS;		// bits attached to leds are output
  switch_state_changed=1;
  led_update();
}

void led_update()
{
  char ledFlags=0;
  
}

