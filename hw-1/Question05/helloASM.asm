section .data
    msg db "hello ASM world", 0xa, 0
    len equ $-msg

section .text
    global _start

_start:
    xor eax, eax
    mov al, 0x04
    xor ebx, ebx
    mov bl, 0x01
    xor ecx, ecx
    mov ecx, msg
    xor edx, edx
    mov edx, len
    int 0x80

    mov eax, 0x01
    mov ebx, 0x00
    int 0x80
