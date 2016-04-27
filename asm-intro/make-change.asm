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
	sub	rsp, 8		;realign the stack

	cmp	rdi, 2		;must have 2 arguments
	jne	error1

	mov	rax, rsi	;put what is inside rsi (cents) into rax register
	cmp	rax, 25		;is cents<=25
	jb	dimes		;jump to dimes if cents - 25 is less than 25????????
	mov	eax, [rax]
	xor	edx, edx	;clear registers for remainders
	mov	ecx, 25		;doing mod 25 essentially
	div	ecx
	add	[quarters], edx	;put the amount of quarters into quarters mem location
	call	puts		;print out quarters
	mov	eax, edx	;remainder stored in edx, quotient stored in eax
	
dimes:
	cmp	eax, 10
	jb	nickles
	mov	ecx, 10
	div	ecx
	mov	eax, edx

nickles:
	cmp	eax, 5
	jb	pennies
	mov	ecx, 5
	div	ecx
	mov	eax, edx

pennies:
	mov	edi, eax
	call	puts
	jmp	done		

error1:
	mov	edi, badArgumentCount
	call	puts
	jmp	done
done:	
	pop	rsi
	pop	rdi
	xor	rax, rax
	ret
quarters:	dq	0	
badArgumentCount:
	db	"Requires exactly two arguments", 10, 0
