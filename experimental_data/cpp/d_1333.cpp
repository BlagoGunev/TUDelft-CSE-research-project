#include <bits/stdc++.h>

#define io ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define ll long long
#define ull unsigned long long
#define pii pair<ll, ll>
#define piii pair<pair<ll, ll>, ll>

using namespace std;
const int N = 200005;
ll t, n, m, k, a, b, x, y, ans, arr[N];
string s;
ll mod = 998244353;

/*
ll solve(ll sum) {
    unordered_map<ll, ll> prevSum;
    ll res = 0;
    ll currsum = 0;
    for (int i = 0; i < n; i++) {
        currsum += arr[i];
        if (currsum == sum)
            res++;
        if (prevSum.find(currsum - sum) != prevSum.end())
            res += (prevSum[currsum - sum]);
        prevSum[currsum]++;
    }
    return res;
}
*/

vector<vector<int>> anss;
int tot;
bool stop;

void solve() {
    string ret = "";
    vector<int> cur;
    for (int i = 0; i < n;) {
        if (i + 1 < n && s[i] == 'R' && s[i + 1] == 'L') {
            swap(s[i], s[i + 1]);
            cur.push_back(i + 1);
            ++tot;
            i += 2;
        }
        else {
            ++i;
        }
    }
    if (cur.size() == 0) {
        stop = true;
        return;
    }
    anss.push_back(cur);
}

int main() {
//    io;
    t = 1;
//    cin >> t;
    while (t--) {
        // I was born to be a fuckin' stupid piece of shit.
        scanf("%lld %lld", &n, &k);
        cin >> s;
        while (!stop) {
            solve();
        }
        if (tot < k || anss.size() > k) {
            cout << -1 << endl;
            continue;
        }
        if (anss.size() == k) {
            for (auto &x : anss) {
                printf("%d", (int) x.size());
                for (auto &y : x)
                    printf(" %d", y);
                printf("\n");
            }
            continue;
        }
        if (tot == k) {
            for (auto &x : anss) {
                for (auto &y : x)
                    printf("1 %d\n", y);
            }
            continue;
        }
        int should = k;
        for (int i = 0; i < anss.size(); ++i) {
            if (tot - anss[i].size() < should - 1) {
                int now = should - tot + anss[i].size();
                int cur = anss[i].size() - now + 1;
                printf("%d", cur);
                for (int j = 0; j < cur; ++j)
                    printf(" %d", anss[i][j]);
                printf("\n");
                for (int j = cur; j < anss[i].size(); ++j)
                    printf("1 %d\n", anss[i][j]);
                for (int x = i + 1; x < anss.size(); ++x) {
                    for (auto &y : anss[x])
                        printf("1 %d\n", y);
                }
                break;
            }
            printf("%d", (int) anss[i].size());
            for (auto &y : anss[i])
                printf(" %d", y);
            printf("\n");
            --should;
            tot -= anss[i].size();
        }
    }
    return 0;
}
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);