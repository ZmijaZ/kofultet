.intel_syntax noprefix

.text

.global prost

prost:
enter 0,0

cmp edi, 1
je nije_prost

mov ecx, 2
mov esi, edi
shr esi

petlja:
cmp ecx, esi 
jg je_prost

cdq
mov eax, edi
div ecx
cmp edx, 0
je nije_prost
inc ecx
jmp petlja

nije_prost:
mov eax, 0
jmp kraj

je_prost:
mov eax, 1
jmp kraj

kraj:
leave
ret
