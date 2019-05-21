; TEXT
segment	.text
; ALIGN
align	4
; GLOBL
global	$_f5:function
; LABEL
$_f5:
; ENTER
	push	ebp
	mov	ebp, esp
	sub	esp, 4
; IMM
	push	dword 5
; LOCAL
	lea	eax, [ebp+8]
	push	eax
; LOAD
	pop	eax
	push	dword [eax]
; MUL
	pop	eax
	imul	dword eax, [esp]
	mov	[esp], eax
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
global	$_entry:function
; LABEL
$_entry:
; ENTER
	push	ebp
	mov	ebp, esp
	sub	esp, 32
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
; LOCAL
	lea	eax, [ebp+-8]
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
; IMM
	push	dword 5
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
; LOCAL
	lea	eax, [ebp+-12]
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
; LOCAL
	lea	eax, [ebp+-8]
	push	eax
; LOAD
	pop	eax
	push	dword [eax]
; LOCAL
	lea	eax, [ebp+-12]
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
	lea	eax, [ebp+-16]
	push	eax
; STORE
	pop	ecx
	pop	eax
	mov	[ecx], eax
; TRASH
	add	esp, 4
; LOCAL
	lea	eax, [ebp+-16]
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
; LOCAL
	lea	eax, [ebp+-16]
	push	eax
; LOAD
	pop	eax
	push	dword [eax]
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
; IMM
	push	dword 4
; ADD
	pop	eax
	add	dword [esp], eax
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
; IMM
	push	dword 2
; MUL
	pop	eax
	imul	dword eax, [esp]
	mov	[esp], eax
; CALL
	call	$_printi
; TRASH
	add	esp, 4
; CALL
	call	$_println
; LOCAL
	lea	eax, [ebp+-16]
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
	call	$_printi
; TRASH
	add	esp, 4
; CALL
	call	$_println
; LOCAL
	lea	eax, [ebp+-12]
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
; LOCAL
	lea	eax, [ebp+-16]
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
	lea	eax, [ebp+-16]
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
; LOCAL
	lea	eax, [ebp+-16]
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
; CALL
	call	$_printi
; TRASH
	add	esp, 4
; CALL
	call	$_println
; LOCAL
	lea	eax, [ebp+-16]
	push	eax
; COPY
	push	dword [esp]
; INCR
	pop	eax
	add	dword [eax], 1
; LOAD
	pop	eax
	push	dword [eax]
; CALL
	call	$_printi
; TRASH
	add	esp, 4
; RODATA
segment	.rodata
; ALIGN
align	4
; LABEL
$_i1:
; DOUBLE
	dq	1.970000e+01
; TEXT
segment	.text
; ADDR
	push	dword $_i1
; LOAD2
	pop	eax
	push	dword [eax+4]
	push	dword [eax]
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
; DADD
	fld	qword [esp]
	add	esp, byte 8
	fld	qword [esp]
	faddp	st1
	fstp	qword [esp]
; D2I
	fld	qword [esp]
	add	esp, byte 4
	fistp	dword [esp]
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
; CALL
	call	$_println
; CALL
	call	$_println
; CALL
	call	$_println
; LOCAL
	lea	eax, [ebp+-8]
	push	eax
; LOAD
	pop	eax
	push	dword [eax]
; COPY
	push	dword [esp]
; JZ
	pop	eax
	cmp	eax, byte 0
	je	near $_i3
; TRASH
	add	esp, 4
; LOCAL
	lea	eax, [ebp+-12]
	push	eax
; LOAD
	pop	eax
	push	dword [eax]
; LABEL
$_i3:
; CALL
	call	$_printi
; TRASH
	add	esp, -1
; CALL
	call	$_println
; LOCAL
	lea	eax, [ebp+-16]
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
$_i4:
; DOUBLE
	dq	4.000000e+00
; TEXT
segment	.text
; ADDR
	push	dword $_i4
; LOAD2
	pop	eax
	push	dword [eax+4]
	push	dword [eax]
; IMM
	push	dword 3
; IMM
	push	dword 2
; IMM
	push	dword 27
; CALL
	call	$_f5
; TRASH
	add	esp, 20
; PUSH
	push	eax
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
; LOCAL
	lea	eax, [ebp+-16]
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
; IMM
	push	dword 3
; IMM
	push	dword 4
; AND
	pop	eax
	and	dword [esp], eax
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
; LOCAL
	lea	eax, [ebp+-16]
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
extern	$_printi
; EXTRN
extern	$_println
; EXTRN
extern	$_factorial
