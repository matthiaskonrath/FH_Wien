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
} hexLine;

FILE * openFile(const char * filename, char * operator);

void readIntelHexIntoMemory(const char * filename, hexLine lines[LINES]);
void writeIntelHexToFile(const char * filename, hexLine lines[LINES]);


// Es sollen als Parameter die Werte example.csv und input.txt übergeben werden
int main (int argc, const char **argv) {

    hexLine lines[LINES];

    // TODO Deklarationen

    // Tip: verwenden Sie argv[1] und argv[2]

    // TODO Einlesen und Schreiben
       return 0;
}

void readIntelHexIntoMemory(const char * filename, hexLine lines[LINES]){
    FILE * fp;
    fp = openFile(filename, "r");


    while(!feof(fp)) { /*bis EOF von *fp*/

        // TODO Einlesen der Zeilen und abspeichern in die Struktur hexLine

        //zB. sscanf(Stringpointer, "%x;%x;...", variablen);

    }

    fclose(fp);
}


void writeIntelHexToFile(const char * filename, hexLine lines[LINES]){

    // TODO Schreiben der hexLine Strukturen in die

    // zum Schreiben: fprintf(file, "%02x\n", irgendwas[...]);

    // Hinweis Checksumme:
    // zB Negieren sum=(~sum) + 1;

}

// Öffnet eine Datei und liefert den File Pointer zurück
// "r" .... zum Lesen öffnen
// "w" .... zum Schreiben öffnen
FILE * openFile(const char * filename, char * operator){
    FILE * fp;
    fp = fopen(filename, operator);
	if (!fp) {
		printf("Cannot open file %s!\n", filename);
		return NULL;
	}
    return fp;
}
