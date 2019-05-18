; BSS
segment	.bss
; ALIGN
align	4
; LABEL
$i:
; BYTE
	resb	4
; BSS
segment	.bss
; ALIGN
align	4
; LABEL
$p:
; BYTE
	resb	8
; BSS
segment	.bss
; ALIGN
align	4
; LABEL
$s:
; BYTE
	resb	4
; TEXT
segment	.text
; ALIGN
align	4
; GLOBL
global	$_entry:function
; LABEL
$_entry:
; ENTER
	push	ebp
	mov	ebp, esp
	sub	esp, 0
; IMM
	push	dword 3
; COPY
	push	dword [esp]
; ADDR
	push	dword $i
; STORE
	pop	ecx
	pop	eax
	mov	[ecx], eax
; TRASH
	add	esp, 4
; RODATA
segment	.rodata
; ALIGN
align	4
; LABEL
$_i1:
; DOUBLE
	dq	4.300000e+00
; TEXT
segment	.text
; ADDR
	push	dword $_i1
; LOAD2
	pop	eax
	push	dword [eax+4]
	push	dword [eax]
; COPY2
	push	dword [esp+4]
	push	dword [esp+4]
; ADDR
	push	dword $p
; STORE2
	pop	ecx
	pop	eax
	mov	[ecx], eax
	pop	eax
	mov	[ecx+4], eax
; TRASH
	add	esp, 8
; RODATA
segment	.rodata
; ALIGN
align	4
; LABEL
$_i2:
; CHAR
	db	0x6F
; CHAR
	db	0x6C
; CHAR
	db	0x61
; CHAR
	db	0x20
; CHAR
	db	0x6F
; CHAR
	db	0x6C
; CHAR
	db	0x61
; CHAR
	db	0x20
; CHAR
	db	0x6F
; CHAR
	db	0x6C
; CHAR
	db	0x61
; CHAR
	db	0x0A
; CHAR
	db	0x0A
; CHAR
	db	0x0A
; CHAR
	db	0x0A
; CHAR
	db	0x0A
; CHAR
	db	0x0A
; CHAR
	db	0x0A
; CHAR
	db	0x00
; TEXT
segment	.text
; ADDR
	push	dword $_i2
; COPY
	push	dword [esp]
; ADDR
	push	dword $s
; STORE
	pop	ecx
	pop	eax
	mov	[ecx], eax
; TRASH
	add	esp, 4
; RODATA
segment	.rodata
; ALIGN
align	4
; LABEL
$_i3:
; CHAR
	db	0x69
; CHAR
	db	0x20
; CHAR
	db	0x2D
; CHAR
	db	0x3E
; CHAR
	db	0x20
; CHAR
	db	0x00
; TEXT
segment	.text
; ADDR
	push	dword $_i3
; CALL
	call	$_prints
; TRASH
	add	esp, 4
; ADDR
	push	dword $i
; LOAD
	pop	eax
	push	dword [eax]
; CALL
	call	$_printi
; TRASH
	add	esp, 4
; CALL
	call	$_println
; RODATA
segment	.rodata
; ALIGN
align	4
; LABEL
$_i4:
; CHAR
	db	0x70
; CHAR
	db	0x20
; CHAR
	db	0x2D
; CHAR
	db	0x3E
; CHAR
	db	0x20
; CHAR
	db	0x00
; TEXT
segment	.text
; ADDR
	push	dword $_i4
; CALL
	call	$_prints
; TRASH
	add	esp, 4
; ADDR
	push	dword $p
; LOAD2
	pop	eax
	push	dword [eax+4]
	push	dword [eax]
; CALL
	call	$_printd
; TRASH
	add	esp, 8
; CALL
	call	$_println
; RODATA
segment	.rodata
; ALIGN
align	4
; LABEL
$_i5:
; CHAR
	db	0x73
; CHAR
	db	0x20
; CHAR
	db	0x2D
; CHAR
	db	0x3E
; CHAR
	db	0x20
; CHAR
	db	0x00
; TEXT
segment	.text
; ADDR
	push	dword $_i5
; CALL
	call	$_prints
; TRASH
	add	esp, 4
; ADDR
	push	dword $s
; LOAD
	pop	eax
	push	dword [eax]
; CALL
	call	$_prints
; TRASH
	add	esp, 4
; IMM
	push	dword 0
; COPY
	push	dword [esp]
; LOCAL
	lea	eax, [ebp+8]
	push	eax
; STORE
	pop	ecx
	pop	eax
	mov	[ecx], eax
; TRASH
	add	esp, 4
; LOCAL
	lea	eax, [ebp+8]
	push	eax
; LOAD
	pop	eax
	push	dword [eax]
; POP
	pop	eax
; LEAVE
	leave
; RET
	ret
; EXTRN
extern	$_printi
; EXTRN
extern	$_println
; EXTRN
extern	$_prints
; EXTRN
extern	$_printd
