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
    
    mov ss:[bp-2], 0506h
    mov ss:[bp-4], 0708h
    mov ax, ss:[bp-2]
    add ax, ss:[bp-4]    
    mov ss:[bp-6], ax
    
    mov ax, ss:[bp+4]
    add ax, ss:[bp+6]   
    add ax, ss:[bp-6]
    
    push 1112h
    push 1314h
    call mathFunc2           
    add sp, 4h
        
    mov sp, bp 
    pop bp
    ret

mathFunc2:     
    push bp
    mov bp, sp
    sub sp, 10
    
    mov ss:[bp-2], 1516h
    mov ss:[bp-4], 1718h
    mov ax, ss:[bp-2]
    add ax, ss:[bp-4]    
    mov ss:[bp-6], ax
    
    mov ax, ss:[bp+4]
    add ax, ss:[bp+6]   
    add ax, ss:[bp-6]
    
    mov sp, bp 
    pop bp
    ret
    
    
code ends    

end start