// Haricharan
#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define vi vector<int>
#define vii vector<vector<int>>
#define vb vector<bool>
#define pi pair<int, int>
#define si set<int>
#define msi muliset<int>
#define rep(var, l, r) for (int var = l; var < r; var++)

void solve()
{

    string s;
    cin >> s;

    rep (i, 1, 9){

        if (i != (s[1] - '0'))
        cout << s[0] <<  i << endl;

    }

    for (char c = 'a'; c <= 'h'; c++)
    {
        if (c != s[0])
        cout << c << s[1] << endl;
    }

}

int32_t main()
{

    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    int tc = 1;
    cin >> tc;
    rep(i, 0, tc)
        solve();

    return 0;
}