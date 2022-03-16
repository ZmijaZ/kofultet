.intel_syntax noprefix

.text

.global kolicnik

kolicnik:
enter 0,0

mov eax, edi
and eax, esi
mov [rdx], eax

mov eax, edi
or eax, esi
mov [rcx], eax

mov eax, edi
xor eax, esi
mov [r8], eax

not edi
mov [r9], edi

leave
ret
