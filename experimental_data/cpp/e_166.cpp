#include <bits/stdc++.h>



using namespace std;

 

#define fi first

#define se second

#define mp make_pair

#define pb push_back

#define pf push_front;

#define fbo find_by_order

#define ook order_of_key

#define lb lower_bound

#define ub upper_bound

#define rep(i,n) for(int i=0;i<n;i++)

#define fori(a,b) for(int i=a;i<=b;i++)

#define mem(x,a) memset(x,a,sizeof(x))



typedef long long ll;

typedef pair<ll,ll> ii;

typedef vector<int> vi;

typedef long double ld;

typedef map<ll,ll> hash;

typedef set<ll> si;

typedef multiset<ll>::iterator sit;

typedef map<int,int>::iterator mii;

typedef vector<int>::iterator vit;

typedef vector<ii> vii;

typedef set<ii> sii;

typedef multiset<ll> msi;

const ll INF = 1e18;

const int MOD = 1e9 + 7;

const int N = 101;



	void  mul(ll a[4][4],ll b[4][4])

	{

		ll c[4][4];

		rep(i,4)

		{

			rep(j,4)

			{

				c[i][j]=0;

				rep(k,4)

				c[i][j]=(c[i][j]+((a[i][k]*b[k][j])%MOD))%MOD;

			}

		}

		rep(i,4) rep(j,4) a[i][j]=c[i][j];

	}

	void matexpo(ll a[4][4],ll b)

	{

		ll ans[4][4];

		rep(i,4)rep(j,4) 

		ans[i][j]=i==j;

		while(b)

		{

			if(b%2)

			mul(ans,a);

			mul(a,a);

			b/=2;

		}

		rep(i,4) rep(j,4)

		a[i][j]=ans[i][j];

	}

int main()

{

	ios_base::sync_with_stdio(0);

	cin.tie(0);

	cout.tie(0);

	ll n,m,x,y;

	cin>>n;

	ll dp[4][4];

	rep(i,4) rep(j,4) dp[i][j]=1;

	dp[0][0]=0;

	dp[1][1]=0;

	dp[2][2]=0;

	dp[3][3]=0;

    matexpo(dp,n);

	cout<<dp[3][3]<<"\n";

}