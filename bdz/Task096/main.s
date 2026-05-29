.section .text
.global _start

func:
    push %rbp
    mov %rsp, %rbp

    mov 16(%rbp), %rax     
    mov 24(%rbp), %rbx     
    add %rbx, %rax
    mov 32(%rbp), %rbx
    add %rbx, %rax     

    pop %rbp
    ret

_start:
    mov $7, %rax
    push %rax              
    mov $5, %rax
    push %rax
    mov $11, %rax
    push %rax  

    call func
    
    add $24, %rsp
    mov %rax, %rbx           
    mov $60, %rax
    mov %rbx, %rdi
    syscall
