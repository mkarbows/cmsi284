;A suite of  three (3) integer calculation programs in C that use functions defined in a single 
;assembly  language  file  to  perform  the  requested  computations  (calc-ops.asm).  The calc-
;ops.asm “library” should  implement  a gcd function  and  two  other integer operations of  your 
;choice (examples: add, subtract, mod, power  [for  positive  exponents  only, of   course]).  The 
;C  programs  then  accept  arguments,  process  them,  and  finally  call  their  corresponding 
;assembly  language  function,  displaying the returned result.

	global 	add
	global 	subtract
	global	gcd
	section	.text

add:
	mov	rax, rdi	;first argument into rax
	mov	rcx, rsi	;second argument into rcx
	add	rax, rcx	;add them
	ret
subtract:
	mov	rax, rdi	;first argument into rax
	mov	rcx, rsi	;second argument into rcx
	sub	rax, rcx	;perform subtraction
	ret
gcd:
	cmp	rsi, 0		;check if second argument is zero
	jne	equalsX		;jump if equal
	mov	rax, rdi	;put first argument into rax
	ret
equalsX:
	mov	rax, rdi	;first argument into rax
	xor	rdx, rdx	;clear to div
	div	rsi		;div by second argument
	mov	rdi, rsi	;move quotient into rdi (first argument)
	mov	rsi, rdx	;move remainder into rsi (second argument)
	call	gcd
	ret
