.section .text
.global _start

_start:
    mov $42, %rax        
    push %rax            
    pop %rbx 
    
    mov $1, %rax
    push %rax   
    mov $2, %rax
    push %rax 
    mov $3, %rax
    push %rax
    mov $4, %rax
    push %rax
    mov $5, %rax
    push %rax
    mov $6, %rax
    push %rax  
    mov $7, %rax
    push %rax     
    mov $8, %rax
    push %rax
    mov $9, %rax
    push %rax  
    mov $10, %rax
    push %rax    
    
    pop %rbx
    pop %rbx
    pop %rbx
    pop %rbx
    pop %rbx
    pop %rbx
    pop %rbx
    pop %rbx
    pop %rbx
    pop %rbx         

    mov $60, %rax       
    mov $0, %rdi        
    syscall              

