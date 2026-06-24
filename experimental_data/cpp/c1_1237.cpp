#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <string>
#include <queue>

using namespace std;

#define sz(a) static_cast<int>((a).size())
#define f first
#define s second
#define els(v) for (auto &el : (v))


#ifdef KIRYA
#define dbg(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
#define dbg(...)
#endif

template<typename T>
void _dbg(const char* _s, T _h) {
    cerr << _s << " = " << _h << "\n";
}

template<typename T, typename... Ts>
void _dbg(const char*_s, T _h, Ts... _t) {
    int _b = 0;

    while (((_b += *_s == '(') -= *_s == ')') != 0 || *_s != ',')
        cerr << *_s++;

    cerr << " = " << _h << ",";
    _dbg(_s + 1, _t...);
}

const int64_t INF = static_cast<int64_t>(1e9) + 7;
const int64_t LINF = INF * INF;
const int MAXN = static_cast<int>(1e6) + 17;

struct asda {
    int x, y, z;
};

pair<int, int> op(int a, int b) {
    return {min(a, b), max(a, b)};
}

void solve() {
    int n;
    cin >> n;
    map<pair<int, int>, vector<pair<int, int>>> um;
    for (int i = 0; i < n; ++i) {
        int x, y, z;
        cin >> x >> y >> z;
        um[pair<int, int>{x, y}].push_back({z, i + 1});
    }
    vector<pair<int, int>> res;
    res.reserve(n);
    map<int, vector<pair<int, int>>> rem;
    auto it = um.rbegin();
    for (; it != um.rend(); ++it) {
        auto &vec = it->second;
        sort(vec.begin(), vec.end());
    
        for (int i = vec.size() - 1; i > 0; i -= 2) {
            res.push_back({vec[i].second, vec[i - 1].second});
        }
        if (vec.size() % 2 == 1) {
            rem[it->first.first].push_back({it->first.second, vec[0].second});
        }
    }
    auto nit = rem.rbegin();
    std::vector<int> new_rem;
    for (; nit != rem.rend(); ++nit) {
        auto &vec = nit->second;
        sort(vec.begin(), vec.end());
    
        for (int i = vec.size() - 1; i > 0; i -= 2) {
            res.push_back({vec[i].second, vec[i - 1].second});
        }
        if (vec.size() % 2 == 1) {
            new_rem.push_back(vec[0].second);
        }
    }
    els(res) {
        cout << el.first << ' ' << el.second << '\n';
    }
    
    for (int i = 0; i < new_rem.size(); i += 2) {
        cout << new_rem[i] << ' ' << new_rem[i + 1] << '\n';
    }
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int q = 1;

    for (int i = 0; i < q; ++i) {
        solve();
    }
}