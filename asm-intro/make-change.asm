; A program that “makes change” for a total number of cents provided as a lone argument:the
; program displays the number of quarters, dimes, nickels, and pennies needed (make-change.asm).
; asm ­felf64 make­change.asm && gcc make­change.o && ./a.out

	global	main
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
quarters:
	xor	rdx, rdx
	mov	rcx, [quarter]	;put 25 into rcx
	div	rcx		;divide rdxrax by 25
	mov	r13, rdx	;store remainder in r13
	mov	rsi, rax	;put quotient into rsi
	mov	rdi, quartersM	;set up printing
	xor	rax, rax
	call	printf		;print quarters	
dimes:	
	mov	rax, r13	;put quarters remainder into rax
	xor	rdx, rdx
	mov	rcx, [dime]	;get ready to divide by 10
	div	rcx
	mov	r14, rdx	;put the remainder in r14
	mov	rsi, rax	;prepare to print amount of dimes
	mov	rdi, dimesM
	xor	rax, rax
	call	printf		;print dimes	
nickles:
	mov	rax, r14	;put dimes remainder into rax
	xor	rdx, rdx	
	mov	rcx, [nickle]	;get ready to divide by 5
	div	rcx
	mov	r15, rdx	;put remainder into r15
	mov	rsi, rax	;get ready to print nickles
	mov	rdi, nicklesM
	xor	rax, rax
	call	printf		;print nickles	
pennies:
	mov	rsi, r15	;what ever is left over from nickles is printed for pennies
	mov	rdi, penniesM
	xor	rax, rax
	call	printf
	jmp	done		

error1:
	mov	rdi, badArgumentCount	;only get here if user doesnt give exactly 2 arguments
	xor	rax, rax	
	call	printf
	jmp	done
done:	
	pop	rsi
	pop	rdi
	ret

quarter:		
	dq	25
dime:
	dq	10
nickle:
	dq	5

badArgumentCount:
	db	"Requires exactly two arguments", 10, 0
quartersM:
	db	"Quarters: %d", 10, 0
dimesM:
	db	"Dimes: %d", 10, 0
nicklesM:
	db	"Nickles: %d", 10, 0
penniesM:
	db	"Pennies: %d", 10, 0
