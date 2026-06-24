#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=3e5+5;
int a[maxn],b[maxn];
inline int read()
{
    ll x=0,w=0;
    char ch=0;
    while (!isdigit(ch))
    {w|=ch=='-';ch=getchar();}
    while (isdigit(ch))
        x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return w?-x:x;
}
int main()
{
    int t;
    t=read();
    while(t--){
        int n;
        n=read();
        for (int i = 1; i <= n; ++i)b[i]=0;
        int s=0;
        for (int i = 1; i <= n; ++i) {
            a[i]=read();
        }
        b[a[n]]--;
        for(int i=2;i<=n;i++){
            if(a[i]!=a[i-1]) b[a[i]]++;
        }
        int ans=b[a[1]];
        for (int i = 2; i <= n; ++i) {
            ans=min(ans,b[a[i]]);
        }
        printf("%d\n",ans+1);
    }
    return 0;
}