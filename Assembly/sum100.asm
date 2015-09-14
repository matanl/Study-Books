.386 
.MODEL Flat, STDCALL 
.DATA 
.DATA? 
.CONST 
.CODE 
start: 
   	mov ecx, 100
	xor eax, eax
	sum:
		add eax, ecx
		loop sum
end start
