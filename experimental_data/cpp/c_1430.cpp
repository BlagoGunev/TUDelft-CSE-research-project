#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>

#include <ext/pb_ds/tree_policy.hpp>

#define ll long long

#define pb push_backj

#define ss second

#define ff first

#define vll vector < ll >

#define all(a)(a).begin(), (a).end()

#define f(i, n) for (ll i = 0; i < n; i++)

#define setbit(x) __builtin_popcount(x)

#define mod 1000000007

using namespace std;

using namespace __gnu_pbds;

template < typename T > using o_set = tree < T, null_type, less_equal < T > , rb_tree_tag, tree_order_statistics_node_update > ;

/*

n=5

1 2 3 4 5

1 2 4 4

1 2 4

1 3

2

1 2 3 4 5 6

1 2 3 5 5

1 2 3 5

1 2 4

1 3

2

1 2 3 4 5 6 7

1 2 3 4 6 6

1 2 3 4 6

1 2 3 5

1 2 4

1 3

2

1 2 3 4 5 6 7 8 

1 2 3 4 5 7 7

1 2 3 4 5 7

1 2 3 4 6

1 2 3 5

1 2 4

1 3

2

*/

void solve(){

      ll n;cin>>n;

   long long z=n-3;

		if (z>0){

			cout<<2<<"\n";

			cout<<n<<" "<<n-2<<"\n";

			cout<<n-1<<" "<<n-1<<"\n";

			for (long long u=z;u>0;u--){

				cout<<u+2<<" "<<u<<"\n";

			}

		}

		if (z==0){

			cout<<2<<"\n";

			cout<<n<<" "<<n-2<<"\n";

			cout<<n-1<<" "<<n-1<<"\n";

		}

		if (z==-1){

			cout<<2<<"\n"<<1<<" "<<2<<"\n";

		}

}

int main() {

    ios_base::sync_with_stdio(false);

    cin.tie(NULL);



     ll t;cin >> t;

      while (t--) {

    solve();

    // cout<<fixed<<setprecision(10);

   }

}