#include <msp430.h>
#include "stateMachines.h"
#include "led.h"

char unsigned red_on=0, green_on=0, led_changed=0;

char toggle_red()		/* always toggle! */
{
  static char state = 1;

  switch (state) {
  case 0://red light on
    red_on = 1;
    state = 1;
    break;
  case 1://turns red light off
    red_on = 0;
    state = 0;
    break;
  }
  return 1;			/* always changes an led */
}

char toggle_green()	/* only toggle green if red is on!  */
{
  char changed = 1;
  if (red_on) {
    green_on ^= 1;
    changed = 1;
  }
  return changed;
}


void state_advance()		/* alternate between toggling red & green */
{
  char changed = 0;  

  static enum {R=0, G=1} color = G;
  switch (color) {
  case R: changed = toggle_red(); color = G; break;
  case G: changed = toggle_green(); color = R; break;
  }

  led_changed = changed;
  led_update();
}



