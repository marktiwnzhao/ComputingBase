//
// Created by 赵政杰 on 2021/10/26.
//
#include <stdio.h>
#include <ctype.h>
int main() {
    int n = 0;
    scanf("%d ", &n);
    char strings[1000];
    for (int i = 1; i <= n; i++) {
        scanf("%c", &strings[i]);
    }
    for (int i = 1; i <= n; i++) {
        if (97 <= strings[i] && strings[i] < 123) {
            printf("%c", toupper(strings[i]));
        }
    }
}
