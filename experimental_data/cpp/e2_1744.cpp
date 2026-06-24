#include<bits/stdc++.h>

#define ll long long

#define ld long double

#define fi first

#define se second

#define pii pair<int, int>

#define pll pair<long long, long long>

using namespace std;



void solve() {

    ll a, b, c, d, a2, b2;

    cin >> a >> b >> c >> d;

    a2 = a; b2 = b;

    map<ll, ll> mp;

    for (ll i = 2; i * i <= a; i++) {

        while(a2 % i == 0) {

            mp[i]++;

            a2 /= i;

        }

    }



    for (ll i = 2; i * i <= b; i++) {

        while(b2 % i == 0) {

            mp[i]++;

            b2 /= i;

        }

    }



    if (a2 > 1) mp[a2]++;

    if (b2 > 1) mp[b2]++;



//    for (auto e : mp) cout << e.fi << " " << e.se << " || "; cout << endl;





    set<pll> st;

    st.insert({1, 1});

    for (auto e : mp) {

        set<pll> st2;

        ll tot = 1, w1 = 1;

        for (int i = 0; i < e.se; i++) tot *= e.fi;

        for (int i = 0; i <= e.se; i++) {

            ll w2 = tot / w1;

            if (w1 > c || w2 > d) {

                w1 *= e.fi;

                continue;

            }



            for (auto e2 : st) {

                ll x = e2.fi * w1;

                ll y = e2.se * w2;

                if (x > c || y > d) continue;

                st2.insert({x, y});

            }



            w1 *= e.fi;

        }



        st.swap(st2);

    }



    for (auto e : st) {

//        cout << e.fi << " " << e.se << endl;

        ll x = (a / e.fi + 1) * e.fi;

        ll y = (b / e.se + 1) * e.se;

        if (x <= c && y <= d) {

            cout << x << " " << y << "\n";

            return;

        }

    }



    cout << -1 << " " << -1 << "\n";

    return;

}



int main() {

    ios_base::sync_with_stdio(false);

    cin.tie(NULL);

    int tt;

    cin >> tt;

    while(tt--) {

        solve();

    }



    return 0;

}