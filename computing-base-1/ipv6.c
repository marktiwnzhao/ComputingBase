//
// Created by 赵政杰 on 2021/11/27.
//
#include <stdio.h>
#include <math.h>

int main() {
    int nums[130] = {0};
    char m;
    for (int i = 0; i < 128; i++) {
        scanf("%c", &m);
        nums[i] = m - '0';
    }
    int nums_1[32] = {0};
    int k = 0;
    while (k < 128) {
        int sum = 0;
        for (int i = 0; i < 4; i++) {
            sum += nums[k + i] * (int) pow(2, 3 - i);
        }
        if (sum <= 9) {
            nums_1[k / 4] = sum + '0';
        } else {
            nums_1[k / 4] = sum - 10 + 'a';
        }
        k += 4;
    }

    int x = 0;
    int pr[8] = {1, 1, 1, 1, 1, 1, 1, 1};


    while (x < 32) {
        for (int i = 0; i < 4; i++) {
            if (nums_1[x + i] != '0') {
                pr[x / 4] = 0;
                break;
            }
        }
        x += 4;
    }


    int max = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = i + 1; j < 8; j++) {
            if (pr[i] > 0 && pr[j] > 0) pr[i]++;
            else break;
        }
        if (pr[i] > max) {
            max = pr[i];
        }
    }

    int y = 0;
    while (y < 32) {
        if (pr[y / 4] == 0) {
            int ps = 0;
            for (int i = 0; i < 4; i++) {
                if (nums_1[y + i] != '0' || ps) {
                    ps = 1;
                    printf("%c", nums_1[y + i]);
                }
            }
            if (y < 28) {
                printf(":");
            }
            y += 4;
        } else if (pr[y / 4] == max) {
            printf(":");
            y = y + pr[y / 4] * 4;
        } else {
            printf("0:");
        }

    }

    return 0;
}