/*..............................................................................................................................

 

							MOSTAFA ALKHDER

 

...............................................................................................................................*/







#include<bits/stdc++.h>

#define ll long long

#define fr(i,a,n)             for (ll i=a;i<=n;i++)

#define frr(i,a,n)             for (ll i=n;i>=a;i--)

#define TEST int t; cin>>t;while(t--)

#define MOSTAFA ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#define endl  "\n"

#define NO cout <<"NO\n";

#define YES cout << "YES\n";

#define F first

#define S second

#define all(v) v.begin(),v.end()

#define pb push_back

#define MAX(a,b,c) max(a,max(b,c))

#define MIN(a,b,c) min(a,min(b,c))

#define sz(a) int((a).size())

#define prl(x) cout << x << endl

#define prl2(x,y) cout << x << " " << y << endl

#define prl3(x,y,z) cout << x << " " << y  << " " << z << endl

#define prld(x, y) cout << fixed << setprecision(y) << x << endl

#define pr(x) cout << x

#define longint int64_t

#define ARR(arr , n)     ll n;   cin >> n;  ll arr[n];  fr(i,0,n-1) cin >> arr[i];

const ll Inf = 1e18;

const double pi = 3.141592653;

ll M = 998244353;

ll mod(ll x) {

	return ((x % M + M) % M);

}

ll mul(ll a, ll b) {

	return mod(mod(a) * mod(b));

}

ll add(ll a, ll b) {

	return mod(mod(a) + mod(b));

}

ll dec(ll a, ll b) {

	return mod(mod(a) - mod(b));

}

const int N = 2e5 + 9;

using namespace std;

 

int main() {

    MOSTAFA

    ll n;   cin >> n;

    ll sum = 0 , count;

    map<ll , ll> mp;

    fr(i,0,n-1){

        ll x;

        cin>>x;

        sum+=x;

        if(mp[sum] || !sum){

            mp.clear();

            mp[x]++;

            count++;

            sum = x;

        }else{

            mp[sum]++;

        }

    }

    cout << count;

}



/*..............................................................................................................................

 

					    		   THE END

 

...............................................................................................................................*/