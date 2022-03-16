.intel_syntax noprefix

.text

.global Prost

Prost:
enter 0,0

push rdi
call Ojler
pop rdi

dec edi
cmp edi, eax
je jeste
mov eax, 0
jmp kraj

jeste:
mov eax, 1

kraj:
leave
ret
