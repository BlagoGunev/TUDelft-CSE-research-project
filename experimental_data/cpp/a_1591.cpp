#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <functional>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <bitset>

#define ll long long
#define rep(i,a,b) for(int i = a; i <= b; ++i)
#define per(i,a,b) for(int i = a; i >= b; --i)
#define reps(i,a,b) for(int i = a; i < b; ++i)
#define pers(i,a,b) for(int i = a; i > b; --i)
#define endl '\n'
#define PII pair<int,int>
#define x first
#define y second
#define pb push_back

#define __builtin_popcount __popcnt 
#define __builtin_popcountl __popcnt

using namespace std;
const int inf = 0x3f3f3f3f;
const int mod1 = 1e9 + 7;
const int mod2 = 998244353;

int t, n;
int a[110];

void solve()
{
    int ans = 1;
    cin >> n;
    rep(i, 1, n) cin >> a[i];
    if (a[1] == 1) ans++;
    rep(i, 2, n)
    {
        if (a[i] == 1)
        {
            if (a[i - 1] == 1) ans += 5;
            else ans += 1;
        }
        else
        {
            if (a[i - 1] == 0)
            {
                cout << -1 << endl;
                return;
            }
        }
    }
    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) solve();
    
    
    return 0;
}