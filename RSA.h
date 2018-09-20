#include "gmp.h"
void Sieve(FILE *fp);
void test();
void key_generate(FILE*);
void String2Hex(char *src, char *dst);
void Encrypt(char *plaintext, FILE *fp_cipher);
void exp_mod(mpz_t base, mpz_t exp, mpz_t n);

