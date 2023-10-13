//
// Created by 赵政杰 on 2021/11/27.
//
#include <stdio.h>
#define MAX 40
int bin[3][MAX] = {0};
void Binary(int x, int y, int z);

int main() {
    int ipv[3][4] = {0};
    for (int i = 0; i < 3; i++) {
        scanf("%d.%d.%d.%d", &ipv[i][0], &ipv[i][1], &ipv[i][2], &ipv[i][3]);
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            Binary(ipv[i][j], j, i);
        }
    }
    for (int i = 0; i < 32; i++) {
        bin[0][i] &= bin[1][i];
        bin[2][i] &= bin[1][i];
    }

    int true = 1;
    for (int i = 0; i < 32; i++) {
        if (bin[0][i] != bin[2][i]) {
            true = 0;
            break;
        }
    }
    if (true) {
        printf("True");
    } else {
        printf("False");
    }

    return 0;
}

void Binary(int x, int y, int z) {
    for (int i = 0; i < 8; i++) {
        bin[z][(y + 1) * 8 - 1 - i] = x % 2;
        x /= 2;
    }
}