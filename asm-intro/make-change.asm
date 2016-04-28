; A program that “makes change” for a total number of cents provided as a lone argument:the
; program displays the number of quarters, dimes, nickels, and pennies needed (make-change.asm).
; asm ­felf64 make­change.asm && gcc make­change.o && ./a.out

	global	main
	extern	puts
	extern	printf
	section	.text
main:
	push	rdi		;save register puts uses, will hold argc
	push	rsi		;will hold argv
	
	add	rsi, 8
	mov	rdi, [rsi]
	call 	puts
	
	cmp	rdi, 2		;must have 2 arguments
	jne	error1

	mov	rax, rsi	;put what is inside rsi (cents) into rax register
	cmp	rax, 25		;is cents<=25
	jb	dimes		;jump to dimes if cents - 25 is less than 25

	xor	rax, rax	;clear registers for quotient
	xor	rdx, rdx	;clear registers for remainders
	mov	rax, rsi	;put the number of cents into rax register
	mov	rdx, 25		;doing mod 25 essentially
	div	rdx
	push	rax
	push	rdx		;pushing remainder onto stack
	add	[quartersAmt], rax	;put the amount of quarters (quotient) into quarters mem location
	
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
quartersAmt:	dq	0
dimesAmt:	dq	0
nicklesAmt:	dq	0
penniesAmt:	dq	0	
badArgumentCount:
	db	"Requires exactly two arguments", 10, 0
