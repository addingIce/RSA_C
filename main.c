#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "RSA.h"
#include "gmp.h"
extern mpz_t p, q, n, e, d;
int main()
{
    /*
    FILE *fp = fopen("prime.txt","w+");
    Sieve(fp);
    fclose(fp);
    */

    FILE *fp = fopen("key_generate.txt","w+");
    key_generate(fp);
    fclose(fp);

    char *plain = "AAAbdeqqbbcccc;1.+";
    FILE *fp_cipher = fopen("ciphertext.txt","w+");
    Encrypt(plain, fp_cipher);
    fclose(fp_cipher);

    fp_cipher = fopen("ciphertext.txt","a+");
    char cipher[500];
    mpz_t C;
    fscanf(fp_cipher, "%s\n", cipher);
    printf("cipher:%s\n", cipher);
    mpz_init_set_str(C, cipher, 16);
    gmp_printf("C: %Zx\n", C);
    //gmp_fscanf(fp_cipher, "%Zx\n", C);
    exp_mod(fp_cipher, C, d, n);
    fclose(fp_cipher);

    return 0;
}
