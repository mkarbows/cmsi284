	global	main
	extern	cos
	extern	sin
	extern	printf

	section	.text

result:	db	" ", 0
print:	db	" :)", 10, 0
pi:	dq	3.141592653589793
delta:	dq	18.0			;one line moves pi/delta radians
two:	dq	2.0			;going to use for two pi
width:	dq	16.0			;random terminal width

main:	push	rbp

L0:	movsd	xmm0, [radian]		;value of radian into xmm0
	call	cos			;call cosine
	movsd	[cosine], xmm0		;results displayed
	movsd	xmm2, [cosine]
	addsd	xmm2, [two]		;adding 2 to result
	mulsd	xmm2, [width]
	cvtsd2si r14, xmm2		;converting to int get number of spaces to print

spacing:
	mov	rdi, result		;put the spaces into rdi
	mov	rax, 1			
	call	printf			;print the spaces

	dec	r14			;decrement the spaces by 1
	jnz	spacing			;if the spaces aren't zero print more
	mov	rdi, print		;prints :)
	mov	rsi, r14
	call	printf

	movsd	xmm0, [radian]
	movsd	xmm1, [pi]
	divsd	xmm1, [delta]
	addsd	xmm0, xmm1		;radian += pi/delta
	movsd	[radian], xmm0
	movsd	xmm2, [pi]
	mulsd	xmm2, [two]
	addsd	xmm1, xmm2		;2*pi + pi/delta
	comisd	xmm0, xmm1
	jc	L0			;CF is set if L0 is less than
	pop	rbp
	ret

	section	.data
radian: 
	dq	0.0
sine:	
	dq	0.0
cosine:	
	dq	0.0
space:	
	dq	0
