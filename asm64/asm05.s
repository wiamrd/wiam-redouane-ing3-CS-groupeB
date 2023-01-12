section .text
    global _start

_start:
    ; exécutez asm01
    call asm01

    ; retourne 0
    mov eax, 0
    xor edi, edi
    xor esi, esi
    xor ebx, ebx
    xor ecx, ecx
    xor edx, edx
    ret

