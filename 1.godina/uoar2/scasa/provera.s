.intel_syntax noprefix

.text

.global negativni

negativni:
enter 0,0

xor ecx, ecx

petlja:
cmp ecx, esi 
je kraj
mov r8, [rdi + 4*rcx]
not r8
mov [rdi + 4*rcx], r8
inc ecx
jmp petlja

kraj:
leave
ret
