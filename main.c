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

    char *plain = "AAAExecuting: E:CodeBlockscb_console_runner.exeF:GithubRSA_CbinDebugRSA_C.exe";
    FILE *fp_cipher = fopen("ciphertext.txt","w+");
    Encrypt(plain, fp_cipher);
    fclose(fp_cipher);

    fp_cipher = fopen("ciphertext.txt","a+");
    Decrypt(fp_cipher);
    fclose(fp_cipher);

    return 0;
}
