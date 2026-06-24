#include <bits/stdc++.h>
using namespace std;
typedef long long lolo;
typedef pair<int,int> pii;
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define IFOR(i,b,a) for(int i=(b);i>=(a);i--)

const int maxn=100005;
const int INF=0x3f3f3f3f;
const lolo inf=0x3f3f3f3f3f3f3f3f;
template <class T>
void read(T& x) {
    x=(T)0;
    char c=getchar();
    while(c<'0'||c>'9') c=getchar();
    do {
        x=(T)(x*10+c-'0');
        c=getchar();
    }while(c>='0'&&c<='9');
}
int a,bm1,bm2,b;
int main() {
//    freopen("../in.txt","r",stdin);
    int n;
    read(n);
    lolo sum=0;
    FOR(i,1,n) {
        read(a);
        sum+=a;
    }
    bm1=bm2=-1;
    FOR(i,1,n) {
        read(b);
        if(b>bm1) {
            bm2=bm1;
            bm1=b;
        } else if(b==bm1) {
            bm2=b;
        } else if(b>bm2) {
            bm2=b;
        }
    }
    if(n==2||sum<=1LL*bm1+bm2) puts("YES");
    else puts("NO");
    return 0;
}