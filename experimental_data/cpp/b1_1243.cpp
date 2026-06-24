#include <iostream>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <iomanip>
#include <sstream>
#include <bitset>
#include <cstdlib>
#include <iterator>
#include <algorithm>
#include <cstdio>
#include <cctype>
#include <cmath>
#include <math.h>
#include <ctime>
#include <cstring>
#include <assert.h>

#define ll long long

#define sl(n) scanf("%lld", &n)
#define ss(n) scanf("%s", n)
#define sf(n) scanf("%lf", &n)

#define PI 2*acos(0.0)
#define INF (1LL<<62)

#define pll pair<ll,ll>

#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define srt(v) sort(v.begin(), v.end())
using namespace std;

char s[10010], t[10010];

int main()
{
  //  freopen("input.txt", "r", stdin);

    ll n, i, j, k, x, y, z, ts;

    sl(ts);

    while(ts--)
    {
        sl(n);
        ss(s);
        ss(t);

        ll mis = 0;

        for (i = 0; i < n; i++)
        {
            if (s[i] != t[i])
            {
                mis++;

                if (mis == 1)
                    x = i;
                else y = i;
            }

        }

        if (mis == 0 || (mis == 2 && s[x] == s[y] && t[x] == t[y]))
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}