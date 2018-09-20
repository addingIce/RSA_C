#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <malloc.h>
#include <string.h>

// EB = 00 + 02 + PS + 00 + plain
void Padding(char *result, char *src){
    char ps[250] = "ab";
    int ps_len, num;
    char ch[2];
    //生成ps_len长度的随机填充ps
    ps_len = 125 - strlen(src)/2;
    srand((unsigned)time(NULL));
    for(int i=0; i<ps_len; i++){
        num = rand() % 254 + 1;
        sprintf(ch, "%02x", num);
       // itoa(num, ch, 16);
        strcat(ps, ch);
    }
    printf("ps: %d  %s\n", strlen(ps), ps);
    strcat(result, ps);
    strcat(result, "00");
    strcat(result, src);
}


void Encrypt(char *plaintext, FILE *fp_cipher){
    //明文长度小于117bytes,一个分组
    if(strlen(plaintext) <= 117){
        char padding_plain[256] = "";
        char hex_plaintext[234] = "";
        String2Hex(plaintext, hex_plaintext);
        strcat(padding_plain, "0002");
        Padding(padding_plain, hex_plaintext);
        printf("%s\n", padding_plain);
    }
}

