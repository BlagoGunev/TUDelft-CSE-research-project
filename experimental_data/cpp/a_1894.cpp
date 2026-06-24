#include <bits/stdc++.h>
#define FAST {ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define FILES {freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);}
#define ll long long
#define ull unsigned long long
#define pqueue priority_queue
#define pb push_back
#define fi first
#define se second
#define ld long double
#define pii pair<int,int>
#define pll pair<long long,long long>
#define all(a) (a).begin(), (a).end()
#define mp make_pair 
using namespace std;
/*
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pll, null_type,less<pll>, rb_tree_tag,tree_order_statistics_node_update>
*/
// order_of_key -> # less than k
// find_by_order -> k-th element
// pq max element                                          

void files() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
}

void maxx(ll &a, ll b) {
    a = max(a,b);
}

void minn(ll &a, ll b) {
    a = min(a,b);
}

const double eps = 0.00000001;
const int NMAX = 3030;
const ll inf = LLONG_MAX/10;
const ll modi = 998244353;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    cout << s.back() << endl;
}

int main () {
    FAST
    files();

    int t=1;

    //*
    cin >> t;
    //*/
 
    int i = 1;
    while(t--) {
        // cout << "Case #" << i++ << ": " ;
        solve();
    }
}