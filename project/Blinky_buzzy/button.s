	.arch msp430g2553

	.text
	.global button
button:
	cmp #1 r12

	jeq	.S1

	cmp #2 r12

	jeq	.S2

	cmp #3 r12

	jeq	.S3

	cmp #4 r12

	jeq 	.S4

.S1:

	ret	#1

.S2:

	ret	#2

.S3:

	ret 	#3

.S4:

	ret	#4
