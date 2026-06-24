#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace chrono;
using namespace __gnu_pbds;

#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
typedef long long int ll;
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define all(x) (x).begin(), (x).end()
#define endl "\n"

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif
const int M = 1e9 + 7;
ll bin(ll a, ll b)
{
    ll ans = 1;
    while (b)
    {
        if (b & 1)
            ans = ans * a % M;
        a = a * a % M;
        b >>= 1;
    }
    return ans;
}

int __lcm(int a, int b)
{
    return a * b / __gcd(a, b);
}

void solve(){
    int n;
    scanf("%d", &n);
    vector<int> a(n), b(n);
    for(auto &it : a) scanf("%d", &it);
    for(auto &it : b) scanf("%d", &it);
    int l = -1, r = -1;
    for(int i=0; i<n; i++){
        if(a[i] != b[i]  &&  l == -1){
            l = i;
        }
        if(a[i] != b[i]){
            r = i;
        }
    }
    while(l > 0  &&  b[l-1] <= b[l]){
        l--;
    }
    while(r < n-1  &&  b[r] <= b[r+1]){
        r++;
    }
    printf("%d %d\n",l+1, r+1);
}
int main()
{
#ifdef LOCAL
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    auto start_time = clock();
#endif
    // fastio();

    int t;
    scanf("%d", &t);
    while(t--){
        solve();
    }

#ifdef LOCAL
    auto end_time = clock();
    cerr << "Execution time: " << (end_time - start_time) * (int)1e3 / CLOCKS_PER_SEC << " ms\n";
#endif
    return 0;
}