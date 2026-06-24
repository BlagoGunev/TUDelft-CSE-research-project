#include<bits/stdc++.h>
#define lowbit(x) ((x)&-(x))
using namespace std;
mt19937_64 myrand(407223);
using LL=long long;
using uint=unsigned;
using pii=pair<int,int>;
using vi=vector<int>;
using vp=vector<pii>;
template<typename T>inline void read(T&t){
    t=0;
    char c=getchar();
    int f=1;
    while (!isdigit(c)) f=c=='-'?-f:f,c=getchar();
    while (isdigit(c)) t=(t<<3)+(t<<1)+c-'0',c=getchar();
    t*=f;
    return;
}
template<typename T,typename...Args>inline void read(T&t,Args&...args){read(t),read(args...);}
template<typename T>void write(T x){if(x>=10)write(x/10);putchar(x%10+'0');return;}

const int N=200005;
int n,b,x,a[N];
LL pre[N];
inline void solve() {
    read(n,b,x);
    x<<=1;
    int sum=0;
    LL S=0;
    for (int i=1;i<=n;i++) read(a[i]),sum+=a[i],S+=1ll*b*a[i]*a[i];
    sort(a+1,a+n+1);
    for (int i=1;i<=n;i++) pre[i]=pre[i-1]+a[i];
    int st=1;
    LL minn=1e18;
    for (int i=1;i<=sum;i++) {
        LL res=1ll*(i-1)*x;
        res+=b*pre[st-1];
        for (int j=st;j<=n;j++) {
            LL a1=a[j]/i+1,b1=a[j]%i;
            LL a2=a[j]/i,b2=i-b1;
            res+=1ll*b*(a1*a1*b1+a2*a2*b2);
            if (a[j]==i) st=j+1;
        }
        minn=min(minn,res);
        // printf("*%d %lld\n",i,res);
    }
    printf("%lld\n",(S-minn)/2);
}

int main() {
    int T=1;
    read(T);
    while (T--) solve();
    return 0;
}

/*


1
10 2


*/