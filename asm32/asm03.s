section .data                           
   inputMsg db 'Valeur : ' 
   lenInputMsg equ $-inputMsg                         
   outputMsg db '1337'
   lenOutputMsg equ $-outputMsg
   num dd '42'
  
section .bss           
   input resb 5
	
section .text          
   global _start
   	
_start:                
   mov eax, 4
   mov ebx, 1
   mov ecx, inputMsg
   mov edx, lenInputMsg
   int 80h

   mov eax, 3
   mov ebx, 2
   mov ecx, input  
   mov edx, 5          
   int 80h
    
   mov eax, 4
   mov ebx, 1
   mov ecx, outputMsg
   mov edx, lenOutputMsg
   int 80h
   
   cmp ecx,[num]
   je exit2
   
   exit1:
   mov eax, 1
   mov ebx, 1
   int 80h

   exit2:
   mov eax, 1
   mov ebx, 0
   int 80h
