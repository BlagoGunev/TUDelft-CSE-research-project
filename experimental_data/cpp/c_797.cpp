#include<bits/stdc++.h>
using namespace std;
#define mx 100009
char s[mx],t[mx],u[mx];
char mn[mx];
int main()
{
    int n,ti=0,ui=0,i;
    scanf("%s",s);
    n=strlen(s);
    mn[n]='z'+1;
    for(i=n-1;i>=0;i--){
        mn[i]=min(s[i],mn[i+1]);
    }
    for(i=0;i<n;i++){
        if(ti && t[ti-1]<=mn[i]){
            u[ui++]=t[--ti];
            i--;
            continue;
        }
        else{
            t[ti++]=s[i];
        }
    }
    while(ti){
        u[ui++]=t[--ti];
    }
    u[ui++]='\0';
    printf("%s\n",u);
    //main();
    return 0;
}