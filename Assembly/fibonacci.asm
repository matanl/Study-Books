.386 
.MODEL Flat, STDCALL 
.DATA 
.DATA? 
.CONST 
.CODE 
start:
 
push 5

call fibonacci

pop ebx

jmp _end


fibonacci:
push ebp
mov ebp, esp
push ebx
push esi

mov ebx, [ebp+8]
;simple cases, case 0 and 1, return 1
cmp ebx,1
jz return1
cmp ebx,2
jz return1
jmp continue

return1:
mov eax,1
jmp _end_fibonacci

continue:
;add fibonacci(n-1) + fibonacci(n-2)
;n-1
dec ebx
push ebx
call fibonacci
pop ebx
mov esi,eax
;n-2
dec ebx
push ebx
call fibonacci
pop ebx
add eax,esi

_end_fibonacci:
pop esi
pop ebx
pop ebp
ret

_end:
end start
