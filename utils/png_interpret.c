
#include "png_interpret.h"

#include <stdlib.h>

#include "utils/err.h"


uint8_t *PNG_decompress(PNG png, uint32_t *outLength) {
}
void PNG_defilter(PNG png, uint8_t *decompressedImage, uint32_t length) {
}

PNG_ReferenceImage PNG_ReferenceImage_get(PNG png) {
	if (png.ihdr.interlaceMethod != PNG_INTERLACEMETHOD_NULL) {
		Err_panic("Not yet designed to handle interlaced images.");
	}
	if (png.ihdr.colorType == PNG_COLORTYPE_INDEXED) {
		Err_panic("Not yet designed to handle palette-indexed images.");
	}

	PNG_ReferenceImage referenceImage = {
		.width = png.ihdr.width,
		.height = png.ihdr.height,
		.bitDepth = png.ihdr.bitDepth,
		.isIndexed = false
	};
	/*
	decompress
	defilter
	return defiltered (I think will be same ptr as decompressed)
	*/
}
