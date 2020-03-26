#ifndef switches_included
#define switches_included

#define SW0 BIT0/* switch1 is S1 */
#define SW1 BIT1// switch2 is S2
#define SW2 BIT2// switch3 is S3
#define SW3 BIT3// switch4 is S4
#define SWITCHES (SW0 | SW1 | SW2 | SW3)/* 4 switches on this board */

void switch_init();
void switch_interrupt_handler();

extern char switch_state_down,switch_state_down1,switch_state_down2,switch_state_down3, switch_state_changed; /* effectively boolean */

#endif // included
