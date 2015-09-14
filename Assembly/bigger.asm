.386 
.MODEL Flat, STDCALL 
.DATA 
.DATA? 
.CONST 
.CODE 
start: 
	cmp eax,ebx
    jge next
    mov eax,ebx
    next:
    cmp eax, ecx
    jge next2
    mov eax, ecx
    next2:
    ;done
end start
