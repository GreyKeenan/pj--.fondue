#ifndef FILES_PNG_READ_H
#define FILES_PNG_READ_H

#include <stdio.h>
#include <stdbool.h>

typedef struct PNG PNG;
typedef struct PNG_ChunkHeader PNG_ChunkHeader;
typedef struct PNG_Chunk_IHDR PNG_Chunk_IHDR;

//PNG_read_path(const char *path);
bool PNG_is(FILE *f);
PNG PNG_read_confirmed(FILE *f);
void PNG_free(PNG *self);

//dont rly need to be public ig, but could come in handy at some point
PNG_ChunkHeader PNG_ChunkHeader_read(FILE *f);
bool PNG_ChunkHeader_compareType_string(PNG_ChunkHeader self, const char*s);
PNG_Chunk_IHDR PNG_Chunk_IHDR_read(FILE *f);

#endif
