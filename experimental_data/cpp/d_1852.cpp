#include <bits/stdc++.h>
#define sz(v) ((int)v.size())
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;


const int maxn = 2e5 + 10;
pair<bool, string> solve(string& s, int l, int r, int k, vector<int> order) {
    for (int i = 1; i < s.size(); ++i) {
        if (s[i] != s[i-1]) k--; 
    } 
    if (k < 0) return make_pair(0, "");
    string res = s;
    res[0] = 'A' + l;
    res.back() = 'A' + r;

    for (int i = 1; i < res.size(); ++i) {
        if (res[i] != res[i-1]) k--; 
    }

    for (int i=0; i<res.size(); ++i) {
        if (s[i] != res[i]) k--;
    }

    if (k == 0) return make_pair(true, res);

    set<int> f[4];
    vector<int> cd(res.size());
    for (int i = 1; i + 1 < res.size(); ++i) {
        int d = s[i] != res[i];
        d += res[i] != res[i-1];
        d += res[i] != res[i+1];
        f[d].insert(i);
        cd[i] = d;
    }

    auto update = [&](int i) {
        if (i == 0 || i + 1 == res.size()) return;
        f[cd[i]].erase(i);
        cd[i] = res[i] != s[i];
        cd[i] += res[i] != res[i-1];
        cd[i] += res[i] != res[i+1];
        f[cd[i]].insert(i);
    };
    auto g = [](int x) {
        if (x == 1) return 1;
        if (x == 2) return -1;
        if (x == 0) return 3;
        return -3;
    };  
    while (true) {
        if (k == 0) return make_pair(true, res);
        int idx = -1;
        for (int i : order) {
            if (abs(k) > abs(k - g(i)) && !f[i].empty()) {
                idx = i;
                break;
            }
        }
        if (idx != -1) {
            k -= g(idx);
            idx = *(f[idx].begin());
            res[idx] = ((res[idx] - 'A') ^ 1) + 'A';
            //cout << res << endl;
            update(idx);
            update(idx-1);
            update(idx+1);
            //cout << "update" << endl;
        } else {
            return make_pair(false, "");
        }
    }
    return make_pair(true, res);
}


int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int T;
    cin>>T;
    while (T--) {
        int n, k;
        cin>>n>>k;
        string s;
        cin>>s;
        bool ok = 0;
        for (int i = 0; i < 4; ++i) {
            auto q = solve(s, i / 2, i % 2, k, {0, 1, 3, 2});
            if (q.first) {
                ok = 1;
                cout << "YES\n";
                cout << q.second << '\n';
                break;
            }
            q = solve(s, i / 2, i % 2, k, {1, 0, 2, 3});
            if (q.first) {
                ok = 1;
                cout << "YES\n";
                cout << q.second << '\n';
                break;
            }
        }
        if (!ok) cout << "NO\n";
    }

    return 0;
}