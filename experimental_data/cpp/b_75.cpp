#include <bits/stdc++.h>

using namespace std;

//cout << setprecision(8) << fixed;
//

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define pii pair<int, int>
#define fi first
#define se second
#define ull uint64_t
#define ll int64_t

bool cmp(const pair<int, string> & a, const pair<int, string> & b) {
    return a.fi > b.fi || (a.fi == b.fi && a.se < b.se);
}

int main() {
    string me;
    cin >> me;
    int n;
    cin >> n;
    map<string, int> score;
    for (int i = 0; i < n; ++i) {
        string f, action, tmp, sec;
        cin >> f >> action;
        if (action != "likes") {
            cin >> tmp;
        }
        cin >> sec >> tmp;
        sec = sec.substr(0, sec.size() - 2);
        int sc = action == "posted" ? 15 : (action == "commented" ? 10 : 5);
        if (sec != me) score[sec];
        if (f != me) score[f];
        if (f == me) score[sec] += sc;
        else if (sec == me) score[f] += sc;
    }
    vector<pair<int, string>> names;
    for (auto i : score) {
        names.eb(i.se, i.fi);
    }
    sort(names.begin(), names.end(), cmp);
    for (auto i : names) cout << i.se << '\n';
    return 0;
}