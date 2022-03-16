.intel_syntax noprefix

.text

.global sumas

sumas:
enter 0,0

mov ecx, 2
xor eax, eax



petlja:
cmp ecx, esi
jge kraj
mov ebx, [rdi +4*rcx - 4]
mov edx, [rdi +4*rcx - 8]

sub ebx, edx
cmp ebx, 0
jl negativan
jmp pozitivan

negativan:
not ebx
inc ebx


pozitivan:
inc ecx
add eax, ebx
jmp petlja




kraj:
leave
ret
