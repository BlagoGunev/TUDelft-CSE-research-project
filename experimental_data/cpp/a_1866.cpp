#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
#define pdd pair<double,double>
#define pii pair<int,int>
#define pll pair<LL,LL>
#define mp make_pair
#define LL long long
#define ULL unsigned long long
#define sqr(x) ((x)*(x))
#define pi acos(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
void solve(){
    int n;
    scanf("%d",&n);
    int ans=1e5;
    for(int i = 0;i<n;i++){
        int x;
        scanf("%d",&x);
        ans=min(ans,abs(x));
    }
    printf("%d\n",ans);
}
int main(){
    int t=1;
   // scanf("%d",&t);
    for(int i = 1;i<=t;i++){
        solve();
    }
    return 0;
}