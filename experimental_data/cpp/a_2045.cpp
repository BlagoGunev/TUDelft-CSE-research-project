#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    int n1 = 0, n2 = 0, N = 0, G = 0, Y = 0;
    for (auto c : s) {
        if (c == 'Y') {
            Y++;
        } else if (c == 'N') {
            N++;
            n2++;
        } else if (c == 'G') {
            G++;
            n2++;
        } else if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
            n1++;
        } else {
            n2++;
        }
    }

    int ans = 0, num = min(N, G);

    for (int i = 0; i <= Y; i++) {
        int a = n1 + i, b = n2 + Y - i;

        if (a == 0 || b < 2) {
            continue;
        }

        int c = b / 2;
        int cnt = min(a, c);
        ans = max(ans, 3 * cnt + min(num, b - 2 * cnt));
    }

    cout << ans << endl;

    return 0;
}