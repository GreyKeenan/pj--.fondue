
#include "png_interpret.h"

#include <stdlib.h>

#include "utils/err.h"


uint8_t *PNG_decompress(PNG png, uint32_t *outLength) {
	if (png.ihdr.compressionMethod != PNG_COMPRESSIONMETHOD_DEFLATE) {
		Err_panic("Unrecognized compression method.");
	}
}
void PNG_defilter(PNG png, uint8_t *decompressedImage, uint32_t length) {
	if (png.ihdr.filterMethod !+ PNG_FILTERMETHOD_5TYPE) {
		Err_panic("Unrecognized filter method.");
	}
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

	uint32_t length = 0;
	uint8_t *decompressed = PNG_decompress(png, &length);

	PNG_defilter(png, decompressed, length);
	//TODO ? will defilter actually be in-place? 
		referenceImage.data = decompressed;
		referenceImage.length = length;
	
	return referenceImage;
}
void PNG_ReferenceImage_destroy(PNG_ReferenceImage *self) {
	free(self->data);
	*self = (PNG_ReferenceImage){0};
}
