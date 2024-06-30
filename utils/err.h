#ifndef ERR_H
#define ERR_H


#define Err_tell(message) Err_doTell(__FILE__, __func__, __LINE__, message)

#define Err_warn(message) Err_doWarn(__FILE__, __func__, __LINE__, message)
#define Err_panic(message) Err_doPanic(__FILE__, __func__, __LINE__, message)
#define Err_unr() Err_doUnr(__FILE__, __func__, __LINE__)

void Err_init(void (*fun)());

void Err_doTell(const char *file, const char *func, int line, const char *message);

void Err_doWarn(const char *file, const char *func, int line, const char *message);
void Err_doPanic(const char *file, const char *func, int line, const char *message);
void Err_doUnr(const char *file, const char *func, int line);

#endif
