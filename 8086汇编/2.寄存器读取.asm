;mov ax, 1122h
;mov bx, 3344H
;add ah, bl
;add bh, al   
           
; ax =  5522
; bx =  5544

;mov ax, 1122h
;mov bx, 1000h
;mov ds, bx
;mov ds:[0h], ax    


;mov ax, 1000h
;mov ds, ax
;mov al, [0]       


mov ax, 1000h
mov ds, ax
; mov [0], 66h
; mov byte ptr [0], 66h 
mov word ptr [0], 66h 
; 1000:0 66
; 1000:1 00
; 1000:2   
; 小端模式 
; 0066 中的高数据00放在高地址中   
; 低数据66放在低地址中