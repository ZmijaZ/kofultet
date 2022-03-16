.intel_syntax noprefix

.text

.global Ojler

Ojler:
enter 0, 0

xor r8d, r8d
mov r9d, 1
mov esi, 1

petlja:
cmp esi, edi
je kraj

push rdi
push rsi
call NZD
pop rsi
pop rdi

cmp eax, r9d
je jeste
inc esi

jmp petlja
jeste:
inc r8d
inc esi
jmp petlja


kraj:
mov eax, r8d
leave
ret
