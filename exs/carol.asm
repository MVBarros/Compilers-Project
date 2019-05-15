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
	sub	esp, 4
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
$_i1:
; DOUBLE
	dq	4.000000e+00
; TEXT
segment	.text
; ADDR
	push	dword $_i1
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
