#include <stdio.h>
#include <stdlib.h>

int Match(char *, char *, int, int );

int main() {
    char *str = calloc(40, sizeof(*str));
    char *reg = calloc(40, sizeof(*reg));
    scanf("%s %s", str, reg);
    printf("%s", Match(str, reg, 0, 0) ? "1" : "0");
    return 0;
}

int Match(char *str, char *reg, int top_1, int top_2) {
    if (str[top_1] == '\0' && reg[top_2] == '\0') return 1;
    else if (str[top_1] == '\0' || reg[top_2] == '\0') return 0;
    if (str[top_1] == reg[top_2]) {
        if (str[top_1] == '\\') {
            if (reg[top_2 + 1] == '\\') {
                if (reg[top_2 + 2] == '*') {
                    return Match(str, reg, top_1 + 1, top_2) ||
                           Match(str, reg, top_1 + 1, top_2 + 2);
                } else {
                    return Match(str, reg, top_1 + 1, top_2 + 2);
                }
            } else return 0;
        } else if (reg[top_2 + 1] == '*') {
            return Match(str, reg, top_1 + 1, top_2) || Match(str, reg, top_1 + 1, top_2 + 2);
        } else return Match(str, reg, top_1 + 1, top_2 + 1);
    } else if (reg[top_2] == '.') {
        if (reg[top_2 + 1] == '*') {
            return Match(str, reg, top_1 + 1, top_2) || Match(str, reg, top_1 + 1, top_2 + 2);
        } else return Match(str, reg, top_1 + 1, top_2 + 1);
    } else if (reg[top_2] == '\\') {
        if (str[top_1] == reg[top_2 + 1]) {
            if (reg[top_2 + 2] == '*') {
                return Match(str, reg, top_1 + 1, top_2 + 1) ||
                        Match(str, reg, top_1 + 1, top_2 + 3);
            } else return Match(str, reg, top_1 + 1, top_2 + 2);
        } else if (reg[top_2 + 2] == '*') {
            return Match(str, reg, top_1 + 1, top_2 + 3);
        } else return 0;
    } else if (reg[top_2 + 1] == '*') {
        return Match(str, reg, top_1, top_2 + 2);
    } else return 0;
}