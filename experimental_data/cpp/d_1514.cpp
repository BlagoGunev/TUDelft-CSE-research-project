#include <bits/stdc++.h>



using namespace std;

typedef long long ll;

typedef pair<int, int> PII;



int main() {

    ios::sync_with_stdio(false);

    cin.tie(nullptr);



    int n, q;

    cin >> n >> q;

    vector<int> a(n);

    for (int i = 0; i < n; i++) {

        cin >> a[i];

        a[i]--;

    }

    vector<array<int, 3>> que(q);

    for (int i = 0; i < q; i++) {

        int l, r;

        cin >> l >> r;

        l--, r--;

        que[i] = {l, r, i};

    }

    int B = sqrt(n);

    sort(que.begin(), que.end(), [&](array<int, 3> &a, array<int, 3> &b){

        if (a[0] / B != b[0] / B) return a[0] < b[0];

        return a[1] < b[1];

    });

    int i = 0, j = 0;

    vector<int> ans(q);

    while (i < q) {

        vector<int> cnt(n);

        while (j < q and que[i][0] / B == que[j][0] / B) j++;

        int right = que[i][0] / B * B + B - 1;

        int res = 0;

        auto add = [&](int x) {

            cnt[x]++;

            res = max(res, cnt[x]);

        };

        while (i < j and que[i][0] / B == que[i][1] / B) {

            auto [l, r, id] = que[i];

            int res = 0;

            for (int k = l; k <= r; k++) {

                cnt[a[k]]++;

                res = max(res, cnt[a[k]]);

            }

            int len = r - l + 1;

            ans[id] = max(1, 2 * res - len);

            for (int k = l; k <= r; k++) {

                cnt[a[k]]--;

            }

            i++;

        }

        int L = right + 1, R = right;

        while (i < j) {

            auto [l, r, id] = que[i];

            while (R < r) add(a[++R]);

            int bres = res;

            int len = r - l + 1;

            while (L > l) add(a[--L]);

            ans[id] = max(1, 2 * res - len);

            while (L < right + 1) cnt[a[L++]]--;

            res = bres;

            i++;

        }

    }

    for (int i = 0; i < q; i++) {

        cout << ans[i] << '\n';

    }

    return 0;

}