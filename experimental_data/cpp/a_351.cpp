#include <bits/stdc++.h>
#define mem(a,b) memset(a,b,sizeof(a))
#define rep(i,a,b) for(int i=a;i<b;i++)
#define debug(a) printf("a =: %d\n",a);
const int INF=0x3f3f3f3f;
const int maxn=2e3+50;
const int Mod=1e9+7;
const double PI=acos(-1);
typedef long long ll;
using namespace std;


int s[maxn*2];
int n;
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
    #endif

    while(~scanf("%d",&n)){
        int tmp,zer=0;
        for (int i=0;i<2*n;i++){
            scanf("%d.%d",&tmp,&s[i]);
            if (s[i]==0) zer++;
        }
        int sum=0;
        for(int i=0;i<2*n;i++) sum+=s[i];
        int ans=INF;
        int l=max(0,zer-n),r=min(n,zer);
        for(int i=l;i<=r;i++){
            ans=min(ans,abs(sum-(n-i)*1000));
        }
        printf("%.3lf\n",(double)ans/1000);
    }
    return 0;
}