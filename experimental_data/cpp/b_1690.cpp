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

        int n; cin >> n;

        int ar[n], br[n];

        for (int i = 0; i < n; i++) {

            cin >> ar[i];

        }

        for (int i = 0; i < n; i++) {

            cin >> br[i];

        }

        int ma = 0;

        for (int i = 0; i < n; i++) {

            ma = max(ma, ar[i] - br[i]);

        }

        for (int i = 0; i < n; i++) {

            ar[i] = max(0, ar[i] - ma);

        }

        bool ok = 1;

        for (int i = 0; i < n; i++) {

            if (ar[i] != br[i]) {ok = 0; break;}

        }

        if (ok) {cout << "YES\n";}

        else {cout << "NO\n";}

    }

}