assume cs:code
data segment
	db 10 dup(0)
data ends
code segment
start:
	mov ax, data
	mov ds, ax
	;mov si, 0				;这个可以没有,因为dtoc有si入栈动作
	mov ax, 12666			;存放需要显示的数据
	call dtoc
		
	mov dh, 2
	mov dl, 2
	mov cl, 2
	mov si, 0
	call show_str
	mov ax, 4c00h
	int 21h

dtoc:
	push ax	
	push bx
	push cx
	push dx
	push si

	mov bx, 0

x:
	mov dx, 0	
	mov cx, 10
	div cx					;cx为除数
	mov cx, ax				;ax存商, 这个主要用于判断商是否为0 为0代表除完了
	add dx, '0'				;余数加'0'的ascll码值
	push dx					;将ascll码入栈
	inc bx
	jcxz f					;当cx为0的时候跳转
	jmp x

f:
	mov cx, bx				;bx里面存的是栈的长度

x1:
	pop ds:[si]				;一个一个将栈里面的内容push到ds:[di]地址
	inc si
	loop x1

	pop si
	pop dx
	pop cx
	pop bx
	pop ax

	ret

show_str:
	push ax
	push cx
	push dx
	push es
	push si
	push di

	mov ax, 0b800h	
	mov es, ax
	mov al, 160
	mul dh
	mov dh, 0
	add dl, dl
	add ax, dx
	mov di, ax
	mov ah, cl

y:
	mov cl, ds:[si]			
	mov ch, 0		
	jcxz f1
	mov al, cl	
	mov es:[di], ax
	inc si	
	inc di
	inc di	
	jmp y


f1:

pop di
	pop si
	pop es
	pop dx
	pop cx
	pop ax
	ret

code ends
end start
