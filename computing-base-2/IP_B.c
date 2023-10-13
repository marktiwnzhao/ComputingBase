//
// Created by 赵政杰 on 2021/12/12.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char outside[100][100];
int top = 0;
void Split(char *str, int m, int n);
int Bool(const char *str, int m, int n) {
    int k = 0;
    int d = 0;
    while (m + k <= n) {
        d = d * 10 + str[m + k] - '0';
        k++;
    }
    if (m > n) {
        return 0;
    }
    if (k > 1 && str[m] == '0') {
        return 0;
    }
    if (d > 255) {
        return 0;
    }
    return 1;
}

int main() {
    char *str = calloc(10, sizeof(*str));
    scanf("%s", str);
    Split(str, 0, 0);
    for (int i = 0; i < top; i++) {
        printf("%s%s", outside[i], (i == top - 1) ? "" : ",");
    }
    free(str);
    //printf("\n%d", top);

    return 0;
}

void Split(char *str, int m, int n) {
    int len = (int) strlen(str);
    if (n == 3) {
        if (Bool(str, m, len - 1)) {
            for (int i = 0; i < len; i++) {
                outside[top][i] = str[i];
            }
            top++;
        }
        return;
    }

    for (int i = m; i < len; i++) {
        if (Bool(str, m, i)) {
            for (int j = len; j > i + 1; j--) {
                str[j] = str[j - 1];
            }
            str[i + 1] = '.';
            Split(str, i + 2, n + 1);
            for (int j = i + 1; j < len; j++) {
                str[j] = str[j + 1];
            }
            str[len] = '\0';
        } else {
            break;
        }
    }
}
