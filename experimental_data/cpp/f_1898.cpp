#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pi = pair<ll,ll>;

ll n, m;
vector <vector<char>> v;
vector <vector<ll>> ho;
vector <vector<pair<pi, pi>>> vv;

bool CHEK(ll x, ll y) {
    return min(x, y) > -1 && x < n && y < m;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t, q, i, j, vx, vy, h, k, num;
    cin >> t;
    for (q = 0; q < t; q++) {
        cin >> n >> m;
        v.clear();
        ho.clear();
        vv.clear();
        vv.resize(n, vector <pair<pi,pi>> (m, {{-1, -1}, {-1, -1}}));
        v.resize(n, vector <char> (m));
        ho.resize(n, vector <ll> (m, 1e9));
        k = 0;
        for (i = 0; i < n; i++) for (j = 0; j < m; j++) {
            cin >> v[i][j];
            if (v[i][j] == 'V') vx = i, vy = j;
            if (v[i][j] == '.') k++;
        }
        ho[vx][vy] = 0;
        queue <ll> q;
        q.push(vx);
        q.push(vy);
        while (q.size()) {
            vx = q.front();
            q.pop();
            vy = q.front();
            q.pop();
            h = 1 + ho[vx][vy];
            if (CHEK(vx+1, vy) && ho[vx+1][vy] > h && v[vx+1][vy] == '.') {
                ho[vx+1][vy] = h;
                q.push(vx+1);
                q.push(vy);
            }
            if (CHEK(vx-1, vy) && ho[vx-1][vy] > h && v[vx-1][vy] == '.') {
                ho[vx-1][vy] = h;
                q.push(vx-1);
                q.push(vy);
            }
            if (CHEK(vx, vy+1) && ho[vx][vy+1] > h && v[vx][vy+1]=='.') {
                ho[vx][vy+1] = h;
                q.push(vx);
                q.push(vy+1);
            }
            if (CHEK(vx, vy-1) && ho[vx][vy-1] > h && v[vx][vy-1]=='.') {
                ho[vx][vy-1] = h;
                q.push(vx);
                q.push(vy-1);
            }
        }
        h = 0;
        for (i = 1; i < n; i++) {
            if (v[i][0] != '#' && ho[i][0] < 1e9) h++;
            if (v[i][m-1] != '#' && ho[i][m-1] < 1e9) h++;
        }
        for (j = 1; j < m; j++) {
            if (v[0][j] != '#' && ho[0][j] < 1e9) h++;
            if (v[n-1][j] != '#' && ho[n-1][j] < 1e9) h++;
        }
        if (h == 0) cout << k << '\n';
        else if (h == 1) {
            h = 1e9;
            for (i = 1; i < n; i++) {
                if (v[i][0] != '#') h=min(h, ho[i][0]);
                if (v[i][m-1] != '#') h=min(h, ho[i][m-1]);
            }
            for (j = 1; j < m; j++) {
                if (v[0][j] != '#') h=min(h, ho[0][j]);
                if (v[n-1][j] != '#') h=min(h, ho[n-1][j]);
            }
            cout << k-h << '\n';
        }
        else {
            queue <ll> qq;
            for (i = 1; i < n; i++) {
                if (v[i][0] != '#' && ho[i][0] < 1e9) {
                    qq.push(i);
                    qq.push(0);
                    qq.push(i*m);
                    vv[i][0].first = {0, i*m};
                }
                if (v[i][m-1] != '#' && ho[i][m-1] < 1e9) {
                    qq.push(i);
                    qq.push(m-1);
                    qq.push(i*m+m-1);
                    vv[i][m-1].first = {0, i*m+m-1};
                }
            }
            for (j = 1; j < m; j++) {
                if (v[0][j] != '#' && ho[0][j] < 1e9) {
                    qq.push(0);
                    qq.push(j);
                    qq.push(j);
                    vv[0][j].first = {0, j};
                }
                if (v[n-1][j] != '#' && ho[n-1][j] < 1e9) {
                    qq.push(n-1);
                    qq.push(j);
                    qq.push((n-1)*m+j);
                    vv[n-1][j].first = {0, (n-1)*m+j};
                }
            }
            while (qq.size()) {
                vx = qq.front();
                qq.pop();
                vy = qq.front();
                qq.pop();
                num = qq.front();
                qq.pop();
                if (vv[vx][vy].first.second == num) h = vv[vx][vy].first.first + 1;
                else h = vv[vx][vy].second.first + 1;
                if (CHEK(vx+1, vy) && v[vx+1][vy] != '#') {
                    if (vv[vx+1][vy].first.first == -1 && vv[vx+1][vy].second.second != num) {
                        qq.push(vx+1);
                        qq.push(vy);
                        qq.push(num);
                        vv[vx+1][vy].first = {h, num};
                    }
                    if (vv[vx+1][vy].second.first == -1 && vv[vx+1][vy].first.second != num) {
                        qq.push(vx+1);
                        qq.push(vy);
                        qq.push(num);
                        vv[vx+1][vy].second = {h, num};
                    }
                }
                if (CHEK(vx-1, vy) && v[vx-1][vy] != '#') {
                    if (vv[vx-1][vy].first.first == -1 && vv[vx-1][vy].second.second != num) {
                        qq.push(vx-1);
                        qq.push(vy);
                        qq.push(num);
                        vv[vx-1][vy].first = {h, num};
                    }
                    if (vv[vx-1][vy].second.first == -1 && vv[vx-1][vy].first.second != num) {
                        qq.push(vx-1);
                        qq.push(vy);
                        qq.push(num);
                        vv[vx-1][vy].second = {h, num};
                    }
                }
                if (CHEK(vx, vy+1) && v[vx][vy+1] != '#') {
                    if (vv[vx][vy+1].first.first == -1 && vv[vx][vy+1].second.second != num) {
                        qq.push(vx);
                        qq.push(vy+1);
                        qq.push(num);
                        vv[vx][vy+1].first = {h, num};
                    }
                    if (vv[vx][vy+1].second.first == -1 && vv[vx][vy+1].first.second != num) {
                        qq.push(vx);
                        qq.push(vy+1);
                        qq.push(num);
                        vv[vx][vy+1].second = {h, num};
                    }
                }
                if (CHEK(vx, vy-1) && v[vx][vy-1] != '#') {
                    if (vv[vx][vy-1].first.first == -1 && vv[vx][vy-1].second.second != num) {
                        qq.push(vx);
                        qq.push(vy-1);
                        qq.push(num);
                        vv[vx][vy-1].first = {h, num};
                    }
                    if (vv[vx][vy-1].second.first == -1 && vv[vx][vy-1].first.second != num) {
                        qq.push(vx);
                        qq.push(vy-1);
                        qq.push(num);
                        vv[vx][vy-1].second = {h, num};
                    }
                }
            }
            h = 1e9;
            for (i = 0; i < n; i++) {
                for (j = 0; j < m; j++) {
                    if (min(vv[i][j].first.first, vv[i][j].second.first) > -1) {
                        h = min(h, vv[i][j].first.first + vv[i][j].second.first + ho[i][j]);
                    }
                }
            }
            cout << k-h << '\n';
        }
    }
}