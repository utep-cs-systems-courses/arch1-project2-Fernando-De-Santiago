# makfile configuration
COMMON_OBJECTS  =

CPU             = msp430g2553

CFLAGS          = -mmcu=${CPU} -I../h

LDFLAGS		= -L/opt/ti/msp430_gcc/include

#switch the compiler (for the internal make rules)

CC              = msp430-elf-gcc
AS              = msp430-elf-as

all: Toy.elf

#additional rules for files

Toy.elf: ${COMMON_OBJECTS} buzzer.o p2_interrupt_handler.o switches.o button.s Toy.o stateMachines.o led.o wdInterruptHandler.o ../lib/libTimer.a
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^

load: Toy.elf
	msp430loader.sh Toy.elf

clean:
	rm -f *.o *.elf *~

led.o: led.c led.h

wdInterruptHandler.o: stateMachines.h

stateMachines.o: led.h stateMachines.h

buzzer.o: buzzer.h

Toy.o: buzzer.h
