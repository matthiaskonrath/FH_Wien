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


void swap(float *a, float *b);
void memswap(char *mem1, char *mem2, int size);
int firstPosOfChar(char *text, char c);
void capitalize(char *text);


/*
 * Main loop
 */
int main(int argc, char **argv)
{
	/*
	 * Terminate the programm successfully
	 */
    return 0;
}

void swap(float* a, float* b) {
	float tmp_storage = 0;

	tmp_storage = *a;
	*a = *b;
	*b = *a;

	return;
}

void memswap(char *mem1, char *mem2, int size) {
	void* tmp_memory_storage_prt = malloc(size);

	memcpy(tmp_memory_storage_prt, (void*) mem1, size);
	memcpy((void*) mem1, (void*) mem2, size);
	memcpy((void*) mem2, tmp_memory_storage_prt, size);

	return;
}

int firstPosOfChar(char *text, char c) {
	for (size_t i = 0; i < strlen(text); i++) {
		if (*(text +i) == c) {
			return i;
		}
	}
	return 0;
}

void capitalize(char *text) {
	// Capitalize the current character
	*text = toupper((unsigned char) *(text));

	for (size_t i = 1; i < strlen(text); i++) {
		// Check if the last character was a space if so capitalize the current character
		if (*(text -1 ) == 0x20) {
			*text = toupper((unsigned char) *(text + i));
		}
	}
	return;
}
