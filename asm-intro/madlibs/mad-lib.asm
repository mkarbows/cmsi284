;An  assembly  language  program  that  uses  the madlib-by-numbers.c code  that  you  wrote  in  
;Assignment 0322 to perform the madlibs operation as  a  command  (madlibs.asm).  Let  the  first 
;argument  be  the  template  (use  double-quotes  to  accommodate  a  template  with  spaces) 
;with  the  remaining  arguments  serving  as  the  words  to  insert.  Do not expect  the  word 
;count  as  an  argument—the  program  can  (and  should)  calculate that on its own

	global	main
	extern madlib_by_numbers
	extern puts
	section	.text
main:
	push	rbx
	mov	rcx, rdi
	sub	rcx, 2
	mov	rdi, [rsi+8]
	add	rsi, 16
	mov	rdx, rsi
	mov	rsi, rcx
	call	madlib_by_numbers
	mov	rdi, rax
	call	puts
	pop	rbx
	ret
