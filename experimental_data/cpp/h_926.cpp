#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <stack>
#include <deque>
#include <unordered_map>
#include <unordered_set>

#define pb push_back
#define mp make_pair
#define all(a) a.begin(), a.end()
#define frn(i, n) for (int i = 0; i < (int)(n); i++)
#define frd(i, n) for (int i = (int)(n - 1); i >= 0; i--)
#define frs(it, n) for(auto it = n.begin(); it != n.end(); it++)
#define frab(i, a, b) for(int i = a; i < b; i++)

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const ll LINF = 1e18;
const int INF = 1e9;
const int M = 1e9 + 7;
const double EPS = 1e-9;

using namespace std;

struct Rose
{
    int beauty;
    char col;
} a[202000];

bool cmp (Rose a, Rose b)
{
    if (a.beauty <= b.beauty)
        return 0;
    return 1;
}

int main(int argc, const char * argv[])
{
    std::ios_base::sync_with_stdio(0);
    
    //    freopen("ain", "r", stdin);
    //    freopen("aout", "w", stdout);
    
    int n, k;
    cin >> n >> k;
    
    frn (i, n)
        cin >> a[i].beauty;
    
    string s;
    cin >> s;
    int ors = 0, rs = 0, ws = 0;
    frn (i, n)
    {
        a[i].col = s[i];
        if (s[i] == 'O')
            ors++;
        else if (s[i] == 'R')
            rs++;
        else ws++;
    }
    if (ors + rs < k && ors + ws < k || k == 1)
    {
        cout << -1;
        return 0;
    }
    
    sort(a, a + n, cmp);
    
    ll ans1 = 0, ans2 = 0;
    int flag1 = 0, flag2 = 0, flag3 = 0;
    
    frn (i, n)
        if (a[i].col == 'O')
        {
            ans1 += a[i].beauty;
            ans2 += a[i].beauty;
            a[i].beauty = -INF;
            a[i].col = 'P';
            flag1 = 1;
            break;
        }
    
    frn (i, n)
        if (a[i].col == 'R')
        {
            ans1 += a[i].beauty;
            a[i].beauty = -INF;
            a[i].col = 'P';
            flag2 = 1;
            break;
        }
    
    frn (i, n)
        if (a[i].col == 'W')
        {
            ans2 += a[i].beauty;
            a[i].beauty = -INF;
            a[i].col = 'P';
            flag3 = 1;
            break;
        }
    
    int ct = 2;
    if (flag1 && flag2 && ct != k)
        frn (i, n)
        {
            if (a[i].col == 'R' || a[i].col == 'O')
            {
                ans1 += a[i].beauty;
                ct++;
                if (ct == k)
                    break;
            }
        }
    if (ct != k)
        flag2 = 0;
    ct = 2;
    if (flag3 && flag1 && ct != k)
        frn (i, n)
            if (a[i].col == 'W' || a[i].col == 'O')
            {
                ans2 += a[i].beauty;
                ct++;
                if (ct == k)
                break;
            }
    
    if (!flag1)
        cout << -1;
    else if (!flag2 && flag3)
        cout << ans2;
    else if (flag2 && !flag3)
        cout << ans1;
    else if (flag2 && flag3)
        cout << max(ans1, ans2);
    else
        cout << -1;
    
    return 0;
}