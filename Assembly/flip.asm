.386 
.MODEL Flat, STDCALL 
.DATA 
.DATA? 
.CONST 
.CODE 
start: 
mov eax, 0AABBCCDDh

xor ebx,ebx
mov ecx, 4

flip:
	shl ebx,8
	mov bl,al
    shr eax,8
    test eax,eax
    loop flip
mov eax,ebx

end start
