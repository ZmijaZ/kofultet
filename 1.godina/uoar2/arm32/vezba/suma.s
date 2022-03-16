.text

.align 2

.global suma

suma:
stmfd sp!, {fp, lr}
mov fp, sp

add r0, r0, r1

mov sp, fp
ldmfd sp!, {fp, pc}
