#include <bits/stdc++.h>
#include <string>

using namespace std;

typedef long long ll;

#define f first
#define s second
#define pb push_back
#define mp make_pair

/*

ll bin_pow(ll x, ll e, ll mod) {
    ll res = 1;
    while(e) {
        if(e & 1) res = res * x % mod;
        e >>= 1;
        x = x * x % mod;
    }
    return res;
}

*/

int n, l, r;
set<pair<int,int>> comp;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("out.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    cin >> n;
    while(n--) {
        cin >> l >> r;
        vector<pair<int,int>> inter;
        auto it = comp.lower_bound(mp(l, -1));
        if(it != comp.begin()) --it;
        int intr = 0;
        while(it != comp.end() && intr < 2) {
            pair<int,int> x = *it;
            if(x.f > r || x.s < l) intr++;
            else inter.pb(x);
            ++it;
        }
        int min_l = l, max_r = r;
        for(auto g : inter) {
            min_l = min(min_l, g.f);
            max_r = max(max_r, g.s);
            comp.erase(g);
        }
        comp.insert(mp(min_l, max_r));
        cout << comp.size() << ' ';
    }
    return 0;
}