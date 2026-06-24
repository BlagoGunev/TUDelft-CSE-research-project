#include <bits/stdc++.h>



#define ll long long int

#define pb push_back

#define pob pop_back

#define F first

#define S second

#define mp make_pair

#define ld long double



using namespace std;



void o (bool a){cout << (a ? "YES":"NO") << endl;}



ll n , k , a[200010];



ll po(ll x, ll y) {

    if ( y == 0 ) return 1;

    if (y == 1) return x;

    ll temp = 1;

    ll ans;

    if ( y % 2  == 1) temp = x;

    ans = po(x,y/2);

    return ans*ans*temp;

}



ll aux = po(2,30);



ll count1(){

	ll ans = 0 ;

	for ( int i = 0 ; i < n ; i ++ ){

		if ( (aux&a[i]) == 0)ans ++;

		a[i] <<= 1;

	}

	return ans ;

}



void solve(){

	cin >> n >> k ;

	for ( int i = 0 ; i < n ; i++ )cin >> a [i];

	bool q = 1;

	ll ans = 0 ,au = po(2,31); ll i = 30;

	for ( int j = 0 ; j < n ; j ++ ){

		if ( (au&a[j]) == 0 )q = 0;

	}

	ans += (q?au:0);

	while (k>=0 && i >= 0){

		ll x = count1();

		if ( x <= k ){

			k-= x;

			ans += po(2,i);

		}

		i--;

	}

	cout << ans << endl;

}



int main (){

	

    // freopen("in","r",stdin);

    // freopen("out","w",stdout);

    ios_base::sync_with_stdio(0);

    cin.tie(0);

    cout.tie(0);

    int ousfhgkjdasdfs = 1;

    cin >> ousfhgkjdasdfs;

    while (ousfhgkjdasdfs--)

    solve();

    

    return 0;

}