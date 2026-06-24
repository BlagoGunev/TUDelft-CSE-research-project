#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, s, ans = 0;

    cin >> n >> s;

    for (int i = n; i > 0; i--) {
        ans += s/i;
        s -= (s/i) * i;
    }

    cout << ans << endl;

    return 0;
}