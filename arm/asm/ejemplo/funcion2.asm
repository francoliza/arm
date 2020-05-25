.data
mensaje: .asciz "holaaaaaaaaaaa\n"

.text
.global print_mensaje
.extern printf

print_mensaje:
	push {ip, lr}
	ldr r0, =mensaje
	bl printf
	pop {ip, pc}
