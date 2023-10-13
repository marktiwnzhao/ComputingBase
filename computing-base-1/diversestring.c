//
// Created by 赵政杰 on 2021/11/13.
//
#include <stdio.h>
#include <string.h>
#define MAX 105
char str[MAX][MAX];

//char Min (const char s[]);
int main() {
    int n = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", str[i]);
    }
    for (int i = 0; i < n; i++) {
        int j = 0;
        while (str[i][j] != '\0') {
            j++;
        }
        int true = 1;
        for (int k = 0; k < j - 1; k++) {
            for (int m = k + 1; m < j; m++) {
                if (str[i][k] - str[i][m] >= j || str[i][k] == str[i][m] || str[i][k] - str[i][m] <= - j) {
                    true = 0;
                    break;
                }
            }
        }
        if (true) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }



    return 0;
}

/**char Min (const char s[]) {
    int k = 0;
    while (s[k] != '\0') {
        k++;
    }
    char min = s[0];
    for (int i = 1; i < k; i++) {
        if (strncmp(min, s[i], 1) >= 0) {
            min = s[i];
        }
    }
    return min;

}
 */