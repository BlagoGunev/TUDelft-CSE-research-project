#include <bits/stdc++.h>
#define msg(x) cout << #x << " = " << x << endl
using namespace std;

const int maxN = 100555;

int cnt[maxN][3];
string str;
int m;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> str;
    for (int i = 0; i < str.size(); i++) {
        cnt[i + 1][str[i] - 'x']++;
        for (int j = 0; j < 3; j++) {
            cnt[i + 1][j] += cnt[i][j];
        }
    }
    cin >> m;
    while (m--) {
        int l, r;
        cin >> l >> r;
        int c[3];
        for (int i = 0; i < 3; i++) {
            c[i] = cnt[r][i] - cnt[l - 1][i];
        }
        sort(c, c + 3);
        if (c[2] - c[0] <= 1 || r - l < 2) puts("YES");
        else puts("NO");
    }
    return 0;
}