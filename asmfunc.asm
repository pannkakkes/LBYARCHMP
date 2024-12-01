section .data
vectorA dq 0.0
vectorB dq 0.0
sdot dq 0.0
zero db 0.0

section .text
bits 64
default rel

global asm_sdot

asm_sdot:
    ; n is in rcx
    ; vectorA is in rdx
    ; add rdx, 8 to access next elements
    ; vectorB is in r8
    ; sdot is in r9
    movsd xmm4, [zero]

L1:
    movsd xmm1, [rdx]
    movsd xmm2, [r8]

    vmulsd xmm3, xmm1, xmm2
    addsd xmm4, xmm3

    add rdx, 8
    add r8, 8

    dec rcx
    jnz L1

FINIS:
    movsd [sdot], xmm4
    movsd [r9], xmm4
    xor rax, rax
    ret
