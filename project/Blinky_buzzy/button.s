	.arch msp430g2553
	.text
jt: 				;jump table 
	.word default 		;default case
	.word S1		;case 1 for button 1
	.word S2		;case 2 for button 2
	.word S3		;case 3 for button 3
	.word S4		;case 4 for button 4
	
	.p2align 1,0
	.global button		;name of the method and it's type global
button:
	cmp #5, r12		;depeding on r12, where r12 is a button when pressed down
	jnc default		;if out of range jump to default
	add r12,r12		;add r12 to r12 in order to get correct array location
	mov jt(r12),r0		;to jump to that location on the jump table depending on r12

default:
	ret 	#0		;return 0
	
S1:
	ret	#1		;return 1

S2:
	ret	#2 		;return 2
	
S3:
	ret 	#3		;return 3
	
S4:
	ret	#4		;return 4
