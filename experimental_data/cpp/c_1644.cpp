#include <bits/stdc++.h>

using namespace std;

#define ls o << 1
#define rs o << 1 | 1
#define fi first
#define se second
#define dbg(x) do { std::cout << #x << ": " << x << std::endl; } while (0)
typedef long long ll;
typedef pair<int, int> pii; 

const int maxn = 5e5+10;
const int mod = 1e9+7;
const int inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3f;

void solve() {    
    int n, x;
    scanf("%d%d", &n, &x);
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    vector<int> sum(n + 1), mx(n + 1, -inf);
    mx[0] = 0;
    for (int i = 1; i <= n; i++) {
        sum[i] = sum[i - 1] + a[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int len = 1; i + len - 1 <= n; len++) {
            mx[len] = max(mx[len], sum[i + len -1] - sum[i - 1]);
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        mx[i] = max(mx[i], mx[i + 1]);
    }
    int last = 0;
    for (int i = 0; i <= n; i++) {
        int now = mx[0];
        if(i == 0) printf("%d ",mx[0]);
        else {
            now = max({mx[i] + i * x, mx[i - 1] + (i - 1) * x, last});
            printf("%d ",now);
        }
        last = now;
    }
    puts("");
}
int main() {
    clock_t t1 = clock();
	#ifndef ONLINE_JUDGE
       freopen("in.in", "r", stdin);
       freopen("out.out", "w", stdout);
    #endif 
	int T;scanf("%d", &T);while (T--)
	solve();
end:
    cerr << "Time used " << clock() - t1 << " ms" << endl;
	return 0;
}