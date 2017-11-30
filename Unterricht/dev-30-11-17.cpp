//
//  main.c
//
//  Created by Matthias Konrath
//  Copyright © 2017 Matthias Konrath. All rights reserved.
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
 *  Power function
 */
int pow(int val, int pow_val);


/*
 *  Function to reverse the order of the numbers (123456 --> 654321)
 */
int reverse_order(int number);


/*
 * Main loop
 */
int main(int argc, char **argv)
{
    /*
     *  Get a number from the user
     */
    int number = 0;
    printf("%s(*) Plase a number: ", KGRN);
	if (scanf("%i", &number) != 1)
        return 1;

    /*
     *  Print the reversed number
     */
    printf("%sThe reversed number: %i\n", KYEL, reverse_order(number));
    printf("%s", KNRM);

	/*
	 * Terminate the programm successfully
	 */
    return 0;
}


int pow(int val, int pow_val) {
	if (pow_val <= 0)
		return 1;
	return val * pow(val, pow_val -1);
}


int reverse_order(int number) {
    /*
     * Declare / Initialise the variables
     */
    int tmp_number = number;
    int rev_number = 0;
    int digits = 0;

    /*
     *  Calculate the amount of digits this number has
     */
    while(tmp_number != 0) {
        tmp_number = (int) (tmp_number/10);
        ++digits;
    }

    /*
     *  Do magic with pow()
     */
    for (size_t i = 1; i <= digits; i++) {
        tmp_number = (int)(((number) / pow(10, digits - i)));
        number -= tmp_number * (pow(10, digits - i));
        rev_number += tmp_number * pow(10, i-1);
    }

    return rev_number;
}
