.386 
.MODEL Flat, STDCALL 
.DATA 
string1 db "Hello World!",0
string2 db "Hello World!",0
.DATA? 
.CONST 
.CODE 
start:
push offset string2
push offset string1

call strcmp

pop ebx
pop ebx    

jmp _end


strcmp:
push ebp
mov ebp,esp
push edi
push esi
push ebx

mov edi, [ebp+8]
mov esi, [ebp+12]
dec edi
dec esi

compare:
	inc edi
    inc esi
    mov ebx, [edi]
	cmp ebx,[esi]
    jnz false
    cmp edi,0
    jz true
    jmp compare
    
false:
	mov eax,-1
    jmp strcmp_end
true:
	mov eax,0

strcmp_end:
pop ebx
pop esi
pop edi
pop ebp
ret


_end:
end start
