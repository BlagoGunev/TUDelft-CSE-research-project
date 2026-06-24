#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define fi first
#define se second
#define pii pair<int, int>

int t;
int n;
int sol, cnt;

int main() {
    cin >> t;

    while (t--) {
        cin >> n;

        cnt = 1;
        sol = 1;
        while (cnt < n) {
            cnt = cnt * 2 + 2;
            sol++;
        }

        cout << sol << "\n";
    }

    return 0;
}