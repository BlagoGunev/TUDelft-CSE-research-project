// LUOGU_RID: 102570633
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const LL mod = 1e9 + 7;
const int N = 100005;

int a[105];
int main() {
    int _;
    cin >> _;
    while (_--) {
        int n, m;
        cin >> n >> m;
        memset(a, 0, sizeof a);
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            a[x] = 1;
        }
        int ans = 100;
        for (int i = 1; i <= 100; i++) {
            if (a[i] == 0) {
                if (m > 0)
                    m--;
                else {
                    ans = i - 1;
                    break;
                }
            }
        }
        ans += m;
        cout << ans << endl;
    }
    return 0;
}