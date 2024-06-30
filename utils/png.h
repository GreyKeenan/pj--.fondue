#ifndef FILES_PNG_H
#define FILES_PNG_H

#include <stdio.h>
#include <stdbool.h>
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

//PNG_read_path(const char *path);
bool PNG_is(FILE *f);
PNG PNG_read_confirmed(FILE *f);
void PNG_free(PNG *self);

//dont rly need to be public ig, but could come in handy at some point
PNG_ChunkHeader PNG_ChunkHeader_read(FILE *f);
bool PNG_ChunkHeader_compareType_string(PNG_ChunkHeader self, const char*s);
PNG_Chunk_IHDR PNG_Chunk_IHDR_read(FILE *f);

#endif
