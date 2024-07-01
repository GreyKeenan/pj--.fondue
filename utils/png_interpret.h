#ifndef PNG_INTERPRET_H
#define PNG_INTERPRET_H

#include <stdint.h>

#include "png_structs.h"

uint8_t *PNG_dechunk(PNG png, uint32_t *outLength);
uint8_t *PNG_decompress(uint32_t *outLength, uint8_t *dechunkedImage, uint32_t length);
	//also dechunks image
void PNG_defilter(PNG png, uint8_t *decompressedImage, uint32_t length);
	//modifies in-place
uint8_t *PNG_getReferenceImage(PNG png);
	//initially, panic at interlacedMethod != 0
	//does process of dechunk, decompress & defilter
	// to be true 'reference image' as in PNG spec, have to de-index here. Dont necessarily want to de-index though

#endif
