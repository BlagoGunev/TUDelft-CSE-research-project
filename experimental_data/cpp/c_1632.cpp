#include <bits/stdc++.h>

using namespace std;



#define endl '\n'

#define YES cout << "YES" << endl

#define NO cout << "NO" << endl

#define all(_) _.begin(), _.end()

#define sz(_) (int)_.size()

#define fs first

#define se second

#define Odd(_x) ((_x) & 1)

typedef long long ll;

typedef pair<int, int> pii;

const int N = 100000;

const int inf = 1e9 + 10;

const ll mod = 1e9 + 7;



void solve() {

    int a, b;

    cin >> a >> b;

    int ans = b - a;

    for (int i = 0; i <= b; i++) {

        if ((i | b) == b) {

            ans = min(ans, abs(i - a) + (b != i));

        }

    }

    cout << ans << endl;

}

#define MULTI_INPUT



int main() {

#ifndef ONLINE_JUDGE

    freopen(R"(D:\source files\source file2\input.txt)", "r", stdin);

    freopen(R"(D:\source files\source file2\output.txt)", "w", stdout);

#endif

    std::ios::sync_with_stdio(false);

    cin.tie(0);

#ifdef MULTI_INPUT

    int T;

    cin >> T;

    while (T--) {

        solve();

    }

#else

    solve();

#endif

    return 0;

}