//
// Created by 赵政杰 on 2021/10/14.
//
#include <stdio.h>
#include <math.h>
#define N 500
int isprime(int y)
{
    int i,ret = 1;
    for(i = 2;i <= sqrt(y);i++)
    {
        if(y%i == 0)
        {ret = 0;break;}
    }
         return ret;
}
int ThePrime(int n)
{
    int num = 0;
    int cur = 2;
    while (num < n) {
        if (isprime(cur))
            num++;
        cur++;
    }cur--;
    return cur;
}
void test2()
{
    int i;
    for (i = 1;i < N+1;i++)
    {
        printf("%6d", ThePrime(i));
        if(i%10 == 0)
            printf("\n");
    }
}
int main()
{
    test2();
}

