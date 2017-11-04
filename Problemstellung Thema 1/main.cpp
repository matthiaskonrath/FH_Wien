//
//  main.c
//  myHelloWorld
//
//  Created by Matthias Konrath on 09.10.17.
//  Copyright © 2017 Matthias Konrath. All rights reserved.
//  Compile with: gcc -o main main.cpp -lssl -lcrypto
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/aes.h>
#include <openssl/rand.h>

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
 * Functions for the hello world programm
 */
static void hex_print(const void* pv, size_t len);
void show_hello_world();

/*
 * Function to convert from °C to F
 */
float convert_temperature_to_f(float temp_in_c);

/*
 * Check if the supplied value is a valid postal code
 */
bool check_postal_code(int postal_code);

/*
 * Get user input an add them together
 */
void add_multiple_user_inupts();

/*
 * Main loop
 */
int main(int argc, char **argv)
{
	/*
	 * Show the hello world message on the screen
	 */
	show_hello_world();
	printf("\n");

	/*
	 * Convert °C to F
	 */
	float temp_in_c = 0;
	printf("%s(*) Please enter a temperature in °C that you want to have converted in F: ", KGRN);
	scanf("%f", &temp_in_c);
	printf("%s(*) %f°C is %fF", KGRN, temp_in_c, convert_temperature_to_f(temp_in_c));
	printf("\n\n");

	/*
	 * Check the postal code from the user
	 */
	int postal_code = 0;
	printf("%s(*) Please enter a valid postal code: ", KGRN);
	scanf("%d", &postal_code);
	// Chekc if the postal code is valid
	if (check_postal_code(postal_code)){
		printf("%s(*) The postal code is valid!", KGRN);
	} else {
		printf("%s(*) The postal code is invalid!", KRED);
	}
	printf("\n\n");

	/*
	 * Continusly add user input together
	 */
	add_multiple_user_inupts();

	/*
	 * Terminate the programm successfully
	 */
    return 0;
}

static void hex_print(const void* pv, size_t len) {
    const unsigned char * p = (const unsigned char*)pv;
    if (NULL == pv)
        printf("NULL");
    else
    {
        size_t i = 0;
        for (; i<len;++i)
            printf("%02X ", *p++);
    }
    printf("\n");
}

void show_hello_world(){
	int keylength = 256;
	unsigned char aes_key[] = {0xDD, 0x0E, 0xD4, 0xD5, 0x2F, 0x1A, 0x65, 0x17, 0x13, 0x82, 0xB9, 0xA3, 0x51, 0x70, 0xBC, 0xCB, 0x95, 0xBA, 0xCE, 0xAE, 0x79, 0x86, 0x21, 0xD0, 0x25, 0x0A, 0x54, 0x36, 0x63, 0xF4, 0x8C, 0x82};
	unsigned char iv[] = {0xAE, 0xF6, 0x9E, 0x46, 0x68, 0xB6, 0x4D, 0xC2, 0x06, 0x8E, 0x72, 0x3F, 0x23, 0xEE, 0x9B, 0x99};
	unsigned char hello_world_string_encrypted[] = {0xC9, 0xFA, 0xE9, 0x83, 0x6D, 0x57, 0x3E, 0xAB, 0x8F, 0x4F, 0x9D, 0x83, 0x06, 0xB3, 0x02, 0x83, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

	size_t inputslength = sizeof(hello_world_string_encrypted);
	const size_t encslength = ((inputslength + AES_BLOCK_SIZE) / AES_BLOCK_SIZE) * AES_BLOCK_SIZE;
	unsigned char dec_out[inputslength];
	memset(dec_out, 0, sizeof(dec_out));

	AES_KEY dec_key;
	AES_set_decrypt_key(aes_key, keylength, &dec_key);
	AES_cbc_encrypt(hello_world_string_encrypted, dec_out, encslength, &dec_key, iv, AES_DECRYPT);

	printf("Decrypted (HEX):\t");
	hex_print(dec_out, sizeof(dec_out));
	printf("Decrypted (ASCI):\t%s\n", dec_out);
}

float convert_temperature_to_f(float temp_in_c){
	return ((temp_in_c * (9 / 5)) + 32);
}

bool check_postal_code(int postal_code){
	// Check if the value is between 1000 and 9999
	if (postal_code >= 1000 && postal_code <= 9999) {
		return true;
	} else {
		return false;
	}
}

void add_multiple_user_inupts(){
	double sum = 0;
	double user_input = 0;

	while(true) {
		sum += user_input;
		printf("%s(*) Current value: %lf\n", KBLU, sum);
		printf("%s(*) Please enter a nuber: ", KGRN);
		// Check if the supplied vlaue was a double
		if (scanf("%lf", &user_input) != 1){
			printf("%s(*) Sum: %lf\n", KGRN, sum);
			return;
		}
	}
}
