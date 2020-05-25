#include <stdio.h>
#include <assert.h>
#include <math.h>
#include "../Ratio_c/common.h"
#include "../Ratio_c/ChainFraq.h"
#include "../Ratio_c/Ratio.h"

void test_add_Ratio() {
    Ratio r = add_Ratio(
        create_Ratio(1, 2),
        create_Ratio(1, 2)
    );

    assert( r.nom == 1 );
    assert( r.den == 1 );
}

void test_sub_Ratio() {
    Ratio r = sub_Ratio(
        create_Ratio(3, 8),
        create_Ratio(1, 8)
    );

    assert( r.nom == 1 );
    assert( r.den == 4 );
}

void test_mul_Ratio() {
    Ratio r = mul_Ratio(
        create_Ratio(3, 4),
        create_Ratio(7, 15)
    );

    assert( r.nom == 7 );
    assert( r.den == 20 );
}

void test_ddiv_Ration() {
    Ratio r = ddiv_Ratio(
        create_Ratio(3, 4),
        3
    );

    assert( r.nom == 1 );
    assert( r.den == 4 );
}


void test_mod_Ration() {

}

void test_dmod_Ratio() {

}

int run_tests() {
    test_add_Ratio();
    test_sub_Ratio();
    test_mul_Ratio();
    test_ddiv_Ration();
    test_mod_Ration();
    test_dmod_Ratio();

    Ratio* a = (Ratio*) malloc(sizeof(Ratio));
    inputc_Ratio(a, "7 . 5 6");
    printf("%d, %d", a->nom, a->den);
    free(a);

    ChainFraq v = create_ChainFraq(7.56, 0.0000001);
    Ratio b = getRatio(v);
    output_fraq(v);
    printf("\nnum: %d, eps: %d", v.num, v.eps);

    return 0;
}
