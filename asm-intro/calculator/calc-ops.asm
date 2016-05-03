;A suite of  three (3) integer calculation programs in C that use functions defined in a single 
;assembly  language  file  to  perform  the  requested  computations  (calc-ops.asm).  The calc-
;ops.asm “library” should  implement  a gcd function  and  two  other integer operations of  your 
;choice (examples: add, subtract, mod, power  [for  positive  exponents  only, of   course]).  The 
;C  programs  then  accept  arguments,  process  them,  and  finally  call  their  corresponding 
;assembly  language  function,  displaying the returned result.

	global 	addition
	global 	subtract
	global	gcd
	extern	puts
	extern	printf
	extern	atoi
	section	.text

addition:
	mov	rax, rdi	;first argument into rax
	mov	rcx, rsi	;second argument into rcx
	add	rax, rcx	;add them
	ret
subtract:
	mov	rax, rdi	;first argument into rax
	mov	rcx, rsi	;second argument into rcx
	sub	rax, rcx
	ret
gcd:
	mov	rax, rdi
	mov	rcx, rsi
	cmp	rsi, 0
	jz	equalsX
equalsX:
	mov	rsi, rax	;put x into rsi
	mov	rdi, xIsGcd
	;xor	rax, rax
	call	printf
begin:
	cmp	rax, 0
	jz	done
	cmp	rax, rdx
	jge	sorted
	cmp
	;finish this............

sorted:
done:

xIsGcd:
	db	"The GCD is %d", 10, 0

answer:
	db	"%d", 10, 0
