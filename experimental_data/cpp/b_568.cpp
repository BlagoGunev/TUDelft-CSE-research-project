# include <iostream>
 # include <cstdio>
 # include <cstdlib>
 # include <cstring>
 # include <map>
 # include <vector>
 # include <algorithm>
 # include <set>
 # define FOR(xxx, yyy, zzz) for(int xxx = yyy; xxx <= zzz; ++xxx)
 # define pb push_back
 # define pii pair<int, int>
 # define mp make_pair
 # define sz(xxx) (int)xxx.size()
 # define all(xxx) xxx.begin(),xxx.end()
 # define f first
 # define s second

 using namespace std;

 typedef long long ll;

 const int N = 4444;
 const int mod = (int)1e9 + 7;

 int c[N][N];
 int n;

 int main () {
    cin >> n;
    -- n;
    c[0][0] = 1;
    FOR (i, 1, n) {
        c[i][0] = c[i - 1][i - 1];
        c[i][0] %= mod;
        FOR (j, 1, i) {
            c[i][j] = c[i][j - 1] + c[i - 1][j - 1];
            c[i][j] %= mod;
        }
    }
    ll sum = 0;
    FOR (i, 0, n) {
        sum += c[n][i];
        sum %= mod;
    }
    cout << sum << endl;
 }