.intel_syntax noprefix

.data
str: .asciz "Cao svete\n"

.text

.global main

main:
enter 0,0

lea rdi, str
call printf

leave
ret

