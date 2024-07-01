
#include "png_read.h"

#include <stdlib.h>

#include "utils/err.h"
#include "utils/endian.h"

#include "png_structs.h"

#define _HEADER_SIZE 8
#define _CHUNKHEADER_SIZE 8
#define _CHUNKCRC_SIZE 4


void _eat(FILE *f, int bytes) {
	for (int i = 0; i < bytes; ++i) {
		fgetc(f);
	}
}
#define _eat_CRC(f) _eat(f, _CHUNKCRC_SIZE)
static inline bool _isLowercase(char c) {
	return c & 32;
}

typedef struct _Header {
	uint8_t highBit;
	char png[3];
	uint8_t dosNewline[2];
	uint8_t dosStopDisplay;
	uint8_t unixNewline;
} _Header;

bool PNG_is(FILE *f) {
	_Header h = {0};
	if (fread(&h, _HEADER_SIZE, 1, f) != 1) {
		Err_warn("Unable to read header bytes from input file.");
		return false;
	}
	if (h.highBit != 0x89) {
		return false;
	}
	if (h.png[0] != 'P') {
		return false;
	}
	if (h.png[1] != 'N') {
		return false;
	}
	if (h.png[2] != 'G') {
		return false;
	}
	if (h.dosNewline[0] != 0x0D) {
		return false;
	}
	if (h.dosNewline[1] != 0x0A) {
		return false;
	}
	if (h.dosStopDisplay != 0x1A) {
		return false;
	}
	if (h.unixNewline != 0x0A) {
		return false;
	}
	//TODO: check for line-ending conversion

	return true;}

bool PNG_ChunkHeader_compareType_string(PNG_ChunkHeader self, const char*s) {
	//TODO valdiate string length / under is bad
	if (self.type[0] != s[0]) {
		return false;
	}
	if (self.type[1] != s[1]) {
		return false;
	}
	if (self.type[2] != s[2]) {
		return false;
	}
	if (self.type[3] != s[3]) {
		return false;
	}
	return true;
}

PNG_ChunkHeader PNG_ChunkHeader_read(FILE *f) {
	PNG_ChunkHeader chunk = {0};
	if (fread(&chunk, _CHUNKHEADER_SIZE, 1, f) != 1) {
		Err_panic("Unable to read the header.");
	}
	if (ENDIAN_ISLITTLE) {
		Endian_flip(&chunk.length, sizeof(chunk.length));
	}
	printf("Chunk: %c%c%c%c %d\n", chunk.type[0], chunk.type[1], chunk.type[2], chunk.type[3], chunk.length);
	return chunk;
}
PNG_Chunk_IHDR PNG_Chunk_IHDR_read(FILE *f) {
	PNG_ChunkHeader ch = PNG_ChunkHeader_read(f);
	if (!PNG_ChunkHeader_compareType_string(ch, "IHDR")) {
		Err_panic("Attempting to read IHDR. Is not IHDR.");
	}

	PNG_Chunk_IHDR ihdr = {0};
	if (fread(&ihdr, 1, ch.length, f) != ch.length) {
		Err_panic("Unable to read the IHDR chunk data.");
	}
	if (ENDIAN_ISLITTLE) {
		Endian_flip(&ihdr.width, sizeof(ihdr.width));
		Endian_flip(&ihdr.height, sizeof(ihdr.height));
	}

	printf("w: %d. h: %d.\n", ihdr.width, ihdr.height);
	printf("bitDepth: %d. colorType: %d. compressionMethod: %d.\n", ihdr.bitDepth, ihdr.colorType, ihdr.compressionMethod);
	printf("filterMethod: %d. interlaceMethod: %d.\n", ihdr.filterMethod, ihdr.interlaceMethod);

	_eat_CRC(f);
	return ihdr;
}

PNG PNG_read_confirmed(FILE *f) {

	PNG self = {0};
	self.ihdr = PNG_Chunk_IHDR_read(f);

	PNG_ChunkHeader chunk = {0};

	while (!PNG_ChunkHeader_compareType_string((chunk = PNG_ChunkHeader_read(f)), "IEND")) {
		if (_isLowercase(chunk.type[0])) {
			printf("Skipping ancillary chunk.\n");
			_eat(f, chunk.length + _CHUNKCRC_SIZE);
			continue;
		}
		if (PNG_ChunkHeader_compareType_string(chunk, "IDAT")) {
			if (self.idata != NULL) {
				Err_panic("Multi-IDAT-chunk pngs not yet supported."); //TODO
			}
			self.idata = malloc(chunk.length);
			if (fread(self.idata, 1, chunk.length, f) != chunk.length) {
				Err_panic("Unable to read IDAT data.");
			}
			_eat_CRC(f);
			continue;
		} 
		if (PNG_ChunkHeader_compareType_string(chunk, "PLTE")) {
			self.palette = malloc(chunk.length);
			if (fread(self.palette, 1, chunk.length, f) != chunk.length) {
				Err_panic("Unable to read PLTE data.");
			}
			_eat_CRC(f);
			continue;
		}

		_eat(f, chunk.length + _CHUNKCRC_SIZE); //TODO TEMP
		
	}

	return self;
}

void PNG_free(PNG *self) {
	free(self->idata);
	self->idata = NULL;
	self->idataLength = 0;

	if (self->palette != NULL) {
		free(self->palette);
		self->palette = NULL;
		self->paletteLength = 0;
	}
}

