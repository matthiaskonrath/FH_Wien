//
//  main.c
//
//  Created by Matthias Konrath on 09.10.17.
//  Copyright © 2017 Matthias Konrath. All rights reserved.
//  Compile with: gcc -o main main.cpp -lssl -lcrypto
//

/*
 * Base program to produce the shellcode
 */
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printHelloWorld() {
    printf("Hello World!\n");
    exit(0);
}
int main(int argc, char **argv)
{
    printHelloWorld();
    return 0;
}
*/



/*
 * Shellcode
 100000f30:	55 	push	rbp
 100000f31:	48 89 e5 	mov	rbp, rsp
 100000f34:	48 83 ec 10 	sub	rsp, 16
 100000f38:	48 8d 3d 65 00 00 00 	lea	rdi, [rip + 101]
 100000f3f:	b0 00 	mov	al, 0
 100000f41:	e8 34 00 00 00 	call	52
 100000f46:	31 ff 	xor	edi, edi
 100000f48:	89 45 fc 	mov	dword ptr [rbp - 4], eax
 100000f4b:	e8 24 00 00 00 	call	36

*/


/*
 *  Program with the integrated shellcode
 */
#include <sys/mman.h>
#include <string.h>

int main ()
{
  /*
        Exit the program
        xor	edi, edi
        mov	dword ptr [rbp - 4], eax
        syscall
  */
    char code[] = {
        0x31, 0xff,
        0x89, 0x45, 0xfc,
        0xe8, 0x24, 0x00, 0x00, 0x00
    };

    void *buf;

    /* copy code to executable buffer */
    buf = mmap (0,sizeof(code),PROT_READ|PROT_WRITE|PROT_EXEC,
              MAP_PRIVATE|MAP_ANON,-1,0);
    memcpy (buf, code, sizeof(code));

    /* run code */
    ((void (*) (void))buf)();

    return 0;
}
