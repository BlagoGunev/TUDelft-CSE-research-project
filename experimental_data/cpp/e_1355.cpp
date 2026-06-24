//IUOTL                 //ITS NOT OVER UNTIL I WIN

#include <bits/stdc++.h>

using namespace std; 



#define fi first

#define sc second

#define pb push_back

typedef long long ll;

const int amod= 998244353;

const int mod=1e9+7;



ll gcd(ll a,ll b){if(b>a){return gcd(b, a);} if(b==0){return a;} return gcd(b, a % b);}

ll power(ll a,ll b,ll mod=1e9+7){ll res=1;while(b>0){if(b&1)res=(1LL*res*a)%mod;a=(1LL*a*a)%mod;b=b>>1;} return res;}

ll n,a,r,m;

vector<ll>h;

ll ans;

ll bs(ll k){

    ll up=0,down=0;

    for(int i=0;i<n;i++){

        if(h[i]>k)up+=h[i]-k;

        else down+=k-h[i];

    }

    ll res=up*r+down*a;

    ll mi=min(up,down);

    res=min(res,res-mi*a-mi*r+mi*m);

    return res;

}

void item(){

    cin>>n>>a>>r>>m;

    h.resize(n);

    ans=1e18;

    for(auto &i:h)cin>>i;

    int l=1,rr=1e9;

    while(rr-l>3){

        int mid=(l+rr)/2;

        if(bs(mid)<bs(mid+1))rr=mid+1;

        else l=mid;

    }

    for(int i=l;i<=rr;i++){

        ans=min(ans,bs(i));

    }

    cout<<ans<<'\n';

}



int main()

{

    ios_base::sync_with_stdio(false);

    cin.tie(NULL);

    cout.tie(NULL);

    int tc=1;

    // cin>>tc;

    for(int T=1;T<=tc;T++){

        item();

    }

    return 0;

}