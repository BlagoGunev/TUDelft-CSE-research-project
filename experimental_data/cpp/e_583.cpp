#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
#define N 200050
#define fr first
#define sc second
#define ll long long
pair <int,int> li[N];
int v[N],n,m,s[N],cnt[N];bool b[N];ll ans;
inline int Read()
 {
    int x=0;char y;
    do y=getchar(); while (y<'0'||y>'9');
    do x=x*10+y-'0',y=getchar(); while (y>='0'&&y<='9');
    return x;
 }
int gcd(int x,int y)
 {return !y?x:gcd(y,x%y);}
void Solve()
 {
    for (int i=1;i<n;)
     {
        int q=li[i].fr,tot=0;
        memset(b,0,sizeof(b));memset(s,0,sizeof(s));
        memset(cnt,0,sizeof(cnt));
        for (int j=1;j<=q;j++)
         {
            int ma=0;
            for (int k=j;k<=n;k+=q)
              ma=max(ma,v[k]);
            for (int k=j;k<=n;k+=q)
             if (ma==v[k]) b[k]=true,tot++;
         }
        int now=0,st=0,it=1;
        for (int j=1;j<=n;j++)
         if (!b[j]) now=0;else
          {
             st+=now==0;
             cnt[st]++;now++;
          }
        if (b[n]&&b[1]&&st!=1) cnt[1]+=cnt[st--];
        for (int j=1;j<=st;j++) s[cnt[j]]++;
        while (i<=n&&li[i].fr==q)
         {
            while (it<li[i].sc)
              tot-=s[it]*it,st-=s[it],it++;
            if (tot==n) ans+=n;else 
              ans+=tot-li[i].sc*st+st;i++;
         }
     }
 }
int main()
 {
    n=Read();
    for (int i=1;i<=n;i++) v[i]=Read();
    for (int i=1;i<n;i++)
      li[i].fr=gcd(i,n),li[i].sc=i;
    sort(li+1,li+n);
    Solve();
    cout <<ans<<endl;
    return 0;
 }