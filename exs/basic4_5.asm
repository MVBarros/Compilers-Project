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
	sub	esp, 28
; IMM
	push	dword 2
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
; IMM
	push	dword 3
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
$_i1:
; DOUBLE
	dq	3.100000e+00
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
; LOCAL
	lea	eax, [ebp+-20]
	push	eax
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
; DOUBLE
	dq	4.500000e+00
; TEXT
segment	.text
; ADDR
	push	dword $_i2
; LOAD2
	pop	eax
	push	dword [eax+4]
	push	dword [eax]
; COPY2
	push	dword [esp+4]
	push	dword [esp+4]
; LOCAL
	lea	eax, [ebp+-28]
	push	eax
; STORE2
	pop	ecx
	pop	eax
	mov	[ecx], eax
	pop	eax
	mov	[ecx+4], eax
; TRASH
	add	esp, 8
; LOCAL
	lea	eax, [ebp+-4]
	push	eax
; LOAD
	pop	eax
	push	dword [eax]
; IMM
	push	dword 1
; LT
	pop	eax
	xor	ecx, ecx
	cmp	[esp], eax
	setl	cl
	mov	[esp], ecx
; JZ
	pop	eax
	cmp	eax, byte 0
	je	near $_i3
; RODATA
segment	.rodata
; ALIGN
align	4
; LABEL
$_i4:
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
	push	dword $_i4
; CALL
	call	$_prints
; TRASH
	add	esp, 4
; JMP
	jmp	dword $_i5
; LABEL
$_i3:
; RODATA
segment	.rodata
; ALIGN
align	4
; LABEL
$_i6:
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
	push	dword $_i6
; CALL
	call	$_prints
; TRASH
	add	esp, 4
; LABEL
$_i5:
; LOCAL
	lea	eax, [ebp+-8]
	push	eax
; LOAD
	pop	eax
	push	dword [eax]
; IMM
	push	dword 2
; GT
	pop	eax
	xor	ecx, ecx
	cmp	[esp], eax
	setg	cl
	mov	[esp], ecx
; JZ
	pop	eax
	cmp	eax, byte 0
	je	near $_i7
; RODATA
segment	.rodata
; ALIGN
align	4
; LABEL
$_i8:
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
	push	dword $_i8
; CALL
	call	$_prints
; TRASH
	add	esp, 4
; LABEL
$_i7:
; LOCAL
	lea	eax, [ebp+-8]
	push	eax
; LOAD
	pop	eax
	push	dword [eax]
; IMM
	push	dword 7
; LE
	pop	eax
	xor	ecx, ecx
	cmp	[esp], eax
	setle	cl
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
; IMM
	push	dword 1
; GE
	pop	eax
	xor	ecx, ecx
	cmp	[esp], eax
	setge	cl
	mov	[esp], ecx
; JZ
	pop	eax
	cmp	eax, byte 0
	je	near $_i11
; RODATA
segment	.rodata
; ALIGN
align	4
; LABEL
$_i12:
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
	push	dword $_i12
; CALL
	call	$_prints
; TRASH
	add	esp, 4
; JMP
	jmp	dword $_i13
; LABEL
$_i11:
; RODATA
segment	.rodata
; ALIGN
align	4
; LABEL
$_i14:
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
	push	dword $_i14
; CALL
	call	$_prints
; TRASH
	add	esp, 4
; LABEL
$_i13:
; LOCAL
	lea	eax, [ebp+-20]
	push	eax
; LOAD2
	pop	eax
	push	dword [eax+4]
	push	dword [eax]
; LOCAL
	lea	eax, [ebp+-28]
	push	eax
; LOAD2
	pop	eax
	push	dword [eax+4]
	push	dword [eax]
; DCMP
	fld	qword [esp+8]
	fld	qword [esp]
	add	esp, byte 12
	fsubp	st1
	fxtract
	ffree	st1
	fistp	dword [esp]
; IMM
	push	dword 0
; LT
	pop	eax
	xor	ecx, ecx
	cmp	[esp], eax
	setl	cl
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
	db	0x66
; CHAR
	db	0x6F
; CHAR
	db	0x75
; CHAR
	db	0x72
; CHAR
	db	0x74
; CHAR
	db	0x68
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
	db	0x34
; CHAR
	db	0x74
; CHAR
	db	0x68
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
	push	dword $_i18
; CALL
	call	$_prints
; TRASH
	add	esp, 4
; LABEL
$_i17:
; LOCAL
	lea	eax, [ebp+-28]
	push	eax
; LOAD2
	pop	eax
	push	dword [eax+4]
	push	dword [eax]
; LOCAL
	lea	eax, [ebp+-20]
	push	eax
; LOAD2
	pop	eax
	push	dword [eax+4]
	push	dword [eax]
; DCMP
	fld	qword [esp+8]
	fld	qword [esp]
	add	esp, byte 12
	fsubp	st1
	fxtract
	ffree	st1
	fistp	dword [esp]
; IMM
	push	dword 0
; GE
	pop	eax
	xor	ecx, ecx
	cmp	[esp], eax
	setge	cl
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
	db	0x66
; CHAR
	db	0x69
; CHAR
	db	0x74
; CHAR
	db	0x68
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
	push	dword $_i20
; CALL
	call	$_prints
; TRASH
	add	esp, 4
; LABEL
$_i19:
; LOCAL
	lea	eax, [ebp+-4]
	push	eax
; LOAD
	pop	eax
	push	dword [eax]
; LOCAL
	lea	eax, [ebp+-8]
	push	eax
; LOAD
	pop	eax
	push	dword [eax]
; NE
	pop	eax
	xor	ecx, ecx
	cmp	[esp], eax
	setne	cl
	mov	[esp], ecx
; JZ
	pop	eax
	cmp	eax, byte 0
	je	near $_i21
; RODATA
segment	.rodata
; ALIGN
align	4
; LABEL
$_i22:
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
	push	dword $_i22
; CALL
	call	$_prints
; TRASH
	add	esp, 4
; JMP
	jmp	dword $_i23
; LABEL
$_i21:
; RODATA
segment	.rodata
; ALIGN
align	4
; LABEL
$_i24:
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
	push	dword $_i24
; CALL
	call	$_prints
; TRASH
	add	esp, 4
; LABEL
$_i23:
; IMM
	push	dword 3
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
; LOCAL
	lea	eax, [ebp+-8]
	push	eax
; LOAD
	pop	eax
	push	dword [eax]
; EQ
	pop	eax
	xor	ecx, ecx
	cmp	[esp], eax
	sete	cl
	mov	[esp], ecx
; JZ
	pop	eax
	cmp	eax, byte 0
	je	near $_i25
; RODATA
segment	.rodata
; ALIGN
align	4
; LABEL
$_i26:
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
	push	dword $_i26
; CALL
	call	$_prints
; TRASH
	add	esp, 4
; JMP
	jmp	dword $_i27
; LABEL
$_i25:
; RODATA
segment	.rodata
; ALIGN
align	4
; LABEL
$_i28:
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
	push	dword $_i28
; CALL
	call	$_prints
; TRASH
	add	esp, 4
; LABEL
$_i27:
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
