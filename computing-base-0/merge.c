//
// Created by 赵政杰 on 2021/10/27.
//
#include <stdio.h>
#define MAX 100000
//以下定义的数组最长为100000（一般）
int main () {

    int n1 = 0;
    int n2 = 0;
    scanf("%d %d", &n1, &n2);
    long long int num1[MAX] = {0};
    for (int i = 0; i < n1; i++) {
        scanf("%lld", &num1[i]);
    }
    long long int num2[MAX] = {0};
    for (int j = 0; j < n2; j++) {
        scanf("%lld", &num2[j]);
    }
    long long int num3[1000] = {0};
    for (int i = 0; i < n1 + n2; i++) {
        if (i <= n1 - 1) {
            num3[i] = num1[i];
        } else {
            num3[i] = num2[i - n1];
        }
    }
    for (int i = 0; i < n1 + n2; i++) {
        int min = num3[i];
        int min_index = i;
        for (int j = i + 1; j < n1 + n2; j++) {
            if (min > num3[j]) {
                min = num3[j];
                min_index = j;
            }
        }
        int tmp = 0;
        tmp = num3[i];
        num3[i] = num3[min_index];
        num3[min_index] = tmp;
    }
    for (int i = 0; i < n1 + n2; i++) {
        if (num3[i] != num3[i + 1]) {
            printf("%lld ", num3[i]);
        }
    }
    return 0;
}
