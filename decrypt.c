#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "gmp.h"
#include "RSA.h"
extern mpz_t p, q, n, e, d;

void Decrypt(FILE *fp_cipher){
    char cipher[500];
    mpz_t C;
    fscanf(fp_cipher, "%s\n", cipher);
    mpz_init_set_str(C, cipher, 16);
    gmp_printf("C: %Zx\n", C);
    exp_mod(fp_cipher, C, d, n);
}
