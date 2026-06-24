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

	ll n; cin>>n;

	vector <ll> a(n);

	fl(i,0,n){

		cin>>a[i];

	}

	ll mn = *min_element(a.begin(), a.end()), mx = *max_element(a.begin(), a.end());

	if (mn==mx){

		cout<<1<<'\n';

		fl(i,0,n){

			cout<<1<<' ';

		}

		cout<<'\n';

		return;

	} else if (n%2==0){

		cout<<"2\n";

		fl(i,0,n){

			cout<<(i%2==0 ? 2 : 1)<<' ';

		}

		cout<<'\n';

		return;

	}

	a.push_back(a[0]);

	ll co = 0;

	vector <ll> val(n+1);

	ll cur = 1, don = 1;

	fl(i,1,n+1){

		if (a[i]==a[i-1]){

			if (don==0){

			} else {

				don--;

			}

		} else {

		}

	}

	if (don == 0){

		don = 1;

		val[0]=1;

		cur=1;

		fl(i,0,n){

			if (a[i+1]==a[i] && don==1){

				val[i]=val[i+1]=cur;

				cur=(cur==1?2:1);

				i++;

				don--;

			} else {

				val[i] = cur;

				cur=(cur==1?2:1);

			}

		}

		if (val[n]!=0){

			val[0]=val[n];

		}

	} else {

		fl(i,0,n){

			val[i] = cur;

			cur = (cur==1?2:1);

		}

		val[0]=3;

	}

	cout<<*max_element(val.begin(), val.end())<<'\n';

	fl(i,0,n){

		cout<<val[i]<<' ';

	}

	cout<<'\n';

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