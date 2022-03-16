.intel_syntax noprefix

.data
rez: .asciz "Rezultat je: "

.text

.global saberi

.global ispisi

ispisi:
enter 0,0

lea rdi, rez
call printf

leave
ret

saberi: 
enter 0,0

mov eax, edi
add eax, esi

leave
ret
