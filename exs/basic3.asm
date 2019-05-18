; TEXT
segment	.text
; ALIGN
align	4
; GLOBL
global	$_givehello:function
; LABEL
$_givehello:
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
	db	0x68
; CHAR
	db	0x65
; CHAR
	db	0x6C
; CHAR
	db	0x6C
; CHAR
	db	0x6F
; CHAR
	db	0x0A
; CHAR
	db	0x00
; TEXT
segment	.text
; ADDR
	push	dword $_i1
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
	sub	esp, 16
; RODATA
segment	.rodata
; ALIGN
align	4
; LABEL
$_i2:
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
	db	0x3F
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
; LOCAL
	lea	eax, [ebp+-8]
	push	eax
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
	db	0x61
; CHAR
	db	0x3A
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
; LOCAL
	lea	eax, [ebp+-8]
	push	eax
; LOAD
	pop	eax
	push	dword [eax]
; CALL
	call	$_prints
; TRASH
	add	esp, 4
; RODATA
segment	.rodata
; ALIGN
align	4
; LABEL
$_i4:
; CHAR
	db	0x61
; CHAR
	db	0x20
; CHAR
	db	0x3A
; CHAR
	db	0x3D
; CHAR
	db	0x20
; CHAR
	db	0x67
; CHAR
	db	0x69
; CHAR
	db	0x76
; CHAR
	db	0x65
; CHAR
	db	0x68
; CHAR
	db	0x65
; CHAR
	db	0x6C
; CHAR
	db	0x6C
; CHAR
	db	0x6F
; CHAR
	db	0x28
; CHAR
	db	0x29
; CHAR
	db	0x20
; CHAR
	db	0x3A
; CHAR
	db	0x3D
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
; CALL
	call	$_givehello
; PUSH
	push	eax
; COPY
	push	dword [esp]
; LOCAL
	lea	eax, [ebp+-8]
	push	eax
; STORE
	pop	ecx
	pop	eax
	mov	[ecx], eax
; CALL
	call	$_prints
; TRASH
	add	esp, 4
; LOCAL
	lea	eax, [ebp+-8]
	push	eax
; LOAD
	pop	eax
	push	dword [eax]
; COPY
	push	dword [esp]
; LOCAL
	lea	eax, [ebp+-12]
	push	eax
; STORE
	pop	ecx
	pop	eax
	mov	[ecx], eax
; COPY
	push	dword [esp]
; LOCAL
	lea	eax, [ebp+-16]
	push	eax
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
$_i5:
; CHAR
	db	0x63
; CHAR
	db	0x3A
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
; LOCAL
	lea	eax, [ebp+-16]
	push	eax
; LOAD
	pop	eax
	push	dword [eax]
; CALL
	call	$_prints
; TRASH
	add	esp, 4
; RODATA
segment	.rodata
; ALIGN
align	4
; LABEL
$_i6:
; CHAR
	db	0x62
; CHAR
	db	0x3A
; CHAR
	db	0x20
; CHAR
	db	0x00
; TEXT
segment	.text
; ADDR
	push	dword $_i6
; CALL
	call	$_prints
; TRASH
	add	esp, 4
; LOCAL
	lea	eax, [ebp+-12]
	push	eax
; LOAD
	pop	eax
	push	dword [eax]
; CALL
	call	$_prints
; TRASH
	add	esp, 4
; RODATA
segment	.rodata
; ALIGN
align	4
; LABEL
$_i7:
; CHAR
	db	0x61
; CHAR
	db	0x67
; CHAR
	db	0x67
; CHAR
	db	0x00
; TEXT
segment	.text
; ADDR
	push	dword $_i7
; COPY
	push	dword [esp]
; LOCAL
	lea	eax, [ebp+-8]
	push	eax
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
$_i8:
; CHAR
	db	0x62
; CHAR
	db	0x63
; CHAR
	db	0x63
; CHAR
	db	0x00
; TEXT
segment	.text
; ADDR
	push	dword $_i8
; COPY
	push	dword [esp]
; LOCAL
	lea	eax, [ebp+-12]
	push	eax
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
$_i9:
; CHAR
	db	0x61
; CHAR
	db	0x20
; CHAR
	db	0x3C
; CHAR
	db	0x20
; CHAR
	db	0x62
; CHAR
	db	0x20
; CHAR
	db	0x3F
; CHAR
	db	0x20
; CHAR
	db	0x00
; TEXT
segment	.text
; ADDR
	push	dword $_i9
; CALL
	call	$_prints
; TRASH
	add	esp, 4
; LOCAL
	lea	eax, [ebp+-8]
	push	eax
; LOAD
	pop	eax
	push	dword [eax]
; LDCHR
	pop	ecx
	movsx	eax,byte [ecx]
	push	eax
; LOCAL
	lea	eax, [ebp+-12]
	push	eax
; LOAD
	pop	eax
	push	dword [eax]
; LDCHR
	pop	ecx
	movsx	eax,byte [ecx]
	push	eax
; LT
	pop	eax
	xor	ecx, ecx
	cmp	[esp], eax
	setl	cl
	mov	[esp], ecx
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
$_i10:
; CHAR
	db	0x61
; CHAR
	db	0x20
; CHAR
	db	0x3E
; CHAR
	db	0x20
; CHAR
	db	0x62
; CHAR
	db	0x20
; CHAR
	db	0x3F
; CHAR
	db	0x20
; CHAR
	db	0x00
; TEXT
segment	.text
; ADDR
	push	dword $_i10
; CALL
	call	$_prints
; TRASH
	add	esp, 4
; LOCAL
	lea	eax, [ebp+-8]
	push	eax
; LOAD
	pop	eax
	push	dword [eax]
; LDCHR
	pop	ecx
	movsx	eax,byte [ecx]
	push	eax
; LOCAL
	lea	eax, [ebp+-12]
	push	eax
; LOAD
	pop	eax
	push	dword [eax]
; LDCHR
	pop	ecx
	movsx	eax,byte [ecx]
	push	eax
; GT
	pop	eax
	xor	ecx, ecx
	cmp	[esp], eax
	setg	cl
	mov	[esp], ecx
; CALL
	call	$_printi
; TRASH
	add	esp, 4
; CALL
	call	$_println
; LOCAL
	lea	eax, [ebp+-8]
	push	eax
; LOAD
	pop	eax
	push	dword [eax]
; LDCHR
	pop	ecx
	movsx	eax,byte [ecx]
	push	eax
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
$_i11:
; CHAR
	db	0x68
; CHAR
	db	0x65
; CHAR
	db	0x6C
; CHAR
	db	0x6C
; CHAR
	db	0x6F
; CHAR
	db	0x20
; CHAR
	db	0x77
; CHAR
	db	0x6F
; CHAR
	db	0x72
; CHAR
	db	0x6C
; CHAR
	db	0x64
; CHAR
	db	0x0A
; CHAR
	db	0x00
; TEXT
segment	.text
; ADDR
	push	dword $_i11
; CALL
	call	$_prints
; TRASH
	add	esp, 4
; IMM
	push	dword 81
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
; COPY
	push	dword [esp]
; LOCAL
	lea	eax, [ebp+-8]
	push	eax
; STORE
	pop	ecx
	pop	eax
	mov	[ecx], eax
; TRASH
	add	esp, 4
; LOCAL
	lea	eax, [ebp+-8]
	push	eax
; LOAD
	pop	eax
	push	dword [eax]
; CALL
	call	$_prints
; TRASH
	add	esp, 4
; CALL
	call	$_println
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
