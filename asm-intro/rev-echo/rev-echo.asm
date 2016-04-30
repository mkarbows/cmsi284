;An  assembly  language  program  that  uses reverse-range-in-place.c to  echo  its  command-
;line  arguments,  including  the  program  name,  but  in  reverse (rev-echo.asm)	

	global	main
	extern	puts
	extern	strlen
	extern	reverse_range_in_place
	section	.text
main:
	push	rdi		;save registers that puts uses
	push	rsi
	sub	rsp, 8		;realign stack
	
	mov	rdi, [rsi]	;argument string
	call	strlen		;get the length of the string
	mov	rdx, rax	;string length in rax, put it in rax
	mov	rdi, [rsi]	;put the string into rdi
	mov	rsi, 0		;make the starting index 0 and put it in rsi
	push	rdi
	call	reverse_range_in_place
	pop	rdi
	call	puts		;print it
	
	add	rsp, 8		;restore %rsp to pre-aligned value
	pop	rsi		;restore registers puts used
	pop	rdi

	add	rsi, 8		;point to the next argument
	dec	rdi		;count down
	jnz	main		;if not done counting keep going
	ret
