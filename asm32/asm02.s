section .data                          
   userMsg db '1337'
   lenUserMsg equ $-userMsg
            
section .text        
   global _start
	
_start:              
   ; print userMsg : 1337
   mov eax, 4
   mov ebx, 1
   mov ecx, userMsg
   mov edx, lenUserMsg
   int 80h  
    
   ; Exit code
   mov eax, 1
   mov ebx, 0
   int 80h

