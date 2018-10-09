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


    char *plain = "Note: in the following steps, we'll assume you're using a 64-bit Windows. Therefore, the package names include the x86_64 architecture identifier. If you're using a 32-bit Windows, please adapt the instructions below using the i686 architecture identifier.";
    //char *plain = "AAA";
    FILE *fp_cipher = fopen("ciphertext.txt","w+");
    Encrypt(plain, fp_cipher);
    fclose(fp_cipher);


    fp_cipher = fopen("ciphertext.txt","a+");
    FILE *fp_plain = fopen("plaintext.txt", "w+");
    Decrypt(fp_cipher, fp_plain);
    fclose(fp_cipher);
    fclose(fp_plain);

    return 0;

}
