#include <bits/stdc++.h>

using std::ios_base;
using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::fixed;
using std::getline;

using std::vector;
using std::string;
using std::stack;
using std::queue;
using std::deque;
using std::map;
using std::set;
using std::unordered_map;
using std::unordered_set;

using std::sort;
using std::reverse;
using std::nth_element;

#define pb push_back
#define mp make_pair
#define all(x) x.begin, x.end()

const int MAXN = 300005;
const int INF = 1e9;
const int MOD = 1e9+7;
const int64_t L_INF = 4e18;

int next[26][MAXN], NEXT_FREE = 1;
int weight[MAXN];
bool is_leaf[MAXN];

void update(const string &s) {
    int node = 0;
    weight[node]++;
    for (char c : s) {
        c -= 'a';
        node = next[(int) c][node];
        weight[node]++;
    }
    is_leaf[node] = true;
}

int add(const string &s) {
    int cnt1 = 0, cnt2 = 0, found_leaf = false;
    
    int node = 0;
    for (char c : s) {
        c -= 'a';
        if (next[(int) c][node] == 0) {
            next[(int) c][node] = NEXT_FREE++;
        }
        node = next[(int) c][node];
        
        cnt1++;
        if (weight[node] == 1) {
            cnt2++;
            if (is_leaf[node]) {
                found_leaf = true;
            }
        }
    }
    if (!is_leaf[node]) {
        update(s);
    }

    if (found_leaf) {
        cnt1 -= std::max(0, cnt2 - 2);
    }
    return cnt1;
}


int split(vector<string> &res, const string &text) {
    int cnt = 0;
    bool is_new = true;
    for (char c : text) {
        if (isalpha(c)) {
            if (is_new) {
                is_new = false;
                res.pb("");
            }
            res.back().pb(c);
        } else {
            cnt++;
            is_new = true;
        }
    }
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;

    string text;
    int ans = 0;
    while (getline(cin, text)) {
        vector<string> results;
        ans += split(results, text);
        for (string &word : results) {
            ans += add(word);
        }
        ans++;
    }
    cout << ans;

    #ifdef LOCAL
        cerr << "\n== " << 1.0 * clock() / CLOCKS_PER_SEC << " sec.\n";
    #endif
    return 0;
}