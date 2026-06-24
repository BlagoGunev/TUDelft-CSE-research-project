#include <bits/stdc++.h>
#define times clock() * 1.0 / CLOCKS_PER_SEC
#define pi 3.1415926535897932384626433832795
#define cntbit(x) __builtin_popcount(x)
//#define double long double
//#define int long long
#define all(x) x.begin(), x.end()
#define x1 lolkekmem
#define y1 kekmemlol
#define STRESS

// oxxxy vseravno pobedil

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int NMAX = 30;
bool used[NMAX][NMAX];

vector<int> g[NMAX];

int color[NMAX];

void dfs(int v) {
    color[v] = 1;
    for (auto t : g[v]) {
        if (color[t] == 1) {
            cout << "NO";
            exit(0);
        }
        if (color[t] == 0) {
            dfs(t);
        }
    }
    color[v] = 2;
}

string push = "";
void dfsbuild(int v) {
    push += static_cast<char>(v + 'a');
    for (auto t : g[v]) {
        dfsbuild(t);
    }
}


int main() {
    srand((unsigned int) time(NULL));
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#if __APPLE__
    freopen("/Users/macbook/ClionProjects/untitled1/a.in", "r", stdin);
    freopen("/Users/macbook/ClionProjects/untitled1/a.out", "w", stdout);
#else
    //    freopen("cinema.in", "r", stdin);
    //    freopen("cinema.out", "w", stdout);
#endif
    int n;
    cin >> n;
    unordered_set<char> us;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        us.insert(s[0]);
        for (int j = 1; j < s.length(); j++) {
            us.insert(s[j]);
            if (!used[s[j - 1] - 'a'][s[j] - 'a']) {
                used[s[j - 1] - 'a'][s[j] - 'a'] = 1;
                g[s[j - 1] - 'a'].push_back(s[j] - 'a');
            }
        }
    }
    for (int i = 0; i < NMAX; i++) {
        int cnt = 0;
        for (int j = 0; j < NMAX; j++) {
            if (used[j][i]) {
                cnt++;
            }
        }
        if (cnt > 1) {
            cout << "NO";
            return 0;
        }
    }
    for (int i = 0; i < NMAX; i++) {
        if (g[i].size() > 1) {
            cout << "NO";
            return 0;
        }
    }
    for (int i = 0; i < NMAX; i++) {
        if (color[i] == 0) {
            dfs(i);
        }
    }
    vector<string> ans;
    for (int i = 0; i < NMAX; i++) {
        bool bad = false;
        for (int j = 0; j < NMAX; j++) {
            if (used[j][i]) {
                bad = true;
                break;
            }
        }
        if (!bad && us.find(static_cast<char>(i + 'a')) != us.end()) {
            push = "";
            dfsbuild(i);
            ans.push_back(push);
        }
    }
    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i];
    }
    cout << endl;

}