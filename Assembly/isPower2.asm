.386 
.MODEL Flat, STDCALL 
.DATA 
.DATA? 
.CONST 
.CODE 
start: 
mov ecx, 13

xor eax, eax
;count the number of 1's
count:
	shr ecx, 1
    adc eax, 0
    test ecx,ecx
    jnz count
    
;if number of 1's is 1 exactly return 1, else return 0xFFFFFFFF

cmp eax,1
jz _end
xor eax,eax
_end:
sub eax,1
end start
