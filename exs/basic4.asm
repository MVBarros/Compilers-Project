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
	sub	esp, 4
; RODATA
segment	.rodata
; ALIGN
align	4
; LABEL
$_i1:
; CHAR
	db	0x77
; CHAR
	db	0x68
; CHAR
	db	0x61
; CHAR
	db	0x74
; CHAR
	db	0x20
; CHAR
	db	0x69
; CHAR
	db	0x73
; CHAR
	db	0x20
; CHAR
	db	0x74
; CHAR
	db	0x68
; CHAR
	db	0x69
; CHAR
	db	0x73
; CHAR
	db	0x20
; CHAR
	db	0x73
; CHAR
	db	0x74
; CHAR
	db	0x72
; CHAR
	db	0x69
; CHAR
	db	0x6E
; CHAR
	db	0x67
; CHAR
	db	0x00
; TEXT
segment	.text
; ADDR
	push	dword $_i1
; COPY
	push	dword [esp]
; LOCAL
	lea	eax, [ebp+-4]
	push	eax
; STORE
	pop	ecx
	pop	eax
	mov	[ecx], eax
; TRASH
	add	esp, 4
; LOCAL
	lea	eax, [ebp+-4]
	push	eax
; LOAD
	pop	eax
	push	dword [eax]
; IMM
	push	dword 2
; ADD
	pop	eax
	add	dword [esp], eax
; LDCHR
	pop	ecx
	movsx	eax,byte [ecx]
	push	eax
; IMM
	push	dword 2
; ADD
	pop	eax
	add	dword [esp], eax
; CALL
	call	$_printi
; TRASH
	add	esp, 4
; PUSH
	push	eax
; TRASH
	add	esp, 4
; CALL
	call	$_println
; PUSH
	push	eax
; TRASH
	add	esp, 4
; LOCAL
	lea	eax, [ebp+-4]
	push	eax
; LOAD
	pop	eax
	push	dword [eax]
; IMM
	push	dword 1
; ADD
	pop	eax
	add	dword [esp], eax
; LDCHR
	pop	ecx
	movsx	eax,byte [ecx]
	push	eax
; CALL
	call	$_printi
; TRASH
	add	esp, 4
; PUSH
	push	eax
; TRASH
	add	esp, 4
; CALL
	call	$_println
; PUSH
	push	eax
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
extern	$_println
; EXTRN
extern	$_prints
; EXTRN
extern	$_printi
