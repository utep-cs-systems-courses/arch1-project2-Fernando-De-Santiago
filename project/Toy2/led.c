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
  if (led_changed) {
    char ledFlags = redVal[red_on] | greenVal[green_on];
    
    P1OUT &= (0xff^LEDS) | ledFlags; // clear bit for off leds
    P1OUT |= ledFlags;		     // set bit for on leds
    led_changed = 0;
  }
  if (switch_state_changed) {
    char ledFlags = 0; /* by default, no LEDs on */
    ledFlags |= switch_state_down ? LED_GREEN : 0;
    ledFlags |= switch_state_down ? 0 : LED_RED;
    P1OUT &= (0xff - LEDS) | ledFlags; // clear bits for off leds
    P1OUT |= ledFlags;         // set bits for on leds
  }else if(switch_state_down1){
    char ledFlags =0;
    ledFlags |= switch_state_down1 ? 0 : 0;
    P1OUT &= (0xff - LEDS) | ledFlags;
    P1OUT |= ledFlags;
  }else if(switch_state_down2){
    buzzer_set_period(1000);
    char ledFlags = redVal[red_on] | greenVal[green_on];

    P1OUT &= (0xff) | ledFlags;
    P1OUT |= ledFlags;
  }
  switch_state_changed = 0;
}

