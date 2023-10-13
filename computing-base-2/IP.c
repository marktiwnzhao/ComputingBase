//
// Created by 赵政杰 on 2021/12/11.
//
#include<stdio.h>
#include<string.h>
char s[10];
int lens,tot,tmp[10];

struct node {
    int a[10];
}ans[100000];

int cd(int l,int r) {
    int res=0;
    for(int i=l;i<=r;i++) res=res*10+s[i]-'0';//printf("%d\n",res);
    return res;
}

void dfs(int pos,int len) {
    if(len==4&&pos!=lens) return;
    if(pos==lens) {
        if(len!=4) return;
        ++tot;
        for(int i=1;i<=4;i++) ans[tot].a[i]=tmp[i];
        return;
    }
    if(s[pos]=='0') return tmp[len+1]=0,dfs(pos+1,len+1);
    for(int i=pos;i<lens;i++) {
        int u=cd(pos,i);//printf("%d %d\n",len,u);
        if(u<256) tmp[len+1]=u,dfs(i+1,len+1);
    }
    return;
}

int main() {
    scanf("%s",s),lens=strlen(s);
    dfs(0,0);
    for(int i=1;i<=tot;i++) for(int j=1;j<=4;j++) printf("%d%c",ans[i].a[j],j==4?(i==tot?'\n':','):'.');
    return 0;
}