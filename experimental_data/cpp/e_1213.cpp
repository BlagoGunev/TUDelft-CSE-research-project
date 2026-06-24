// ,---------------------------------------------------,
// |   christyap // christyyy_a // chiaro11 // chiaro  |
// '---------------------------------------------------'

#include <bits/stdc++.h>
#define sf scanf
#define pf printf
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define endl '\n'
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;

const int N = 15e4;
const int INF = 2e9;
const int MOD = 1e6;
const double PI = acos(-1);

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n;
    string s1, s2, ans = "abc", tmp;
    bool flag = 0;

    cin >> n >> s1 >> s2;

    do {
        tmp = ans + ans;
        if (tmp.find(s1) == -1 && tmp.find(s2) == -1) {
            flag = 1;
            break;
        }
    } while (next_permutation(ans.begin(), ans.end()));

    cout << "YES\n";
    if (flag) {
        for (int i = 0; i < n; ++i) cout << ans;
        cout << endl;
    } else {
        ans = "abc";
        do {
            tmp = "";
            for (int i = 0; i < 3; ++i) {
                tmp += ans[i];
                tmp += ans[i];
            }
            // cout << ans << " " << tmp << endl;
            if (tmp.find(s1) == -1 && tmp.find(s2) == -1) {
                flag = 1;
                break;
            }
        } while (next_permutation(ans.begin(), ans.end()));

        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << ans[i];
            }
        }
        cout << endl;
    }
    

    return 0;
}