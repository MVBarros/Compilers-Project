; TEXT
segment	.text
; ALIGN
align	4
; GLOBL
global	$_hello:function
; LABEL
$_hello:
; ENTER
	push	ebp
	mov	ebp, esp
	sub	esp, 8
; LOCAL
	lea	eax, [ebp+8]
	push	eax
; LOAD
	pop	eax
	push	dword [eax]
; LOCAL
	lea	eax, [ebp+12]
	push	eax
; LOAD
	pop	eax
	push	dword [eax]
; MUL
	pop	eax
	imul	dword eax, [esp]
	mov	[esp], eax
; I2D
	fild	dword [esp]
	sub	esp, byte 4
	fstp	qword [esp]
; RODATA
segment	.rodata
; ALIGN
align	4
; LABEL
$_i1:
; DOUBLE
	dq	7.400000e+00
; TEXT
segment	.text
; ADDR
	push	dword $_i1
; LOAD2
	pop	eax
	push	dword [eax+4]
	push	dword [eax]
; DMUL
	fld	qword [esp]
	add	esp, byte 8
	fld	qword [esp]
	fmulp	st1
	fstp	qword [esp]
; COPY2
	push	dword [esp+4]
	push	dword [esp+4]
; LOCAL
	lea	eax, [ebp+-8]
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
	lea	eax, [ebp+-8]
	push	eax
; LOAD2
	pop	eax
	push	dword [eax+4]
	push	dword [eax]
; DPOP
	fld	qword [esp]
	add	esp, byte 8
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
	sub	esp, 28
; RODATA
segment	.rodata
; ALIGN
align	4
; LABEL
$_i2:
; DOUBLE
	dq	3.400000e+00
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
	lea	eax, [ebp+-12]
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
	lea	eax, [ebp+-12]
	push	eax
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
$_i3:
; DOUBLE
	dq	2.700000e+00
; TEXT
segment	.text
; ADDR
	push	dword $_i3
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
; LOCAL
	lea	eax, [ebp+-12]
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
; DADD
	fld	qword [esp]
	add	esp, byte 8
	fld	qword [esp]
	faddp	st1
	fstp	qword [esp]
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
	lea	eax, [ebp+-28]
	push	eax
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
; LOCAL
	lea	eax, [ebp+-28]
	push	eax
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
; COPY2
	push	dword [esp+4]
	push	dword [esp+4]
; LOCAL
	lea	eax, [ebp+-12]
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
	lea	eax, [ebp+-20]
	push	eax
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
; LOCAL
	lea	eax, [ebp+-12]
	push	eax
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
; LOCAL
	lea	eax, [ebp+-28]
	push	eax
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
; LOCAL
	lea	eax, [ebp+-12]
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
; EQ
	pop	eax
	xor	ecx, ecx
	cmp	[esp], eax
	sete	cl
	mov	[esp], ecx
; CALL
	call	$_printi
; TRASH
	add	esp, 4
; CALL
	call	$_println
; LOCAL
	lea	eax, [ebp+-12]
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
; RODATA
segment	.rodata
; ALIGN
align	4
; LABEL
$_i4:
; DOUBLE
	dq	3.000000e+00
; TEXT
segment	.text
; ADDR
	push	dword $_i4
; LOAD2
	pop	eax
	push	dword [eax+4]
	push	dword [eax]
; DSUB
	fld	qword [esp]
	add	esp, byte 8
	fld	qword [esp]
	fsubrp	st1
	fstp	qword [esp]
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
; CALL
	call	$_printi
; TRASH
	add	esp, 4
; CALL
	call	$_println
; LOCAL
	lea	eax, [ebp+-12]
	push	eax
; LOAD2
	pop	eax
	push	dword [eax+4]
	push	dword [eax]
; IMM
	push	dword 1
; IMM
	push	dword 1
; ADD
	pop	eax
	add	dword [esp], eax
; IMM
	push	dword 1
; ADD
	pop	eax
	add	dword [esp], eax
; I2D
	fild	dword [esp]
	sub	esp, byte 4
	fstp	qword [esp]
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
	lea	eax, [ebp+-12]
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
; DADD
	fld	qword [esp]
	add	esp, byte 8
	fld	qword [esp]
	faddp	st1
	fstp	qword [esp]
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
	lea	eax, [ebp+-28]
	push	eax
; LOAD2
	pop	eax
	push	dword [eax+4]
	push	dword [eax]
; IMM
	push	dword 7
; I2D
	fild	dword [esp]
	sub	esp, byte 4
	fstp	qword [esp]
; DADD
	fld	qword [esp]
	add	esp, byte 8
	fld	qword [esp]
	faddp	st1
	fstp	qword [esp]
; CALL
	call	$_printd
; TRASH
	add	esp, 8
; CALL
	call	$_println
; IMM
	push	dword 2
; I2D
	fild	dword [esp]
	sub	esp, byte 4
	fstp	qword [esp]
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
	lea	eax, [ebp+-28]
	push	eax
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
; LOCAL
	lea	eax, [ebp+-12]
	push	eax
; LOAD2
	pop	eax
	push	dword [eax+4]
	push	dword [eax]
; IMM
	push	dword 3
; I2D
	fild	dword [esp]
	sub	esp, byte 4
	fstp	qword [esp]
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
; IMM
	push	dword 1
; IMM
	push	dword 1
; CALL
	call	$_hello
; TRASH
	add	esp, 8
; DPUSH
	sub	esp, byte 8
	fstp	qword [esp]
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
	lea	eax, [ebp+-28]
	push	eax
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
; IMM
	push	dword 2
; IMM
	push	dword 2
; CALL
	call	$_hello
; TRASH
	add	esp, 8
; DPUSH
	sub	esp, byte 8
	fstp	qword [esp]
; CALL
	call	$_printd
; TRASH
	add	esp, 8
; CALL
	call	$_println
; IMM
	push	dword 1
; I2D
	fild	dword [esp]
	sub	esp, byte 4
	fstp	qword [esp]
; RODATA
segment	.rodata
; ALIGN
align	4
; LABEL
$_i5:
; DOUBLE
	dq	7.400000e+00
; TEXT
segment	.text
; ADDR
	push	dword $_i5
; LOAD2
	pop	eax
	push	dword [eax+4]
	push	dword [eax]
; DMUL
	fld	qword [esp]
	add	esp, byte 8
	fld	qword [esp]
	fmulp	st1
	fstp	qword [esp]
; CALL
	call	$_printd
; TRASH
	add	esp, 8
; CALL
	call	$_println
; IMM
	push	dword 3
; CALL
	call	$_factorial
; TRASH
	add	esp, 4
; DPUSH
	sub	esp, byte 8
	fstp	qword [esp]
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
	lea	eax, [ebp+-28]
	push	eax
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
; IMM
	push	dword 0
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
; POP
	pop	eax
; LEAVE
	leave
; RET
	ret
; EXTRN
extern	$_printd
; EXTRN
extern	$_println
; EXTRN
extern	$_printi
; EXTRN
extern	$_factorial
