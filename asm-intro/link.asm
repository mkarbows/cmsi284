;Examine  the  list  of   64-bit  Linux  system  calls (you  will  find  a  decent  number  on 
;the  web)  and pick two (2) system calls that you find interesting. Implement  an  assembly 
;language  program  that invokes  that  system  call  and  displays  appropriate feedback  (via 
;the write system  call,  natch).

	global	main
        section	.text
main:
	;link(rdi(oldname), rsi(newname))
	push	rsi
	mov	rax, 1		;use the system call write (1)
	mov	rdi, 1		;use file handle 1
	mov	rsi, message	;put string we want to print into rsi
	mov	rdx, 12		;specify the number of bytes
	syscall			;use the write syscall

	pop	rsi		;get back our rsi that pushed originally
	mov	rax, 86		;86 is syscall number for link
	mov	rdi, [rsi+8]	;put the first argument into rdi
	mov	rsi, [rsi+16]	;put second argument into rsi
	syscall			;use the link syscall 
	ret                       
