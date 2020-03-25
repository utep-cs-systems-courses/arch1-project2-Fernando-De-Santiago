#include <msp430.h>
#include "led.h"
#include "switches.h"
#include "stateMachines.h"
static char redVal[] = {0, LED_RED}, greenVal[] = {0, LED_GREEN},swapVal[]={LED_RED, 0,LED_GREEN,LED_RED};
void led_init()
{
  P1DIR |= LEDS;
  switch_state_changed=1;
  led_update();
}

void led_update()
{
  char ledFlags=0;
  switch(button_states()){
      case 1:
	if(led_changed){
	  ledFlags = redVal[red_on] | greenVal[green_on];;
	  P1OUT &= (0xff - LEDS) | ledFlags;
	  P1OUT |= ledFlags;
	}
	if (switch_state_changed){
	  ledFlags=0;
	  P1OUT &= (0xff - LEDS) | ledFlags;
	  P1OUT |= ledFlags;
	}
	break;
      case 2:
        ledFlags=LED_GREEN;
	P1OUT &= (0xff^LEDS) | ledFlags;
	P1OUT |= ledFlags;
       break;
      case 3:
	ledFlags=0;
	P1OUT &= (0xff^LEDS) | ledFlags;
	P1OUT |= ledFlags;
	break;
      case 4:
	ledFlags=LEDS;
	P1OUT &= (0xff^LEDS) | ledFlags;
	P1OUT |= ledFlags;
	break;
    }
}
