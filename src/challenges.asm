;===================================================================
; SOME DEFINES
;===================================================================
sys_exit	equ     1d
sys_read	equ     3d
sys_write	equ     4d

stdin		equ     0d
stdout		equ     1d
stderr		equ     3d

EOL		equ	0x0A

;===================================================================
; HELPER FUNCTIONS
;===================================================================

section .text
;-------------------------------------------------------------------
; Delay
; Input:
;   RDI - delay 
;-------------------------------------------------------------------
global Delay
Delay:
	mov rcx, rdi
DelayLoop:
	loop DelayLoop
	ret

;-------------------------------------------------------------------
; RenderText
; Input:
;   RCX - address of a string to be printed 
;   RDX - it's size
; Destr: RAX, RBX, RCX, RDX 
;-------------------------------------------------------------------
RenderText:
	mov rax, sys_write
	mov rbx, stdout
	int 80h
	ret

;-------------------------------------------------------------------
; ReadText
; Input:
;   R8 - address of a buffer to store the input 
;   R9 - it's size
; Output:
;   RAX - number of chars written
; Destr: RAX, RBX, RCX, RDX, R10, R11
;-------------------------------------------------------------------
ReadText:
	push r14
	push r13
	push r12

	mov r12, r8
	mov r13, r9
	mov r14, 0 ; r10 = <number of chars read>

	mov byte [r8], 'A'

ReadOneChar:
	mov rax, sys_read
	mov rbx, stdin
	mov rcx, oneByte
	mov rdx, 1
	int 80h

	cmp byte [oneByte], EOL
	je ReadText_exit

	cmp r14, r13   ; < If buffer is full do not store new chars
	je ReadOneChar ; <

	mov r11b, byte [oneByte]
	mov byte [r12 + r14], r11b
	inc r14

	jmp ReadOneChar

ReadText_exit:
	mov rax, r14

	pop r12
	pop r13
	pop r14
	ret

section .data
oneByte		db	0

section .text
;-------------------------------------------------------------------
; Exit
;-------------------------------------------------------------------
Exit:
	mov rax, 1   ; sys_exit syscall 
	xor rbx, rbx ; Error code 0
	int 80h

;===================================================================
; WALKTHROUGH INDICATORS 
;===================================================================

section .data
walkthrough: 	db	0

;===================================================================
; PART (1): Buffer overflow
;===================================================================

extern hashPass
extern LVL1_accessDenied
extern LVL1_accessGranted

section .data
LVL1_invitation	db 	">> Enter password: ",EOL,">> "
LVL1_invSize	equ	$-LVL1_invitation
LVL1_hash	db	0x91,0xfd,0xb7,0x17,0x4a,0x53,0xd4,0xa0,0x4a,0xba,0x15,0xd7,0xbb,0x84,0xd7,0x30


section .data
global LVL1_interact
LVL1_interact:
	mov rcx, LVL1_invitation
	mov rdx, LVL1_invSize
	call RenderText

	mov r8, LVL1_smartBuffer
	mov r9, LVL1_smartBufferSize
	call ReadText

	mov rdi, LVL1_smartBuffer ; < rax = hashPass(LVL1_smartBuffer, rax, LVL1_hash)
	mov rsi, rax              ; <
	mov rdx, LVL1_hash        ; <
	call hashPass             ; <

	cmp rax, 0
	jmp LVL1_smartBufferEnd
LVL1_smartBuffer:	db 	"000010000100001000010000100001"
LVL1_smartBufferSize 	equ	$-LVL1_smartBuffer+1 ; <<<< VULNERABILITY: ONLY ONE CHARACTER
LVL1_smartBufferEnd:
	jne LVL1_passed

	call LVL1_accessDenied
	jmp LVL1_interact

LVL1_passed:
	call LVL1_accessGranted
	add byte [walkthrough], 1d
	ret
	
;===================================================================
; PART (2): Stack in buffer overflow change ret
;===================================================================

; extern hashPass
extern LVL2_accessDenied
extern LVL2_accessGranted

section .data
LVL2_invitation	db 	">> Enter password, if you dare: ",EOL,">> "
LVL2_invSize	equ	$-LVL2_invitation
LVL2_hash	db	0xd8,0x52,0x1b,0x31,0xa5,0xe7,0x51,0x69,0x3e,0xa8,0x5f,0x1e,0x53,0xac,0x03,0xed

section .text
global LVL2_interact
LVL2_interact:
	mov rcx, LVL2_invitation
	mov rdx, LVL2_invSize
	call RenderText
	
	call LVL2_checkBuffer

	cmp rax, 0
	jne LVL2_passed
	
	call LVL2_accessDenied
	jmp LVL2_interact

LVL2_passed:
	call LVL2_accessGranted
	add byte [walkthrough], 1d
	ret

; Returns pass condition in RAX
LVL2_checkBuffer:
%define LVL2_buffer \
	[rsp - 100d] ; HERE IS THE VULNERABILITY: IN THIS LITTLE 'd'
%define LVL2_bufferSz \
	100h
	
	sub sp, LVL2_bufferSz

	lea r8, LVL2_buffer
	mov r9, LVL2_bufferSz
	call ReadText

	lea rdi, LVL2_buffer ; < rax = hashPass(LVL2_buffer, rax, LVL2_hash)
	mov rsi, rax         ; <
	mov rdx, LVL2_hash   ; <
	call hashPass        ; <

	add sp, LVL2_bufferSz

	nop
	nop
	nop
	nop ; HERE SHOULD THE INJECTION HAPPEN
	ret

;===================================================================
; PART (3): Stack injection 
;===================================================================

; extern hashPass
extern LVL3_accessDenied
extern LVL3_accessGranted

section .data
LVL3_invitation	db 	">> Abandon all hope, ye who enter here hiera passwords: ",EOL,">> "
LVL3_invSize	equ	$-LVL3_invitation
LVL3_hash	db	0x91,0x9a,0x16,0x80,0x1f,0xa8,0x28,0x52,0xbe,0x75,0x44,0x42,0x0f,0x3a,0xa4,0x80

section .bss
LVL3_buffer 	resb	100d
LVL3_bufferSz	equ	100d


section .text
global LVL3_interact
LVL3_interact:
	mov rcx, LVL3_invitation
	mov rdx, LVL3_invSize
	call RenderText

	mov r8, LVL3_buffer
	mov r9, LVL3_bufferSz
	call ReadText

	mov rdi, LVL3_buffer ; < rax = hashPass(LVL3_buffer, rax, LVL3_hash)
	mov rsi, rax         ; <
	mov rdx, LVL3_hash   ; <
	call hashPass        ; <

	cmp rax, 0
	jne LVL3_passed
	
	call LVL3_accessDenied
	jmp LVL3_interact

LVL3_passed:
	call LVL3_accessGranted
	add byte [walkthrough], 1d
	ret

;===================================================================
; LA GRAND FINALE
;===================================================================

section .data
FIN_code_hash	db	0x32,0xfd,0x36,0x3e,0x68,0x70,0xd3,0x18,0x4d,0x18,0x31,0x1e,0x33,0x8c,0x86,0x05

extern FIN_cheaterEnding
extern FIN_hackerEnding
extern FIN_geniusEnding

section .text
global FIN_interact
FIN_interact:
	mov rdi, Delay         ; < rax = hashPass(Delay, ..., FIN_code_hash)
	mov rsi, 140h          ; < 
	mov rdx, FIN_code_hash ; < 
	call hashPass          ; < 

	xor rcx, rcx ; rcx = 0

	mov dl, byte [LVL1_smartBufferEnd] ; < rcx = <command at LVL1_smartBufferEnd is unchanged>
	xor dl, 'u'                        ; <
	cmp dl, 0d                         ; <
	mov r8, 1d                         ; <
	cmove rcx, r8                      ; <

	and rax, rcx ; rax = <command at LVL1_smartBufferEnd is unchanged> && <code hash is same>

	cmp rax, 1
	je FIN_integrity_check_passed

	call FIN_cheaterEnding
	ret

FIN_integrity_check_passed:
	cmp byte [walkthrough], 3d
	je FIN_all_checks_passed

	call FIN_hackerEnding
	ret

FIN_all_checks_passed:
	call FIN_geniusEnding
	ret

