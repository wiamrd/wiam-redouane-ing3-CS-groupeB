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

    ; compare input to 42
    mov eax, [input]
    cmp eax, 42
    jne end
    ; input is 42
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
    ; input is not 42
    mov eax, 1
    mov ebx, 1
    int 0x80

