#include <bits/stdc++.h>

using namespace std;

 

typedef unsigned long long ull;

typedef long long ll;

typedef long double ld;

 

const ll mod  = 1e9+7;

const ld eps  = 1e-9 ;

const ll maxn = 1e5+1;

const ll inf  = 5e18 ;

const ll minf = -inf ;

 

#define mp make_pair

#define pb push_back

#define endl "\n"

 

bool solve()

{

    ll n,x;

    cin >> n >> x;

    vector<ll> v(n);

 

    for(ll i=0 ; i<n ; ++i) cin >> v[i];

 

    vector<ll> dup = v;

    sort(dup.begin(),dup.end());

 

    for(ll i=0 ; i<n ; ++i)

    {

        if(i-x>=0 || i+x<n) continue;

 

        if(dup[i]!=v[i]) return false;

    }

    

    return true;    

}

 

int main()

{

    ios_base :: sync_with_stdio(false);

    cin.tie(NULL);

    cout.tie(NULL);

 

    ll t=1;

    cin >> t;

 

    while(t--)

    {

        if(solve())

        {

            cout << "YES" << endl;

        }

        else

        {

            cout << "NO" << endl;

        }

    }

 

    return 0;

}