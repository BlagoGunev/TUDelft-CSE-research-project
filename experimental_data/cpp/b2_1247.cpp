#include <bits/stdc++.h>
#pragma GCC optimize(2)
using namespace std;

template<class T> inline void read(T &x) {
    x = 0;
    char ch = getchar(), w = 0;
    while (!isdigit(ch)) w = (ch == '-'), ch = getchar();
    while (isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
    x = w ? -x : x;
    return;
}

int n, T, k, d, sum, minn, a[200005];
int vis[1000005];

signed main() {
    read(T);
    while (T--) {
        sum = 0;
        read(n), read(k), read(d);
        for (int i = 1; i <= n; ++i) {
            read(a[i]), vis[a[i]] = 0;
        }
        for (int i = 1; i <= d; ++i) {
            if (!vis[a[i]]) sum++;
            vis[a[i]]++;
        }
        minn = sum;
        for (int i = d + 1; i <= n; ++i) {
            if (!vis[a[i]]) sum++;
            vis[a[i]]++;
            vis[a[i - d]]--;
            if (!vis[a[i - d]]) sum--;
            minn = min(minn, sum);
        }
        printf("%d\n", minn);
    }
    return 0;
}