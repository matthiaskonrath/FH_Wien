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


/*
 * Calculated the middle out of multiple values
 */
 float get_user_input_middle(int vlaues);

/*
 * Calculate the amount of water (liters) for a given volume
 */
float claculate_needed_water(float* length, float* width, float* height);

/*
 * Get min value from user
 */
float get_min_value(int values);

/*
 * Check for short year
 */
bool check_short_year(int year);

/*
 * Show stars
 */
void show_starts(int number_of_stars);


/*
 * Main loop
 */
int main(int argc, char **argv)
{

	/*
	 * Get the middle from three values
	 */
	float middle = get_user_input_middle(3);
	printf("%s(*) Middle: %f\n", KBLU, middle);

	/*
	 * Calculate the nedded amount of water to fill a given volume
	 */
	float length, width, height, needed_amount_of_water;
	printf("%s(*) Calculated needed amount of water to fill up a volume!\n", KGRN);
	// Get the user inputs
	printf("%s(*) Length: ", KGRN);
	if (scanf("%f", &length) != 1)
		return 1;
	printf("%s(*) Width: ", KGRN);
	if (scanf("%f", &width) != 1)
		return 1;
	printf("%s(*) Height: ", KGRN);
	if (scanf("%f", &height) != 1)
		return 1;
	// Calculate the amount of water
	needed_amount_of_water = claculate_needed_water(&length, &width, &height);
	printf("%s(*) The needed amount of water to fill the volume: %f\n", KGRN, needed_amount_of_water);

	/*
	 * Get the smales user input out of three tries
	 */
	float min = get_min_value(3);
	printf("%s(*) Minimal user input: %f\n", KGRN, min);

	/*
	 * Check for short year
	 */
	int year = 0;
	printf("%s(*) Please enter a year: ", KGRN);
	if (scanf("%d", &year) != 1)
		return 1;
	if (check_short_year(year)) {
		printf("%s(*) This year is a short one!\n", KGRN);
	} else {
		printf("%s(*) This year is a long one!\n", KRED);
	}

	/*
	 * Show the user stars
	 */
	show_starts(6);

	/*
	 * Terminate the programm successfully
	 */
    return 0;
}


float get_user_input_middle(int values) {
	float sum = 0;
	float user_input = 0;

	for (size_t i = 0; i < values; i++) {
		printf("%s(*) Please enter a number: ", KGRN);
		if (scanf("%f", &user_input) != 1) {
			printf("%s<!> ERROR not a number provided!", KRED);
			exit(1);
		}
		sum += user_input;
	}

	return (sum / values);
}

float claculate_needed_water(float* length, float* width, float* height) {
	return (*length * *width * *height);
}

float get_min_value(int values) {
	float min = 0;
	float tmp_var = 0;

	for (size_t i = 0; i < values; i++) {
		printf("%s(*) Please enter a value: ", KGRN);
		if (scanf("%f", &tmp_var) != 1){
			printf("%s<!> NAN\n", KGRN);
			exit(1);
		} else {
			if (tmp_var < min) {
				min = tmp_var;
			}
		}
	}
	return min;
}

bool check_short_year(int year) {
	if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0)) {
		return true;
	} else {
		return false;
	}
}


void show_starts(int number_of_stars) {
	for (size_t i = number_of_stars; i > 0; i--) {
		for(int i0 = 0; i0 < i; i0++) {
        	printf("%s*", KGRN);
		}
		printf("\n");
	}
}
