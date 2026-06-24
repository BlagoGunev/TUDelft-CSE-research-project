#include <bits/stdc++.h>
using namespace std;

const int MAX = 500000;
int p[MAX + 1];
char s[MAX + 1];
long long t[2][MAX + 1];

int getint()
{
    int c, v = 0;
    while (isdigit(c = getchar()))
        v = 10 * v + c - '0';
    return v;
}

int main()
{
    int n = getint();
    for (int i = 1; i <= n; i++)
        p[i] = getint();
    scanf("%s", s + 1);
    for (int i = 1; i <= n; i++) {
        t[0][i] = t[0][i - 1];
        t[1][i] = t[1][i - 1];
        t[s[i] == 'B'][i] += p[i];
    }
    long long v = 0;
    for (int i = 0; i <= n; i++)
        v = max(v, max(t[0][i] + t[1][n] - t[1][i], t[1][i] + t[0][n] - t[0][i]));
    printf("%I64d\n", v);
}