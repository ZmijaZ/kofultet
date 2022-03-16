.intel_syntax noprefix

.text

.global saberi

saberi:
enter 0,0

mov eax, edi
dec edi

petlja:
cmp esi, edi
jge kraj
cdq
mul edi
dec edi
jmp petlja

kraj:
leave
ret
