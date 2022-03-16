.intel_syntax noprefix

.text

.global NZD
NZD:
enter 0, 0

mov eax, edi


petlja:
cmp esi, 0
je kraj

cdq
div esi
mov eax, esi
mov esi, edx
jmp petlja



kraj:
leave
ret
