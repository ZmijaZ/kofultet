.intel_syntax noprefix

.text

.global niz

niz:
enter 0,0

xor ecx, ecx
xor ebx, ebx


petlja:
cmp ecx, esi
jge kraj
mov edi, [rdi + 4*rcx]
mov r8, [rdi + 4*rcx]

push rdi
push rsi
push rbx
push rcx
push rdx
call prost
pop rdx
pop rcx
pop rbx
pop rsi
pop rdi

cmp eax, 1
je prost
jmp nije

prost:
inc ebx
mov [rdx + 4*rbx], r8

nije:
inc ecx
jmp petlja

kraj:
mov eax, ebx
leave
ret
