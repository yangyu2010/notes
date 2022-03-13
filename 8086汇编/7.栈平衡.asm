assume cs:code, ds:data, ss:stack

stack segment
    db 10 dup(0)  
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
        
        push 1122h
        push 3344h
        call mathFunc           
        add sp, 4h
                    
        push 1122h
        push 3344h
        call mathFunc2           
                     
        mov bx, ax
          
        ; exit
        mov ah, 4ch
        int 21h

; j
;
;
;
;   
mathFunc2:
    mov bp, sp
    mov ax, ss:[bp+2]
    add ax, ss:[bp+4]
    ret 4

; add sp, 4h 
mathFunc:
    mov bp, sp
    mov ax, ss:[bp+2]
    add ax, ss:[bp+4]
    ret
        
code ends    

end start