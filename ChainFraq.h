#ifndef __CHAIN__
#define __CHAIN__

#include "common.h"
#include "Ratio.h"

typedef struct ChainFraq {
    IntType num;
    IntType* a;
    DType eps;
} ChainFraq;

ChainFraq create_ChainFraq(DType x, DType eps);
ChainFraq createN_ChainFraq(DType x, IntType num);

int destroy_ChainFraq(ChainFraq x);

void output_fraq(ChainFraq x);

DType getPrecision(ChainFraq x);
Ratio getRatio(ChainFraq x);
DType getNum(ChainFraq x);

#endif


