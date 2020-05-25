.data
.balign 4
string: .asciz "resultado: %d + %d = %d\n"
a: 	.word 33
b: 	.word 44
c: 	.word 0	 		@directivas del procesador	

.text
.global main
.extern printf

suma:
	push {ip, lr}
	add r0, r1, r2
	pop {ip, pc}

main:
	push {ip, lr}
	ldr r1, =a
	ldr r1, [r1]
	ldr r2, =b
	ldr r2, [r2]

	bl suma
	
	ldr r2, =c
	str r0, [r2]

@printf("%d + %d = %d\n",r1,r2,r3)_
	ldr r0, =string
	ldr r1, =a
	ldr r1, [r1]
	ldr r2, =b
	ldr r2, [r2]
	ldr r3, =c
	ldr r3, [r3]
	bl printf
	pop {ip, pc}
