#include "toys-sc.h"
#include <assert.h>

#ifndef SANTA_CLAUS_TOY_BUILDER_CAP
#define SANTA_CLAUS_TOY_BUILDER_CAP 10
#endif

void ScToyDescSeqBuilder_start(ScToyDescSeqBuilder* b)
{
    b->len = 0;
    b->cap = SANTA_CLAUS_TOY_BUILDER_CAP;
    b->descs = malloc(SANTA_CLAUS_TOY_BUILDER_CAP);
    assert(b->descs);
}

void ScToyDescSeqBuilder_add(ScToyDescSeqBuilder* b, ScToyDesc desc)
{
    if (b->len == b->cap) {
        b->cap *= 3;
        b->descs = realloc(b->descs, b->cap);
        assert(b->descs);
    }
    b->descs[b->len++] = desc;
}

void ScToyDescSeqBuilder_finish(ScToyDescSeqBuilder* b, ScToyDescSeq* s)
{
    s->size = b->len;
    s->descs = b->descs;
    b->cap = 0;
    b->len = 0;
    b->descs = NULL;
}

