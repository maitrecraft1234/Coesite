#ifndef ITLEI
#define ITLEI

#include <stddef.h>

//this function can fail, returns 0 on success and -1 on failure
int interpretor_run_from_file(const char *path);

#include "general/macros.h"

#define ITLEI_RUNSTR(s) interpretor_run_from_string(s, COOL_STRLEN(s))
//
void interpretor_run_from_string(const char *string, size_t len);

#endif
