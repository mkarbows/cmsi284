;A  program  that  states  whether  or  not  a  given year is a leap year, according to the
;current algorithm: the program accepts the year as a lone argument, then states whether or not 
;that year is a leap year (leap-year.asm)

	global	main
	extern	atoi
	extern	printf
	section	.text
main:
	mov	rdi, [rsi+8]	;put the year/argument into rdi
	call	atoi		;make argument an integer

	xor	rdx, rdx	;clear register
	mov	rsi, rax	;put the year in rsi
	mov	rcx, [fhund]	;put 400 into rcx
	div	rcx		;divide year by 400
	mov	r14, rdx	;put remainder into rdx
	cmp	r14, 0		;check if remainder is 0
	mov	rax, rsi
	jne	checkHund
	jmp	leapYear
checkHund:		
	xor	rdx, rdx	
	mov	rcx, [hund]	;put hundred into rcx
	div	rcx
	mov	r15, rdx	;put remainder in rdx
	cmp	r15, 0
	mov	rax, rsi
	je	false
checkFour:
	xor	rdx, rdx
	mov	rcx, [four]
	div	rcx
	mov	r13, rdx
	cmp	r13, 0
	je	leapYear
	
fhund:
	dq	400
hund:
	dq	100
four:
	dq	4

false:
	mov	rdi, notLeap
	xor	rax, rax
	call	printf
	ret
leapYear:
	mov	rdi, yesLeap
	xor	rax, rax
	call	printf
	ret

notLeap:
	db	"The year %d is not a leap year", 10, 0
yesLeap:
	db	"The year %d is a leap year!", 10, 0
