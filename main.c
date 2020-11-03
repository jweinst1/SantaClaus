#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifdef HAVE_ERRNO
#  include <errno.h>
#endif

#ifndef SANTA_CLAUS_REPL_LEN
#define SANTA_CLAUS_REPL_LEN 2048
#endif

#define SANTA_CLAUS_REPL_SYM "<(^ _ ^)> "

static int _is_exit_statement(const char* code)
{
    while (*code) {
        if (*code != ' ' && *code != '\n' && *code != '\t') {
            return 0 == strncmp(code, "exit", 4);
        } 
        ++code;
    }
    return 0;
}

typedef int (*code_func)(const char*);

void repl_loop(code_func cb)
{
    char line_buf[SANTA_CLAUS_REPL_LEN] = {0};
    while (1) {
        printf(SANTA_CLAUS_REPL_SYM);
        const char* result = fgets(line_buf, sizeof(line_buf), stdin);
        if (result == NULL) {
        #ifdef HAVE_ERRNO
            int err_val = errno;
            printf("ERROR with code: %d\n", err_val);  
        #else // HAVE_ERRNO
            if(ferror(stdin)) {
                puts("ERROR stdin <(.) _ (.)>");
                clearerr(stdin);     
            } else {
                puts("ERROR * _ *");
            }
        #endif // !HAVE_ERRNO            
            break;
        } else {
            // check for exit statement
            if (_is_exit_statement(line_buf))
                break;
            // Success, Check if it's an exit statement
            if (!cb(line_buf))
                break;
        }
    }
}

int ScRepl_cb(const char* code)
{
    printf("Ho Ho got the code: %s", code);
    return 1;
}

int main(int argc, char const* argv[]) {
    puts("SantaClaus: Ho Ho Ho!");
    repl_loop(&ScRepl_cb);
    return 0;
}
