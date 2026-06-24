#include <bits/stdc++.h>
/*.....................
Author : PTY
Time : 13/01/13
.....................*/
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
using namespace std;
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define drep(i,r,l) for(int i=r;i>=l;i--)
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define LL long long
#define Travel(E, u) for(int i=E.start[u],v;v=E.e[i].a,i;i=E.e[i].next)
#define sqr(x) ((x)*(x))
#define pb push_back
#define read() (strtol(ipos, &ipos, 10))
#define pb push_back
#define pi 3.1415926535897
LL n, t;
LL c[65][65], ans;
int cnt;

struct Tprogram
{
    void open()
    {
        freopen("", "r", stdin);
        freopen("", "w", stdout);
    }
    void close()
    {
        fclose(stdin);
        fclose(stdout);
    }
    void init()
    {
        rep(i,0,60) c[i][0] = 1;
        rep(i,1,60)
            rep(j,1,60)
                c[i][j] = c[i-1][j] + c[i-1][j-1];
        scanf("%lld%lld", &n, &t);
            n++;
    }
    LL ask(LL k, LL n, int C)
    {
        if (n == 0) return 0;
        if (C == 0) return 1;
        if (k == 0) return 0;
        LL s = 1LL<<k-1;
        if (n >= s)
            return c[k-1][C] + ask(k - 1, n - s, C-1);
        else return ask(k-1, n, C);
    }
    void work()
    {
        if ((t & -t) != t) printf("0\n");
        else
        {
            cnt = 0;
            while (t != 1) cnt++, t >>= 1;
            rep(i,0,60)
            {
                if ((1LL<<i) <= n) ans += c[i][cnt];
                else
                {
                    ans += ask(i, n, cnt);
                    break;
                }
                n -= (1LL << i);
            }
            if (cnt == 0) ans--;
            printf("%lld\n", ans);
        }
    }
}Program;
int main()
{
    //Program.open();
    Program.init();
    Program.work();
    //while (1);
    return 0;
}