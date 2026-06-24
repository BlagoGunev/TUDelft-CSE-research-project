#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

priority_queue<ll> pq ;
vector<ll> val[200005];
int n ;
int t, cs;
int main(){

    cin>>t ;
    while( cs < t ){
        cs++;
        scanf("%d", &n);
        for(int i=1;i<=n;i++) val[i].clear();
        for(int i=1; i <= n ; i++){
            int idx ;
            ll x ;
            scanf("%d %lld",&idx,&x);
            val[++idx].push_back(x);
        }

        for(int i=1; i <= n ; i++){
            for(auto u: val[i]) pq.push(u) ;
            if( !pq.empty() ) pq.pop() ;
        }

        ll ans = 0 ;
        while(!pq.empty() ) ans += pq.top() , pq.pop() ;
        printf("%lld\n",ans);
    }
    return 0;
}