//
// Created by 赵政杰 on 2021/12/12.
//
#include <stdio.h>
#include <string.h>
char ipv4[50][20];
int len;
int line = 0;
void Split(char ch[],char new_string[],int loc ,int new_loc,int num){
    if(num > 0 && loc >= len) {
        return;
    }else if(num == 0 && len - 1 - loc >= 3 ){
        return;
    }else if(num == 0 && len - 1 - loc == 2 && ch[loc] > '2')return;
    if(num == 0){
        for (int i = loc; i < len; i++) {
            new_string[new_loc] = ch[i];
            new_loc++;
        }
        strncpy(ipv4[line],new_string,len + 3);
        line++;
        return;
    }
    if(ch[loc] == '0' && num > 0){
        new_string[new_loc] = ch[loc];
        new_string[new_loc + 1] = '.';
        Split(ch,new_string,loc + 1,new_loc + 2,num - 1);
    }else if(ch[loc] != '0' && num > 0){
        new_string[new_loc] = ch[loc];
        new_string[new_loc + 1] = '.';
        Split(ch,new_string,loc + 1,new_loc + 2,num - 1);
        new_string[new_loc + 1] = ch[loc + 1];
        new_string[new_loc + 2] = '.';
        Split(ch,new_string,loc + 2,new_loc + 3,num - 1);
        if(ch[loc] <= '2'){
            new_string[new_loc + 2] = ch[loc + 2];
            new_string[new_loc + 3] = '.';
            Split(ch,new_string,loc + 3,new_loc + 4 , num - 1);
        }
    }
}
int Check(char str[]){
    int str_len = strlen(str);
    if(str[str_len - 1] == '.'){
        return 0;
    }
    int count = 0;
    for (int i = 0; i < str_len; i++) {
        if(str[i] == '.')count++;
    }
    if(count != 3){
        return 0;
    }
    int points[4] = {0};
    int k = 1;
    for (int i = 0; i < str_len; i++) {
        if(str[i] == '.'){
            points[k] = i;
            k++;
        }
    }
    if(str_len - points[3] == 4 && str[points[3] + 1] == '0'){
        return 0;
    }else if(str_len - points[3] == 3 && str[points[3] + 1] == '0')return 0;
    if(points[1] - points[0] == 3){
        int sum1 = (str[0] - 48 ) * 100 + (str[1] - 48) * 10 + (str[2] - 48);
        if(sum1 > 255)return 0;
    }
    for (int i = 1; i < 4; i++) {
        int sum = 0;
        if(points[i] - points[i - 1] == 4){
            sum = (str[points[i - 1] + 1] - 48) * 100 + (str[points[i - 1] + 2] - 48) * 10 + str[points[i - 1] + 3] - 48;
        }
        if(sum > 255)return 0;
    }
    if(str_len - points[3] == 4){
        int sum2 = (str[points[3] + 1] - 48) * 100 + (str[points[3] + 2] - 48) * 10 + str[points[3] + 3] - 48;
        if(sum2 > 255)return 0;
    }
    return 1;
}
int main(){
    char ch[8] ;
    scanf("%s",ch);
    len = strlen(ch);
    char new_string[20] = {0};
    int loc = 0;
    int new_loc = 0;
    Split(ch,new_string,loc,new_loc,3);
    int count = 0;
    for (int i = 0; i < 50; i++) {
        if(ipv4[i][0] != 0 && Check(ipv4[i])&&count == 0){
            printf("%s",ipv4[i]);
            count++;
        }else if(ipv4[i][0] != 0 && Check(ipv4[i]) && count > 0){
            printf(",%s",ipv4[i]);
        }
    }
    return 0;
}

