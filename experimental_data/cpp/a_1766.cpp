#include <iostream>

#include <vector>

#include <algorithm>

#include <cmath>

#include <map>

#include <set>

#include <string>

#include <queue>

#include <stack>

#include <list>

#include <unordered_map>

#include <unordered_set>



using namespace std;



typedef long long ll;

typedef long double ld;

#define all(a) a.begin(), a.end()

#define rall(a) a.rbegin(), a.rend()

#define endl "\n"

#define len(s) int(s.size())



const int inf = 2147483000;

const ll linf = 9223372036854775000;

const ld pi = 3.141592653589793238462643383;

const int mod = 1e9 + 7;

const int maxn = 1000000;



// author: @cot-in



vector<int> dp(maxn, 0);



bool good(int x) {

    int cnt = 0, length = 0;

    while (x > 0) {

        cnt += (x % 10 == 0);

        x /= 10;

        length++;

    }

    return (cnt + 1 == length);

}



void precalc() {

    for (int i = 1; i < maxn; i++)

        dp[i] = dp[i - 1] + good(i);

}



void solve() {

    int n;

    cin >> n;

    cout << dp[n] << endl;

}



int main() {

#ifdef cot_in

    freopen("in.txt", "r", stdin);

    freopen("out.txt", "w", stdout);

#endif

    ios_base::sync_with_stdio(false);

    cin.tie(nullptr);

    precalc();

    int t;

    cin >> t;

    while (t--) solve();

    return 0;

}