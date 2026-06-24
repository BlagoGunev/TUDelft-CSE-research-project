/*
  Author : lifehappy
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 2e3 + 10;

char str[N][N];

int l[N][10], r[N][10];

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int T, n;
    cin >> T;
    while(T--) {
        vector<int> ans(10, 0);
        cin >> n;
        for(int i = 1; i <= n; i++) {
            cin >> str[i] + 1;
        }
        for(int i = 1; i <= n; i++) {
            for(int j = 0; j <= 9; j++) {
                l[i][j] = 0x3f3f3f3f, r[i][j] = -1;
            }
        }
        vector<int> pos[10];
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                l[i][str[i][j] - '0'] = min(l[i][str[i][j] - '0'], j);
                r[i][str[i][j] - '0'] = max(r[i][str[i][j] - '0'], j);
            }
            for(int j = 0; j <= 9; j++) {
                if(l[i][j] != 0x3f3f3f3f) {
                    pos[j].push_back(i);
                }
            }
        }
        for(int i = 1; i <= n; i++) {
            for(int j = 0; j <= 9; j++) {
                if(l[i][j] == 0x3f3f3f3f) continue;
                if(l[i][j] != r[i][j]) {
                    ans[j] = max(ans[j], (r[i][j] - l[i][j]) * max(abs(i - 1), abs(n - i)));
                    ans[j] = max(ans[j], max(r[i][j] - 1, n - l[i][j]) * max(abs(pos[j][0] - i), abs(pos[j][pos[j].size() - 1] - i)));
                }
                else {
                    ans[j] = max(ans[j], max(l[i][j] - 1, n - l[i][j]) * max(abs(pos[j][0] - i), abs(pos[j][pos[j].size() - 1] - i)));
                }
            }
        }
        for(int i = 0; i <= 9; i++) {
            pos[i].clear();
        }
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j < i; j++) {
                swap(str[i][j], str[j][i]);
            }
        }
        for(int i = 1; i <= n; i++) {
            for(int j = 0; j <= 9; j++) {
                l[i][j] = 0x3f3f3f3f, r[i][j] = -1;
            }
        }
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                l[i][str[i][j] - '0'] = min(l[i][str[i][j] - '0'], j);
                r[i][str[i][j] - '0'] = max(r[i][str[i][j] - '0'], j);
            }
            for(int j = 0; j <= 9; j++) {
                if(l[i][j] != 0x3f3f3f3f) {
                    pos[j].push_back(i);
                }
            }
        }
        for(int i = 1; i <= n; i++) {
            for(int j = 0; j <= 9; j++) {
                if(l[i][j] == 0x3f3f3f3f) continue;
                if(l[i][j] != r[i][j]) {
                    ans[j] = max(ans[j], (r[i][j] - l[i][j]) * max(abs(i - 1), abs(n - i)));
                    ans[j] = max(ans[j], max(r[i][j] - 1, n - l[i][j]) * max(abs(pos[j][0] - i), abs(pos[j][pos[j].size() - 1] - i)));
                }
                else {
                    ans[j] = max(ans[j], max(l[i][j] - 1, n - l[i][j]) * max(abs(pos[j][0] - i), abs(pos[j][pos[j].size() - 1] - i)));
                }
            }
        }
        for(int i = 0; i <= 9; i++) {
            cout << ans[i] << " \n"[i == 9];
        }
    }
    return 0;
}