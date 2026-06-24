/***--_Mr.Turtle_--***/
#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define sz(x) (int)x.size()
#define el '\n'
const ll N = 2e5 + 5, mod = 1e9 + 7;

void solve()
{
    int n;
    cin >> n;

    vector<vector<vector<int>>> v(n, vector<vector<int>>(n, vector<int>(n)));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++) 
                cin >> v[i][j][k];

    vector<vector<vector<int>>> dp(n, vector<vector<int>>((1 << n), vector<int>((1 << n), -1)));
    function<int(int, int, int)> cal = [&](int z, int mskX, int mskY) {
        if(z == n)
            return 0;

        int &ret = dp[z][mskX][mskY];
        if(~ret)
            return ret;

        ret = 1e9;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if(!(mskX & (1 << i)) && !(mskY & (1 << j)))
                    ret = min(ret, v[i][j][z] + cal(z + 1, mskX | (1 << i), mskY | (1 << j)));

        return ret;
    };

    cout << cal(0, 0, 0);
}

signed main()
{
    if (fopen("input.txt", "r")) {
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    }
    ios_base::sync_with_stdio(false), cout.tie(NULL), cin.tie(NULL);
    int _t = 1;
    // cin >> _t;
    for (int i = 1; i <= _t; i++)
    {
        // cout << "Case #" << i << ": ";
        solve();
    }
}