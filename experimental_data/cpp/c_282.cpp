#include <bits/stdc++.h>
#include<cstdio>
#include<cstring>
using namespace std;

char s[1000005];
int n1,n2,t1,t2,i,j,k;

int main(){

    fgets(s, sizeof(s), stdin);
    t1=0;
    n1=strlen(s);
    for(i=0;i<strlen(s);i++)
        if(s[i]=='1')t1++;

    fgets(s, sizeof(s), stdin);
    t2=0;
    n2=strlen(s);
    for(i=0;i<strlen(s);i++)
        if(s[i]=='1')t2++;

    if(n1!=n2)printf("NO\n");
    else{
        if((t1==0)==(t2==0))printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}