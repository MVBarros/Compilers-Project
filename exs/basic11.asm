; TEXT
segment	.text
; ALIGN
align	4
; LABEL
$_printconst:
; ENTER
	push	ebp
	mov	ebp, esp
	sub	esp, 0
; RODATA
segment	.rodata
; ALIGN
align	4
; LABEL
$_i1:
; CHAR
	db	0x69
; CHAR
	db	0x20
; CHAR
	db	0x61
; CHAR
	db	0x6D
; CHAR
	db	0x20
; CHAR
	db	0x69
; CHAR
	db	0x6E
; CHAR
	db	0x20
; CHAR
	db	0x76
; CHAR
	db	0x6F
; CHAR
	db	0x69
; CHAR
	db	0x64
; CHAR
	db	0x20
; CHAR
	db	0x66
; CHAR
	db	0x75
; CHAR
	db	0x6E
; CHAR
	db	0x63
; CHAR
	db	0x74
; CHAR
	db	0x69
; CHAR
	db	0x6F
; CHAR
	db	0x6E
; CHAR
	db	0x0A
; CHAR
	db	0x00
; TEXT
segment	.text
; ADDR
	push	dword $_i1
; CALL
	call	$_prints
; TRASH
	add	esp, 4
; LEAVE
	leave
; RET
	ret
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
; CALL
	call	$_printconst
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
