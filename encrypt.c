#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// EB = 00 + 02 + PS + 00 + plain
void Padding(char result[], char *src){
    char ps[125] = "";
    int ps_len, num;
    char ch[2];
    //生成ps_len长度的随机填充ps
    ps_len = 125 - strlen(src);
    srand((unsigned)time(NULL));
    for(int i=0; i<ps_len; i++){
        num = rand() % 254 + 1;
        itoa(num, ch, 16);
        strcat(ps, ch);
    }
    strcat(result, ps);
    strcat(result, "00");
    strcat(result, src);
}
void Encrypt(char *plaintext, FILE *fp_cipher){
    //明文长度小于117bytes,一个分组
    if(strlen(plaintext) <= 117){
        char plain[130] = "0002";
        Padding(plain, plaintext);
        printf("%s\n", plain);
    }
}

