#include<bits/stdc++.h>

#define ll long long

#define ull unsigned long long

#define db double

#define ldb long double

#define pb push_back

#define mp make_pair

#define pii pair<int, int>

using namespace std;

inline int read() {

    int x = 0; bool op = 0;

    char c = getchar();

    while(!isdigit(c))op |= (c == '-'), c = getchar();

    while(isdigit(c))x = (x << 1) + (x << 3) + (c ^ 48), c = getchar();

    return op ? -x : x;

}

const int N = 5010;

int n, P;

void add(int &a, int b) {a = (a + b) % P;}

void sub(int &a, int b) {a = (a - b + P) % P;}

int ksm(int x, int k) {

    int res = 1;

    for(int pw = x; k; (k & 1) ? res = 1ll * res * pw % P : 0, pw = 1ll * pw * pw % P, k >>= 1);

    return res;

}

int fac[N], ifac[N], pw[N][N];

void init() {

    fac[0] = ifac[0] = 1;

    for(int i = 1; i < N; i++)fac[i] = 1ll * fac[i - 1] * i % P;

    // puts("OK");

    ifac[N - 1] = ksm(fac[N - 1], P - 2);

    for(int i = N - 2; i; i--)ifac[i] = 1ll * ifac[i + 1] * (i + 1) % P;

    for(int i = 1; i < N; i++) {

        pw[i][0] = 1;

        for(int j = 1; j < N; j++) {

            pw[i][j] = 1ll * pw[i][j - 1] * i % P;

        }

    }

    return ;

}

int com(int n, int m) {return n < m || m < 0 ? 0 : 1ll * fac[n] * ifac[m] % P * ifac[n - m] % P;}

int main() { 

    // puts("OK");

    n = read(); P = read();

    init();

    int val = 1, ans = 0;

    for(int j = 1; (j << 1) <= n; j++) {

        val = 1ll * val * (n - 1) % P;

        for(int i = 0; i <= n - (j << 1); i++) {

            int w = 1;

            w = 1ll * w * com(n, i) % P * pw[n - i - j][i] % P;

            // printf("w:%d %d %d\n", i, j, w);

            w = 1ll * w * fac[n - i] % P * com(n - i - j - 1, j - 1) % P * ifac[j] % P * val % P;

            add(ans, w);

        }

    }

    printf("%d\n", ans);

    return 0;

}