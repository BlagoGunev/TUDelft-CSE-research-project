#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define int ll

#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define pb push_back
#define all(a) (a).begin(),(a).end()
#define sz(a) ((int)(a).size())
#define pii pair<int,int>
#define tiii tuple<int,int,int>
#define nrbits __builtin_popcount
#define nrbitsll __builtin_popcountll

void testcase()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cout << i << ' ';
    cout << '\n';
}

bool multiple_testcases = true;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc = 1;
    if (multiple_testcases == true)
        cin >> tc;
    while (tc--)
        testcase();
    return 0;
}