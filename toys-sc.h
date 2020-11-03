#ifndef TOYS_SANTA_CLAUS_H
#define TOYS_SANTA_CLAUS_H

#include <stdlib.h>
#include <string.h>

typedef enum {
   TOY_DESC_TYPE_RED
} ScToyDesc;

typedef struct {
    size_t size;
    ScToyDesc* descs;
} ScToyDescSeq;

typedef struct {
   size_t len;
   size_t cap;
   ScToyDesc* descs;
} ScToyDescSeqBuilder;

typedef enum {
    SC_TOY_OBJECT_HORSE
} ScToyObj;

typedef struct {
    ScToyDescSeq descs;
    ScToyObj obj;
} ScToy;

typedef struct {
    size_t size;
    ScToy* toys;
} ScToySeq;

/**
 * This starts a descriptor sequence, and allows new descs to be
 * appended to it.
 */
extern void ScToyDescSeqBuilder_start(ScToyDescSeqBuilder* b);
/**
 * This appends a desc and reallocs as needed.
 */
extern void ScToyDescSeqBuilder_add(ScToyDescSeqBuilder* b, ScToyDesc desc);
/**
 * This transfers the inner desc pointer to a seq obj.
 * Warning, this transfers ownership of memory
 */
extern void ScToyDescSeqBuilder_finish(ScToyDescSeqBuilder* b, ScToyDescSeq* s);

#endif // TOYS_SANTA_CLAUS_H
