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
	sub	esp, 12
; RODATA
segment	.rodata
; ALIGN
align	4
; LABEL
$_i1:
; CHAR
	db	0x6F
; CHAR
	db	0x6C
; CHAR
	db	0x61
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
; RODATA
segment	.rodata
; ALIGN
align	4
; LABEL
$_i2:
; CHAR
	db	0x70
; CHAR
	db	0x6C
; CHAR
	db	0x61
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
; LOCAL
	lea	eax, [ebp+-4]
	push	eax
; LOAD
	pop	eax
	push	dword [eax]
; LDCHR
	pop	ecx
	movsx	eax,byte [ecx]
	push	eax
; RODATA
segment	.rodata
; ALIGN
align	4
; LABEL
$_i3:
; CHAR
	db	0x70
; CHAR
	db	0x6C
; CHAR
	db	0x61
; CHAR
	db	0x00
; TEXT
segment	.text
; ADDR
	push	dword $_i3
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
; JZ
	pop	eax
	cmp	eax, byte 0
	je	near $_i4
; RODATA
segment	.rodata
; ALIGN
align	4
; LABEL
$_i5:
; CHAR
	db	0x69
; CHAR
	db	0x6E
; CHAR
	db	0x20
; CHAR
	db	0x69
; CHAR
	db	0x66
; CHAR
	db	0x0A
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
; JMP
	jmp	dword $_i6
; LABEL
$_i4:
; RODATA
segment	.rodata
; ALIGN
align	4
; LABEL
$_i7:
; CHAR
	db	0x69
; CHAR
	db	0x6E
; CHAR
	db	0x20
; CHAR
	db	0x65
; CHAR
	db	0x6C
; CHAR
	db	0x73
; CHAR
	db	0x65
; CHAR
	db	0x0A
; CHAR
	db	0x00
; TEXT
segment	.text
; ADDR
	push	dword $_i7
; CALL
	call	$_prints
; TRASH
	add	esp, 4
; LABEL
$_i6:
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
; RODATA
segment	.rodata
; ALIGN
align	4
; LABEL
$_i8:
; CHAR
	db	0x6F
; CHAR
	db	0x6C
; CHAR
	db	0x61
; CHAR
	db	0x00
; TEXT
segment	.text
; ADDR
	push	dword $_i8
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
; JZ
	pop	eax
	cmp	eax, byte 0
	je	near $_i9
; RODATA
segment	.rodata
; ALIGN
align	4
; LABEL
$_i10:
; CHAR
	db	0x69
; CHAR
	db	0x6E
; CHAR
	db	0x20
; CHAR
	db	0x73
; CHAR
	db	0x65
; CHAR
	db	0x63
; CHAR
	db	0x6F
; CHAR
	db	0x6E
; CHAR
	db	0x64
; CHAR
	db	0x20
; CHAR
	db	0x69
; CHAR
	db	0x66
; CHAR
	db	0x20
; CHAR
	db	0x63
; CHAR
	db	0x68
; CHAR
	db	0x65
; CHAR
	db	0x63
; CHAR
	db	0x6B
; CHAR
	db	0x20
; CHAR
	db	0x61
; CHAR
	db	0x73
; CHAR
	db	0x73
; CHAR
	db	0x65
; CHAR
	db	0x6D
; CHAR
	db	0x62
; CHAR
	db	0x6C
; CHAR
	db	0x79
; CHAR
	db	0x0A
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
; LABEL
$_i9:
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
; RODATA
segment	.rodata
; ALIGN
align	4
; LABEL
$_i11:
; CHAR
	db	0x71
; CHAR
	db	0x6C
; CHAR
	db	0x61
; CHAR
	db	0x00
; TEXT
segment	.text
; ADDR
	push	dword $_i11
; LDCHR
	pop	ecx
	movsx	eax,byte [ecx]
	push	eax
; LE
	pop	eax
	xor	ecx, ecx
	cmp	[esp], eax
	setle	cl
	mov	[esp], ecx
; JZ
	pop	eax
	cmp	eax, byte 0
	je	near $_i12
; RODATA
segment	.rodata
; ALIGN
align	4
; LABEL
$_i13:
; CHAR
	db	0x69
; CHAR
	db	0x6E
; CHAR
	db	0x20
; CHAR
	db	0x74
; CHAR
	db	0x68
; CHAR
	db	0x69
; CHAR
	db	0x72
; CHAR
	db	0x64
; CHAR
	db	0x20
; CHAR
	db	0x69
; CHAR
	db	0x66
; CHAR
	db	0x0A
; CHAR
	db	0x00
; TEXT
segment	.text
; ADDR
	push	dword $_i13
; CALL
	call	$_prints
; TRASH
	add	esp, 4
; LABEL
$_i12:
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
; RODATA
segment	.rodata
; ALIGN
align	4
; LABEL
$_i14:
; CHAR
	db	0x6F
; CHAR
	db	0x6C
; CHAR
	db	0x61
; CHAR
	db	0x00
; TEXT
segment	.text
; ADDR
	push	dword $_i14
; LDCHR
	pop	ecx
	movsx	eax,byte [ecx]
	push	eax
; GE
	pop	eax
	xor	ecx, ecx
	cmp	[esp], eax
	setge	cl
	mov	[esp], ecx
; JZ
	pop	eax
	cmp	eax, byte 0
	je	near $_i15
; RODATA
segment	.rodata
; ALIGN
align	4
; LABEL
$_i16:
; CHAR
	db	0x69
; CHAR
	db	0x6E
; CHAR
	db	0x20
; CHAR
	db	0x69
; CHAR
	db	0x66
; CHAR
	db	0x20
; CHAR
	db	0x65
; CHAR
	db	0x78
; CHAR
	db	0x70
; CHAR
	db	0x65
; CHAR
	db	0x63
; CHAR
	db	0x74
; CHAR
	db	0x65
; CHAR
	db	0x64
; CHAR
	db	0x20
; CHAR
	db	0x4A
; CHAR
	db	0x4C
; CHAR
	db	0x54
; CHAR
	db	0x0A
; CHAR
	db	0x00
; TEXT
segment	.text
; ADDR
	push	dword $_i16
; CALL
	call	$_prints
; TRASH
	add	esp, 4
; JMP
	jmp	dword $_i17
; LABEL
$_i15:
; RODATA
segment	.rodata
; ALIGN
align	4
; LABEL
$_i18:
; CHAR
	db	0x69
; CHAR
	db	0x6E
; CHAR
	db	0x20
; CHAR
	db	0x65
; CHAR
	db	0x6C
; CHAR
	db	0x73
; CHAR
	db	0x65
; CHAR
	db	0x20
; CHAR
	db	0x77
; CHAR
	db	0x69
; CHAR
	db	0x6C
; CHAR
	db	0x6C
; CHAR
	db	0x20
; CHAR
	db	0x6E
; CHAR
	db	0x65
; CHAR
	db	0x76
; CHAR
	db	0x65
; CHAR
	db	0x72
; CHAR
	db	0x20
; CHAR
	db	0x72
; CHAR
	db	0x65
; CHAR
	db	0x61
; CHAR
	db	0x63
; CHAR
	db	0x68
; CHAR
	db	0x20
; CHAR
	db	0x68
; CHAR
	db	0x65
; CHAR
	db	0x72
; CHAR
	db	0x65
; CHAR
	db	0x0A
; CHAR
	db	0x00
; TEXT
segment	.text
; ADDR
	push	dword $_i18
; CALL
	call	$_prints
; TRASH
	add	esp, 4
; LABEL
$_i17:
; LOCAL
	lea	eax, [ebp+-4]
	push	eax
; LOAD
	pop	eax
	push	dword [eax]
; LDCHR
	pop	ecx
	movsx	eax,byte [ecx]
	push	eax
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
; NE
	pop	eax
	xor	ecx, ecx
	cmp	[esp], eax
	setne	cl
	mov	[esp], ecx
; JZ
	pop	eax
	cmp	eax, byte 0
	je	near $_i19
; RODATA
segment	.rodata
; ALIGN
align	4
; LABEL
$_i20:
; CHAR
	db	0x69
; CHAR
	db	0x6E
; CHAR
	db	0x20
; CHAR
	db	0x6E
; CHAR
	db	0x6F
; CHAR
	db	0x74
; CHAR
	db	0x20
; CHAR
	db	0x65
; CHAR
	db	0x71
; CHAR
	db	0x75
; CHAR
	db	0x61
; CHAR
	db	0x6C
; CHAR
	db	0x20
; CHAR
	db	0x65
; CHAR
	db	0x78
; CHAR
	db	0x70
; CHAR
	db	0x65
; CHAR
	db	0x63
; CHAR
	db	0x74
; CHAR
	db	0x65
; CHAR
	db	0x64
; CHAR
	db	0x20
; CHAR
	db	0x4A
; CHAR
	db	0x45
; CHAR
	db	0x51
; CHAR
	db	0x0A
; CHAR
	db	0x00
; TEXT
segment	.text
; ADDR
	push	dword $_i20
; CALL
	call	$_prints
; TRASH
	add	esp, 4
; JMP
	jmp	dword $_i21
; LABEL
$_i19:
; RODATA
segment	.rodata
; ALIGN
align	4
; LABEL
$_i22:
; CHAR
	db	0x77
; CHAR
	db	0x69
; CHAR
	db	0x6C
; CHAR
	db	0x6C
; CHAR
	db	0x20
; CHAR
	db	0x6E
; CHAR
	db	0x65
; CHAR
	db	0x76
; CHAR
	db	0x65
; CHAR
	db	0x72
; CHAR
	db	0x20
; CHAR
	db	0x72
; CHAR
	db	0x65
; CHAR
	db	0x61
; CHAR
	db	0x63
; CHAR
	db	0x68
; CHAR
	db	0x20
; CHAR
	db	0x68
; CHAR
	db	0x65
; CHAR
	db	0x72
; CHAR
	db	0x65
; CHAR
	db	0x0A
; CHAR
	db	0x00
; TEXT
segment	.text
; ADDR
	push	dword $_i22
; CALL
	call	$_prints
; TRASH
	add	esp, 4
; LABEL
$_i21:
; RODATA
segment	.rodata
; ALIGN
align	4
; LABEL
$_i23:
; CHAR
	db	0x70
; CHAR
	db	0x6C
; CHAR
	db	0x61
; CHAR
	db	0x00
; TEXT
segment	.text
; ADDR
	push	dword $_i23
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
; LDCHR
	pop	ecx
	movsx	eax,byte [ecx]
	push	eax
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
; EQ
	pop	eax
	xor	ecx, ecx
	cmp	[esp], eax
	sete	cl
	mov	[esp], ecx
; JZ
	pop	eax
	cmp	eax, byte 0
	je	near $_i24
; RODATA
segment	.rodata
; ALIGN
align	4
; LABEL
$_i25:
; CHAR
	db	0x69
; CHAR
	db	0x6E
; CHAR
	db	0x20
; CHAR
	db	0x65
; CHAR
	db	0x71
; CHAR
	db	0x75
; CHAR
	db	0x61
; CHAR
	db	0x6C
; CHAR
	db	0x20
; CHAR
	db	0x65
; CHAR
	db	0x78
; CHAR
	db	0x70
; CHAR
	db	0x65
; CHAR
	db	0x63
; CHAR
	db	0x74
; CHAR
	db	0x65
; CHAR
	db	0x64
; CHAR
	db	0x20
; CHAR
	db	0x4A
; CHAR
	db	0x4E
; CHAR
	db	0x45
; CHAR
	db	0x0A
; CHAR
	db	0x00
; TEXT
segment	.text
; ADDR
	push	dword $_i25
; CALL
	call	$_prints
; TRASH
	add	esp, 4
; JMP
	jmp	dword $_i26
; LABEL
$_i24:
; RODATA
segment	.rodata
; ALIGN
align	4
; LABEL
$_i27:
; CHAR
	db	0x77
; CHAR
	db	0x69
; CHAR
	db	0x6C
; CHAR
	db	0x6C
; CHAR
	db	0x20
; CHAR
	db	0x6E
; CHAR
	db	0x65
; CHAR
	db	0x76
; CHAR
	db	0x65
; CHAR
	db	0x72
; CHAR
	db	0x20
; CHAR
	db	0x72
; CHAR
	db	0x65
; CHAR
	db	0x61
; CHAR
	db	0x63
; CHAR
	db	0x68
; CHAR
	db	0x20
; CHAR
	db	0x68
; CHAR
	db	0x65
; CHAR
	db	0x72
; CHAR
	db	0x65
; CHAR
	db	0x0A
; CHAR
	db	0x00
; TEXT
segment	.text
; ADDR
	push	dword $_i27
; CALL
	call	$_prints
; TRASH
	add	esp, 4
; LABEL
$_i26:
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
