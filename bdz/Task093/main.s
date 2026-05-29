 .global _start

.data
mes:
    .ascii "equal\n" 
    
.text
_start:
        movq $0, %rax
        cmp $5, %rax
        jne N_EQ
N_EQ:
        addq $1, %rax
        cmp $5, %rax
        jne N_EQ
        je EQ
EQ:
		movq $mes, %rsi
		movq $1, %rdi        
    	movq $6, %rdx       
    	movq $1, %rax        
    	syscall              
        mov     $60, %rax               
        mov     $0, %rdi                
        syscall    
                             
        

