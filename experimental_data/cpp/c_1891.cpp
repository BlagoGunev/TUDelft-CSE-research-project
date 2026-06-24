#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 200200

int n;
int a[M];
int f[M], g[M];
set<int> Set;

bool okay(int x) {

}

void solve() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", a+i);
    sort(a+1, a+n+1);
    reverse(a+1, a+n+1);
    ll sum = 0;
    for (int i = 1; i <= n; i++) sum += a[i];
    ll sum2 = sum / 2;
    int i;
    ll s = 0;
    for (i = 1; i <= n; i++) {
        s += a[i];
        if (s > sum2) break;
    }
    s -= a[i];
    i--;

    ll answer = s + i;
    sum -= 2 * s;
    if (sum%2==0) {
        if (sum>0)
            answer += sum/2 + 1;
    } else {
        if (sum==1) answer++;
        else answer += sum/2 + 2;
    }
    printf("%I64d\n", answer);
    //exit(0);
}

int main() {
    //freopen("in.txt", "r", stdin);
    int T;
    for (scanf("%d", &T); T--; ) {
        solve();
    }
}