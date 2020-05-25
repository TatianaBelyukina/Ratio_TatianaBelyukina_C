#include "../Ratio_c/common.h"
#include "../Ratio_c/ChainFraq.h"
#include "../Ratio_c/Ratio.h"

#include <math.h>

ChainFraq create_ChainFraq(DType x, DType eps) {
    ChainFraq result = {
        -1, NULL, eps
    };

    IntType* a = (IntType*) malloc(20 * sizeof(IntType));
    result.a = a;

    Ratio r = fromDType(x);

    int i = 0;
    while (1) {
        int a0 = (int) floor(r.nom / abs(r.den));
        a[i] = a0;
        i++;

        if (r.den == 1) {
            result.eps = abs(r.nom/r.den - x);
            break;
        } else if (abs(r.nom/r.den) < eps) {
            result.num = (i+1);
            break;
        }

        UIntType tmp_den = r.den;
        int sign = (r.nom > 0) - (r.nom < 0);
        r.den = abs(r.nom) - abs(a0)*tmp_den;
        r.nom = tmp_den * sign;
    }

    result.num = i;

    Ratio v = getRatio(result);
    result.eps = abs(v.nom/v.den) - x;

    return result;
}

ChainFraq createN_ChainFraq(DType x, IntType num) {
    ChainFraq result = {
        num, NULL, 0
    };

    IntType* a = (IntType*) malloc(num * sizeof(IntType));
    result.a = a;

    Ratio r = fromDType(x);

    int i = 0;
    for (int i=0; i<num; i++) {
        int a0 = (int) floor(r.nom / abs(r.den));
        a[i] = a0;
        i++;

        if (r.den == 1) {
            result.eps = abs(r.nom/r.den - x);
            result.num = i;
            break;
        }

        UIntType tmp_den = r.den;
        int sign = (r.nom > 0) - (r.nom < 0);
        r.den = abs(r.nom) - abs(a0)*tmp_den;
        r.nom = tmp_den * sign;
    }

    Ratio v = getRatio(result);
    result.eps = v.nom/abs(v.den) - x;
    printf("%d %d\n", v.nom/abs(v.den), x);

    return result;
}

int destroy_ChainFraq(ChainFraq x) {
    free(x.a);
    return 1;
}

void output_fraq(ChainFraq x) {
    for (int i=0; i< x.num-1; i++) {
        printf("%d + 1/(", x.a[i]);
    }
    printf("1/%d", x.a[ x.num-1 ]);
    for (int i=0; i< x.num-1; i++) {
        printf(")", x.a[i]);
    }
}

DType getPrecision(ChainFraq x) {
    return x.eps;
}

Ratio getRatio(ChainFraq x) {
    Ratio r = {x.a[x.num-1], 1};
    for (int i=x.num-2; i>=0; i--) {
        IntType tmp_nom = r.nom;
        IntType sign = (r.nom > 0) - (r.nom < 0);
        r.nom = (x.a[i] * r.nom + r.den) * sign;
        r.den = tmp_nom * sign;
    }
    return r;
}

DType getNum(ChainFraq x) {
    return x.num;
}
