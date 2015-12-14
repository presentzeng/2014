;用movsb 从ds:si 拷贝到 es:di
assume cs:code

code segment
start:
	mov ax, cs	
	mov ds, ax
	mov si, offset do0	;源地址初始化
	mov ax, 0		;目的地址初始化
	mov es, ax		
	mov di, 200h		;移到0:0200h地址
	mov cx, offset do0end-offset do0
	cld
	rep movsb

	mov ax, 0		;修改中断向量表
	mov es, ax
	mov word ptr es:[0*4], 200h
	mov word ptr es:[0*4+2], 0	

	mov ax, 1000h		;做好准备工作后执行溢出操作
	mov bh, 1
	div bh
	mov ax, 4c00h
	int 21h

do0:				;被移动的代码
	jmp short do0start
	db "overflow!"

do0start:
	mov ax, cs
	mov ds, ax
	mov si,202h		;202h指的就是overflow的地址

	mov ax, 0b800h	
	mov es, ax
	mov di, 12*160 + 36*2
	mov cx, 9

s:
       	mov ah, 01000010B
	mov al, [si]
	mov es:[di], ax
	inc si
	add di, 2
	loop s

	mov ax, 4c00h
	int 21h

do0end:nop
code ends
end start
