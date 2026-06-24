#include <bits/stdc++.h>

using namespace std;



#define MOD 1000000007

#define pb push_back

#define mp make_pair

#define all(c) (c).begin(),(c).end()

#define sz(a) int((a).size())

#define F first

#define S second



#define rep(i, a, b) for(int i = a; i < b; ++i)

#define per(i, a, b) for(int i = a; i >= b; --i)

#define travel(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)

#define INDEX(arr,ind)			(lower_bound(all(arr),ind)-arr.begin())



typedef long long ll;

typedef long double ld;

typedef vector<int> vi;

typedef pair<int,int> pii;

typedef pair<ll,int> pli;

typedef pair<ll,ll> pll;

typedef pair<int, pii> piii;

typedef pair<ll, pll> plll;

typedef vector<pii> vpii;

typedef vector<piii> vpiii;



inline ll powmod(ll x, ll n, ll _mod){ 

  ll res = 1; 

  while (n){

    if (n & 1)res = (res*x) % _mod; 

    x = (x*x) % _mod; 

    n >>= 1;

    }

    return res; 

  }





#define N 30001

int n,m;

int v[1002];



int main(){

ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);



// freopen("in.txt","r",stdin);

// freopen("o.txt","w",stdout);



int ans=0;

cin>>n>>m;

rep(i,0,n)cin>>v[i];

rep(i,0,m){

	int x,y;

	cin>>x>>y;

	x--,y--;

	ans+=min(v[x],v[y]);

}

cout<<ans<<'\n';

return 0;

}