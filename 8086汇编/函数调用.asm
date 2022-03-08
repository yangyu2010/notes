assume cs:code, ds:data, ss:stack

stack segment
    db 1h, 2h, 3h, 4h, 5h, 6h, 7h, 8h, 9h, 10h
stack ends    


data segment
   db 30 dup(3)  
   string db 'hello$'
data ends     


code segment
start:
        mov ax, stack
        mov ss, ax
        
        mov ax, data
        mov ds, ax
        
        call print           
                   
        mov ax, 1122h
        mov bx, 3344h
          
        ; exit
        mov ah, 4ch
        int 21h
        
 print:       
    mov dx, offset string
    mov ah, 9h
    int 21h 
    ret
        
code ends    

end start