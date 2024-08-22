#include "itlei.h"
#include <string.h>
#include <errno.h>

const char default_program[] = "let a = 1;\nprint(a)";

int main(int argc, char *argv[argc])
{
    errno = 0;

    if (argc == 1)
        ITLEI_RUNSTR(default_program);
    else
        interpretor_run_from_file(argv[1]);
    return errno;
}
