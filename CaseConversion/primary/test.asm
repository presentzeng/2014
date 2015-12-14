
assume cs:codesg, ds:datasg
datasg segment ;define data
	db 'BaSic'
	db 'MinIX'
datasg ends

codesg segment
start:
	mov ax, datasg
	mov ds, ax		;mov ds, datasg
	mov bx, 0		;for counting
	mov cx, 5

s:	mov al,[bx]		;get value of datasg:[bx]
	and	al, 11011111b	;and operation
	mov	[bx], al		;after operation mov value back
	inc	bx				;bx++
	loop s 				;return to s

	mov bx, 5
	mov cx, 5			;initial
s0:	mov al,[bx]			;another loop
	or al,00100000b		;or operation
	mov [bx], al
	inc bx
	loop s0
codesg ends

end start
