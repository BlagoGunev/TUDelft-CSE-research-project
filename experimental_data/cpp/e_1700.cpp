#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n, m;

void recalc(ll i, ll j, vector<vector<ll>>& a, vector<vector<ll>>& b, ll& x) {

    x -= (b[i][j] == 0);

    b[i][j] = 0;

    if (i > 0 && a[i - 1][j] < a[i][j]) ++b[i][j];

    if (i < n - 1 && a[i + 1][j] < a[i][j]) ++b[i][j];

    if (j > 0 && a[i][j - 1] < a[i][j]) ++b[i][j];

    if (j < m - 1 && a[i][j + 1] < a[i][j]) ++b[i][j];

    if (a[i][j] == 1) b[i][j] = 4;

    x += (b[i][j] == 0);

}

int main() {

    ios_base::sync_with_stdio(false);

    cin.tie();

    cin >> n >> m;

    vector<vector<ll>> a(n, vector<ll>(m)), b(n, vector<ll>(m, 0));

    for (ll i = 0; i < n; ++i) {

        for (ll j = 0; j < m; ++j) cin >> a[i][j];

    }

    ll x = 0;

    vector<pair<ll, ll>> v, z;

    for (ll i = 0; i < n; ++i) {

        for (ll j = 0; j < m; ++j) {

            if (i > 0 && a[i - 1][j] < a[i][j]) ++b[i][j];

            if (i < n - 1 && a[i + 1][j] < a[i][j]) ++b[i][j];

            if (j > 0 && a[i][j - 1] < a[i][j]) ++b[i][j];

            if (j < m - 1 && a[i][j + 1] < a[i][j]) ++b[i][j];

            if (a[i][j] == 1) b[i][j] = 4;

            x += (b[i][j] == 0 && a[i][j] != 1);

            if (b[i][j] == 0 && a[i][j] != 1) {

                z.push_back({i, j});

                for (ll i1 = i - 2; i1 < i + 3; ++i1) {

                    for (ll j1 = j - 2; j1 < j + 3; ++j1) {

                        if (i1 >= 0 && i1 < n && j1 >= 0 && j1 < m && abs(i1 - i) + abs(j1 - j) < 3) v.push_back({i1, j1});

                    }

                }

            }

        }

    }

    sort(v.begin(), v.end());

    set<vector<ll>> s;

    if (x == 0) cout << 0;

    else if (x > 1) {

        if (v.size() > 500) return cout << 2, 0;

        for (ll i = 0; i < (ll)v.size(); ++i) {

            for (ll j = i + 1; j < (ll)v.size(); ++j) {

                if (v[i] == v[j] || (i && v[i] == v[i - 1]) || v[j] == v[j - 1]) continue;

                ll i1 = v[i].first, j1 = v[i].second, i2 = v[j].first, j2 = v[j].second;

                swap(a[i1][j1], a[i2][j2]);

                ll i3 = i1, j3 = j1;

                if (i3 >= 0 && i3 < n && j3 >= 0 && j3 < m) recalc(i3, j3, a, b, x);

                i3 = i1 - 1, j3 = j1;

                if (i3 >= 0 && i3 < n && j3 >= 0 && j3 < m) recalc(i3, j3, a, b, x);

                i3 = i1 + 1, j3 = j1;

                if (i3 >= 0 && i3 < n && j3 >= 0 && j3 < m) recalc(i3, j3, a, b, x);

                i3 = i1, j3 = j1 - 1;

                if (i3 >= 0 && i3 < n && j3 >= 0 && j3 < m) recalc(i3, j3, a, b, x);

                i3 = i1, j3 = j1 + 1;

                if (i3 >= 0 && i3 < n && j3 >= 0 && j3 < m) recalc(i3, j3, a, b, x);

                i3 = i2, j3 = j2;

                if (i3 >= 0 && i3 < n && j3 >= 0 && j3 < m) recalc(i3, j3, a, b, x);

                i3 = i2 - 1, j3 = j2;

                if (i3 >= 0 && i3 < n && j3 >= 0 && j3 < m) recalc(i3, j3, a, b, x);

                i3 = i2 + 1, j3 = j2;

                if (i3 >= 0 && i3 < n && j3 >= 0 && j3 < m) recalc(i3, j3, a, b, x);

                i3 = i2, j3 = j2 - 1;

                if (i3 >= 0 && i3 < n && j3 >= 0 && j3 < m) recalc(i3, j3, a, b, x);

                i3 = i2, j3 = j2 + 1;

                if (i3 >= 0 && i3 < n && j3 >= 0 && j3 < m) recalc(i3, j3, a, b, x);

                if (x == 0) {

                    if (pair<ll, ll>{i1, j1} < pair<ll, ll>{i2, j2}) s.insert({i1, j1, i2, j2});

                    else s.insert({i2, j2, i1, j1});

                }

                swap(a[i1][j1], a[i2][j2]);

                i3 = i1, j3 = j1;

                if (i3 >= 0 && i3 < n && j3 >= 0 && j3 < m) recalc(i3, j3, a, b, x);

                i3 = i1 - 1, j3 = j1;

                if (i3 >= 0 && i3 < n && j3 >= 0 && j3 < m) recalc(i3, j3, a, b, x);

                i3 = i1 + 1, j3 = j1;

                if (i3 >= 0 && i3 < n && j3 >= 0 && j3 < m) recalc(i3, j3, a, b, x);

                i3 = i1, j3 = j1 - 1;

                if (i3 >= 0 && i3 < n && j3 >= 0 && j3 < m) recalc(i3, j3, a, b, x);

                i3 = i1, j3 = j1 + 1;

                if (i3 >= 0 && i3 < n && j3 >= 0 && j3 < m) recalc(i3, j3, a, b, x);

                i3 = i2, j3 = j2;

                if (i3 >= 0 && i3 < n && j3 >= 0 && j3 < m) recalc(i3, j3, a, b, x);

                i3 = i2 - 1, j3 = j2;

                if (i3 >= 0 && i3 < n && j3 >= 0 && j3 < m) recalc(i3, j3, a, b, x);

                i3 = i2 + 1, j3 = j2;

                if (i3 >= 0 && i3 < n && j3 >= 0 && j3 < m) recalc(i3, j3, a, b, x);

                i3 = i2, j3 = j2 - 1;

                if (i3 >= 0 && i3 < n && j3 >= 0 && j3 < m) recalc(i3, j3, a, b, x);

                i3 = i2, j3 = j2 + 1;

                if (i3 >= 0 && i3 < n && j3 >= 0 && j3 < m) recalc(i3, j3, a, b, x);

            }

        }

        if (s.size()) cout << "1 " << s.size();

        else cout << 2;

    } else {

        ll i = z[0].first, j = z[0].second;

        for (ll i1 = i - 1; i1 < i + 2; ++i1) {

            for (ll j1 = j - 1; j1 < j + 2; ++j1) {

                if (i1 >= 0 && i1 < n && j1 >= 0 && j1 < m && abs(i1 - i) + abs(j1 - j) < 2) {

                    for (ll i2 = 0; i2 < n; ++i2) {

                        for (ll j2 = 0; j2 < m; ++j2) {

                            if (i1 == i2 && j1 == j2) continue;

                            swap(a[i1][j1], a[i2][j2]);

                            ll i3 = i1, j3 = j1;

                            if (i3 >= 0 && i3 < n && j3 >= 0 && j3 < m) recalc(i3, j3, a, b, x);

                            i3 = i1 - 1, j3 = j1;

                            if (i3 >= 0 && i3 < n && j3 >= 0 && j3 < m) recalc(i3, j3, a, b, x);

                            i3 = i1 + 1, j3 = j1;

                            if (i3 >= 0 && i3 < n && j3 >= 0 && j3 < m) recalc(i3, j3, a, b, x);

                            i3 = i1, j3 = j1 - 1;

                            if (i3 >= 0 && i3 < n && j3 >= 0 && j3 < m) recalc(i3, j3, a, b, x);

                            i3 = i1, j3 = j1 + 1;

                            if (i3 >= 0 && i3 < n && j3 >= 0 && j3 < m) recalc(i3, j3, a, b, x);

                            i3 = i2, j3 = j2;

                            if (i3 >= 0 && i3 < n && j3 >= 0 && j3 < m) recalc(i3, j3, a, b, x);

                            i3 = i2 - 1, j3 = j2;

                            if (i3 >= 0 && i3 < n && j3 >= 0 && j3 < m) recalc(i3, j3, a, b, x);

                            i3 = i2 + 1, j3 = j2;

                            if (i3 >= 0 && i3 < n && j3 >= 0 && j3 < m) recalc(i3, j3, a, b, x);

                            i3 = i2, j3 = j2 - 1;

                            if (i3 >= 0 && i3 < n && j3 >= 0 && j3 < m) recalc(i3, j3, a, b, x);

                            i3 = i2, j3 = j2 + 1;

                            if (i3 >= 0 && i3 < n && j3 >= 0 && j3 < m) recalc(i3, j3, a, b, x);

                            if (x == 0) {

                                if (pair<ll, ll>{i1, j1} < pair<ll, ll>{i2, j2}) s.insert({i1, j1, i2, j2});

                                else s.insert({i2, j2, i1, j1});

                            }

                            swap(a[i1][j1], a[i2][j2]);

                            i3 = i1, j3 = j1;

                            if (i3 >= 0 && i3 < n && j3 >= 0 && j3 < m) recalc(i3, j3, a, b, x);

                            i3 = i1 - 1, j3 = j1;

                            if (i3 >= 0 && i3 < n && j3 >= 0 && j3 < m) recalc(i3, j3, a, b, x);

                            i3 = i1 + 1, j3 = j1;

                            if (i3 >= 0 && i3 < n && j3 >= 0 && j3 < m) recalc(i3, j3, a, b, x);

                            i3 = i1, j3 = j1 - 1;

                            if (i3 >= 0 && i3 < n && j3 >= 0 && j3 < m) recalc(i3, j3, a, b, x);

                            i3 = i1, j3 = j1 + 1;

                            if (i3 >= 0 && i3 < n && j3 >= 0 && j3 < m) recalc(i3, j3, a, b, x);

                            i3 = i2, j3 = j2;

                            if (i3 >= 0 && i3 < n && j3 >= 0 && j3 < m) recalc(i3, j3, a, b, x);

                            i3 = i2 - 1, j3 = j2;

                            if (i3 >= 0 && i3 < n && j3 >= 0 && j3 < m) recalc(i3, j3, a, b, x);

                            i3 = i2 + 1, j3 = j2;

                            if (i3 >= 0 && i3 < n && j3 >= 0 && j3 < m) recalc(i3, j3, a, b, x);

                            i3 = i2, j3 = j2 - 1;

                            if (i3 >= 0 && i3 < n && j3 >= 0 && j3 < m) recalc(i3, j3, a, b, x);

                            i3 = i2, j3 = j2 + 1;

                            if (i3 >= 0 && i3 < n && j3 >= 0 && j3 < m) recalc(i3, j3, a, b, x);

                        }

                    }

                }

            }

        }

        if (s.size()) cout << "1 " << s.size();

        else cout << 2;

    }

}