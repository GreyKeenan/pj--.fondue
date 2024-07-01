#ifndef FILES_PNG_STRUCTS_H
#define FILES_PNG_STRUCTS_H

#include <stdint.h>

#define PNG_COLORTYPE_GRAYSCALE 0
#define PNG_COLORTYPE_TRUECOLOR 2
#define PNG_COLORTYPE_INDEXED 3
#define PNG_COLORTYPE_GRAYSCALEALPHA 4
#define PNG_COLORTYPE_TRUECOLORALPHA 5

#define PNG_COMPRESSIONMETHOD_NULL 0
#define PNG_COMPRESSIONMETHOD_DEFLATE 1

#define PNG_FILTERMETHOD_NULL 0
#define PNG_FILTERMETHOD_5TYPE 0
	#define PNG_FILTERMETHOD_5TYPE_NONE 0
	#define PNG_FILTERMETHOD_5TYPE_SUB 1
	#define PNG_FILTERMETHOD_5TYPE_UP 2
	#define PNG_FILTERMETHOD_5TYPE_AVERAGE 3
	#define PNG_FILTERMETHOD_5TYPE_PAETH 4

#define PNG_INTERLACEMETHOD_NULL 0
#define PNG_INTERLACEMETHOD_ADAM7 1

typedef struct PNG_ChunkHeader {
	uint32_t length;
	char type[4];
} PNG_ChunkHeader;

typedef struct PNG_Chunk_IHDR {
	uint32_t width;
	uint32_t height;
	uint8_t bitDepth; //1, 2, 4, 8, 16
	uint8_t colorType;
	uint8_t compressionMethod;
	uint8_t filterMethod;
	uint8_t interlaceMethod;
} PNG_Chunk_IHDR;

typedef struct PNG {
	PNG_Chunk_IHDR ihdr;

	uint8_t *idata;
	uint32_t idataLength;

	uint8_t *palette;
	uint32_t paletteLength;
} PNG;

#endif
