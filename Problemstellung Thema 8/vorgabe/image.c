/*
 *  image.c
 *
 */

#include "image.h"

struct pixel* readBitmap(const char *filename, struct header* pHeader, struct info* pInfo)
{
	struct pixel *pData;
	FILE* fp;
	
	fp = fopen(filename, "rb");
	if (fp == NULL) {
		printf("Datei %s kann nicht geoeffnet werden!\n", filename);
		return NULL;
	}
	
	/* fread dient zum Einlesen von Binärdateien. fread-Parameter:
	 1.: Zeiger auf den Speicherbereich in den die eingelesenen Daten geschrieben werden
	 2.: Groesse eines Elements welches eingelesen werden soll
	 3.: Anzahl der Elemente die eingelesen werden sollen
	 4.: Datei von der gelesen werden soll
	 */
	/* elemente muessen einzeln eingelesen werden, da ints immer an einer
	 4-byte grenze ausgerichtet werden und das erste feld nur aus 2 byte besteht */
	fread(&pHeader->bfType, sizeof(char), 2, fp);
	fread(&pHeader->bfSize, sizeof(unsigned int), 1, fp);
	fread(&pHeader->bfReserved, sizeof(unsigned int), 1, fp);
	fread(&pHeader->bfOffBits, sizeof(unsigned int), 1, fp);
	fread(pInfo, sizeof(struct info), 1, fp);
	
	/*
	 * TODO IMPLEMENTIEREN SIE AN DIESER STELLE DAS EINLESEN DER BILDDATEN (PIXEL)
	 */
	
	fclose(fp);
	
	return pData;
}

void writeBitmap(const char *filename, struct header* pHeader, struct info* pInfo, struct pixel* pData)
{
	FILE* fp;
	
	fp = fopen(filename, "wb");
	if (fp == NULL) {
		printf("Datei %s kann nicht geoeffnet werden!\n", filename);
		return;
	}
	
	/*
	 * TODO IMPLEMENTIEREN SIE AN DIESER STELLE DAS SPEICHERN DES BITMAPS
	 */	
	
	fclose(fp);
}

struct pixel* mirror(struct info* pInfo, struct pixel* pData)
{
	/*
	 * TODO IMPLEMENTIEREN SIE AN DIESER STELLE DAS HORIZONTALE UND VERTIKALE SPIEGELN
	 * ERSETZEN SIE "RETURN NULL" DURCH EIN SINNVOLLES RETURN STATEMENT
	 */
	return NULL;
}

struct pixel* invert(struct info* pInfo, struct pixel* pData)
{
	/*
	 * TODO IMPLEMENTIEREN SIE AN DIESER STELLE DAS HORIZONTALE UND VERTIKALE SPIEGELN
	 * ERSETZEN SIE "RETURN NULL" DURCH EIN SINNVOLLES RETURN STATEMENT
	 */
	return NULL;
}

struct pixel* saturation(struct info* pInfo, struct pixel* pData, double wRed, double wGreen, double wBlue)
{
	/*
	 * TODO IMPLEMENTIEREN SIE AN DIESER STELLE DAS ÄNERDN DER FARBSÄTTIGUNG
	 * ERSETZEN SIE "RETURN NULL" DURCH EIN SINNVOLLES RETURN STATEMENT
	 */
	return NULL;
}


