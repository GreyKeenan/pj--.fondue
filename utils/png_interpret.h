#ifndef PNG_INTERPRET_H
#define PNG_INTERPRET_H

#include <stdint.h>
#include <stdbool.h>

#include "png_structs.h"

typedef struct PNG_ReferenceImage {
	uint8_t *data;
	uint32_t width, height, length;
	uint8_t bitDepth;
	bool isIndexed;
	//alpha?
} PNG_ReferenceImage;

uint8_t *PNG_decompress(PNG png, uint32_t *outLength);
void PNG_defilter(PNG png, uint8_t *decompressedImage, uint32_t length);
	//modifies in-place i think?
PNG_ReferenceImage PNG_ReferenceImage_get(PNG png);
	//does process of dechunk, decompress & defilter

#endif
