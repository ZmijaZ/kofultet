.intel_syntax noprefix

.data
fmt: .asciz "Hello World\n"

.text
.global main
main:
enter 0,0
lea rdi, fmt
call printf

leave
ret

