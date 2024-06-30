
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

#include "utils/err.h"
#include "utils/endian.h"

#include "utils/png.h"

int main(int argc, char **argv) {

	printf("\n");

	if (argc < 3) { //TODO specifying padding to ignore. top/bottom/left/right | specifying dimensions
		Err_panic("Not enough arguments. Expect 2 arguments as <input-png> <output-png>");
	}
	printf("Converting (%s) to (%s).\n", argv[1], argv[2]);

	FILE *f = fopen(argv[1], "r");
	if (f == NULL) {
		Err_panic("Unable to open input file.");
	}

	if (!PNG_is(f)) {
		Err_panic("Input file not recognized as a PNG.");
	}

	printf("Is this little endian? %s!\n", ENDIAN_ISLITTLE? "Yes":"No");

	PNG png = PNG_read_confirmed(f);

	fclose(f);

	PNG_free(&png);

	return 0;
}
