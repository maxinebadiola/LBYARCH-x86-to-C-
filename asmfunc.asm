section .data
section .text
    bits 64
    default rel
    global dotProduct64

; callee adjustment
; 1st param n (RCX)
; 2nd param sdot (RDX)
; 3rd param vectorA (R8)
; 4th param vectorB (R9)
dotProduct64:
    xor r10, r10 ;counter
    movss xmm3, dword [rdx] ;sdot
    ;if n=0 terminate
    cmp rcx, 0  
    jle end

loop:
    cmp r10, rcx  
    jge end
    
    ;load vectors A and B elements 
    movss xmm0, dword [r8 + r10 * 4] ;vectorA element 
    movss xmm1, dword [r9 + r10 * 4] ;vectorB element 
    
     ;multiply Ai * Bi 
     mulss xmm0, xmm1  
    
     ;add to total sdot 
     addss xmm3, xmm0  
    
     inc r10  
     jmp loop 

end:
   movss dword [rdx], xmm3 ;sdot
   ret  
