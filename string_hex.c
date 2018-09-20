#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

void String2Hex(char *src, char *dst){
    int num;
    char ch[2];
    for(int i=0; i<strlen(src); i++){
        num = (int)src[i];
        sprintf(ch, "%02x", num);
        //itoa(num, ch, 16);
        strcat(dst, ch);
    }
}
