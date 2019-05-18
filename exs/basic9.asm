; DATA
segment	.data
; ALIGN
align	4
; LABEL
$i:
; INTEGER
	dd	7
; RODATA
segment	.rodata
; ALIGN
align	4
; LABEL
$j:
; INTEGER
	dd	13
; DATA
segment	.data
; ALIGN
align	4
; LABEL
$p:
; DOUBLE
	dq	1.200000e+01
; RODATA
segment	.rodata
; ALIGN
align	4
; LABEL
$q:
; DOUBLE
	dq	1.450000e+01
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
$t:
; RODATA
segment	.rodata
; ALIGN
align	4
; LABEL
$_i2:
; CHAR
	db	0x6F
; CHAR
	db	0x6C
; CHAR
	db	0x61
; CHAR
	db	0x20
; CHAR
	db	0x73
; CHAR
	db	0x6F
; CHAR
	db	0x20
; CHAR
	db	0x71
; CHAR
	db	0x75
; CHAR
	db	0x65
; CHAR
	db	0x20
; CHAR
	db	0x63
; CHAR
	db	0x6F
; CHAR
	db	0x6E
; CHAR
	db	0x73
; CHAR
	db	0x74
; CHAR
	db	0x00
; DATA
segment	.data
; ID
	dd	$_i2
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
	sub	esp, 0
; RODATA
segment	.rodata
; ALIGN
align	4
; LABEL
$_i3:
; CHAR
	db	0x69
; CHAR
	db	0x20
; CHAR
	db	0x2D
; CHAR
	db	0x3E
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
; ADDR
	push	dword $i
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
; CHAR
	db	0x6A
; CHAR
	db	0x20
; CHAR
	db	0x2D
; CHAR
	db	0x3E
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
; ADDR
	push	dword $j
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
$_i5:
; CHAR
	db	0x70
; CHAR
	db	0x20
; CHAR
	db	0x2D
; CHAR
	db	0x3E
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
; ADDR
	push	dword $p
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
$_i6:
; CHAR
	db	0x71
; CHAR
	db	0x20
; CHAR
	db	0x2D
; CHAR
	db	0x3E
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
; ADDR
	push	dword $q
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
	push	dword 4
; COPY
	push	dword [esp]
; ADDR
	push	dword $i
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
$_i7:
; DOUBLE
	dq	1.100000e+00
; TEXT
segment	.text
; ADDR
	push	dword $_i7
; LOAD2
	pop	eax
	push	dword [eax+4]
	push	dword [eax]
; COPY2
	push	dword [esp+4]
	push	dword [esp+4]
; ADDR
	push	dword $p
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
$_i8:
; CHAR
	db	0x61
; CHAR
	db	0x66
; CHAR
	db	0x74
; CHAR
	db	0x65
; CHAR
	db	0x72
; CHAR
	db	0x20
; CHAR
	db	0x61
; CHAR
	db	0x73
; CHAR
	db	0x73
; CHAR
	db	0x69
; CHAR
	db	0x67
; CHAR
	db	0x6E
; CHAR
	db	0x6D
; CHAR
	db	0x65
; CHAR
	db	0x6E
; CHAR
	db	0x74
; CHAR
	db	0x20
; CHAR
	db	0x69
; CHAR
	db	0x20
; CHAR
	db	0x2D
; CHAR
	db	0x3E
; CHAR
	db	0x20
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
; ADDR
	push	dword $i
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
$_i9:
; CHAR
	db	0x61
; CHAR
	db	0x66
; CHAR
	db	0x74
; CHAR
	db	0x65
; CHAR
	db	0x72
; CHAR
	db	0x20
; CHAR
	db	0x61
; CHAR
	db	0x73
; CHAR
	db	0x73
; CHAR
	db	0x69
; CHAR
	db	0x67
; CHAR
	db	0x6E
; CHAR
	db	0x6D
; CHAR
	db	0x65
; CHAR
	db	0x6E
; CHAR
	db	0x74
; CHAR
	db	0x20
; CHAR
	db	0x70
; CHAR
	db	0x20
; CHAR
	db	0x2D
; CHAR
	db	0x3E
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
; ADDR
	push	dword $p
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
$_i10:
; CHAR
	db	0x73
; CHAR
	db	0x20
; CHAR
	db	0x2D
; CHAR
	db	0x3E
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
; ADDR
	push	dword $s
; LOAD
	pop	eax
	push	dword [eax]
; CALL
	call	$_prints
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
	db	0x74
; CHAR
	db	0x20
; CHAR
	db	0x2D
; CHAR
	db	0x3E
; CHAR
	db	0x20
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
; ADDR
	push	dword $t
; LOAD
	pop	eax
	push	dword [eax]
; CALL
	call	$_prints
; TRASH
	add	esp, 4
; CALL
	call	$_println
; RODATA
segment	.rodata
; ALIGN
align	4
; LABEL
$_i12:
; CHAR
	db	0x61
; CHAR
	db	0x66
; CHAR
	db	0x74
; CHAR
	db	0x65
; CHAR
	db	0x72
; CHAR
	db	0x20
; CHAR
	db	0x61
; CHAR
	db	0x73
; CHAR
	db	0x73
; CHAR
	db	0x69
; CHAR
	db	0x67
; CHAR
	db	0x6E
; CHAR
	db	0x6D
; CHAR
	db	0x65
; CHAR
	db	0x6E
; CHAR
	db	0x74
; CHAR
	db	0x00
; TEXT
segment	.text
; ADDR
	push	dword $_i12
; COPY
	push	dword [esp]
; ADDR
	push	dword $s
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
$_i13:
; CHAR
	db	0x73
; CHAR
	db	0x20
; CHAR
	db	0x2D
; CHAR
	db	0x3E
; CHAR
	db	0x20
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
; ADDR
	push	dword $s
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
extern	$_printi
; EXTRN
extern	$_println
; EXTRN
extern	$_prints
; EXTRN
extern	$_printd
