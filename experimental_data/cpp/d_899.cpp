# include<bits/stdc++.h>
using namespace std;
# define lowbit(x) ((x)&(-x))
# define pi acos(-1.0)
# define eps 1e-8
# define MOD 100000007
# define INF 100000000
# define mem(a,b) memset(a,b,sizeof(a))
# define FOR(i,a,n) for(register int i=a; i<=n; ++i)
# define FDR(i,a,n) for(register int i=a; i>=n; --i)
# define bug puts("H");
# define lch p<<1,l,mid
# define rch p<<1|1,mid+1,r
# define mp make_pair
# define pb push_back
typedef pair<int,int> PII;
typedef vector<int> VI;
# pragma comment(linker, "/STACK:1024000000,1024000000")
typedef long long LL;
inline char nc(){
    static char buf[1000000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;
}
inline int Scan(){
    char ch=nc();int sum=0, f=1;
    if (ch=='-') f=-1, ch=nc();
    while(!(ch>='0'&&ch<='9'))ch=nc();
    while(ch>='0'&&ch<='9')sum=sum*10+ch-48,ch=nc();
    return sum*f;
}
const int N=60005;

LL po[15];

int main ()
{
    int n;
    scanf("%d",&n);
    po[0]=1; FOR(i,1,10) po[i]=po[i-1]*10;
    if (n<=4) {printf("%d\n",n*(n-1)/2); return 0;}
    LL x=9, tmp, num=1;
    while (1) {
        tmp=x*10+9;
        if (tmp/2+1<=n) x=tmp, ++num;
        else break;
    }
    LL ans=0;
    FOR(i,0,8) {
        LL y=(LL)i*po[num]+x;
        if (y/2+1<=n) ans+=min(y/2,n-y/2);
    }
    printf("%lld\n",ans);
    return 0;
}