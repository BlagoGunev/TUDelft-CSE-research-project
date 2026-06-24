#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <deque>
#include <assert.h>
#include <bitset>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <tuple>
#include <stdio.h>
#include <string.h>
#include <utility>
#include <math.h>
using namespace std;

inline int in(){int32_t x ; scanf("%d",&x) ; return x ; }
inline string get(){char ch[10010] ; scanf("%s",ch) ; return ch;}
template<class P, class Q> inline P smin(P &a, Q b) { if (b < a) a = b; return a; }
template<class P, class Q> inline P smax(P &a, Q b) { if (a < b) a = b; return a; }
#define mp make_pair
#define EPS 1e-9
#define int long long
typedef pair<int , int > pii;
typedef long double ld;
typedef unsigned long long ull;
typedef long long ll;
const int maxn = 600 + 10;

const int base = 29;
const int MAX_LG = 21;
//const int mod = 1e9 + 7;
int a[maxn][maxn] , n , m , mod;
inline void fail()
{
    cout << "0\n";
    exit(0);
}
int cnt[maxn];
int cnt1 , cnt2;
bool mark[maxn][maxn];
int dp[maxn][maxn];

inline int calc(int needOne , int needTwo)
{
    if (mark[needOne][needTwo]) return dp[needOne][needTwo];
    int sum = needOne + (n - needOne - needTwo)*2;
    if (sum % 2) return 0;
    int row = sum/2 + 1;
    if (row == n + 1)
        return (!needOne && !needTwo);
    mark[needOne][needTwo] = true;
    dp[needOne][needTwo] = ((needTwo && needOne ? (ll)needOne*needTwo*calc(needOne  , needTwo - 1) : 0)%mod
    + (needOne >= 2 ? (ll)needOne*(needOne - 1)/2*calc(needOne-2 , needTwo) : 0)%mod
    + (needTwo >= 2 ? (ll)needTwo*(needTwo - 1)/2*calc(needOne+2,needTwo-2):0)%mod)%mod;
    return dp[needOne][needTwo];
}
int32_t main()
{
    n = in() , m = in(), mod = in();
    for (int i = 0 ; i < m  ; i ++)
    {
        string s = get();
        for (int j = 0 ; j < n ; j ++)
        {
            a[i][j] = (s[j] - '0');
            if (a[i][j])
            {
                cnt[j] ++;
                if (cnt[j] > 2)
                    fail();
            }
        }
    }
    if (m == n)
        return cout << 1 << endl , 0;
    for (int j = 0 ; j < n ; j ++)
    {
        if (cnt[j] == 1) cnt1 ++;
        else if (cnt[j] == 0) cnt2 ++;
    }
    return cout << calc(cnt1 , cnt2) << endl , 0;
}