#include <iostream>

#include <cstring>

#include <algorithm>



using namespace std;



const int N = 1e5 + 9000, MAXN = 450;



typedef long long LL;



LL a[N];

int n;

LL f[2][N];



int main() {

    int T; cin >> T;

    while (T -- ) {

        cin >> n;

        for (int i = 1; i <= n; i ++ ) cin >> a[i];

        reverse(a + 1, a + 1 + n);

        for (int i = 1; i <= n; i ++ ) a[i] += a[i - 1];

        memset(f, 0, sizeof (n + 1) * 16);

        for (int i = 0; i <= n; i ++ ) f[0][i] = 1e17;

        int ans = 0;

        for (int i = 1; i <= MAXN; i ++ ) {

            f[i & 1][i * (i + 1) / 2 - 1] = 0;

            for (int j = i * (i + 1) / 2; j <= n; j ++ ) {

                f[i & 1][j] = f[i & 1][j - 1];

                LL s = a[j] - a[j - i];

                if (s < f[i - 1 & 1][j - i]) {

                    ans = i;

                    f[i & 1][j] = max(s, f[i & 1][j]);

                }

            }

        }

        cout << ans << endl;

    }

    return 0;

}