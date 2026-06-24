#include <cstdio>
#include <iostream>
using namespace std;

int read();

int n;

int a[200005];
long long cnt[2];
int main() {
    n = read();
    for (int i = 1; i <= n; ++i) a[i] = (read() < 0);
    for (int i = 1; i <= n; ++i) a[i] = a[i] ^ a[i - 1], cnt[a[i]]++;
    cnt[0]++;
    printf("%I64d %I64d\n", cnt[0] * cnt[1],
           (cnt[0] * (cnt[0] - 1) + cnt[1] * (cnt[1] - 1)) / 2);
    return 0;
}

int read() {
    int x = 0, f = 1;
    char c = getchar();
    while (c < '0' || c > '9') f = (c == '-') ? -1 : f, c = getchar();
    while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
    return x * f;
}