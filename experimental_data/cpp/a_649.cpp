#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define all(a) (a).begin(), (a).end()
#define lup(i,j,n) for(int i = j; i < n; ++i)
#define lupr(i,j,n) for(int i = j; i >= n; --i)
#define endl '\n'
#define vi vector<int>
#define vpi vector<pair<int,int> >
#define vvi vector<vector<int> >
#define pii pair<int, int>
#define MP make_pair
#define F first
#define S second
#define bitcount(x) __builtin_popcount(x)
#define INF 1e9
#define MOD 1000000007
#define MAXN ((int)2e5 + 4)

void solve() {
    int n;
    cin >> n;
    
    vi freq(31, 0);
    lup(i, 0, n) {
        int x;
        cin >> x;
        lupr(j, 30, 0) {
            if(x % (1 << j) == 0) {
                ++freq[j];
                break;
            }
        }
    }

    lupr(i, 30, 0) {
        if(freq[i]) {
            cout << (1 << i) << ' ' << freq[i] << endl;
            return;
        }
    }
}   

signed main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(0); 
    cout.tie(0);
    
    int _t = 1;
    // cin >> _t;
    while(_t--) {
        solve();
    }
}