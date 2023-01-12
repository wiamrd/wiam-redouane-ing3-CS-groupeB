section .data
    num db '1337'
    input db 0

section .text
    global _start

_start:
    ; read input
    mov eax, 3
    mov ebx, 0
    mov ecx, input
    mov edx, 1
    int 0x80

    ; check if input is even
    mov eax, [input]
    and eax, 1
    cmp eax, 0
    jne end
    ; input is even
    mov eax, 4
    mov ebx, 1
    mov ecx, num
    mov edx, 4
    int 0x80
    ; exit syscall
    mov eax, 1
    xor ebx, ebx
    int 0x80

end:
    ; input is odd
    mov eax, 1
    mov ebx, 1
    int 0x80

