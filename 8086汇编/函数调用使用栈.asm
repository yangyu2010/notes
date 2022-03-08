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
                   
        mov bx, ax
          
        ; exit
        mov ah, 4ch
        int 21h

; 22 23 24行代码执行前，空栈时
; 00 00 00 00 00 00 00 00 00 00
; 执行后 栈中数据目前是
; 00 00 00 00 13 00 44 33 22 11
; 其中11 22 33 44是push的数据 
; 其中 00 13 是调用call下一条指令的地址 函数调用完成后ip指向这个地址
; 
; 在函数调用中 不能直接pop 应该栈顶放的是返回的地址
; 需要访问数据要用到bp这个寄存器
; sp是堆栈指针 bp是基数指针
mathFunc:
    mov bp, sp
    mov ax, ss:[bp+2]
    add ax, ss:[bp+4]
    ret
        
code ends    

end start