#include <bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define ll __int128
//#define ll long long
#define int long long
#define LEFT(a) ((a)<<1)
#define RIGHT(a) (LEFT(a) + 1)
#define MID(a,b) ((a+b)>>1)
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define y1 y122
//#pragma comment(linker, "/STACK: 20000000005")
using namespace std;

const int MOD = 1e9 + 7;


int POWER (int x, int y){
    x %= MOD;
    int ans = 1;
    while (y){
        if (y & 1)
            ans = ans * x % MOD;
        x = x*x % MOD;
        y >>= 1;
    }
    return ans;
}

void mm(int &v){
    v = ((v%MOD) + MOD)%MOD;
}

const int N = 505, INF = 1e18 + 5, inf = 1e9;

int B[100];

int inv2;

map<pair<int,int>, int> M;

int solve(int n, int k){
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    if (k == 0)
        return 1;
    if (M.find({n, k}) != M.end())
        return M[{n, k}];
    if (n == B[k+1])
        n--;
    if (n < B[k+1]){
        return n%MOD * ((n+1)%MOD) % MOD * inv2 % MOD;
    }
    int t = 0;
    while (B[t+1] < n)
        t++;
    int ans = solve(B[t], k);
    ans += solve(n - B[t], k-1);
    ans %= MOD;
    M[{n, k}] = ans;
    return ans;
}

void solve (){
    int n, k;
    cin >> n >> k;
    cout << solve(n, k) << endl;
}

main()
{
   // freopen ("in.in", "r", stdin);freopen ("out.out", "w", stdout);
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    B[0] = 1;
    for (int i = 1; i <= 64; i++)
        B[i] = B[i-1] * 2;
    inv2 = POWER(2, MOD - 2);
    int T=1;
    cin >> T;
    for (int i = 1; i <= T; i++){
        solve ();
    }
    return 0;
}