#include <bits/stdc++.h>
using namespace std;

void doRoutine() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

#define int int64_t

map<pair<string, string>, int> cnt;

void add(string a, string b, int d) {
    if (a > b) {
        swap(a, b);
    }
    cnt[{a, b}] += d;
}

#define DPC 11
signed main() {
#if DPC == 1
    freopen("C:\\Users\\lkmak\\user\\alg\\codeforces\\acm\\input.txt", "r", stdin);
    freopen("C:\\Users\\lkmak\\user\\alg\\codeforces\\acm\\output.txt", "w", stdout);
#endif
    doRoutine();

    int n, a, b, k, f;
    cin >> n >> a >> b >> k >> f;

    string s0, t0, s, t;
    cin >> s0 >> t0;
    add(s0, t0, a);

    while (cin >> s >> t) {
        if (s == t0) {
            add(s, t, b);
        }
        else {
            add(s, t, a);
        }
        s0 = s;
        t0 = t;
    }

    vector<int> arr;
    for (auto pr : cnt) {
        arr.push_back(pr.second);
    }

    sort(arr.rbegin(), arr.rend());
    int ans = 0;
    for (int i = 0; i < arr.size(); ++i) {
        if (i < k && arr[i] > f) {
            ans += f;
        }
        else {
            ans += arr[i];
        }
    }

    cout << ans << endl;

    return 0;
}