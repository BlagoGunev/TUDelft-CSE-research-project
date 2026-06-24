//Optimize
#pragma GCC optimize("Ofast")

//Head File
#include<bits/stdc++.h>
using namespace std;

#define il inline

//Variable
#define ll long long
#define ull unsigned long long
#define db double
#define lb long double

//Debug
#define B cerr<<"Break Point"<<endl;
#define P(x) cerr<<#x<<' '<<"="<<' '<<(x)<<endl;
#define p(x) cerr<<#x<<' '<<"="<<' '<<(x)<<' ';
#define ml(x) cerr<<"Size of array is "<<x*4/1024/1024<<" MB"<<endl;

//Vector
#define vc vector
#define pub push_back
#define pob pop_back
#define vbe(x) x.begin(),x.end()

//Memset
#define ms(x) memset(x,0,sizeof(x))
#define MS(x) memset(x,0x3f3f3f3f,sizeof(x))

//Pair
#define fi first
#define se second

//File

#define fin(x) freopen(x,"r",stdin)
#define fou(x) freopen(x,"w",stdout)
void fio()
{
    #ifndef ONLINE_JUDGE
    freopen("sample.in","r",stdin);
    freopen("sample.out","w",stdout);
    #endif
}
void pti()
{
    double timeuse = clock()*1000.0/CLOCKS_PER_SEC;
    cerr<<"Timeuse "<<timeuse<<"ms"<<endl;
}
void end()
{
    pti();
    exit(0);
}

//Inf
#define INF 0x3f3f3f3f
#define LINF ((long long)(0x3f3f3f3f3f3f3f3f))

//IO
namespace io
{
	const int SIZ=55;int que[SIZ],op,qr;char ch;
	template<class I>
	il void gi(I &w)
    {
        ch=getchar(),op=1,w=0;while(!isdigit(ch)){if(ch=='-') op=-1;ch=getchar();}
        while(isdigit(ch)){w=w*10+ch-'0';ch=getchar();}w*=op;
    }
	template<class I>
	il void print(I w)
    {
        qr=0;if(!w) putchar('0');if(w<0) putchar('-'),w=-w;while(w) que[++qr]=w%10+'0',w/=10;
        while(qr) putchar(que[qr--]);
    }
}
using io::gi;
using io::print;

const int N=2e5+5;

int T,n,m,k;
int a[N];

bool check(int p)
{
    int res=m;
    for(int i=p;i>=1;i-=2)
    {
        if(res>=a[i]) res-=a[i];
        else return false;
    }
    return true;
}
int main()
{
    fio();
    gi(T);
    while(T--)
    {
        gi(n),gi(m),gi(k);
        for(int i=1;i<=n;++i) gi(a[i]);
        sort(a+1,a+n+1);
        int l=0,r=n,ans;
        while(l<=r)
        {
            int mid=(l+r)>>1;
            if(check(mid)) ans=mid,l=mid+1;
            else r=mid-1;
        }
        print(ans),putchar(10);
    }
    end();
}