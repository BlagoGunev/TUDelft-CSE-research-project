#include <bits/stdc++.h>

using namespace std;



using i64 = long long;

using pii = pair<int, int>;



int P;

constexpr int N = 405;

i64 f[N][N];



void add(i64& x, i64 y) {

    x += y;

    if (x >= P)

        x -= P;

}



void run() {

    int n;

    cin >> n >> P;

    f[0][0] = 1;

    for (int i = 0; i <= n; i++) {

        for (int j = 0; j <= i; j++) {

            add(f[i + 1][j + 1], f[i][j] * (j + 1) % P);

            add(f[i + 1][j], f[i][j] * 2 * j % P);

            add(f[i + 2][j], f[i][j] * 2 * j % P);

            if (j > 1) {

                add(f[i + 2][j - 1], f[i][j] * 2 * (j - 1) % P);

                add(f[i + 3][j - 1], f[i][j] * (j - 1) % P);

            }

        }

    }

    cout << f[n][1] << "\n";

}



int main() {

    ios::sync_with_stdio(0);

    cin.tie(0), cout.tie(0);

    int T = 1;

    // cin >> T;

    while (T--) {

        run();

    }

    return 0;

}