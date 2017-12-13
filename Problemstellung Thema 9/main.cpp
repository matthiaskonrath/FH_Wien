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

// Struktur und Prototypen

#define LINES 16
#define NIBBLES 16

typedef struct intelHexLine{
    char startCode;
    char byteCount;
    short address;
    char recordType;
    char data[NIBBLES];
    char checksum;
};

FILE * openFile(const char * filename, char* op);

void readIntelHexIntoMemory(const char* filename, intelHexLine* lines);
void writeIntelHexToFile(const char* filename, intelHexLine* lines);


// Es sollen als Parameter die Werte example.csv und input.txt übergeben werden
int main (int argc, const char **argv) {

    intelHexLine* lines = (intelHexLine*) malloc(sizeof(intelHexLine) * 18);

    if (argv[1] == 0 || argv[2] == 0) {
        printf("Parameters not set!\n");
        return 0;
    }

    readIntelHexIntoMemory(argv[1], lines);

    return 0;
}

void readIntelHexIntoMemory(const char * filename, intelHexLine* lines){
    FILE * fp;
    fp = openFile(filename, "r");

    int hex_line_obj = 0;

    char* header = (char*) malloc(168);
    char* buffer = (char*) malloc(32);
    char* nl_char = (char*) malloc(1);

    memset((void*) header, 187, '\0');
    memset((void*) buffer, 32, '\0');

    for (size_t i = 0; i < 167; i++) {
        fread((header + i), sizeof(char), 1, fp);
    }
    fread((nl_char), sizeof(char), 1, fp);
    printf("HEADER: %s", header);


    printf("%s\n", buffer);

    while(!feof(fp)) { /*bis EOF von *fp*/
        // Read the data
        for (size_t i = 0; i < 31; i++) {
            fread((buffer + i), sizeof(char), 1, fp);
        }
        // Read the new line
        fread((nl_char), sizeof(char), 1, fp);

        // Convert it to intel hex line
        lines[hex_line_obj].startCode = ':';
        lines[hex_line_obj].byteCount = 16;

        for (size_t i = 0; i < 16; i++) {
            // Set the field type
            if (i == 0) {
                lines[hex_line_obj].recordType = 2;
            } else if (i == 16) {
                lines[hex_line_obj].recordType = 1;
            } else {
                lines[hex_line_obj].recordType = 0;
            }

            // Set the address
            lines[hex_line_obj].address = i * 16;
        }
        printf("%s\n", buffer);

        hex_line_obj += 1;

    }

    fclose(fp);
}


void writeIntelHexToFile(const char * filename, intelHexLine* lines){

    // TODO Schreiben der hexLine Strukturen in die

    // zum Schreiben: fprintf(file, "%02x\n", irgendwas[...]);

    // Hinweis Checksumme:
    // zB Negieren sum=(~sum) + 1;

}

// Öffnet eine Datei und liefert den File Pointer zurück
// "r" .... zum Lesen öffnen
// "w" .... zum Schreiben öffnen
FILE * openFile(const char * filename, char* op){
    FILE * fp;
    fp = fopen(filename, op);
	if (!fp) {
		printf("Cannot open file %s!\n", filename);
		return NULL;
	}
    return fp;
}
