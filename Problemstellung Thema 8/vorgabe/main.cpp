#include <stdio.h>
#include <stdlib.h>
#include "image.h"

int main (int argc, const char **argv)
{
	struct header bmpHeader;
	struct info bmpInfo;
	struct pixel *data;
	struct pixel *mirrorData;

	data = readBitmap(argv[1], &bmpHeader, &bmpInfo);

	mirrorData = invert(&bmpInfo, data);
	writeBitmap(argv[2], &bmpHeader, &bmpInfo, mirrorData);

	free(data);
	free(mirrorData);

    return 0;
}
