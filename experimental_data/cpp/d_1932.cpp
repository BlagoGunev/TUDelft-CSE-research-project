#include <bits/stdc++.h>
#include <list>
#define len(x) (int) x.size()
#define all(x) x.begin(), x.end()
#define ll long long
#define ull unsigned long long
#define ld long double
#define start time_t res1 = time(NULL)
#define finish              \
    time_t res2 = time(NULL); \
    cerr << res2 - res1 << '\n'
const long long mod1 = 1e9 + 7;
const long long mod2 = 998244353;
const long long MAXLL = 9223372036854775807;
const long long MAXINT = 2147483647;

using namespace std;

void print(vector<pair<int, int>> a);

void print(vector<int> a);

void print(vector<vector<int>> a);

void print(vector<ll> a);

void print(vector<vector<char>> a);

void print(vector<char> a);

#define mtask
// #define int ll

void solve() {
    int n;
    cin >> n;
    char c;
    cin >> c;
    map<char, vector<int>> mp;
    for(int i = 0; i < 2 * n; ++i){
        string s;
        cin >> s;
        mp[s[1]].push_back(s[0] - '0');
    }
    vector<pair<char, int>> nd;
    vector<vector<pair<char, int>>> ans;
    for(auto &x : mp){
        sort(all(x.second));
        if(x.first != c) {
            for (int i = 1; i < len(x.second); i += 2) {
                ans.push_back({{x.first, x.second[i - 1]},
                               {x.first, x.second[i]}});
            }
            if(len(x.second) & 1){
                nd.push_back({x.first, x.second[len(x.second) - 1]});
            }
        }
    }
    if(len(nd) > len(mp[c])){
        cout << "IMPOSSIBLE\n";
        return;
    }
    sort(all(mp[c]));
    for(int i = 0; i < len(nd); ++i){
        ans.push_back({nd[i], {c, mp[c][i]}});
    }
    for(int i = len(nd) + 1; i < len(mp[c]); i += 2){
        ans.push_back({{c, mp[c][i - 1]}, {c, mp[c][i]}});
    }
    for(auto x : ans){
        cout << x[0].second << x[0].first << ' ' << x[1].second << x[1].first << '\n';
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(40);
    srand(time(NULL));
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
#ifdef mtask
    int tt;
    cin >> tt;
    while (tt--)
#endif
    solve();
}

void print(vector<pair<int, int>> a) {
    for (int i = 0; i < len(a); ++i) {
        cout << a[i].first << ' ' << a[i].second << '\n';
    }
}

void print(vector<int> a) {
    for (int i = 0; i < len(a); ++i) {
        cout << a[i] << ' ';
    }
    cout << '\n';
}

void print(vector<vector<int>> a) {
    for (int i = 0; i < len(a); ++i) {
        print(a[i]);
    }
}

void print(vector<char> a) {
    for (int i = 0; i < len(a); ++i) {
        cout << a[i];
    }
    cout << '\n';
}

#ifndef int

void print(vector<ll> a) {
    for (int i = 0; i < len(a); ++i) {
        cout << a[i] << ' ';
    }
    cout << '\n';
}

#endif

void print(vector<vector<char> > a) {
    for (int i = 0; i < len(a); ++i) {
        print(a[i]);
    }
}