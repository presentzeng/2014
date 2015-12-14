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

s:	mov al,[bx]			;get value of datasg:[bx]
	and	al, 11011111b	;and operation
	mov	[bx], al		;after operation mov value back

	mov al,[5+bx]		
	or al,00100000b		;or operation
	mov [5+bx], al		
	inc	bx				;bx++
	loop s 				;return to s
codesg ends

end start

; Cstyle:

;main()
;{
;	int i;
;	i = 0;
;	do
;	{
;		a[i] = a[i] & 0xDF
;		b[i] = b[i] & 0x20
;		i++;
;	}while(i < 5);
;}








