section .data
    num db '1337'

section .text
    global _start

_start:
    mov eax, 4    ; syscall code for sys_write
    mov ebx, 1    ; file descriptor for stdout
    mov ecx, num  ; address of the string to be printed
    mov edx, 4    ; length of the string
    int 0x80      ; call kernel
    ; exit syscall
    mov eax, 1
    xor ebx, ebx
    int 0x80

