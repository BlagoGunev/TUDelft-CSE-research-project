#include <iostream>
#include <cstdio>
#include <map>
#include <vector>

using namespace std;

const int MAXN = 4005;
vector<int> v[MAXN];
map<int, int> mp;
int a[MAXN];

inline int gao(vector<int>& a, vector<int>& b) {
    int n = (int)a.size(), m = (int)b.size();
    int x = 0, y = 0;
    int pre = -1, cnt = 0;

    while (x < n && y < m) {
        if (a[x] < b[y]) {
            ++x;
            if (pre == -1 || pre == 1) {
                ++cnt;
                pre = 0;
            }
        } else {
            ++y;
            if (pre == -1 || pre == 0) {
                ++cnt;
                pre = 1;
            }
        }
    }
    return max(cnt + 1, max(n, m));
}

int main() {
    //freopen("in.txt", "r", stdin);
    int n;
    int m = 0;

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (mp.count(a[i]) == 0) {
            mp[a[i]] = m++;
        }
    }
    for (int i = 0; i < n; ++i) {
        v[mp[a[i]]].push_back(i);
    }
    
    //printf("m = %d\n", m);
    int ans = 0;
    for (int i = 0; i < m; ++i) {
        ans = max(ans, (int)v[i].size());
        for (int j = i + 1; j < m; ++j) {
            if (v[i].size() + v[j].size() <= ans) {
                continue;
            }
            ans = max(ans, gao(v[i], v[j]));
        }
    }
    cout << ans << endl;

    return 0;
}