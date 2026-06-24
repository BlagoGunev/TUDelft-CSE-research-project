#include <cstring>
#include<stdio.h>
#include <cstdlib>
#include <cctype>
#include <algorithm>
#include <map>
#include <vector>
#include <list>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <string>
#include <cmath>
using namespace std;
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define REP(i,n) FOR(i,0,n)
#define pb push_back
#define ITER(i,a) for( typeof(a.begin()) i=a.begin();i!=a.end();i++)
#define mod 1000000007
#define MAXN 1000010
#define get getchar//_unlocked
inline int inp()
{
    int n=0,s=1;
    char p=get();
    if(p=='-')
    s=-1;
    while((p<'0'||p>'9')&&p!=EOF)
    p=get();
    while(p>='0'&&p<='9')
    {
    n = (n<< 3) + (n<< 1) + (p - '0');
    p=get();
    };
    return n*s;
}
long long power(long long a,long long b)
{
    long long r=1,x=a;
    while(b)
    {
        if(b&1)r=(r*x)%mod;
        x=(x*x)%mod;
        b>>=1;
    }
    return r;
}
vector<int> a,b;
int main()
{
    int i,n,j,k,l,m,t,ans,min,max;
    char ch;
    n=inp();min=mod;max=-1;i=0;
    m=n;
    while(n--)
    {
        i++;
        k=inp();l=inp();
        a.pb(k);b.pb(l);
       if(k<min)
       min=k;
       if(l>max)
       max=l;
    }
    for(i=0;i<m;i++)
    {
        if(a[i]==min&&b[i]==max)
        {printf("%d\n",i+1);break;}
    }

    if(i==m)printf("-1\n");
    return 0;
}