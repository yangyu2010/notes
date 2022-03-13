assume cs:code, ds:data, ss:stack

stack segment
    db 30 dup(99h)  
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
                     
        mov bx, ax
          
        ; exit
        mov ah, 4ch
        int 21h

mathFunc:
    mov bp, sp      
    sub sp, 10
    
    mov ss:[bp-2], 0506h
    mov ss:[bp-4], 0708h
    mov ax, ss:[bp-2]
    add ax, ss:[bp-4]    
    mov ss:[bp-6], ax
    
    mov ax, ss:[bp+2]
    add ax, ss:[bp+4]   
    add ax, ss:[bp-6]
    
    mov sp, bp
    ret
        
code ends    

end startrt