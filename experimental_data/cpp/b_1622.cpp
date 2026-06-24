#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<ii> vii;
#define endl '\n'
#define fi first
#define se second
#define mp make_pair
#define debug(x) cout << #x << ": " << x << endl;
#define vname(x) cout << #x << ": " << endl;

void debugv(int arr_print[]) {
    int x = sizeof(arr_print) / sizeof(arr_print[0]);
    for (int c = 0; c < x; ++c) {
        cout << arr_print[c] << " ";
    }
    cout << endl;
}

void debugv(int arr_print[], int x) {
    for (int c = 0; c < x; ++c) {
        cout << arr_print[c] << " ";
    }
    cout << endl;
}

void debugv(vector<int> &arr_print) {
    for (int c: arr_print) {
        cout << c << " ";
    }
    cout << endl;
}

void debugv(vector<long long> &arr_print) {
    for (long long c: arr_print) {
        cout << c << " ";
    }
    cout << endl;
}

void debugv(vector<int> &v_print, int x) {
    for (int c = 0; c < x; ++c) {
        cout << v_print[c] << " ";
    }
    cout << endl;
}

void debugv(vector<vector<int>> &v_print) {
    int x = v_print.size();
    int y = 0;
    if (!v_print.empty()) {
        y = v_print[0].size();
    }
    for (int c1 = 0; c1 < x; ++c1) {
        y = v_print[c1].size();
        for (int c2 = 0; c2 < y; ++c2) {
            cout << v_print[c1][c2] << " ";
        }
        cout << endl;
    }
}

void debugv(vector<pair<int, int>> &v_print) {
    int x = v_print.size();
    for (int c = 0; c < x; ++c) {
        cout << v_print[c].first << " " << v_print[c].second << endl;
    }
}

void debugv(vector<pair<int, int>> &v_print, int x) {
    for (int c = 0; c < x; ++c) {
        cout << v_print[c].first << " " << v_print[c].second << endl;
    }
}

void debugv(pair<int, int> v_print[], int x) {
    for (int c = 0; c < x; ++c) {
        cout << v_print[c].first << " " << v_print[c].second << endl;
    }
}

void debugv(vector<vector<int>> &v_print, int x, int y) {
    for (int c1 = 0; c1 < x; ++c1) {
        for (int c2 = 0; c2 < y; ++c2) {
            cout << v_print[c1][c2] << " ";
        }
        cout << endl;
    }
}

template<typename TwoD>
void debugv(TwoD &v_print, int x, int y) {
    for (int c1 = 0; c1 < x; ++c1) {
        for (int c2 = 0; c2 < y; ++c2) {
            cout << v_print[c1][c2] << " ";
        }
        cout << endl;
    }
}

void debugv(unordered_map<int, int> &v_print) {
    for (auto &e: v_print) {
        cout << e.first << ": " << e.second << endl;
    }
}

void debugv(unordered_set<int> &v_print) {
    for (int e: v_print) {
        cout << e << " ";
    }
    cout << endl;
}

void debugv(multiset<int> &v_print) {
    for (int e: v_print) {
        cout << e << " ";
    }
    cout << endl;
}

int n;
const int N = 2e5 + 7;
int p[N], q[N], in[N];
string s;

void solve_each(int test_case) {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
        in[p[i]] = i;
    }
    cin >> s;
    s = " " + s;
    int cur = n;
    for (int i = n; i >= 1 && cur >= 1; --i) {
        if (s[in[i]] == '1') {
            q[in[i]] = cur;
            cur--;
        }
    }
    for (int i = n; i >= 1 && cur >= 1; --i) {
        if (s[in[i]] == '0') {
            q[in[i]] = cur;
            cur--;
        }
    }
    for (int i = 1; i <= n; ++i) {
        cout << q[i] << " ";
    }
    cout << endl;


}

void solve() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int test;
    cin >> test;
    for (int test_case = 1; test_case <= test; ++test_case) {
        solve_each(test_case);
    }
//    cout << fixed << setprecision(2);
}

int main() {
    solve();
    return 0;
}