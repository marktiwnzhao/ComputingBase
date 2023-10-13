//
// Created by Misaka on 2021/11/27.
//

#include <stdio.h>
#include <math.h>

char xN[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
char input[128] = {'\0'};
char temp[32];
char output[32];
int record[8] = {0};

int main () {
    scanf("%s", input);
    for (int l = 0; l < 128; l += 4) {
        int key = 0;
        for (int j = 0; j < 4; j ++) {
            key += (input[l + j] - 48) * pow(2, 3 - j);
        }
        int w = l / 4 - l / 4 % 4;
        if (temp[w] != '\0' || temp[w + 1] != '\0' || (l/4 + 1) % 4 == 0 || xN[key] != '0') {
            temp[l / 4] = xN[key];
        }
    }
    for (int i = 0; i < 32; i++) {
        printf("%c", temp[i]);
    }
    printf("\n");


    int t = 0;
    for (int l = 0; l < 32; l += 4) {
        if (temp[l + 2] == '\0' && temp[l + 3] == '0') {
            record[t] = 1;
        }
        t ++;
    }


    for (int i = 0; i < 8; i ++) {
        for (int j = i; j < 8; j ++) {
            if (record[j] == 1) {
                record[i] ++;
            } else {
                break;
            }
        }
    }
    for (int i = 0; i < 8; i++) {
        printf("%d", record[i]);
    }
    printf("\n");



    int max = 0;
    int max_i = 0;
    for (int i = 0; i < 8; i ++) {
        if (max < record[i]) {
            max = record[i];
            max_i = i;
        }
    }
    printf("%d\n", max_i);
    for (int i = 0; i < max - 1; i ++) {
        temp[max_i * 4 + 3] = '\0';
        max_i ++;
    }

    int p = 0;
    int q = 0;
    while (p < 32) {
        if (temp[p] != '\0') {
            output[q] = temp[p];
            q ++;
        }
        if (p < 31 && (p + 1) % 4 == 0 && (output[q - 1] != ':' || output[q - 2] != ':')) {
            output[q] = ':';
            q ++;
        }
        p ++;
    }

    int g = 0;
    while (output[g] != '\0') {
        printf("%c", output[g]);
        g ++;
    }


    return 0;
}