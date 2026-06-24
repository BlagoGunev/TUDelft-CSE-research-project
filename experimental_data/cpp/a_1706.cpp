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

        int n, m; cin >> n >> m;

        int ar[n];

        for (int i = 0; i < n; i++) {

            cin >> ar[i];

        }

        string ans = string(m, 'B');

        for (int i = 0; i < n; i++) {

            int x = ar[i] - 1;

            if (m - 1 - x < x) {

                if (ans[m - 1 - x] == 'B') {

                    ans[m - 1 - x] = 'A';

                }

                else {

                    ans[x] = 'A';

                }

            }

            else {

                if (ans[x] == 'B') {

                    ans[x] = 'A';

                }

                else {

                    ans[m - 1 - x] = 'A';

                }

            }

        }

        cout << ans << "\n";

    }

}