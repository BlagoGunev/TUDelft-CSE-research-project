#include<bits/stdc++.h>
using namespace std;
const int N=2e5+7;
int n,c[30],i,j,k,T_T;char s[N],t[N];
int cal(char s[N],int ans=0){for(int i=1;i<=n;++i)for(int j=1;j<i;++j)if(s[i]>s[j])ans++;return ans;}
int main(){
    for(scanf("%d",&T_T);T_T--;){
        memset(c,0,sizeof(c));
        for(scanf("%d%s%s",&n,s+1,t+1),k=0,i=1;i<=n;++i)c[s[i]-'a']++;
        for(i=1;i<=n;++i)c[t[i]-'a']--;
        for(i=0;i<26;++i)if(c[i])k=1;
        if(!k){
            k=0;memset(c,0,sizeof(c));
            for(i=1;i<=n;++i)c[t[i]-'a']++;
            for(i=0;i<26;++i)if(c[i]>=2)k=1;
            if(k)puts("YES");
            else{
                if(cal(s)-cal(t)&1)puts("NO");else puts("YES");
            }
        }
        else puts("NO");
    }
}
/*
4
4
abcd
abdc
5
ababa
baaba
4
asdf
asdg
4
abcd
badc

*/