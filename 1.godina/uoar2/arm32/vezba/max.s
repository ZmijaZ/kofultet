.text

.align 2

.global max

max:
stmfd sp!, {fp, lr}
mov fp, sp

cmp r0, r1
bgt kraj
mov r0, r1

kraj:
mov sp, fp
ldmfd sp!, {fp, pc}
