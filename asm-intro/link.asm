;Examine  the  list  of   64-bit  Linux  system  calls (you  will  find  a  decent  number  on 
;the  web)  and pick two (2) system calls that you find interesting. Implement  an  assembly 
;language  program  that invokes  that  system  call  and  displays  appropriate feedback  (via 
;the write system  call,  natch).

	global	main
        section	.text
main:
	;link(rdi(oldname), rsi(newname))
	mov	rax, 86			;syscall number for link 
	mov	rdi, [rsi+8]		;getting the first argument
        mov	rsi, [rsi+16]		;getting the second argument
	syscall                         

	;exit(0)
	mov	eax, 60			;system call 60 is exit
	xor	rdi, rdi		;exit code 0
	syscall				;invoke operating system to exit
