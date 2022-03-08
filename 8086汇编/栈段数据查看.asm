assume cs:code, ds:data, ss:stack

stack segment
    db 20 dup(2)
stack ends    


data segment
   db 30 dup(3)
data ends     


code segment
start:
        mov ax, stack
        mov ss, ax
        
        mov ax, data
        mov ds, ax
        
        mov ax, 1122h
        mov bx, 3344h
        
        push ax
        push bx
        pop ax
        pop bx      
              
        ; exit
        mov ah, 4ch
        int 21h
code ends    

end start