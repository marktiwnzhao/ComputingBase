//
// Created by 赵政杰 on 2021/11/13
//
#include <stdio.h>
#define MAX 100000

int s[MAX] = {0};

int main() {
    int n = 0;
    scanf("%d", &n);

    s[99999] = 1;
    int v = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 99999; j >= 100000 - n; j--) {
            s[j] = s[j] * 2 + v;
            v = s[j] / 10;
            s[j] = s[j] % 10;
        }
    }

    int k = 0;
    for (k; k < 100000; k++) {
        if (s[k] != 0) {
            break;
        }
    }
    for (k; k < 100000; k++) {
        printf("%d", s[k]);
    }

    return 0;
}
