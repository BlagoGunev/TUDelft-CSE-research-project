#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>
#include <climits>
#include <cassert>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <functional>

#define x first
#define y second
#define MP std::make_pair
#define DEBUG(...) fprintf(stderr, __VA_ARGS__)
#define DISP(x) std::cerr << #x " = " << x << std::endl

typedef long long LL;
typedef std::pair<int, int> Pii;

const int oo = 0x3f3f3f3f;

template<typename T> inline bool chkmax(T &a, T b) { return a < b ? a = b, true : false; }
template<typename T> inline bool chkmin(T &a, T b) { return a > b ? a = b, true : false; }
template<typename T> T read(T &x)
{
    int f = 1;
    char ch = getchar();
    for (; !isdigit(ch); ch = getchar())
        if (ch == '-')
            f = -1;
    for (x = 0; isdigit(ch); ch = getchar())
        x = 10 * x + ch - '0';
    return x *= f;
}
template<typename T> void write(T x)
{
    if (x == 0) {
        putchar('0');
        return;
    }
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    static char s[20];
    int top = 0;
    for (; x; x /= 10)
        s[++top] = x % 10 + '0';
    while (top)
        putchar(s[top--]);
}
// EOT

const int MAXN = 2e5 + 5;
const int CNT = 60;

int N;
Pii A[MAXN];

int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}

inline int count(int i, int j)
{
    return gcd(std::abs(A[j].x - A[i].x), std::abs(A[j].y - A[i].y));
}

inline LL cross(const Pii &a, const Pii &b)
{
    return (LL)a.x * b.y - (LL)a.y * b.x;
}

void input()
{
    read(N);
    for (int i = 0; i < N; ++i) {
        read(A[i].x); read(A[i].y);
    }
}

void solve()
{
    memcpy(A + N, A, sizeof(*A) * N);
    LL a = 0, b = 0;
    for (int i = 0; i < N; ++i) {
        a += cross(A[i], A[i + 1]);
        b += count(i, i + 1);
    }

    long double coef[MAXN];

    long double tnn = pow((long double)2, -N);
    for (int i = 2; i <= CNT && i < N - 1; ++i) {
        coef[i] = pow((long double)2, -i - 1) - tnn;
    }

    long double ans = 0.5 * a - 0.5 * b + 1;
    long double contrib = 0;
    for (int i = 0; i < N; ++i) {
        a = cross(A[i], A[i + 1]);
        b = count(i, i + 1);
        for (int k = 2; k <= CNT && k < N - 1; ++k) {
            int j = i + k;
            a += cross(A[j - 1], A[j]);
            b += count(j - 1, j);
            LL a0 = cross(A[j], A[i]);
            LL b0 = count(j, i);
            contrib += (0.5 * (a + a0) - 0.5 * (b + b0) + b0) * coef[k];
        }
    }
    ans -= contrib / (1 - tnn - N * tnn - (LL)N * (N - 1) / 2 * tnn);

    printf("%.15f\n", (double)ans);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("tmp.in", "r", stdin);
    freopen("tmp.out", "w", stdout);
#endif

    input();
    solve();

    return 0;
}