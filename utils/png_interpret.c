
#include "png_interpret.h"

#include <stdlib.h>

#include "utils/err.h"

uint8_t *PNG_dechunk(PNG png, uint32_t *outLength) {
}
uint8_t *PNG_decompress(uint32_t *outLength, uint8_t *dechunkedImage, uint32_t length) {
}
void PNG_defilter(PNG png, uint8_t *decompressedImage, uint32_t length) {
}

uint8_t *PNG_getReferenceImage(PNG png) {
	if (png.ihdr.interlaceMethod != PNG_INTERLACEMETHOD_NULL) {
		Err_panic("Not yet designed to handle interlaced images.");
	}
	if (png.ihdr.colorType == PNG_COLORTYPE_INDEXED) {
		Err_panic("Not yet designed to handle palette-indexed images.");
	}
	/*
	dechunk
	decompress
	free dechunked
	defilter
	free decompressed
	return defiltered
	?? de-indexing?
	*/
}
