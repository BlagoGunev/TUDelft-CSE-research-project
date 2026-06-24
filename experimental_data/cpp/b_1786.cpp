/*

 * 

 * 	^v^

 * 

 */

#include <iostream>

#include <string>

#include <cmath>

#include <vector>

#include <iomanip>

#include <map>

#include <functional>

#include <algorithm>

#include <set>

#include <queue>

#include <climits>

#include <cstdlib>

#include <chrono>

// #include <ext/pb_ds/assoc_container.hpp>

// #include <ext/pb_ds/tree_policy.hpp>

// using namespace __gnu_pbds;

using namespace std;

// #define ordered_set tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>

#define iamtefu ios_base::sync_with_stdio(false); cin.tie(0);

#define ll long long int

#define ld long double

#define fl(i,a,n) for (ll i(a); i<n; i++)

#define rfl(i,a,n) for (ll i(n-1); i>=a; i--)

#define print(a) for (auto x:a){cout<<x<<" ";} cout<<"\n";

#define tt int tt; cin>>tt; for(;tt--;)

ll gcd(ll a, ll b){

	if (b==0){

		return a;

	}

	return gcd(b, a%b);

}

ll pw(ll a, ll b, ll m){

	ll res=1;

	a%=m;

	while (b){

		if (b&1){

			res=(res*a)%m;

		}

		a=(a*a)%m;

		b>>=1;

	}

	return res;

}

void scn(){

	ll n, w, h; cin>>n>>w>>h;

	vector <ll> wi(n), hi(n);

	fl(i,0,n){

		cin>>wi[i];

	}

	fl(i,0,n){

		cin>>hi[i];

	}

	ll don=0;

	if (w<h){

		don++;

	}

	fl(i,1,n){

		wi[i]+=(hi[0]-h)-(wi[0]-w);

	}

	wi[0]+=(hi[0]-h)-(wi[0]-w);

	ll yo = wi[0]-w-hi[0]+h, yom = wi[0]+w-(hi[0]+h);

	fl(i,0,n){

		yo = max(yo, wi[i]-w-hi[i]+h);

		yom = min(yom, wi[i]+w-(hi[i]+h));

		if (yo>yom){

			break;

		}

	}

	if (yo>yom || don){

		cout<<"No\n";

	} else {

		cout<<"Yes\n";

	}

}

int main(){

	iamtefu;

#if defined(airths)

	auto t1=chrono::high_resolution_clock::now();

	freopen("input.txt", "r", stdin);

	freopen("output.txt", "w", stdout);

#else

	//

#endif

	tt

	{

		scn();

	}

#if defined(airths)

	auto t2=chrono::high_resolution_clock::now();

	ld ti=chrono::duration_cast<chrono::nanoseconds>(t2-t1).count();

	ti*=1e-6;

	cerr<<"Time: "<<setprecision(12)<<ti;

	cerr<<"ms\n";

#endif

	return 0;

}