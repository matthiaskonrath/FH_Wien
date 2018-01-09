


/*
 *  Program with the integrated shellcode
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* func() {
    char test[] = "Hallo Welt!\n";
    //printf("");
    return test;
}

int main ()
{

    char* test_ptr = func();

    // OPTION A (for the normal guys)
    // Store the value first --> printf will overwrite it !!!
    // int size_of_string = 12;
    // char* mem = (char*) malloc(size_of_string);
    // for (size_t i = 0; i < size_of_string; i++) {
    //     *(mem + i) = *(test_ptr + i);
    // }
    // printf("String: %s", mem);


    // OPTION B (just for real hackers !!!)
    // Manipulate the registers
    __asm__ ("subq $100, %rsp");
    printf("String: %s", test_ptr);
    __asm__ ("addq $100, %rsp");




    return 0;
}
