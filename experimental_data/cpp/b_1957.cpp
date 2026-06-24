#include <bits/stdc++.h>
using namespace std;
void Solution() {
    int n, k;
    cin >> n >> k;
    if (n == 1) {
        cout << k << '\n';
        return;
    }
    int sum = 0, sb = 0;
    for (int i = 0; ; i++) {
        if (sb + (1 << i) > k) {
            break;
        }
        sb += 1 << i;
    }
    cout << sb << ' ';
    k -= sb;
    cout << k << ' ';
    n -= 2;
    while (n--) {
        cout << "0 ";
    }
    cout << '\n';
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int TT;
    cin >> TT;

    while (TT--) {
        Solution();
    }
    return 0;
}