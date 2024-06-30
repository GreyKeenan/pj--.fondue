#ifndef ENDIAN_H
#define ENDIAN_H

#include <stdint.h>
#include <stddef.h>

union _Endian_Test {
	uint8_t byte;
	uint16_t doubleByte;
};
extern const union _Endian_Test _Endian_isLittle;
#define ENDIAN_ISLITTLE _Endian_isLittle.byte

void Endian_flip(void *target, size_t size);

#endif
