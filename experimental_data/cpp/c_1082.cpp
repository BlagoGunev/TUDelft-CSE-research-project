#include<bits/stdc++.h>
#define DBG(x) cerr << #x << " = " << x << endl;
const int maxn = 1e5+5;
using namespace std;
typedef long long LL;

struct node{
    int l,r;
    bool operator < (const node & a)const{
        return l != a.l ? l < a.l : r > a.r;
    }
}p[maxn];

LL cnt[maxn];

int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i = 1 ; i <= n ; i++ )scanf("%d%d",&p[i].l,&p[i].r);
    sort(p+1,p+1+n);
    int pos=1;
    LL tmp=0;
    for(int i=1;i<=n;i++){
        if(i == 1 || p[i].l != p[i - 1].l){
            pos=1;tmp=0;
            if(1LL*(tmp + p[i].r) > 0LL)cnt[pos++] += 1LL*(tmp + p[i].r);
            tmp+=p[i].r;
        }else{
            if(1LL*(tmp + p[i].r) > 0LL)cnt[pos++] += 1LL*(tmp + p[i].r);
            tmp+=p[i].r;
        }
    }
    LL ans=0;
    for(int i=1;i<=n;i++)ans=max(ans,cnt[i]);
    printf("%I64d\n",ans);
    return 0;
}