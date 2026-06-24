#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define f first
#define s second

mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

const int facN = 1e6 + 5;
const int mod = 1e9 + 7; // 998244353
int ff[facN], iff[facN];
bool facinit = false;

int power(int x, int y){
	if (y == 0) return 1;

	int v = power(x, y / 2);
	v = 1LL * v * v % mod;

	if (y & 1) return 1LL * v * x % mod;
	else return v;
}

void factorialinit(){
	facinit = true;
	ff[0] = iff[0] = 1;

	for (int i = 1; i < facN; i++){
		ff[i] = 1LL * ff[i - 1] * i % mod;
	}

	iff[facN - 1] = power(ff[facN - 1], mod - 2);
	for (int i = facN - 2; i >= 1; i--){
		iff[i] = 1LL * iff[i + 1] * (i + 1) % mod;
	}
}

int C(int n, int r){
	if (!facinit) factorialinit();

	if (n == r) return 1;

	if (r < 0 || r > n) return 0;
	return 1LL * ff[n] * iff[r] % mod * iff[n - r] % mod;
}

int P(int n, int r){
	if (!facinit) factorialinit();

	assert(0 <= r && r <= n);
	return 1LL * ff[n] * iff[n - r] % mod;
}

int Solutions(int n, int r){
	//solutions to x1 + ... + xn = r 
	//xi >= 0

	return C(n + r - 1, n - 1);
}

void Solve() 
{
    int n, m1, m2; cin >> n >> m1 >> m2;

    vector <int> a(m1);
    vector <int> b(m2);
    for (auto &x : a) cin >> x;
    for (auto &x : b) cin >> x;

    if (a[0] != 1 || b.back() != n || a.back() != b[0]){
    	cout << 0 << "\n";
    	return;
    }
    
    vector <int> c(n + 1, 0);
    for (auto x : a) c[x] += 1;
    for (auto x : b) c[x] += 2;

    // int ans = ff[n];
    // for (int i = 1; i < m1; i++){
    // 	ans *= iff[a[i] - a[i - 1]];
    // 	ans %= mod;
    // }

    // for (int i = 1; i < m2; i++){
    // 	ans *= iff[b[i] - b[i - 1]];
    // 	ans %= mod;
    // }
    
    // cout << ans << "\n";

    // int sz = m1 + m2 - 1;
    // ans *= power(sz, mod - 2); ans %= mod;
    // ans *= iff[m1 - 1]; ans %= mod;
    // ans *= iff[m2 - 1]; ans %= mod;

    // cout << ans << "\n";
    
    int ways = a.back() - 1;
    int ans = C(n - 1, ways);
   // cout << ans << "\n";
    for (int i = a.back() - 1; i >= 1; i--){
        if (c[i] != 1){
       //     cout << i << " " << ways << "\n";
            ans *= ways - 1;
            ans %= mod;
        }
        ways--;
    }
    
    ways = n - b[0];
    
    for (int i = b[0] + 1; i <= n; i++){
        if (c[i] != 2){
        //    cout << i << " " << ways << "\n";
            ans *= ways - 1;
            ans %= mod;
        }
        ways--;
    }
    
    cout << ans << "\n";
}

int32_t main() 
{
    auto begin = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // freopen("in",  "r", stdin);
    // freopen("out", "w", stdout);
    
    cin >> t;
    factorialinit();
    for(int i = 1; i <= t; i++) 
    {
        //cout << "Case #" << i << ": ";
        Solve();
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
    return 0;
}