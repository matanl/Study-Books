.386 
.MODEL Flat, STDCALL 
.DATA 
.DATA? 
.CONST 
.CODE 
start: 
	push 3
    push 5
    
    call pow
    ; result is 5^3=125
    
    pop ebx
    pop ebx


jmp _end

pow:
	push ebp
    mov ebp,esp
    push ebx
    
    ;if the power is 0 then return 1
    mov ebx,[ebp+12]
    cmp ebx,0
    jnz calc
    mov eax,1
    jmp end_pow
    
    ;calc the power
    calc:
    mov ebx, [ebp+12]
	dec ebx    
    push ebx
    push [ebp+8]
    call pow
    ;pop the inserted values
    pop ebx
    pop ebx
    ;multiply by the given number
    mul dword ptr[ebp+8]
    
    end_pow:
    pop ebx
    pop ebp
    ret

_end:
end start