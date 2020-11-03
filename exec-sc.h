#ifndef EXEC_SANTA_CLAUS_H
#define EXEC_SANTA_CLAUS_H

#include "toys-sc.h"
#include <string.h>

typedef struct {
    char msg[256];
} ScErr;

typedef struct {
    ScErr err;
} ScState;

extern void ScState_exec(ScState* state);


#endif // EXEC_SANTA_CLAUS_H

