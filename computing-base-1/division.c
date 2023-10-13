//
// Created by 赵政杰 on 2021/11/27.
//
#include <stdio.h>
#include <math.h>
#define MAX 40


long long a[MAX] = {0};
long long Dec(int nums[], int len);
void Be(long long n);

int main() {
    char strs[2][MAX] = {'\0'};
    scanf("%s %s", strs[0], strs[1]);
    int len_1 = 0;
    while (strs[0][len_1] != '\0') {
        len_1++;
    }
    int len_2 = 0;
    while (strs[1][len_2] != '\0') {
        len_2++;
    }

    int nums[2][MAX] = {0};
    for (int i = 0; i < len_1; i++) {
        nums[0][i] = strs[0][i] - '0';
    }
    for (int i = 0; i < len_2; i++) {
        nums[1][i] = strs[1][i] - '0';
    }

    long long out_1 = Dec(nums[0], len_1) / Dec(nums[1], len_2);
    long long ont_2 = Dec(nums[0], len_1) % Dec(nums[1], len_2);
    if (out_1) {
        Be(out_1);
        int k = 0;
        for (int i = 0; i < MAX; i++) {
            if (a[i]) k = 1;
            if (k) {
                printf("%d", a[i]);
            }
        }
    } else {
        printf("0");
    }
    printf("\n");
    for (int i = 0; i < len_1; i++) {
        printf("%d", nums[0][i]);
    }
    Be(ont_2);
    for (int i = 0; i < len_2; i++) {
        printf("%d", a[MAX - len_2 + i]);
    }
    return 0;
}

long long Dec(int nums[], int len) {
    long long dec = 0;
    for (int i = 0; i < len; i++) {
        dec += nums[len - 1 - i] * (long long)pow(2, i);
    }
    return dec;
}

void Be(long long n) {
    for (int i = 0; i < MAX; i++) {
        a[MAX - 1 - i] = n % 2;
        n /= 2;
    }
}