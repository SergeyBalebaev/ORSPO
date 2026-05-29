.section .text
.global _start

_start:
    # Кладём два числа на стек
    mov $10, %rax
    push %rax            
    mov $2, %rax
    push %rax           

    pop %rax
    movq (%rsp), %rbx
    subq %rax, %rbx       

    # Выход с кодом = rbx
    mov $60, %rax        
    mov %rbx, %rdi        
    syscall
    
