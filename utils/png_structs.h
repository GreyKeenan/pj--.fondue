#ifndef FILES_PNG_STRUCTS_H
#define FILES_PNG_STRUCTS_H

#include <stdint.h>

typedef struct PNG_ChunkHeader {
	uint32_t length;
	char type[4];
} PNG_ChunkHeader;

typedef struct PNG_Chunk_IHDR {
	uint32_t width;
	uint32_t height;
	uint8_t bitDepth; //1, 2, 4, 8, 16
	uint8_t colorType; //0, 2, 3, 4, 6
	uint8_t compressionMethod; //should always be 0
	uint8_t filterMethod; //?also always 0
	uint8_t interlaceMethod; //0 = no interlace. 1 = Adam7 interlace.
} PNG_Chunk_IHDR;

typedef struct PNG {
	PNG_Chunk_IHDR ihdr;

	uint8_t *idata;
	uint32_t idataLength;

	uint8_t *palette;
	uint32_t paletteLength;
} PNG;

#endif
