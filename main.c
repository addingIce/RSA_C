#include <stdio.h>
#include <stdlib.h>
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
    //gmp_test();
    FILE *fp = fopen("key_generate.txt","w+");
    key_generate(fp);

    char *plain = "AAABBB123";
    Encrypt(plain, fp);

    fclose(fp);

    return 0;
}
