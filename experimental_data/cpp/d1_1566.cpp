#include<bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>

#include <ext/pb_ds/tree_policy.hpp>

#define orderedset tree < int, null_type, greater_equal<int>, rb_tree_tag,tree_order_statistics_node_update>

#define ll long long

#define cin(v) for(auto& i : v) cin >> i;

#define cout(v) for(auto& i : v) cout << i << " "; cout << "\n";

#define all(v) v.begin(),v.end()

#define rall(v) v.rbegin(),v.rend()

#define Ceil(n , m) ((n / m) + (n % m ? 1 : 0))

#define sz(s) (long long)(s.size())

const double eps = 1e-9; 

const ll Mod = 1e9 + 7;

using namespace std;

using namespace __gnu_pbds;

void FAST(){

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    //cout << fixed << setprecision(15);

   #ifndef ONLINE_JUDGE

    //freopen("hano.in", "r", stdin);

    //freopen("output.txt", "w", stdout);

   #endif

}

int main(){

    FAST();

    int t; cin >> t;

    while(t--){

    	int n , m; cin >> n >> m;

    	vector<int> v(m); cin(v);

    	reverse(all(v));

    	orderedset st;

    	ll res = 0;

    	for(int i = 0; i < m; i++){

    		st.insert(v[i]);

    		res += st.order_of_key(v[i]);

		}

        cout << res << "\n";

	}

   

   

    return 0;

}