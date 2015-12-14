assume cs:codesg, ds:datasg
datasg segment
	db 'welcome to masm!'
	db '................'
datasg ends
;mov 'welcome to masm' to ...
codesg segment
	start:
	mov ax, datasg	
	mov ds, ax		;ds points datasg
	mov si, 0		;mark the beginning
	mov di, 16		;mark the end

	mov cx, 8		;loop 8 times
s:	mov ax, [si]	; ax = tmp
	mov [di], ax
	add si, 2
	add di, 2
	loop s

	mov ax, 4c00h
	int 21h

codesg ends
end start

;{
;	char src[32] = "welcome to masm!";	
;	int i, j;	
;	for(i = 0, j = 16; i < 16; i++, j++)
;	{
;		src[j] = src[i];
;	}
;}
