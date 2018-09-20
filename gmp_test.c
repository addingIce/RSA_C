#include <stdio.h>
#include <time.h>
#include "gmp.h"
void gmp_test(){
    //定义
    mpz_t a, b, c;
    //初始化
    mpz_init_set_ui(a,254);
    mpz_init_set_str(b, "1000000000000000000000000000000", 10);
    mpz_init_set_str(c, "2000000000000000000000000000000", 10);
    //打印
    gmp_printf("a = %Zd, b = %Zd, c = %Zd\n", a, b, c);
    /*
    //加减法
    mpz_add(a, b, c);
    gmp_printf("b + c = %Zd\n", a);
    mpz_sub(a, b, c);
    gmp_printf("b - c = %Zd\n", a);
    //乘法
    mpz_mul(a, b, c);
    gmp_printf("b * c = %Zd\n", a);
    //除法
    mpz_cdiv_q(a, b, c);    //求商，向上取整
    mpz_cdiv_r(a, b, c);    //求余数
    mpz_fdiv_q(a, b, c);    //求商，向下取整
    gmp_printf("b / c = %Zd\n", a);
    mpz_fdiv_r(a, b, c);    //求余数
    gmp_printf("b %% c = %Zd\n", a);
    //求平方根，向下取整
    mpz_sqrt(a, b);
    gmp_printf("b**-2 = %Zd\n", a);
    //幂运算
    mpz_pow_ui(a, b, 2);
    gmp_printf("b**2 = %Zd\n", a);
    */
    unsigned long int t;
    t = mpz_get_ui(b);
    printf("t = %ld\n", t);

    FILE *fp = fopen("gmp_test.txt", "w+");
    gmp_fprintf(fp, "%Zx\n%Zd\n%Zd\n%Zd\n", a, a, b, c);

    //将b转换为str，16进制表示
    char *A = NULL;
    A = mpz_get_str(A, 16, b);
    printf("A: %s\n", A);

    gmp_randstate_t grt;


    gmp_randinit_default(grt);
    gmp_randseed_ui(grt, time(NULL));
    mpz_t e;
    mpz_init_set_ui(e, 2);
    mpz_pow_ui(b, e, 9);
    while(mpz_cmp(a, b) < 0){
        mpz_urandomb(a, grt, 10);
    }
    printf("rand_a: %s\n", mpz_get_str(A, 2, a));

    fclose(fp);
    mpz_clear(a);
    mpz_clear(b);
    mpz_clear(c);
}
