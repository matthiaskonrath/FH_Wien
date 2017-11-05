//
//  main.c
//
//  Created by Matthias Konrath on 09.10.17.
//  Copyright © 2017 Matthias Konrath. All rights reserved.
//  Compile with: gcc -o main main.cpp -lssl -lcrypto
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

/*
 * Colors for the terminal
 */
#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"


char * stringString(char *haystack, char *needle);


/*
 * Main loop
 */
int main(int argc, char **argv)
{

    char haystack[] = "Dies ist ein Test";
    char needle[] = "is";

    char* needle_start_addr = stringString(haystack, needle);

    if (needle_start_addr != NULL) {
        printf("Found neddle at position %ld, pointer: %p, message: %s\n", needle_start_addr - haystack, needle_start_addr, needle_start_addr);
    }


	/*
	 * Terminate the programm successfully
	 */
    return 0;
}

char * stringString(char *haystack, char *needle) {
    for (size_t i_overall = 0; i_overall < strlen(haystack); i_overall++) {
        // Check if the end of the haystack was reached
        if (strlen(needle) + i_overall > strlen(haystack)) {
            return NULL;
        }
        // Check for matching characters
        for (size_t i_needle = 0; i_needle < strlen(needle); i_needle++) {
            // A matching character was found
            if (*(haystack + i_overall + i_needle) == *(needle + i_needle)) {
                // Check if the needle was found
                if (i_needle +1 == strlen(needle)) {
                    return (haystack + i_overall);
                }
            } else {
                // If no match was found break out of the inner for loop
                break;
            }
        }
    }

    return NULL;
}
