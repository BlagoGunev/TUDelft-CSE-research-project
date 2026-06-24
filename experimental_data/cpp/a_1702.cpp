#include <bits/stdc++.h>

using namespace std;



#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

#define JUGAD freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);



const int MOD = 1e9 + 7;

const int MAXN = 1e5 + 3;



int main() {

    FAST;

    int t; cin >> t;

    while (t--) {

        long long n, m; cin >> n; m = 1;

        while (10 * m <= n) {m *= 10;}

        cout << n - m << "\n";

    }

}