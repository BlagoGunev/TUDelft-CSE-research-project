#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;

ll ar[100005],br[100005];
int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    ll t;
    cin>>t;
    while(t--)
    {
        ll n; cin>>n;
        for(ll i=0;i<n;i++) cin>>ar[i];
        ll k=max_element(ar,ar+n)-ar;

        priority_queue<pll>pq;
        for(ll i=k%2;i<n;i+=2) pq.push({-ar[i],i});
        ll cnt=n;
        while(!pq.empty())
        {
            pll p=pq.top(); pq.pop();
            br[p.se]=cnt--;
        }
        for(ll i=!(k%2);i<n;i+=2) pq.push({-ar[i],i});
        cnt=n/2;
        while(!pq.empty())
        {
            pll p=pq.top(); pq.pop();
            br[p.se]=cnt--;
        }
        for(ll i=0;i<n;i++) cout<<br[i]<<' ';
        cout<<'\n';
    }

    return 0;
}