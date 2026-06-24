#include <bits/stdc++.h>
using namespace std;

#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

pair<int, int> point[4];

void solve() {
    for (int i = 1; i <= 3; i++)
        cin >> point[i].first >> point[i].second;
    int S = 1;
    if (point[1].first <= point[2].first && point[2].first <= point[3].first) {
        S += point[2].first - point[1].first;
    }
    if (point[1].first <= point[3].first && point[3].first <= point[2].first && point[2].first != point[3].first) {
        S += point[3].first - point[1].first;
    }
    if (point[1].first >= point[2].first && point[2].first >= point[3].first) {
        S += abs(point[2].first - point[1].first);
    }
    if (point[1].first >= point[3].first && point[3].first >= point[2].first && point[3].first != point[2].first) {
        S += abs(point[3].first - point[1].first);
    }
    if (point[1].second <= point[2].second && point[2].second <= point[3].second) {
        S += point[2].second - point[1].second;
    }
    if (point[1].second <= point[3].second && point[3].second <= point[2].second && point[2].second != point[3].second) {
        S += point[3].second - point[1].second;
    }
    if (point[1].second >= point[2].second && point[2].second >= point[3].second) {
        S += abs(point[2].second - point[1].second);
    }
    if (point[1].second >= point[3].second && point[3].second >= point[2].second && point[2].second != point[3].second) {
        S += abs(point[3].second - point[1].second);
    }
    cout << S << '\n';
}

int main() {
    fast
    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}