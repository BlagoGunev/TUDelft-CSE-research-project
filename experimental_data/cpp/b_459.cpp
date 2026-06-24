#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cctype>
using namespace std;

#define LL int64_t
const int maxn=2e5+10;
const int INF=1e9+10;
int readint()
{
    int x=0;
    char ch;
    ch=getchar();
    while(!isdigit(ch))ch=getchar();
    while(isdigit(ch))
    {
        x=x*10+ch-'0';
        ch=getchar();
    }
    return x;
}
int main()
{
    //freopen("D:\\in.txt","r",stdin);
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        int i,j,k,x,mina=INF,min_num=0,maxa=-1,max_num=0;
        for(i=0;i<n;i++)
        {
            x=readint();
            if(x<mina)
            {
                mina=x;
                min_num=1;
            }
            else if(x==mina)min_num++;
            if(x>maxa)
            {
                maxa=x;
                max_num=1;
            }
            else if(x==maxa)max_num++;
        }
        LL ans=(LL)min_num*max_num;
        if(maxa==mina)ans=(LL)min_num*(max_num-1)/2;
        printf("%d %lld\n",maxa-mina,ans);
    }
    return 0;
}