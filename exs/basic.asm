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
	sub	esp, 0
; IMM
	push	dword 5
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
	sub	esp, 28
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
; LOCV
	push	dword [ebp+-4]
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
	push	dword 5
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
; LOCV
	push	dword [ebp+-8]
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
; LOCV
	push	dword [ebp+-4]
; LOCV
	push	dword [ebp+-8]
; ADD
	pop	eax
	add	dword [esp], eax
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
; LOCV
	push	dword [ebp+-12]
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
; LOCV
	push	dword [ebp+-12]
; COPY
	push	dword [esp]
; LOCAL
	lea	eax, [ebp+-4]
	push	eax
; STORE
	pop	ecx
	pop	eax
	mov	[ecx], eax
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
; LOCV
	push	dword [ebp+-4]
; IMM
	push	dword 4
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
; LOCV
	push	dword [ebp+-4]
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
; LOCV
	push	dword [ebp+-12]
; COPY
	push	dword [esp]
; LOCAL
	lea	eax, [ebp+-8]
	push	eax
; STORE
	pop	ecx
	pop	eax
	mov	[ecx], eax
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
; LOCV
	push	dword [ebp+-4]
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
; LOCV
	push	dword [ebp+-8]
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
	lea	eax, [ebp+-12]
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
; LOCV
	push	dword [ebp+-12]
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
	lea	eax, [ebp+-12]
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
	lea	eax, [ebp+-12]
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
; PUSH
	push	eax
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
	lea	eax, [ebp+-12]
	push	eax
; STORE
	pop	ecx
	pop	eax
	mov	[ecx], eax
; TRASH
	add	esp, 4
; CALL
	call	$_println
; PUSH
	push	eax
; TRASH
	add	esp, 4
; LOCV
	push	dword [ebp+-12]
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
	push	dword 1
; IMM
	push	dword 2
; IMM
	push	dword 3
; RODATA
segment	.rodata
; ALIGN
align	4
; LABEL
$_i3:
; DOUBLE
	dq	4.000000e+00
; TEXT
segment	.text
; ADDR
	push	dword $_i3
; LOAD2
	pop	eax
	push	dword [eax+4]
	push	dword [eax]
; CALL
	call	$_f5
; TRASH
	add	esp, 20
; PUSH
	push	eax
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
; LOCV
	push	dword [ebp+-12]
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
extern	$_printi
; EXTRN
extern	$_println
