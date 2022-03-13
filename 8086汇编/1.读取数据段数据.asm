         
; ----------数据段 begin------------         
data segment   
    ; define byte
    ; define word
    ; db 'hello word$'
    ;dw 1011h 
    ;dw 2011h
    no dw 30h   
    age db 20h   
    
    string db 'hello word$'
data ends 
; ----------数据段 end------------  

; ----------代码段 begin------------  
code segment     
start:           

    mov ax, data
    mov ds, ax
    
    ; 读取数据段的数据 
    ; dw 10h
    ; dw 20h
    ; mov ax, ds:[0]
    ; mov bx, ds:[2]
    
    ; 读取数据段的数据 定义别名
    ;no dw 30h   
    ;age db 20h
    ;mov ax, no
    ;mov bl, age
      
    ; string的偏移地址
    mov dx, offset string
    mov ah, 9h
    int 21h
    
       
    ;mov dx, 0
    ;mov ah, 9h
    ;int 21h
                 
    ; 退出
    mov ax, 4c00h
    int 21h
code ends
; ----------代码段 end------------             

end start