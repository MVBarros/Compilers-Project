; TEXT
segment	.text
; ALIGN
align	4
; GLOBL
global	$_strcmp:function
; LABEL
$_strcmp:
; ENTER
	push	ebp
	mov	ebp, esp
	sub	esp, 8
; IMM
	push	dword 0
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
	lea	eax, [ebp+8]
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
; ADD
	pop	eax
	add	dword [esp], eax
; LDCHR
	pop	ecx
	movsx	eax,byte [ecx]
	push	eax
; IMM
	push	dword 0
; NE
	pop	eax
	xor	ecx, ecx
	cmp	[esp], eax
	setne	cl
	mov	[esp], ecx
; LOCAL
	lea	eax, [ebp+12]
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
; ADD
	pop	eax
	add	dword [esp], eax
; LDCHR
	pop	ecx
	movsx	eax,byte [ecx]
	push	eax
; IMM
	push	dword 0
; NE
	pop	eax
	xor	ecx, ecx
	cmp	[esp], eax
	setne	cl
	mov	[esp], ecx
; AND
	pop	eax
	and	dword [esp], eax
; COPY
	push	dword [esp]
; JZ
	pop	eax
	cmp	eax, byte 0
	je	near $_i1
; TRASH
	add	esp, 4
; LOCAL
	lea	eax, [ebp+8]
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
; ADD
	pop	eax
	add	dword [esp], eax
; LDCHR
	pop	ecx
	movsx	eax,byte [ecx]
	push	eax
; LOCAL
	lea	eax, [ebp+12]
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
; ADD
	pop	eax
	add	dword [esp], eax
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
; LABEL
$_i1:
; JZ
	pop	eax
	cmp	eax, byte 0
	je	near $_i2
; LABEL
$_i3:
; LOCAL
	lea	eax, [ebp+-8]
	push	eax
; COPY
	push	dword [esp]
; INCR
	pop	eax
	add	dword [eax], 1
; LOAD
	pop	eax
	push	dword [eax]
; TRASH
	add	esp, 4
; LOCAL
	lea	eax, [ebp+8]
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
; ADD
	pop	eax
	add	dword [esp], eax
; LDCHR
	pop	ecx
	movsx	eax,byte [ecx]
	push	eax
; IMM
	push	dword 0
; NE
	pop	eax
	xor	ecx, ecx
	cmp	[esp], eax
	setne	cl
	mov	[esp], ecx
; LOCAL
	lea	eax, [ebp+12]
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
; ADD
	pop	eax
	add	dword [esp], eax
; LDCHR
	pop	ecx
	movsx	eax,byte [ecx]
	push	eax
; IMM
	push	dword 0
; NE
	pop	eax
	xor	ecx, ecx
	cmp	[esp], eax
	setne	cl
	mov	[esp], ecx
; AND
	pop	eax
	and	dword [esp], eax
; COPY
	push	dword [esp]
; JZ
	pop	eax
	cmp	eax, byte 0
	je	near $_i5
; TRASH
	add	esp, 4
; LOCAL
	lea	eax, [ebp+8]
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
; ADD
	pop	eax
	add	dword [esp], eax
; LDCHR
	pop	ecx
	movsx	eax,byte [ecx]
	push	eax
; LOCAL
	lea	eax, [ebp+12]
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
; ADD
	pop	eax
	add	dword [esp], eax
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
; LABEL
$_i5:
; JNZ
	pop	eax
	cmp	eax, byte 0
	jne	near $_i3
; LABEL
$_i4:
; LABEL
$_i2:
; LOCAL
	lea	eax, [ebp+12]
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
; ADD
	pop	eax
	add	dword [esp], eax
; LDCHR
	pop	ecx
	movsx	eax,byte [ecx]
	push	eax
; LOCAL
	lea	eax, [ebp+8]
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
; ADD
	pop	eax
	add	dword [esp], eax
; LDCHR
	pop	ecx
	movsx	eax,byte [ecx]
	push	eax
; SUB
	pop	eax
	sub	dword [esp], eax
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
; TEXT
segment	.text
; ALIGN
align	4
; GLOBL
global	$_strcpy:function
; LABEL
$_strcpy:
; ENTER
	push	ebp
	mov	ebp, esp
	sub	esp, 8
; IMM
	push	dword 0
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
	lea	eax, [ebp+8]
	push	eax
; LOAD
	pop	eax
	push	dword [eax]
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
	lea	eax, [ebp+12]
	push	eax
; LOAD
	pop	eax
	push	dword [eax]
; IMM
	push	dword 0
; NE
	pop	eax
	xor	ecx, ecx
	cmp	[esp], eax
	setne	cl
	mov	[esp], ecx
; COPY
	push	dword [esp]
; JZ
	pop	eax
	cmp	eax, byte 0
	je	near $_i6
; TRASH
	add	esp, 4
; LOCAL
	lea	eax, [ebp+12]
	push	eax
; LOAD
	pop	eax
	push	dword [eax]
; LDCHR
	pop	ecx
	movsx	eax,byte [ecx]
	push	eax
; IMM
	push	dword 0
; NE
	pop	eax
	xor	ecx, ecx
	cmp	[esp], eax
	setne	cl
	mov	[esp], ecx
; LABEL
$_i6:
; JZ
	pop	eax
	cmp	eax, byte 0
	je	near $_i7
; LABEL
$_i8:
; LOCAL
	lea	eax, [ebp+12]
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
; ADD
	pop	eax
	add	dword [esp], eax
; LDCHR
	pop	ecx
	movsx	eax,byte [ecx]
	push	eax
; COPY
	push	dword [esp]
; LOCAL
	lea	eax, [ebp+8]
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
; ADD
	pop	eax
	add	dword [esp], eax
; STORE
	pop	ecx
	pop	eax
	mov	[ecx], eax
; TRASH
	add	esp, 4
; LOCAL
	lea	eax, [ebp+-8]
	push	eax
; COPY
	push	dword [esp]
; LOAD
	pop	eax
	push	dword [eax]
; SWAP
	pop	eax
	pop	ecx
	push	eax
	mov	eax, ecx
	push	eax
; INCR
	pop	eax
	add	dword [eax], 1
; TRASH
	add	esp, 4
; LOCAL
	lea	eax, [ebp+12]
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
; ADD
	pop	eax
	add	dword [esp], eax
; LDCHR
	pop	ecx
	movsx	eax,byte [ecx]
	push	eax
; IMM
	push	dword 0
; NE
	pop	eax
	xor	ecx, ecx
	cmp	[esp], eax
	setne	cl
	mov	[esp], ecx
; JNZ
	pop	eax
	cmp	eax, byte 0
	jne	near $_i8
; LABEL
$_i9:
; LABEL
$_i7:
; IMM
	push	dword 0
; COPY
	push	dword [esp]
; LOCAL
	lea	eax, [ebp+8]
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
; ADD
	pop	eax
	add	dword [esp], eax
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
; TEXT
segment	.text
; ALIGN
align	4
; GLOBL
global	$_strchr:function
; LABEL
$_strchr:
; ENTER
	push	ebp
	mov	ebp, esp
	sub	esp, 8
; IMM
	push	dword 0
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
	lea	eax, [ebp+8]
	push	eax
; LOAD
	pop	eax
	push	dword [eax]
; LDCHR
	pop	ecx
	movsx	eax,byte [ecx]
	push	eax
; IMM
	push	dword 0
; JEQ
	pop	eax
	pop	ecx
	cmp	ecx, eax
	je	near $_i10
; LABEL
$_i11:
; LOCAL
	lea	eax, [ebp+8]
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
; ADD
	pop	eax
	add	dword [esp], eax
; LDCHR
	pop	ecx
	movsx	eax,byte [ecx]
	push	eax
; LOCAL
	lea	eax, [ebp+12]
	push	eax
; LOAD
	pop	eax
	push	dword [eax]
; JNE
	pop	eax
	pop	ecx
	cmp	ecx, eax
	jne	near $_i13
; LOCAL
	lea	eax, [ebp+8]
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
; ADD
	pop	eax
	add	dword [esp], eax
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
; JMP
	jmp	dword $_i12
; JMP
	jmp	dword $_i14
; LABEL
$_i13:
; LOCAL
	lea	eax, [ebp+-8]
	push	eax
; COPY
	push	dword [esp]
; INCR
	pop	eax
	add	dword [eax], 1
; LOAD
	pop	eax
	push	dword [eax]
; TRASH
	add	esp, 4
; LABEL
$_i14:
; LOCAL
	lea	eax, [ebp+8]
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
; ADD
	pop	eax
	add	dword [esp], eax
; LDCHR
	pop	ecx
	movsx	eax,byte [ecx]
	push	eax
; IMM
	push	dword 0
; NE
	pop	eax
	xor	ecx, ecx
	cmp	[esp], eax
	setne	cl
	mov	[esp], ecx
; JNZ
	pop	eax
	cmp	eax, byte 0
	jne	near $_i11
; LABEL
$_i12:
; LABEL
$_i10:
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
extern	$_factorial
