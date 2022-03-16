.intel_syntax noprefix

.text
.global suma_a

suma_a:
enter 0,0

xor ecx, ecx
xor eax, eax
xor r8, r8

petlja:
cmp ecx, esi
jge kraj

mov edx, [rdi + 4*rcx]

cmp edx, 0
jl negativan
add eax, edx
inc ecx
jmp petlja

negativan:
not edx
inc edx
add eax, edx
inc ecx
jmp petlja

kraj:
leave
ret
