#include "bits/stdc++.h"
#define hhh cerr<<"hhh"<<endl
#define see(x) cerr<<(#x)<<'='<<(x)<<endl
using namespace std;
typedef long long ll;
typedef pair<int,int> pr;
inline int read() {int x=0,f=1;char c=getchar();while(c!='-'&&(c<'0'||c>'9'))c=getchar();if(c=='-')f=-1,c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return f*x;}

const int maxn = 3e5+7;
const int mod = 998244353;
const int inf = 0x3f3f3f3f;

int n, k;
int p[maxn];

int main() {
    n=read(), k=read();
    printf("%lld ", ll(k)*(n+n-k+1)/2);
    ll last=0, res=1;
    for(int i=1; i<=n; ++i) {
        p[i]=read();
        if(p[i]>=n-k+1) {
            if(last) res=res*(i-last)%mod;
            last=i;
        }
    }
    printf("%lld\n", res);
}