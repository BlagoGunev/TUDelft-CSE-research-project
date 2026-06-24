#include <cstring>
#include <cstdlib>
#include <map>
#include <unordered_map>
#include <string>
#include <list>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <cstdio>
#include <iostream>
#include <set>
#include <unordered_set>
using namespace std;

#define ABS(a) ((a)<0?(-(a)):(a))
#define CS while(cases())
#define I(n) int n = gi()
#define II(n) n = gi()
#define L(n) ll n = gli()
#define LL(n) n = gli()
#define F(i, n) for (int i = 0; i < n; i++)
#define Fa(n, a) for (int ___i = 0; ___i < n; ___i++) a[___i] = gi()
#define R(i, n) for (int i = n-1; i >= 0; i--)
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef pair<int, int> pii;

template<class T>
T gcd(T a, T b) {
    return (b == 0 ? a : gcd(b, a%b));
}

int gi() {
    int a;
    scanf("%d", &a);
    return a;
}

ll gli() {
    ll a;
#ifndef ONLINE_JUDGE
    scanf("%lld", &a);
#else
    scanf("%I64d", &a);
#endif
    return a;
}

int cases() {
    static int t = gi();
    return t--;
}

#define MD 1000000007
#define N 100000
int a[N];
int isp[N+4];
vector<int> p[N];
int mxlen[N];
int h[N][20];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    memset(isp, 0, sizeof(isp));
    for (int i = 2; i <= N; i++) {
        if (isp[i] == 0) {
            for (int j = i; j <= N; j+=i)
                isp[j] = i;
        }
    }

    I(n);
    I(q);
    Fa(n, a);
    F(i, n) {
        mxlen[i] = n-i;
        int x = a[i];
        while (x > 1) {
            int pr = isp[x];
            while (x%pr == 0)
                x /= pr;
            p[pr].push_back(i);
        }
    }

    F(i, N) {
        int l = p[i].size();
        for (int j = 1; j < l; j++) {
            int f = p[i][j-1];
            int s = p[i][j];
            mxlen[f] = min(mxlen[f], s-f);
        }
    }

    for (int i = n-2; i >= 0; i--)
        mxlen[i] = min(mxlen[i], mxlen[i+1] + 1);

    for (int i = n-1; i >= 0; i--) {
        h[i][0] = mxlen[i];
        for (int b = 1; b <= 17; b++) {
            int l = h[i][b-1];
            if (l == n-i)
                h[i][b] = n-i;
            else
                h[i][b] = l + h[i+l][b-1];
        }
        h[i][18] = h[i][17];
    }

    F(iiiii, q) {
        I(L) - 1;
        I(R);
        int res = 0;
        while (R > L) {
            int b = 0;
            while (h[L][b+1] < R-L)
                b++;
            res += 1<<b;
            L += h[L][b];
        }
        printf("%d\n", res);
    }

    return 0;
}