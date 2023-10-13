//
// Created by 赵政杰 on 2021/11/13.
//
#include <stdio.h>
#define MAX 20001
int old[MAX] = {0};
int new[MAX] = {0};

int main() {
    int n = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &old[i]);
    }

    for (int j = 1; j <= n; j++) {
        for (int i = 1; i <= 2 * n; i++) {
            if (old[i] > 0) {
                new[i + 1] = old[i];
                old[i] = 0;
            }
        }
        for (int i = 1; i <= 2 * n; i++) {
            if (new[i] + old[i] > 0) {
                old[i] = new[i];
            }
            if (new[i] + old[i] == 0) {
                old[i] = 0;
            }

        }

        for (int i = 1; i <= 2 * n; i++) {
            new[i] = 0;
        }

    }

    for (int i = 1; i <= 2 * n; i++) {
        if (old[i] > 0 || old[i] < 0) {
            printf("%d ", old[i]);
        }
    }

    return 0;
}
