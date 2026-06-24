#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <string>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <bitset>

#define INF 0x3f3f3f3f
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

template<class T>
inline void read(T &x) {
    x = 0;
    char c = getchar();
    bool flag = 0;
    while (!isdigit(c)) {
        if (c == '-')
            flag = 1;
        c = getchar();
    }
    while (isdigit(c)) {
        x = (x << 3) + (x << 1) + c - '0';
        c = getchar();
    }
    x = flag ? -x : x;
}

template<class T>
inline void write(T x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x >= 10)
        write(x / 10);
    putchar(x % 10 + '0');
}

const int maxn = 2e5 + 10;
const int mod = 998244353;

int a[maxn];
int sum[maxn];

int main() {
    
    int t;
    read(t);
    while (t--) {
        int n;
        read(n);
        int c1 = 0, c2 = 0;
        map<int, int> m;
        m[0] = 0;
        for (int i = 1; i <= n * 2; ++i) {
            read(a[i]);
            if (a[i] == 2)
                a[i] = -1;
            
            if (a[i] == 1)
                ++c1;
            else
                ++c2;
            if (i != n + 1) {
                sum[i] = sum[i - 1] + a[i];
            } else {
                sum[i] = a[i];
            }
            if (i > n) {
                if (m.find(sum[i]) == m.end())
                    m[sum[i]] = i - n;
            }
        }
        int ans = INF;
        for (int i = 0; i <= n; ++i) {
            int l = sum[n] - sum[i];
            int r = c1 - l - c2;
            if (m.find(r) != m.end())
                ans = min(ans, n - i + m[r]);
        }
        printf("%d\n", ans);
    }
}