#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
#define clr(a, b) memset(a, b, sizeof(a))
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define gi gI()

using namespace std;

typedef long long ll;

inline ll gI() {
    ll p = 0, flag = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') flag = -1, c = getchar();
    while ('0' <= c && c <= '9') p = p * 10 + (c - '0'), c = getchar();
    return p * flag;
}

priority_queue<ll> q1, q2;
ll n, m, k, p;
int a[1011][1011];
ll sumc[1011], sumr[1011];
ll ansc[1000010], ansr[1000010];
ll ans = 0;

int main() {
#ifndef ONLINE_JUDGE
#endif
    n = gi, m = gi, k = gi, p = gi;
    rep(i, 0, n - 1) 
    rep(j, 0, m - 1) {
        a[i][j] = gi;
        sumr[i] += a[i][j];
        sumc[j] += a[i][j];
    }
    ansr[0] = 0;
    rep(i, 0, n - 1) q1.push(sumr[i]);
    rep(i, 1, k) {
    ll now = q1.top();
    ansr[i] = ansr[i - 1] + now;
    q1.pop();
        q1.push(now - p * m);
    }
    ansc[0] = 0;
    rep(i, 0, m - 1) q2.push(sumc[i]);
    rep(i, 1, k) {
    ll now = q2.top();
    ansc[i] = ansc[i - 1] + now;
    q2.pop();
    q2.push(now - p * n);
    }
    ll ans = -(ll)0x7FFFFFF * 0x7F7F7F7F;
    rep(i, 0, k) {
    ll now = ansr[i] - p * i * (k - i) + ansc[k - i];
    ans = max(ans, now);
    }
    printf("%I64d\n", ans);

    fclose(stdin);
    fclose(stdout);
    return 0;
}