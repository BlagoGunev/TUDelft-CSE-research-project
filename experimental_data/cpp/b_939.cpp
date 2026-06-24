#include <bits/stdc++.h>
//by sdfzchy
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long LL;
const int inf=(1<<30);
inline LL in()
{
 char ch=getchar();
 LL f=1,tmp=0;
 while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
 while(ch>='0'&&ch<='9') {tmp=(tmp<<1)+(tmp<<3)+(ch-'0');ch=getchar();}
 return tmp*f;
}

LL n,k;
int main()
{
// freopen("in.in","r",stdin);
// freopen("out.out","w",stdout);
 n=in(),k=in();
 LL ans=1e18+10,x=1,y=0;
 for(int i=1;i<=k;i++)
 {
  LL a=in();
  if((n-(n/a*a))<ans) ans=n-n/a*a,x=i,y=n/a;
 }
 printf("%lld %lld",x,y);
 return 0;
}