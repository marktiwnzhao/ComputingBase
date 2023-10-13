//
// Created by 赵政杰 on 2021/12/14.
//
#include <stdio.h>

char in[100];
char re[100];
int flag = 0;

int Match (const char * input, const char * regular, int pointer1, int pointer2);

int main () {
    scanf("%s", in);
    scanf("%s", re);
    Match(in, re, 0, 0);
    if (flag) {
        printf("1");
    } else {
        printf("0");
    }

    return 0;
}

int Match (const char * input, const char * regular, int pointer1, int pointer2) {
    if (*(input + pointer1) == '\0' && *(regular + pointer2) == '\0') {
        flag = 1;
        return 1;
    } else if (*(input + pointer1) == '\0' || *(regular + pointer2) == '\0') {
        return 0;
    } else {
        if (*(input + pointer1) == *(regular + pointer2)) {
            if (*(input + pointer1) == '\\') {
                if (*(regular + pointer2 + 1) == '\\') {
                    if (*(regular + pointer2 + 2) == '*') {
                        Match(input, regular, pointer1 + 1, pointer2);
                        Match(input, regular, pointer1 + 1, pointer2 + 2);
                    } else {
                        Match(input, regular, pointer1 + 1, pointer2 + 2);
                    }
                } else {
                    return 0;
                }
            } else if (*(regular + pointer2 + 1) == '*') {
                Match(input, regular, pointer1 + 1, pointer2);
                Match(input, regular, pointer1 + 1, pointer2 + 2);
            } else {
                Match(input, regular, pointer1 + 1, pointer2 + 1);
            }
        } else if (*(regular + pointer2) == '.') {
            if (*(regular + pointer2 + 1) == '*') {
                Match(input, regular, pointer1 + 1, pointer2);
                Match(input, regular, pointer1 + 1, pointer2 + 2);
            } else {
                Match(input, regular, pointer1 + 1, pointer2 + 1);
            }
        } else if (*(regular + pointer2) == '\\') {
            if (*(input + pointer1) == *(regular + pointer2 + 1)) {
                if (*(regular + pointer2 + 2) == '*') {
                    Match(input, regular, pointer1 + 1, pointer2 + 1);
                    Match(input, regular, pointer1 + 1, pointer2 + 3);
                } else {
                    Match(input, regular, pointer1 + 1, pointer2 + 2);
                }
            } else if (*(regular + pointer2 + 2) == '*') {
                Match(input, regular, pointer1, pointer2 + 3);
            } else {
                return 0;
            }
        } else if (*(regular + pointer2 + 1) == '*') {
            Match(input, regular, pointer1, pointer2 + 2);
        } else {
            return 0;
        }
    }
}
