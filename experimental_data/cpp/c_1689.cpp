#include<bits/stdc++.h>

using namespace std;



#define pb push_back

#define p push

#define fi first

#define se second

#define mk make_pair

#define endl "\n"

#define enld "\n"



#define For(i, n, m) for(ll (i)=(m);(i)<(n);++(i))

#define rep(i, n) For(i,n,0)



#define  LCM(a,b)    a*b/__gcd(a,b)

#define  GCD(a,b)    __gcd(a,b)



#define sz 1000

#define limit 10000000

#define mod 1000000007

#define inf 100000000000000ll



typedef long long int ll;

typedef pair<int, int>  pi;

typedef pair<ll, ll>  pl;

ll root =0;

ll minInfec(ll pa, ll cur,vector<vector<ll>> &adj,vector<ll> &deg)

{

    if(cur==root) 

    {

    	if(deg[cur]==1) return 2;

    }

    else if(deg[cur]<=2) return deg[cur];

    ll _minInfec=inf;

    for(ll child : adj[cur])

    {

    	if(pa!=child)

    	{

    		_minInfec=min(minInfec(cur, child, adj,deg), _minInfec);

    	}

    }

    return _minInfec+2;

}

int main()

{

    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	int t;

	cin>>t;

	while(t--)

	{

        ll n;

        cin>>n;

        vector< vector<ll>> adj(n);

        vector<ll> deg(n);

        for(int i=0;i<n-1;i++)

        {

            int u,v;

            cin>>u>>v;

            u--;v--;

            deg[u]++;

            deg[v]++;

            adj[u].push_back(v);

            adj[v].push_back(u);

        }

        cout<<n-minInfec(0,0,adj,deg)<<endl;		

	}

}