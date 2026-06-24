//菜菜菜菜菜菜菜菜菜菜菜菜菜菜菜菜菜菜菜菜菜菜菜菜菜菜菜菜菜菜

#include<bits/stdc++.h>



using namespace std;

#define endl "\n"

#define pb push_back

#define eb emplace_back

using ll = long long;

//constexpr int inf=0x7fffffff;

constexpr int inf = 0x3f3f3f3f;

constexpr int P = 1e9+7;

auto seed = chrono::system_clock::now().time_since_epoch().count();

mt19937 rnd(seed);



template<typename T>

T rd(T l, T r) { return uniform_int_distribution<T>(l, r)(rnd); }



int n;

ll powmod(ll a,ll b){

	ll res=1;

	while(b){

		if(b&1) res=res*a%P;

		a=a*a%P;

		b>>=1;

	}

	return res;	

}



void solve() {

    ll n,m,k,r,c;

    ll ax,ay,bx,by;

    cin>>n>>m>>k>>r>>c;

    cin>>ax>>ay>>bx>>by;

    ll ans;

    if(ax==bx&&ay==by){

    	ans=n*m;

    }else{

    	ans=n*m-r*c;

    }

    cout<<powmod(k,ans)<<endl;

}



int main() {

    ios_base::sync_with_stdio(false);

    cin.tie(nullptr);

    cout.tie(nullptr);

    int _t = 1;

    while (_t--) {

        solve();

    }

    return 0;

}