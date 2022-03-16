.intel_syntax noprefix

.text
.global obrni

obrni:
enter 0,0


lea rdx, [rdi + 4*rsi - 4]

petlja:
cmp rdi, rdx
jge kraj

mov r8d, [rdi]
mov r9d, [rdx]
mov [rdx], r8d
mov [rdi], r9d

add rdi, 4
sub rdx, 4

jmp petlja

kraj:
leave
ret
