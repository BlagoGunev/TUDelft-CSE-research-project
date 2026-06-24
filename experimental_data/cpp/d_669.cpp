#include <cstdio>

using namespace std;

char c, d[20];
int out, os, sign;
#define read(X) X = 0; for (c = getchar(); c != '-' && (c > '9' || c < '0'); c = getchar()); if (c == '-') { sign = -1; c = getchar(); } else sign = 1; for (; c >= '0' && c <= '9'; c = getchar()) X = X * 10 + c - '0'; X *= sign
#define write(X) out = X; d[os++] = out % 10 + '0'; out /= 10; for (; out; out /= 10) d[os++] = out % 10 + '0'; for (; os; --os) putchar(d[os - 1]); putchar(' ')

int main()
{
    int n, q, b1(0), b2(1), t, s;
    read(n);
    read(q);
    for (; q; --q)
    {
        read(t);
        switch(t)
        {
        case 1:
            read(s);
            b1 = ((b1 + s) % n + n) % n;
            b2 = ((b2 + s) % n + n) % n;
            break;
        case 2:
            b1 += (b1 % 2 ? -1 : 1);
            b2 += (b2 % 2 ? -1 : 1);
            b1 %= n;
            b2 %= n;
            break;
        }
    }
    int ans[n];
    for (int i(0); i < n; i += 2)
    {
        ans[(b1 + i) % n] = i + 1;
        ans[(b2 + i) % n] = i + 2;
    }
    for (int i(0); i < n; ++i)
    {
        write(ans[i]);
    }
}