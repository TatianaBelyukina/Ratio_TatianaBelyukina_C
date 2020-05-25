#ifndef __RATIO__
#define __RATIO__

#include "common.h"

typedef struct Ratio {
    IntType nom;
    UIntType den;
} Ratio;

IntType input_Ratio(Ratio* x);
IntType inputc_Ratio(Ratio* x, char* str);

Ratio fromDType(DType x);

IntType gcd(IntType a, IntType b);

void simplify_Ratio(Ratio* x);
Ratio create_Ratio(IntType nom, UIntType den);

Ratio add_Ratio(Ratio x, Ratio y);
Ratio sub_Ratio(Ratio x, Ratio y);
Ratio mul_Ratio(Ratio x, Ratio y);
Ratio mul_Ratio_d(Ratio x, DType y);
Ratio div_Ratio(Ratio x, Ratio y);
Ratio ddiv_Ratio(Ratio x, IntType y);
Ratio mod__Ratio(Ratio x, Ratio y);
Ratio dmod_Ratio(Ratio x, DType y);

Ratio* unadd_Ratio(Ratio* x, const Ratio y);
Ratio* unsub_Ratio(Ratio* x,const Ratio y);
Ratio* unmul_Ratio(Ratio* x,const Ratio y);
Ratio* undiv_Ratio(Ratio* x, const Ratio y);
Ratio* unmod_Ratio(Ratio* x, Ratio y);

void output_Ratio(Ratio x, IntType type, IntType width, IntType precision);
IntType inputBinaryFile_Ratio(char* file, Ratio* x);
IntType outputBinaryFile_Ratio(char* File, Ratio x);
IntType inputTextFile_Ratio(char* file, Ratio* x);
IntType outputTextFile_Ratio(char* File, Ratio x, IntType type, IntType width, IntType precision);

Ratio generate_Ratio(IntType n);

#endif
