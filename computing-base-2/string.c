//
// Created by 赵政杰 on 2021/12/11.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

int main() {
    char *str = malloc(MAX * sizeof(str));
    gets(str);
    int len = strlen(str);
    int true = 1;
    for (int i = 0, j = len - 1; i < j; i++, j--) {
        if (*(str + i) != *(str + j)) {
            true = 0;
            break;
        }
    }
    if (true) {
        for (int i = 0; i < len / 2 + len % 2; i++) {
            printf("%c", *(str + i));
        }
    } else {
        printf("%s", str);
    }
    return 0;
}
