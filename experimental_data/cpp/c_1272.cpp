#include<bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define sz  sizeof
#define eps 1e-9
typedef long long			ll;
typedef unsigned long long	ull;
typedef pair<int, int>		pii;
const int MAX = 2e5 + 10;

int N, K;
char s[MAX];
int vis[200];


int main() {
#ifdef ACM_LOCAL
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    auto start_clock = clock();
#endif
    scanf("%d%d%s", &N, &K, s + 1);
    for (int i = 1; i <= K; i++) {
        char ch;
        getchar();
        scanf("%c", &ch);
        vis[ch] = 1;
    }
    ll ans = 0, cnt = 0;
    for (int i = 1; i <= N + 1; i++) {
        if (vis[s[i]]) cnt++;
        else {
            ans += cnt * (cnt + 1) / 2;
            cnt = 0;
        }
    }
    printf("%lld\n", ans);

#ifdef ACM_LOCAL
    cerr << (double)(clock() - start_clock) / CLOCKS_PER_SEC << "s" << endl;
#endif
    return 0;
}