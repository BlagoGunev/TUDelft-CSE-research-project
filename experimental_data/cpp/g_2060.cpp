#include<bits/stdc++.h>
using namespace std;
using namespace chrono;
using ll = long long;
#define endl '\n'; //comment this out for interactive problems


void solve() {
    ll n;
    cin >> n;
    vector<array<ll, 2>> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i][0];
    }
    for (int i = 0; i < n; i++) {
        cin >> v[i][1];
    }
    sort(v.begin() , v.end(), [&](array<ll, 2> &a , array<ll, 2> &b) {
        return min(a[0] , a[1]) < min(b[0] , b[1]);
    });

    vector<vector<vector<int>>> dp(n , vector<vector<int>> (2 , vector<int> (2 , -1)));

    auto find = [&](auto && self, int ind , int p , int c)->bool{
        if (ind >= n) {
            return c == 0;
        }

        if (dp[ind][p][c] != -1) {
            return (bool)dp[ind][p][c];
        }

        if (p) {
            swap(v[ind - 1][0] , v[ind - 1][1]);
        }
        bool yes = 0;
        // want to swap
        swap(v[ind][0] , v[ind][1]);
        if (v[ind][0] >= v[ind - 1][0] and v[ind][1] >= v[ind - 1][1]) {
            swap(v[ind][0] , v[ind][1]);
            yes |= self(self , ind + 1 , 1 , c ^ 1);
        } else{
            swap(v[ind][0] , v[ind][1]);
        }
        //dont want to swap
        if (v[ind][0] >= v[ind - 1][0] and v[ind][1] >= v[ind - 1][1]) {
            yes |= self(self , ind + 1 , 0 , c ^ 0);
        } else{
        }
        if (p) {
            swap(v[ind - 1][0] , v[ind - 1][1]);
        }

        return dp[ind][p][c] = yes;
    };

    if (find(find , 1 , 0 , 0) or find(find , 1 , 1 , 1)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    auto start1 = high_resolution_clock::now();
    int T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }
    auto stop1 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop1 - start1);
    cerr << "Time: " << duration . count() / 1000 << " ms" << endl;
}