#include <bits/stdc++.h>
#define R register
#define mp make_pair
#define ll long long
#define pii pair<int, int>
using namespace std;
const int N = 1100000;

int n, a[N], prime[N], ispr[N], nopr;
ll sum, ans = 1e18;

template <class T>
inline void read(T &x) {
    x = 0;
    char ch = getchar(), w = 0;
    while (!isdigit(ch)) w = (ch == '-'), ch = getchar();
    while (isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
    x = w ? -x : x;
    return;
}

inline ll calc(ll pr) {
    ll ret = 0, mid = (pr + 1) / 2, num = 0;
    for (R int i = 1; i <= n; ++i) {
        int tmp = a[i];
        if (num <= mid) {
            if (tmp >= mid - num)
                tmp -= mid - num, num = mid;
            else {
                num += tmp, ret += num;
                continue;
            }
        }
        if (num >= mid) {
            if (tmp >= pr - num)
                tmp -= pr - num, num = 0;
            else {
                num += tmp, ret += pr - num;
                continue;
            }
        }
        num = tmp % pr;
        if (num < mid) ret += num;
        else ret += pr - num;
    }
    return ret;
}

int main() {
    read(n);
    for (R int i = 1; i <= n; ++i) read(a[i]), sum += a[i];
    if (sum == 1) return printf("-1\n"), 0;
    int lim = sqrt(sum);
    for (R int i = 2; i <= lim; ++i) {
        if (!ispr[i]) prime[++nopr] = i;
        for (R int j = 1, k; j <= nopr && (k = i * prime[j]) <= lim; ++j) {
            ispr[k] = 1;
            if (i % prime[j] == 0) continue;
        }
    }
    ll tmp = sum;
    for (R int i = 1; i <= nopr; ++i) {
        if (tmp % prime[i] == 0) {
            ans = min(ans, calc(prime[i]));
            while (tmp % prime[i] == 0) tmp /= prime[i];
        }
    }
    if (tmp != 1) ans = min(ans, calc(tmp));
    cout << ans << endl;
    return 0;
}