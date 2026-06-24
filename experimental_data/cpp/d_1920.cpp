#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 7;
const long long llINF = 1e18 + 7;

void testcase() {
    int n, q;
    cin >> n >> q;

    vector <int> b(n + 1), x(n + 1);
    vector <long long> sub;
    sub.push_back(0ll);

    long long sz = 0;
    for (int i = 1; i <= n; i++) {
        cin >> b[i] >> x[i];

        if (b[i] == 1) sz++;
        else if (b[i] == 2) {
            sub.push_back(sz);

            x[i]++;
            if (sz >= 2e18 / x[i]) sz = 2e18;
            else sz *= x[i];

        }
    }

    vector <int> ans(q + 1);
    priority_queue <pair <long long, int>> ask;
    for (int i = 1; i <= q; i++) {
        long long k;
        cin >> k;

        ask.emplace(k, i);
    }

    // cout << "sub : ";
    // for (auto v : sub) cout << v << ' ';
    // cout << '\n';

    for (int i = n; i >= 1; i--) {
        if (b[i] == 1) {
            while (!ask.empty() and ask.top().first == sz) {
                ans[ask.top().second] = x[i];
                ask.pop();
            }
            sz--;
        }
        else if (b[i] == 2) {
            sz = sub.back();
            sub.pop_back();

            while (!ask.empty() and ask.top().first > sz) {
                ask.emplace((ask.top().first - 1) % sz + 1, ask.top().second);
                ask.pop();
            }
        }
    }

    for (int i = 1; i <= q; i++) cout << ans[i] << ' ';
    cout << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int t = 1;
    cin >> t;

    while (t--) testcase();
    return 0;
}