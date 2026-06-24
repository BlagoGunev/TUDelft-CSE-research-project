#include <stdio.h>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <string>
#include <string.h>
using namespace std;
typedef long long num;
#define rep(i, l, r) for (int i = l; i < r; ++i)
const int BigInt = 2000 * 1000 * 1000;

const int maxn = 100200;

int n;
string ss[maxn];

inline int code(const string& s) {
    int counts[26];
    memset(counts, 0, sizeof(counts));
    for (char c : s)
        counts[c - 'a']++;

    int res = 0;
    for (int i = 0; i < 26; i++)
        res |= ((counts[i] % 2 == 1) << i);

    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen(".txt", "r", stdin);

    map<int, int> counts;

    cin >> n;
    rep (i, 0, n) {
        cin >> ss[i];
        //cout << ss[i] << ": " << code(ss[i]) << endl;
        counts[code(ss[i])]++;
    }

    num res = 0;

    for (auto [c, count] : counts) {
        res += count * (count - 1ll) / 2;

        for (int i = 0; i < 26; i++) {
            if (c & (1 << i)) {
                int inv = c ^ (1 << i);
                
                auto it = counts.find(inv);
                if (it != counts.end()) {
                    res += count * (num)it->second;
                }
            }
        }
    }

    cout << res << endl;

    return 0;
}