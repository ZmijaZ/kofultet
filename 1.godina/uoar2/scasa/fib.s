.intel_syntax noprefix

.text

.global fibonaci

fibonaci:
enter 0,0

mov r8d, 1

mov [rdi], r8d
mov [rdi +4], r8d
mov ecx, 2

petlja:
cmp esi, ecx
jle kraj
add eax, [rdi + 4*rcx]
add eax, [rdi + 4*rcx + 4]
mov [rdi + 4*rcx + 4 +4], eax
inc ecx
jmp petlja

kraj:
leave
ret
