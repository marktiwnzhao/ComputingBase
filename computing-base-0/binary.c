//
// Created by 赵政杰 on 2021/10/27.
//
#include <stdio.h>
#include <math.h>
int main(){
    long long int n = 0;
    int num[32] = {0};
    scanf("%lld", &n);
    if (n >= 0) {
        for (int i = 0; i < 32; i++) {
            num[31 - i] = (n / (int)(pow(2,i))) % 2;
        }
    }
    if (n < 0) {
        for (int i = 0; i < 32; i++) {
            num[31 - i] = 1 - (((-n) / (int)(pow(2,i))) % 2);
        }
        num[31] += 1;
        for (int i = 0; i < 31; i++) {
            if (num[31 - i]  == 2) {
                num[31 - i] = 0;
                num[30 - i] += 1;

            }
        }
    }
    for (int i = 0; i < 32; i++) {
        printf("%d", num[i]);
    }
    return 0;
}
