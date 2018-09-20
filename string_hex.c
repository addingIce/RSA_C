#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

void String2Hex(char *src, char *dst){
    for(int i=0; i<strlen(src); i++){
        sprintf(dst+i*2,"%02x",*(src+i));
    }
}
