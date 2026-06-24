#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

#define MAXINT 1001001001ll

int d[1000][1000];

int req[1000];

long long sum[1000][1000];

int exist[1000];

vector <long long> ANS;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    int n; scanf ("%d", &n);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            scanf ("%d", &d[i][j]);

    for (int i = 0; i < n; i++)
        scanf ("%d", &req[i]);

    long long ans = 0;
    for (int q = n - 1; q >= 0; q--) {
        int x = req[q]; exist[x] = 1;

        for (int i = 1; i <= n; i++)
        if (exist[i]) {
            ans += d[i][x];
            ans += d[x][i];
        }

        int k = x;
        for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        if (d[i][j] > d[i][k] + d[k][j]) {
            if (exist[i] && exist[j]) ans -= d[i][j];
            d[i][j] = d[i][k] + d[k][j];
            if (exist[i] && exist[j]) ans += d[i][j];
        }

        ANS.push_back (ans);
    }

    for (int i = (int) ANS.size () - 1; i >= 0; i--)
        printf ("%I64d ", ANS[i]);

    return 0;
}