//
// Created by 赵政杰 on 2021/11/27.
//
#include <stdio.h>
#define MAX 30000
char str[MAX] = {'\0'};
int top = 0;
void Open(char m[]);
int main() {
    char string[105];
    scanf("%s", string);
    //scanf("%d", &len);
    //for (int i = 0; i < len; i++) {
        //scanf(" %c", &string[i]);
   // }

    Open(string);
    for (int i = 0; i < top; i++) {
        if (str[i] == '[') {
            printf("{");
        } else if (str[i] == ']') {
            printf("}");
        } else {
            printf("%c", str[i]);
        }
    }

    return 0;
}
void Open(char m[]) {
    int len = 0;
    while (m[len] != '\0') {
        len++;
    }
    for (int i = 0; i < len; i++) {
        if ((m[i] >= 48 && m[i] <= 57) || (65 <= m[i] && m[i] <= 90)
        || (m[i] >= 97 && m[i] <= 122) || m[i] == '{') {
            str[top] = m[i];
            top++;
        }
        if (m[i] == '}') {
            if (str[top - 1] == '{') {
                if (top >= 2 && str[top - 2] == '{') {
                    top--;
                    str[top] = '\0';
                    str[top - 1] = '[';
                    continue;
                } else {
                    str[top - 1] = ']';
                    i++;
                    continue;
                }
            }
            int j = top - 1;
            int q = 0;
            for (; j >= 0; j--) {
                if (str[j] == '{') {
                    str[j] = '\0';
                    for (int k = j + 1; k <= top - 1; k++) {
                        q = q * 10 + str[k] - '0';
                        str[k] = '\0';
                    }
                    //printf("%d", q);
                    top = j + q - 1;
                    for (int k = j; k < top; k++) {
                        str[k] = str[j - 1];
                    }
                    break;
                }
            }
        }
    }
}
