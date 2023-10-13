//
// Created by 赵政杰 on 2021/11/29.
//
#include <stdio.h>
#include <math.h>

int main() {
    char strs[129] = {'\0'};

    scanf("%s", strs);
    char op[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
    char str_1[32] = {'\0'};
    for (int i = 0; i < 128; i += 4) {
        int k = 0;
        for (int j = 0; j < 4; j++) {
            k += ((int)strs[i + j] - 48) * (int)pow(2, 3 - j);
        }
        int m = i / 16 * 4;
        if (op[k] != '0' || str_1[m] != '\0' ||
            str_1[m + 1] != '\0' || (i / 4 + 1) % 4 == 0) {
            str_1[i / 4] = op[k];
        }
    }
    //for (int i = 0; i < 32; i++) {
        //printf("%c", str_1[i]);
    //}
    //printf("\n");


    int pr[8] = {0};
    int x = 0;
    while (x < 32) {
        if (str_1[x + 2] == '\0' && str_1[x + 3] == '0') {
            pr[x / 4] = 1;
        }
        x += 4;
    }

    int max = 0;
    int max_index = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = i + 1; j < 8; j++) {
            if (pr[i] > 0 && pr[j] > 0) {
                pr[i]++;
            } else {
                break;
            }
        }
        if (pr[i] > max) {
            max = pr[i];
            max_index = i;
        }
    }
    //for (int i = 0; i < 8; i++) {
      //  printf("%d", pr[i]);
    //}
    //printf("\n");
    //printf("%d\n", max_index);



    for (int i = 0; i < max; i++) {
        str_1[max_index * 4 + 3] = '\0';
        max_index++;
    }
    //压栈
    char str_2[33] = {'\0'};
    int top = 0;
    for (int i = 0; i < 32; i++) {
        if (str_1[i] != '\0') {
            str_2[top] = str_1[i];
            top++;
        }
        if ((i + 1) % 4 == 0 && i <= 30) {
            if (str_2[top - 1] != ':' || str_2[top - 2] != ':') {
                str_2[top] = ':';
                top++;
            }
        }
    }

    for (int i = 0; str_2[i] != '\0'; i++) {
        printf("%c", str_2[i]);
    }
    return 0;
}