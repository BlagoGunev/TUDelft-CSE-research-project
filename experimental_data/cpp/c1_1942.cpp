#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cassert>
#include<cstdio>
#include<cctype>
#include<vector>
#include<bitset>
#include<random>
#include<ctime>
#include<queue>
#include<cmath>
#include<list>
#include<map>
#include<set>
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define pll pair<long long,long long>
#define FF fflush(stdout)
#define inf 0x3f3f3f3f
#define endl "\n"
#define fi first
#define se second
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
//char buf[1<<20],*p1,*p2;
//#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<20,stdin),p1==p2)?EOF:*p1++)
inline int read()
{
    int s=0,f=1;
    char x=getchar();
    while(!isdigit(x))f=(x=='-'?-1:1),x=getchar();
    while(isdigit(x))s=s*10+x-'0',x=getchar();
    return s*f;
}
const int p=1e9+7;
//ll ksm(int a,int b){ll ans=1,bs=a;while(b){if(b&1)ans=ans*bs%p;bs=bs*bs%p;b>>=1;}return ans;}
mt19937 rd(time(0));
#define reaD read
int a[200005];
int main()
{
    int T=reaD();
    while(T--)
    {
        int n=reaD(),k=reaD(),y=read();
        for(int i=1;i<=k;i++)
        a[i]=reaD();
        sort(a+1,a+k+1);
        int ans=k-2;
        for(int i=1;i<k;i++)
        {
            if(a[i+1]==a[i]+2)ans++;
        }
        if(n+a[1]==a[k]+2)ans++;
        printf("%d\n",ans);
    }
    system("pause");
    return 0;
}