#include <iostream>
#include <cstdio>
#include <set>
#include <map>
#include <queue>
#include <vector>
#include <cstring>
#include <cmath>
#include <ctime>
#include <algorithm>
#define msg(x) cout << #x << " = " << x << endl
using namespace std;

const int maxN = 2123123;

int n;
int a[maxN];

int main() {
    // freopen("input.in", "r", stdin);
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> n;
    int cnt = 1, nextCnt = 1, used = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    reverse(a + 1, a + n + 1);
    unsigned long long ans = 0;
    int nn = 1, next = n / 4;
    for (int i = n; i >= 1; i--) {
        if (i == next) {
            next = i / 4;
            ++nn;
        }
        ans += 1LL * nn * a[i];
    }
    cout << ans << endl;
    return 0;
}