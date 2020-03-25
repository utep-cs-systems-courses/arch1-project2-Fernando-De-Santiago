#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "buzzer.h"
#include "switches.h"
int Tones[]={1000,200,0,500,2000};
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
  int i=0;
  led_changed = changed;
  led_update();
  switch(button_states()){
  case 1:
    buzzer_set_period(Tones[i++]);
    break;
  case 2:
    buzzer_set_period(200);
    break;
  case 3:
    buzzer_off();
    break;
  case 4:
    buzzer_set_period(3000);
    break;
    }
}

int button_states(){
  if(switch_state_down){
   int counter=1;
    return counter;
  }else if(switch_state_down1){
    int counter=2;
    return counter;
  }else if(switch_state_down2){
    int counter=3;
    return counter;
  }else if(switch_state_down3){
    int counter=4;
    return counter;
  }
}
