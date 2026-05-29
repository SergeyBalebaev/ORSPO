.globl _start
 
.data 
message: .asciz "Chistovsky Evgeny Vladislavovich IVT-23\n"   # текст выводимого сообщения
 
.text
_start:
 
    movq $message, %rsi  # в RSI - адрес строки
    movq $1, %rdi        # в RDI - дексриптор вывода в стандартный поток (консоль)
    movq $40, %rdx       # в RDX - длина строки
    movq $1, %rax        # в RAX - номер функции для вывода в поток 
    syscall              # вызываем функцию Linux
 
    movq $60, %rax
    movq $0, %rdi
    syscall
