#include <bits/stdc++.h>
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define bit(n) (1LL << (n))
#define getbit(x, i) (((x) >> (i)) & 1)
#define pii pair<int, int>
#define ALL(x) x.begin(), x.end()
using namespace std;
const int M = 5e5 + 5;
const int N = 2e5 + 5;
const int mod = 1e9 + 7;
const int oo = 1e9;
const long long ooo = 1e18;
const double pi = acos(-1);

template<typename T1, typename T2> bool mini(T1 &a, T2 b) {if(a > b) a = b; else return 0; return 1;}
template<typename T1, typename T2> bool maxi(T1 &a, T2 b) {if(a < b) a = b; else return 0; return 1;}

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("file.inp", "r",stdin);
    #endif
    int t; cin >> t;
    while (t--) {
        int n;
        cin >> n;
        if (n & 1) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            for (int i = 1; i <= n / 2; i++) {
                if (i & 1) {
                    cout << "AA";
                } else {
                    cout << "BB";
                }
            }
            cout << "\n";
        }
    }
    return 0;
}