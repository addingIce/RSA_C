#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gmp.h"

//base^exp (mod n)
void exp_mod(mpz_t base, mpz_t exp, mpz_t n){
    char exp_bit[1030];
    mpz_t m;
    mpz_init_set_ui(m, 1);
    mpz_get_str(exp_bit, 2, exp);
    for(int i = strlen(exp_bit - 1); i>=0; i--){
        mpz_mul(m, m, m);
        if(exp_bit[i] == '1')
            mpz_mul(m, m, base);
            mpz_mod(m, m, n);
    }
    gmp_printf("%Zd\n", m);
}
