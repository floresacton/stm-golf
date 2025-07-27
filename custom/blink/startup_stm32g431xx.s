
.syntax unified
.cpu cortex-m4
.thumb

.global g_pfnVectors
.global main

.section .isr_vector,"a",%progbits
.type g_pfnVectors, %object

g_pfnVectors:
    .word _estack       // Initial stack pointer
    .word main          // Reset vector

.size g_pfnVectors, .-g_pfnVectors

.section .text
.type main, %function

main:
    LDR R0, =0x4002104C 
    MOVS R1, #(1 << 1)
    STR R1, [R0]

    LDR R2, =0x48000400
    ADD R3, R2, #0x18
    
    LSL R4, R1, #12
    LSL R5, R1, #25
    LSL R6, R1, #28

loop:
    STR R5, [R2]
    STR R4, [R3]

    BL delay

    STR R6, [R3]

    BL delay

    B loop

delay:
    LSL R7, R1, #20

delay_loop:
    SUBS R7, R7, #1
    BNE delay_loop
    BX LR

.size main, .-main

