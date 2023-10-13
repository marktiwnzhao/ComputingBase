//
// Created by 赵政杰 on 2021/10/27.
//
#include <stdio.h>
int main() {
    int n = 0;
    scanf("%d", &n);
    long int num[1000] = {0};
    for (int i = 0; i < n; i++) {
        scanf("%d", &num[i + 1]);
    }
    num[n + 1] = num[n] + 2;
    for (int i = 0; i <= n; i++) {
        if (num[i + 1] - num[i] >= 2) {
            printf("%d", num[i] + 1);
            break;
        }
    }
    return 0;
}
