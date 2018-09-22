#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "gmp.h"
#include "RSA.h"
#define block_size 128
#define plain_size 117
extern mpz_t p, q, n, e, d;
// EB = 00 + 02 + PS + 00 + plain   128bytes
void Padding(char *result, char *src){
    char ps[250];
    int ps_len, num;
    //生成ps_len长度的随机填充ps
    ps_len = block_size - 3 - strlen(src)/2;
    srand((unsigned)time(NULL));
    for(int i=0; i<ps_len; i++){
        num = rand() % 254 + 1;
        sprintf(ps + i*2, "%02x", num);
    }
    strcat(result, ps);
    strcat(result, "00");
    strcat(result, src);
}


void Encrypt(char *plaintext, FILE *fp_cipher){
    mpz_t M;
    char plain_block[118];
    for(int i=0; i<=strlen(plaintext)/plain_size; i++){
        if(i<strlen(plaintext))
            strncpy(plain_block, plaintext + i*plain_size, plain_size);
        else
            strcpy(plain_block, plaintext + i*plain_size);
        char hex_plaintext[234] = "";   //明文转换得来的16进制ASCII码
        char padding_plain[256] = "";   //paddin完成后的分组
        String2Hex(plain_block, hex_plaintext);
        strcat(padding_plain, "0002");
        Padding(padding_plain, hex_plaintext);
        mpz_init_set_str(M, padding_plain, 16);
        gmp_printf("M: %Zx\n", M);
        exp_mod(fp_cipher, M, e, n);    //加密明文M

    }
}

