#include <bits/stdc++.h>



using namespace std;

typedef long long ll;

typedef pair<int, int> PII;



int main() {

    ios::sync_with_stdio(false);

    cin.tie(nullptr);



    string s;

    cin >> s;

    int x, y;

    cin >> x >> y;

    if (x > y) {

        swap(x, y);

        for (int j = 0; j < s.size(); j++) {

            if (s[j] != '?') {

                s[j] = '0' + '1' - s[j];

            }

        }

    }

    vector<int> cnt(3);

    ll res = 0;

    for (int i = 0; i < s.size(); i++) {

        if (s[i] == '0') {

            cnt[0]++;

            res += (ll)(cnt[2] + cnt[1]) * y;

        } else if (s[i] == '1') {

            cnt[1]++;

            res += (ll)cnt[0] * x;

        } else {

            cnt[2]++;

            res += (ll)cnt[0] * x;

        }

    }

    vector<int> cur(3);

    ll ans = res;

    for (int i = 0; i < s.size(); i++) {

        if (s[i] == '0') {

            cur[0]++;

        } else if (s[i] == '1') {

            cur[1]++;

        } else {

            cur[2]++;

            res = res + ((ll)cur[1] * y) + (ll)(cnt[1] - cur[1] + cnt[2] - cur[2]) * x - (ll)(cur[0] + cur[2] - 1) * x - (ll)(cnt[0] - cur[0]) * y;

        }

        ans = min(ans, res);

    }

    cout << ans << '\n';

    return 0;

}