#include <bits/stdc++.h>
#define R register
#define mp make_pair
#define ll long long
#define pii pair<int, int>
using namespace std;
const int N = 210000;

int n, a[N], b[N], q;
ll sum;
map<pii, int> to;

template <class T>
inline void read(T &x) {
    x = 0;
    char ch = getchar(), w = 0;
    while (!isdigit(ch)) w = (ch == '-'), ch = getchar();
    while (isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
    x = w ? -x : x;
    return;
}

int main() {
    int x, y, w;
    read(n);
    for (R int i = 1; i <= n; ++i) read(a[i]), sum += a[i];
    read(q);
    while (q--) {
        read(x), read(y), read(w);
        auto it = to.find(mp(x, y));
        if (it != to.end()) {
            if (--b[it->second] < a[it->second]) ++sum;
            to.erase(it);
        }
        if (++b[w] <= a[w]) --sum;
        to[mp(x, y)] = w;
        printf("%lld\n", sum);
    }
    return 0;
}