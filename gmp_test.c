#include <stdio.h>
#include <time.h>
#include "gmp.h"
void gmp_test(){
    //����
    mpz_t a, b, c;
    //��ʼ��
    mpz_init_set_ui(a,254);
    mpz_init_set_str(b, "1000000000000000000000000000000", 10);
    mpz_init_set_str(c, "2000000000000000000000000000000", 10);
    //��ӡ
    gmp_printf("a = %Zd, b = %Zd, c = %Zd\n", a, b, c);
    /*
    //�Ӽ���
    mpz_add(a, b, c);
    gmp_printf("b + c = %Zd\n", a);
    mpz_sub(a, b, c);
    gmp_printf("b - c = %Zd\n", a);
    //�˷�
    mpz_mul(a, b, c);
    gmp_printf("b * c = %Zd\n", a);
    //����
    mpz_cdiv_q(a, b, c);    //���̣�����ȡ��
    mpz_cdiv_r(a, b, c);    //������
    mpz_fdiv_q(a, b, c);    //���̣�����ȡ��
    gmp_printf("b / c = %Zd\n", a);
    mpz_fdiv_r(a, b, c);    //������
    gmp_printf("b %% c = %Zd\n", a);
    //��ƽ����������ȡ��
    mpz_sqrt(a, b);
    gmp_printf("b**-2 = %Zd\n", a);
    //������
    mpz_pow_ui(a, b, 2);
    gmp_printf("b**2 = %Zd\n", a);
    */
    unsigned long int t;
    t = mpz_get_ui(b);
    printf("t = %ld\n", t);

    FILE *fp = fopen("gmp_test.txt", "w+");
    gmp_fprintf(fp, "%Zx\n%Zd\n%Zd\n%Zd\n", a, a, b, c);

    //��bת��Ϊstr��16���Ʊ�ʾ
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
