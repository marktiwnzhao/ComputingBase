//
// Created by 赵政杰 on 2021/12/13.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAX 35

int Match(char *, char *);
int FrontMatch(char a, char b);

int main() {
    char *old_str = calloc(MAX, sizeof(*old_str));
    char *new_str = calloc(MAX, sizeof(*new_str));
    scanf("%s %s", old_str, new_str);
    if (Match(old_str, new_str)) {
        printf("1\n");
    } else {
        printf("0\n");
    }
    free(old_str);
    free(new_str);

    return 0;
}

int FrontMatch(char a, char b) {
    return a == b || b == '.';
}

int Match(char *str_1, char *str_2) {
    int top_1 = 0;
    int top_2 = 0;
    if (*(str_2 + top_2) == '\0' && *(str_1 + top_1) == '\0')  return 1;
    else if (*(str_1 + top_1) == '\0' || *(str_2 + top_2) == '\0')  return 0;
    bool front_match = *(str_1 + top_1) == *(str_2 + top_2) || *(str_2 + top_2) == '.';
    if (*(str_2 + top_2) == '\\') {
        top_2++;
        if (*(str_2 + top_2) == *(str_1 + top_1)) {
            return Match(str_1 + top_1, str_2 + top_2);
        } else {
            return 0;
        }
    } else if (*(str_2 + (++top_2)) == '*') {
        top_2--;
        return Match(str_1 + top_1, str_2 + (top_2 + 2)) || (front_match && Match(str_1 + (++top_1), str_2 + top_2));
    } else return Match(str_1 + (++top_1), str_2 + (++top_2));
}
