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

quarters:
	xor	rdx, rdx
	mov	rcx, [quarter]	;doing mod 25 essentially
	div	rcx
	mov	r13, rdx
	mov	rsi, rax
	mov	rdi, quartersM
	xor	rax, rax
	call	printf
	
dimes:	
	mov	rax, r13	;remainder stored in rdx, quotient stored in rax
	xor	rdx, rdx
	mov	rcx, [dime]
	div	rcx
	mov	r14, rdx
	mov	rsi, rax
	mov	rdi, dimesM
	xor	rax, rax
	call	printf
	
nickles:
	mov	rax, r14
	xor	rdx, rdx
	mov	rcx, [nickle]
	div	rcx
	mov	r15, rdx
	mov	rsi, rax
	mov	rdi, nicklesM
	xor	rax, rax
	call	printf
	
pennies:
	mov	rsi, r15
	mov	rdi, penniesM
	xor	rax, rax
	call	printf
	jmp	done		

error1:
	mov	rdi, badArgumentCount
	call	puts
	jmp	done
done:	
	pop	rsi
	pop	rdi
	ret

badArgumentCount:
	db	"Requires exactly two arguments", 10, 0
quarter:		
	db	25
dime:
	db	10
nickle:
	db	5
quartersM:
	db	"Quarters: %d", 10, 0
dimesM:
	db	"Dimes: %d", 10, 0
nicklesM:
	db	"Nickles: %d", 10, 0
penniesM:
	db	"Pennies: %d", 10, 0
