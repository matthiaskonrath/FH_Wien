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



void get_notes(int* notenliste, const int notes);
int get_all_fives(int* notenliste, const int notes);
float get_mean(int* notenliste, const int notes);


/*
 * Main loop
 */
int main(int argc, char **argv)
{
	/*
	 * Get all the notes from the student
	 */
	const int notes = 10;
	int fives = 0;
	float mean = 0;
	int* notenliste = (int*) malloc(sizeof(int) * notes);

	// Get all the notes from the user and analyse them
	get_notes(notenliste, notes);
	fives = get_all_fives(notenliste, notes);
	mean = get_mean(notenliste, notes);

	printf("%s(*) Amount of notes: %d\n(*) Amount of fives: %d\n(*) Mean: %f\n", KGRN, notes, fives, mean);

	/*
	 * Random number generator
	 */
	srand(time(NULL));		/* Initialisierung */
	rand();  				/* Die erste Zufallszahl ist meist ungeeignet */
    int zufallszahl = 1+ (int)(100.0 * rand() / (RAND_MAX + 1.0));

	int guess = 0;
	for (size_t i = 0; i < 10; i++) {
		printf("%s(*) Please guess a number between 1 and 100: ", KGRN);
		scanf("%d", &guess);

		if (guess == zufallszahl) {
			printf("%s(*) You guessed right!\n", KGRN);
			break;
		} else {
			if (guess < zufallszahl) {
				printf("%s(*) You guessed too low!\n", KRED);
			} else {
				printf("%s(*) You guessed too high!\n", KRED);
			}
		}
	}

	/*
	 * Terminate the programm successfully
	 */
    return 0;
}

void get_notes(int* notenliste, const int notes) {
	int tmp_note = 0;

	for (size_t i = 0; i < notes; i++) {
		printf("%s(*) Enter note: ", KGRN);
		if (scanf("%d", &tmp_note) != 1 || (tmp_note < 1 && tmp_note > 5)) {
			exit(1);
		} else {
			*(notenliste +i) = tmp_note;
		}
	}
}

int get_all_fives(int* notenliste, const int notes) {
	int fives = 0;
	for (size_t i = 0; i < notes; i++) {
		if (*(notenliste +i) == 5) {
			fives += 1;
		}
	}
	return fives;
}

float get_mean(int* notenliste, const int notes) {
	float sum = 0;
	for (size_t i = 0; i < notes; i++) {
		sum += *(notenliste +i);
	}
	return (float)(sum / (float)notes);
}
