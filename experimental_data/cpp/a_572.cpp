#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <cstring>
#include <string>
#include <cmath>
#include <set>
#include <ctime>

using namespace std;

#define rep(i,l,r) for(i=l;i<=r;i++)
#define ser(i,r,l) for(i=r;i>=l;i--)
#define INF 1000005
#define inf 1000000007
typedef long long ll;
int n,m,Q,t;
int a[INF],b[INF];
int read()
{
    int k=0,f=1;
    char ch;
    while(ch<'0' || ch>'9'){
      if(ch=='-')f=-1;
      ch=getchar();
    }
    while(ch>='0' && ch<='9')k=k*10+ch-'0',ch=getchar();
    return k*f;
}
void init()
{
    int i,j,k;
    n=read(),m=read();
    Q=read(),t=read();
    rep(i,1,n)a[i]=read();
    sort(a+1,a+n+1);
    rep(i,1,m)b[i]=read();
    sort(b+1,b+m+1);
    if(a[Q]<b[m-t+1]){
        printf("YES\n");
    }
    else {
        printf("NO\n");
    }
}
void work()
{
    int i,j,k;
}
int main()
{
    init();
    work();
    return 0;
}