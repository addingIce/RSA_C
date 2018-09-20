#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "RSA.h"
#include "gmp.h"
int main()
{
    /*
    FILE *fp = fopen("prime.txt","w+");
    Sieve(fp);
    fclose(fp);
    */
    /*
    FILE *fp = fopen("key_generate.txt","w+");
    key_generate(fp);

    char *plain = "AAAbbbcccc;1.+";
    Encrypt(plain, fp);

    fclose(fp);
    */
    mpz_t base, exp, n;
    mpz_init_set_ui(base, 2);
    mpz_init_set_ui(exp, 5);
    mpz_init_set_ui(n, 7);
    exp_mod(base, exp, n);
    return 0;
}
