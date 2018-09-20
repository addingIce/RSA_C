#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#define N 512

void Sieve(FILE *fp){
    static bool prime[N];
    int i, j;
    /*
    //建立bool数组
    for(i=2;i<N;i++){
        if(i%2) prime[i] = true;
        else prime[i] = false;
    }
    //筛选素数
    for(i=3;i<sqrt(N);i++){
        if(prime[i]){
            for(j=i+i;j<N;j+=i) prime[j] = false;
        }
    }
    */

    //建立bool数组,只管奇数，prime[i]代表 2*i+3
    for(i=0;i<(N-1)/2;i++){
        prime[i] = true;
    }
    //筛选素数
    for(i=0;(2*i+1)<sqrt(N);i++){
        if(prime[i]){
            for(j=3*(2*i+3);j<=N;j+=2*(2*i+3)) prime[(j-3)/2] = false;
        }
    }


    //将结果输出到文件
    for(i=0;i<(N-1)/2;i++){
        if(prime[i]) fprintf(fp, "%d ",2*i+3);
    }

    printf("Primes smaller than %d have been written to prime.txt .\n", N);
}
