#include "../Ratio_c/common.h"
#include "../Ratio_c/Ratio.h"

#include <stdio.h>
#include <string.h>
#include <math.h>

IntType gcd(IntType a, IntType b)
{
    if (a == 0)
        return b;
    return gcd(b%a, a);
}

IntType input_Ratio(Ratio* x) {
    size_t l = floor(strlen(str)/2);

    // строка -> массив
    char str_cpy[l];
    strcpy(str_cpy, str);

    char str_cpy2[l];

    char *token = strtok(str_cpy, " ");

    UIntType decimals_count = 0;

    IntType i = 0;
    while (token != NULL)
    {
        str_cpy2[i] = token[0];
        if (token[0] == '.') {
            decimals_count = l - i;
        }
        token = strtok(NULL, " ");
        i++;
    }

    DType x_tmp = atof(str_cpy2);

    // заполняем Ratio x
    UIntType den = ceil(pow(10, decimals_count));
    IntType nom = ceil(x_tmp * pow(10, decimals_count));

    x->den = den;
    x->nom = nom;

    simplify_Ratio(x);

    return l;
}

IntType inputc_Ratio(Ratio* x, char* str) {
    size_t l = floor(strlen(str)/2);

    // строка -> массив
    char str_cpy[l];
    strcpy(str_cpy, str);

    char str_cpy2[l];

    char *token = strtok(str_cpy, " ");

    UIntType decimals_count = 0;

    IntType i = 0;
    while (token != NULL)
    {
        str_cpy2[i] = token[0];
        if (token[0] == '.') {
            decimals_count = l - i;
        }
        token = strtok(NULL, " ");
        i++;
    }

    DType x_tmp = atof(str_cpy2);

    // заполняем Ratio x
    UIntType den = ceil(pow(10, decimals_count));
    IntType nom = ceil(x_tmp * pow(10, decimals_count));

    x->den = den;
    x->nom = nom;

    simplify_Ratio(x);

    return l;
}

Ratio fromDType(DType x) {
    UIntType den = 1;
    while (floor(x) - x != 0) {
        x *= 10;
        den *= 10;
    }

    Ratio r = {x, den};
    simplify_Ratio(&r);
    return r;
}

void simplify_Ratio(Ratio* x) {
    IntType rgcd = abs(gcd(x->nom, x->den));
    x->nom /= rgcd;
    x->den /= rgcd;
}

Ratio create_Ratio(IntType nom, UIntType den) {
    Ratio result = {nom, den};
    simplify_Ratio(&result);
    return result;
}

Ratio add_Ratio(Ratio x, Ratio y) {
    Ratio result = {x.nom*y.den + y.nom*x.den, x.den*y.den};
    simplify_Ratio(&result);
    return result;
}

Ratio sub_Ratio(Ratio x, Ratio y) {
    y.nom = -y.nom;
    Ratio result = add_Ratio(x, y);
    return result;
}
Ratio mul_Ratio(Ratio x, Ratio y) {
    Ratio result = {x.nom * y.nom, x.den * y.den};
    simplify_Ratio(&result);
    return result;
}

Ratio ddiv_Ratio(Ratio x, IntType y) {
    Ratio result = {x.nom/y, x.den};
    simplify_Ratio(&result);
    return result;
}
Ratio* unadd_Ratio(Ratio* x, const Ratio y) {
    x->nom = x->nom*y.den + y.nom*x->den;
    x->den = x->den*y.den;
    simplify_Ratio(x);
    return x;
}

Ratio* unsub_Ratio(Ratio* x,const Ratio y) {
    Ratio y_rev = {-y.nom, y.den};
    unadd_Ratio(x, y_rev);
    return x;
}

Ratio* unmul_Ratio(Ratio* x,const Ratio y) {
    x->nom *= y.nom;
    x->den *= y.den;
    simplify_Ratio(x);
    return x;
}

Ratio* undiv_Ratio(Ratio* x, const Ratio y) {
    x->nom *= y.den;
    x->den *= y.nom;
    simplify_Ratio(x);
    return x;
}

Ratio* unmod_Ratio(Ratio* x, Ratio y) {

    return x;
}

Ratio generate_Ratio(IntType n);

char* toString(Ratio x) {
    return " ";
}

