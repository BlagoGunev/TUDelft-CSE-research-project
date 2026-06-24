// I'm a paragraph. Click here to add your own text and edit me. It’s easy. 

// Just click “Edit Text” or double click me to add your own content 

// and make changes to the font. Feel free to drag and drop me anywhere 

// you like on your page. I’m a great place for you to tell a story 

// and let your users know a little more about you.



#include <bits/stdc++.h>

using namespace std;

#define filename ""



#define sz(x) ((int) size(x))

#define all(x) begin(x), end(x)

#define rep(i, a, b) for(int i = a; i < b; i++)

using ll = long long;

using ld = long double;

using vi = vector<int>;

using pii = pair<int, int>;



using vl = vector<ll>;



const ll oo = 1e18;



void solve() {   

    int n;

    ll b, p, m;

    cin >> n >> b >> p >> m;



    vector<vl> plus;

    vl mult, tail;

    map<int, vi> temp_pos;

    ll base_ans = 1;

    ll fullp = 1;



    for (int i = 0; i < n; i++) {

        string s;

        int x;

        cin >> s >> x;



        if (s == "+") {

            if (sz(plus)) {

                plus.back().push_back(x);

                tail.back() += x;

            }

            else

                base_ans += x;

        }   

        else {

            if (x == 1) continue;

            

            base_ans *= x;

            fullp *= x;



            temp_pos[x].push_back(sz(mult));

            mult.push_back(x);

            tail.push_back(0);

            plus.emplace_back();

        }

    }



    vector<pair<int, vi>> pos = {all(temp_pos)};



    int k = sz(mult);

    vector<vl> sums(k, {0});

    ll currp = 1;



    for (int i = k-1; i >= 0; i--) {

        sort(all(plus[i]), greater());

        sums[i].insert(end(sums[i]), all(plus[i]));

        for (int j = 0; j + 1 < sz(sums[i]); j++) 

            sums[i][j+1] += sums[i][j];

        

        tail[i] *= currp;

        if (i + 1 < k) tail[i] += tail[i+1];

        currp *= mult[i];

    }

    

    vector<bool> on(k, 1);



    auto alien = [&](ll cost) -> pair<int, ll> {

        ll prod = 1;

        int took = 0;

        ll gain = 0;

        ll tailp = fullp;



        for (int i = 0; i < k; i++) {

            if (on[i]) {

                prod *= mult[i];

                tailp /= mult[i];

            }



            ll herep = tailp * (prod - 1);

            int p = herep ? (lower_bound(all(plus[i]), cost / herep, greater()) - begin(plus[i])) : 0;



            gain += sums[i][p] * herep - p * cost + sums[i].back() * tailp;

            took += p;

        }



        return {took, gain};

    };

    auto calc = [&](ll take) -> ll {

        ll lo = 0, hi = oo;



        while (lo < hi) {

            ll mid = (lo + hi) / 2;



            if (alien(mid).first <= take)

                hi = mid;

            else

                lo = mid + 1;

        }



        ll gain = alien(hi).second;

        return gain + take * hi;

    };

    auto go = [&](int j, ll budget, auto&& go) -> ll {

        if (j == sz(pos))

            return calc(budget / p);

        

        ll ans = go(j+1, budget, go);

        int iters = 0;



        for (int i : pos[j].second) {

            if (budget < m) break;

            budget -= m;

            on[i] = 0;

            iters++;



            ll here = go(j+1, budget, go);

            ans = max(ans, here);

        }



        while (iters > 0) on[pos[j].second[--iters]] = 1;



        return ans;

    };



    ll ans = go(0, b, go) + base_ans;

    cout << ans << "\n";

} 



int main() {

    cin.tie(0)->sync_with_stdio(0);

    cin.exceptions(cin.failbit);

    // freopen(filename ".in", "r", stdin); freopen(filename ".out", "w", stdout); 



    // int t; cin >> t; while (t--)

    solve();



    return 0;

}