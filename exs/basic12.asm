; DATA
segment	.data
; ALIGN
align	4
; LABEL
$i:
; INTEGER
	dd	7
; DATA
segment	.data
; ALIGN
align	4
; LABEL
$ptr:
; ID
	dd	$i
; DATA
segment	.data
; ALIGN
align	4
; LABEL
$s:
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
	db	0x0A
; CHAR
	db	0x00
; DATA
segment	.data
; ID
	dd	$_i1
; DATA
segment	.data
; ALIGN
align	4
; LABEL
$sptr:
; ID
	dd	$s
; DATA
segment	.data
; ALIGN
align	4
; LABEL
$r:
; DOUBLE
	dq	3.220000e+01
; DATA
segment	.data
; ALIGN
align	4
; LABEL
$rptr:
; ID
	dd	$r
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
; RODATA
segment	.rodata
; ALIGN
align	4
; LABEL
$_i2:
; DOUBLE
	dq	1.530000e+01
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
; RODATA
segment	.rodata
; ALIGN
align	4
; LABEL
$_i3:
; CHAR
	db	0x6F
; CHAR
	db	0x6C
; CHAR
	db	0x61
; CHAR
	db	0x20
; CHAR
	db	0x6F
; CHAR
	db	0x6C
; CHAR
	db	0x61
; CHAR
	db	0x0A
; CHAR
	db	0x00
; TEXT
segment	.text
; ADDR
	push	dword $_i3
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
; ADDR
	push	dword $ptr
; LOAD
	pop	eax
	push	dword [eax]
; LOAD
	pop	eax
	push	dword [eax]
; CALL
	call	$_printi
; TRASH
	add	esp, 4
; CALL
	call	$_println
; ADDR
	push	dword $ptr
; LOAD
	pop	eax
	push	dword [eax]
; IMM
	push	dword 0
; ADD
	pop	eax
	add	dword [esp], eax
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
	lea	eax, [ebp+-4]
	push	eax
; COPY
	push	dword [esp]
; ADDR
	push	dword $ptr
; STORE
	pop	ecx
	pop	eax
	mov	[ecx], eax
; TRASH
	add	esp, 4
; ADDR
	push	dword $ptr
; LOAD
	pop	eax
	push	dword [eax]
; LOAD
	pop	eax
	push	dword [eax]
; CALL
	call	$_printi
; TRASH
	add	esp, 4
; CALL
	call	$_println
; ADDR
	push	dword $sptr
; LOAD
	pop	eax
	push	dword [eax]
; IMM
	push	dword 0
; IMM
	push	dword 4
; MUL
	pop	eax
	imul	dword eax, [esp]
	mov	[esp], eax
; ADD
	pop	eax
	add	dword [esp], eax
; LOAD
	pop	eax
	push	dword [eax]
; CALL
	call	$_prints
; TRASH
	add	esp, 4
; LOCAL
	lea	eax, [ebp+-16]
	push	eax
; COPY
	push	dword [esp]
; ADDR
	push	dword $sptr
; STORE
	pop	ecx
	pop	eax
	mov	[ecx], eax
; TRASH
	add	esp, 4
; ADDR
	push	dword $sptr
; LOAD
	pop	eax
	push	dword [eax]
; IMM
	push	dword 0
; IMM
	push	dword 4
; MUL
	pop	eax
	imul	dword eax, [esp]
	mov	[esp], eax
; ADD
	pop	eax
	add	dword [esp], eax
; LOAD
	pop	eax
	push	dword [eax]
; CALL
	call	$_prints
; TRASH
	add	esp, 4
; ADDR
	push	dword $rptr
; LOAD
	pop	eax
	push	dword [eax]
; IMM
	push	dword 0
; IMM
	push	dword 8
; MUL
	pop	eax
	imul	dword eax, [esp]
	mov	[esp], eax
; ADD
	pop	eax
	add	dword [esp], eax
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
; ADDR
	push	dword $rptr
; LOAD
	pop	eax
	push	dword [eax]
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
; COPY
	push	dword [esp]
; ADDR
	push	dword $rptr
; STORE
	pop	ecx
	pop	eax
	mov	[ecx], eax
; TRASH
	add	esp, 4
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
