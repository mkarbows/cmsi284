; A program that “makes change” for a total number of cents provided as a lone argument:the
; program displays the number of quarters, dimes, nickels, and pennies needed (make-change.asm).
; asm ­felf64 make­change.asm && gcc make­change.o && ./a.out

	global	main
	extern	puts
	extern	printf
	extern	atoi
	section	.text
main:
	push	rdi		;save register puts uses, will hold argc
	push	rsi		;will hold argv
	add	rsi, 8		;adjust pointer to print second argument
	cmp	rdi, 2		;must have 2 arguments
	jne	error1

	mov	rdi, [rsi]	;if there are 2 arguments, put second argument into rdi
	call	atoi		;make argument an integer
	mov	[cents], rax	;put integer into cents
	
	cmp	rax, 25		;is cents<=25
	jb	dimes		;jump to dimes if cents - 25 is less than 25

	mov	rdx, 25		;doing mod 25 essentially
	div	rdx
	add	[quartAmt], rax	;put the amount of quarters (quotient) into quarters mem location
	
	mov	rax, rdx	;remainder stored in rdx, quotient stored in rax
	
dimes:
	cmp	rax, 10
	jb	nickles
	mov	rdx, 10
	div	rdx
	add	[dimesAmt], rax	;put dimes amount into dimesamt
	mov	rax, rdx

nickles:
	cmp	rax, 5
	jb	pennies
	mov	rdx, 5
	div	rdx
	add	[nicklesAmt], rax
	mov	rax, rdx

pennies:
	mov	[penniesAmt], rax
	call	puts
	jmp	done		

error1:
	mov	rdi, badArgumentCount
	call	puts
	jmp	done
done:	
	pop	rsi
	pop	rdi

	ret
cents:		dq	0
quartAmt:	dq	0
dimesAmt:	dq	0
nicklesAmt:	dq	0
penniesAmt:	dq	0	
badArgumentCount:
	db	"Requires exactly two arguments", 10, 0
