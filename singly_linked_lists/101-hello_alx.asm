section .data
    msg db "Hello, ALX", 10, 0    ; 10 is the ASCII code for newline, 0 is null terminator
    fmt db "%s", 0                ; format string for printf

section .text
    extern printf
    global main

main:
    push rbp            ; Set up stack frame
    mov rbp, rsp

    mov rdi, fmt        ; First argument: format string ("%s")
    mov rsi, msg        ; Second argument: string to print ("Hello, ALX\n")
    mov eax, 0          ; Clear AL (required for variadic functions like printf)
    call printf         ; Call printf

    mov eax, 0          ; Return 0
    pop rbp             ; Restore stack frame
    ret
