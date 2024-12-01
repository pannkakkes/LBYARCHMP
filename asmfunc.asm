section .data
msg db "vectorA = %f", 13, 10, 0
vectorA dq 0.0
vectorB dq 0.0

section .text
bits 64
default rel

global asm_sdot
extern printf

asm_sdot:
    ; n is in rcx
    ; vectorA is in rdx
    ; add rdx, 8 to access next elements
    ; vectorB is in r8
    movsd xmm1, [rdx]
    movsd [vectorA], xmm1
    movsd xmm2, [r8]
    movsd [vectorB], xmm2

    sub rsp, 8*7
        lea rcx, [msg]
        mov rdx, [vectorA]
        call printf
    add rsp, 8*7

    xor rax, rax
    ret
