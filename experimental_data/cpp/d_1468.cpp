#include <bits/stdc++.h>



using namespace std;

#define int long long

#define double long double

#define ii pair<int, int>

#define ui uint64_t

#define nl "\n"

#define yes "YES\n"

#define no "NO\n"

#define inv vector<int> v(n);for(int i = 0; i<(n);++i){cin >> v[i];}

#define st ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)

#define fi first

#define si second

#define tsolve() int t; cin >> t;while(t--){solve();}

#define print(b) if(b){cout << "YES\n";}else {cout << "NO\n";}



int mo = 1020202009;





void solve() {

    int n,m,a,b;

    cin >> n >> m >> a >> b;

    vector<int> v(m);

    for (int i = 0; i < m; ++i) {

        cin >> v[i];

    }

    std::sort(v.begin(), v.end());

    int pos = 0;

    int dist = a<b ? a-1 : n-a;

    for (int i = 0; i < m; ++i) {

        if(i-pos+v[pos]<=v[i]){

            pos = i;

        }

        if(i-pos+v[pos]>=abs(b-a)+dist){

            cout << min(i, abs(a-b)-1) << nl;

            return;

        }

    }

    cout << min(m, abs(a-b)-1)  << nl;

}



int32_t main() {

    st;

    tsolve();

}