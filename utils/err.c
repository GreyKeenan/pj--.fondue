
#include "err.h"

#include <stdio.h>
#include <stdlib.h>

void (*_funEnd)() = NULL;

void _terminate(int status) {
	if (_funEnd != NULL) {
		_funEnd();
	}
	exit(status);
}

static inline void _printLocation(const char *file, const char *func, int line) {
	printf("(%s) -> (%s) -> %d", file, func, line);
}
static inline void _printLeader() {
	printf("\n| ERR | ");
}
static inline void _printCloser() {
	printf("\n| ERR END |\n");
}

void Err_init(void (*fun)()) {
	_funEnd = fun;
}

void Err_doTell(const char *file, const char *func, int line, const char *message) {
	printf("\n| ");
	_printLocation(file, func, line);
	printf(" |\n");
	printf("| %s |\n", message);
}

void Err_doWarn(const char *file, const char *func, int line, const char *message) {
	_printLeader();
	_printLocation(file, func, line);
	printf("\n%s", message);
	_printCloser();
}

void Err_doPanic(const char *file, const char *func, int line, const char *message) {
	Err_doWarn(file, func, line, message);
	_terminate(1);
}
void Err_doUnr(const char *file, const char *func, int line) {

	_printLeader();
	printf("Unreachable: ");
	_printLocation(file, func, line);
	printf(" |\n");

	_terminate(1);
}
