.intel_syntax noprefix

.text

.global suma

suma:
enter 0,0

mov eax, [rdi]
xor rcx, rcx
xor r8d, r8d


petlja:
cmp esi, ecx
je kraj
cmp [rdi+4*rcx], eax
jg vece
jmp nije

vece:
mov eax, [rdi +4*rcx]
mov r8d, ecx

nije:
inc ecx
jmp petlja

kraj:
mov eax, r8d
leave
ret
