assume cs:code, ds:data, ss:stack

stack segment
    db 40 dup(99h)  
stack ends    


data segment
   db 10 dup(0)  
   string db 'hello$'
data ends     


code segment
start:
        mov ax, stack
        mov ss, ax
        
        mov ax, data
        mov ds, ax
        
        push 0102h
        push 0304h
        call mathFunc           
        add sp, 4h
           
        ; exit
        mov ah, 4ch
        int 21h

mathFunc:     
    push bp
    mov bp, sp
    sub sp, 10
    
    ;保护可能用到的寄存器
    push si
    push di
    push bx         
    
    mov ax, 0cccch
    mov bx, ss
    mov es, bx 
    ; 取出bp-2的位置里的值 给 di
    ;mov di, [bp-2]             
    mov di, bp
    sub di, 10
    mov cx, 5
    rep stosw
         
    mov ss:[bp-2], 0506h
    mov ss:[bp-4], 0708h
    mov ax, ss:[bp-2]
    add ax, ss:[bp-4]    
    mov ss:[bp-6], ax
    
    mov ax, ss:[bp+4]
    add ax, ss:[bp+6]   
    add ax, ss:[bp-6]
    
    pop bx
    pop di
    pop si       
       
    mov sp, bp 
    pop bp
    ret

code ends    

end start