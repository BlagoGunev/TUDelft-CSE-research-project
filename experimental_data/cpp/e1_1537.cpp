#include "bits/stdc++.h"

#define iio ios::sync_with_stdio(0);cin.tie(0);cout << fixed;

#define rep(a, b) for(int i = a; i < b; i++)

#define all(x) (x).begin(), (x).end()

#define el '\n'

#define vi vector<int>

#define eps 1e-9

#define debug(x) cout << (#x) << " is now " << x << endl

#define debug2(x, y) cout << (#x) << " is now " << x << " and " << (#y) << " is now " << y << endl

#define vii vector<pair<int,  int>>

#define pb push_back

#define F first

#define S second

#define int long long



using ll = long long;

using ld = long double;



using namespace std;

void solve(int tt){    

    int n, k;

    string s;

    cin >> n >> k >> s;

    string ans = "";

    rep(0, k)ans.pb('z');

    rep(1, n+1)

    {

        string temp = s.substr(0, i);

        string ttemp = temp;

        while(ttemp.size()<k)ttemp+=temp;

        ttemp = ttemp.substr(0, k);

        ans = min(ans, ttemp);

    }

    cout << ans << el;

}

signed main()

{

iio

//freopen("input.in", "r", stdin);

//freopen("output.out", "w", stdout);

int tt = 1;

int z = tt;

while(tt--)

{

    solve(z-tt);

}

}