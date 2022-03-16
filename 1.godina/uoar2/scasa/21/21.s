.intel_syntax noprefix

.text
.global podeli
podeli:
enter 0,0

mov eax,edi
mov ebx,esi
div eax,ebx

leave
ret
