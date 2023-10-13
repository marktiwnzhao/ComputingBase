//
// Created by 赵政杰 on 2021/11/13.
//
#include <stdio.h>
void ThreePrint (int num);

int main() {
    int n = 0;
    scanf("%d", &n);

    int x = n / 1000000000;
    int y = (n % 1000000000) / 1000000;
    int z = (n % 1000000) / 1000;
    int v = n % 1000;
    if (x != 0) {
        ThreePrint(x);
        printf("Billion ");
        ThreePrint(y);
        if (y != 0) {
            printf("Million ");
        }
        ThreePrint(z);
        if (z != 0) {
            printf("Thousand ");
        }
        ThreePrint(v);
    } else {
        if (y != 0) {
            ThreePrint(y);
            printf("Million ");
            ThreePrint(z);
            if (z != 0) {
                printf("Thousand ");
            }
            ThreePrint(v);
        } else {
            ThreePrint(z);
            if (z != 0) {
                printf("Thousand ");
            }
            ThreePrint(v);
        }
    }
    return 0;
}

void ThreePrint (int num) {
    int a = num / 100;
    int b = (num % 100) / 10;
    int c = num % 10;
    char str[50][20] = {{"Zero"}, {"One"}, {"Two"}, {"Three"}, {"Four"}, {"Five"}, {"Six"}, {"Seven"}, {"Eight"}, {"Nine"},
                        {"Ten"}, {"Eleven"}, {"Twelve"}, {"Thirteen"}, {"Fourteen"},{"Fifteen"}, {"Sixteen"}, {"Seventeen"}, {"Eighteen"}, {"Nineteen"},
                        {"Twenty"}, {"Thirty"}, {"Forty"}, {"Fifty"}, {"Sixty"}, {"Seventy"}, {"Eighty"}, {"Ninety"}};
    if (a != 0) {
        if (b == 1) {
                printf("%s Hundred And %s ", str[a], str[10 + c]);
        } else if (b == 0) {
            if (c != 0) {
                printf("%s Hundred And %s ", str[a], str[c]);
            } else {
                printf("%s Hundred ", str[a]);
            }
        } else {
            if (c != 0) {
                printf("%s Hundred And %s %s ", str[a], str[b + 18], str[c]);
            } else {
                printf("%s Hundred And %s ", str[a], str[b + 18]);
            }
        }
    } else {
        if (b == 0) {
            if (c != 0) {
                printf("%s ", str[c]);
            }
        } else if (b == 1) {
            printf("%s ", str[c + 10]);
        } else {
            if (c != 0) {
                printf("%s %s ", str[b + 18], str[c]);
            } else {
                printf("%s ", str[b + 18]);
            }
        }
    }
}
