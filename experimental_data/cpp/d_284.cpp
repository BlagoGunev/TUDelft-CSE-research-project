#include <iostream>
#include <cstdio>
#include <set>
#include <map>
#include <queue>
#include <vector>
#include <cstring>
#include <ctime>
#include <cmath>
#include <algorithm>
using namespace std;

const int MAXN = 2e5 + 224;

int n, a[MAXN];
bool mark[2][MAXN];
long long memo[2][MAXN];

long long go(int curr, int sgn)
{
    int lol = 1;
    if (sgn == -1) lol = 0;
   // cout << curr << endl;
    if (curr <= 0 || curr > n)
        return 0;

    if ((mark[lol][curr] && !memo[lol][curr]) || curr == 1)
        return -1;
    else if (mark[lol][curr])
        return memo[lol][curr];
    mark[lol][curr] = true;

    long long add = go(curr + sgn * a[curr], sgn * (-1));
   // cout << " s " << add << endl;
    if (add == -1)
        memo[lol][curr] = -1;
    else
        memo[lol][curr] = a[curr] + add;
    //cout << curr << " " << a[curr] << " " << memo[curr] << endl;
    return memo[lol][curr];
}

int main()
{
    cin.sync_with_stdio(0);
   //freopen("ss.in", "r", stdin);
    cin.tie(0);

    cin >> n;
    for (int i = 2; i <= n; i++)
        cin >> a[i];

      //  go(2, -1);
     //   cout << memo[0][2] << " " << memo[1][2] << endl;
   //     cout << go(4, -1) << endl;
    for (int i = 1; i < n; i++)
    {
        long long sum = go(i + 1, -1);

        if (sum != -1) sum += i;
        cout << sum << "\n";
    }

    return 0;
}