


/*
 *  Program with the integrated shellcode
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* func() {
    char test[] = "Hallo Welt!\n";
    printf("TESTING: %s", test);
    return test;
}

int main ()
{
    int size_of_string = 12;
    char* mem = (char*) malloc(size_of_string);
    char* test_ptr = func();

    // Store the value first --> printf will overwrite it !!!
    for (size_t i = 0; i < size_of_string; i++) {
        *(mem + i) = *(test_ptr + i);
    }
    printf("String: %s\n", mem);



    return 0;
}
