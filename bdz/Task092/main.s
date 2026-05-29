 .global _start

.data
mes:
    .ascii "equal\n"

.text
_start:

        movq     $5, %rax
        cmp      $5, %rax
        jne N_EQ
        je EQ       

N_EQ:
	movq $60, %rax
	movq $0, %rdi
	syscall
EQ:
	movq $1, %rax
	movq $1, %rdi
	leaq mes(%rip), %rsi
	movq $6, %rdx
	syscall
	
	movq $60, %rax
	movq $0, %rdi
	syscall
        
