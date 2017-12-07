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
#include <math.h>



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
 *  Some mathematical functions
 */
 // X
float linear_function(float x) {
    return x;
 }
// X*X
float power2_function(float x) {
    return pow(x, 2) - 4;
}
// X*X*X
float power3_function(float x) {
    return pow(x, 3);
}


/*
 *  Function the calculate the mean
 */
float get_mean(float x0, float x1) {
    return ((x0 + x1) / 2);
}


/*
 *  Check if there is a null point between two points
 */
bool check_for_null_point(float x0, float x1, float (*function)(float)) {
    if (function(x1) * function(x0) < 0) {
        return true;
    } else {
        return false;
    }
}


/*
 *  Check if the target presision is reached (returns false is the presission is reached)
 */
bool is_presision_reached(float x0, float x1, float epsilon, float (*function)(float)) {
    if ((function(x1) - function(x0)) > epsilon or (function(x0) - function(x1)) > epsilon) {
        return true;
    } else {
        return false;
    }
}


/*
 *  Show the null point details
 */
void show_results(float x0, float x1, int steps) {
    if (x0 == x1) {
        printf("%s(*) Found null point at: %f\n", KGRN, x0);
    } else {
        printf("%s(*) Closest point (x0): %f\n", KGRN, x0);
        printf("%s(*) Closest point (x1): %f\n", KGRN, x1);
    }
    printf("%s(*) Needed steps: %d\n", KGRN, steps);
}


/*
 *  Show start values
 */
void show_start_values(float x0, float x1, float epsilon) {
    printf("%s(*) Start point (x0): %f\n", KMAG, x0);
    printf("%s(*) Start point (x1): %f\n", KMAG, x1);
    printf("%s(*) Epsilon: %f\n", KMAG, epsilon);
}

/*
 *  Find the null point for a given function
 *  (function has to have only one parameter || FLOAT)
 */
float find_null_point(float x0, float x1, float epsilon, float (*function)(float)) {
    float mean = 0;
    int steps = 0;
    int max_allowed_steps = 10000;

    // Show the user the start values
    show_start_values(x0, x1, epsilon);

    // Check if there is a null point between the start and stop
    if (!check_for_null_point(x0, x1, function)) {
        printf("%s<!> There is no null point corssing (or multiple)!\n", KRED);
        return 0;
    } else {
        while (is_presision_reached(x0, x1, epsilon, function)) {
            if (steps > max_allowed_steps) {
                printf("%s<!> There are too many calculations!\n", KRED);
                return 0;
            }
            steps++;
            // Calculate the mean
            mean = get_mean(x0, x1);
            // Check if the real mean was found
            if (!check_for_null_point(x0, mean, function) and !check_for_null_point(x1, mean, function)) {
                show_results(x0, x1, steps);
                return mean;
            } else if (check_for_null_point(x0, mean, function)) {
                // Check if the point is closer to x1
                x1 = mean;
            } else {
                // Check if the point is closer to x0
                x0 = mean;
            }
        }
    }
    // Show the user the
    show_results(x0, x1, steps);
    return 0;
}



/*
 * Main loop
 */
int main(int argc, char **argv)
{
    // Calcute with linear functions
    find_null_point(-11, 10, 0.001, &linear_function);
    find_null_point(11, -10, 0.001, &linear_function);
    find_null_point(-10, 10, 0.001, &linear_function);

    // Calculate with more complex curves
    find_null_point(-11, 0, 0.001, &power2_function);


	/*
	 * Terminate the programm successfully and reset the colors for the terminal
	 */
    printf("%s", KNRM);
    return 0;
}
