#ifdef LOCAL

    #define _GLIBCXX_DEBUG

#endif



#include <bits/stdc++.h>



#include <ext/pb_ds/assoc_container.hpp>

#include <ext/pb_ds/tree_policy.hpp>



using namespace std;

using namespace __gnu_pbds;



typedef long long ll;

typedef long double ld;

typedef unsigned long long ull;



#define pll pair<ll, ll>

#define pii pair<int, int>

#define pdd pair<ld, ld>

#define ff first

#define ss second

#define all(v) v.begin(),v.end()



typedef tree<

    pii,

    null_type,

    less<pii>,

    rb_tree_tag,

    tree_order_statistics_node_update> ordset;



#pragma GCC optimize("-O3")

#pragma GCC optimize("unroll-loops")



ll INF = 4e18;

const ll mod = 1e9 + 7;



mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());



ll binpow(ll n, ll m){

    if(m == 0) return 1ll;

    if(m & 1ll) return (n * binpow(n, m - 1ll)) % mod;

    ll b = binpow(n, m / 2ll);

    return (b*b) % mod;

}



void solve(){

    int n;

    cin >> n;

    string s;

    cin >> s;

    vector<int> nxt(n), pr(n), to(n), zeroes;

    zeroes.reserve(n);

    int lst = -1;

    for(int i = 0; i < n; i++){

        if(s[i] == '0'){

            to[i] = (int)zeroes.size();

            zeroes.push_back(i);

            lst = i;

        }

        pr[i] = lst;

    }

    lst = n;

    for(int i = n - 1; i >= 0; i--){

        if(s[i] == '0') lst = i;

        nxt[i] = lst;

    }

    int sz = (int)zeroes.size();

    if(!sz){

        int q;

        cin >> q;

        for(int i = 0; i < q; i++){

            int l1, l2, len;

            cin >> l1 >> l2 >> len;

            cout << "Yes\n";

        }

        return;

    }

    vector<ll> deg1(sz + 1), h1(sz + 1);

    vector<ull> deg2(sz + 1), h2(sz + 1);

    deg2[0] = deg1[0] = 1;

    h1[0] = h2[0] = 0;

    ull p = 167;

    for(int i = 0; i < sz; i++){

        int diff = (i ? zeroes[i] - zeroes[i - 1] - 1 : zeroes[i]);

        diff %= 2;

        if(!diff) diff = 2;

        deg2[i + 1] = deg2[i] * p;

        deg1[i + 1] = (deg1[i] * p) % mod;

        h2[i + 1] = h2[i] * p + (ull)diff;

        h1[i + 1] = (((h1[i] * p) % mod) + (ll)(diff)) % mod;

    }

    auto gethash = [&](int l, int r){

        pair<ll, ull> p;

        p.ff = (h1[r + 1] - ((h1[l] * deg1[r - l + 1]) % mod) + mod) % mod;

        p.ss = h2[r + 1] - h2[l] * deg2[r - l + 1];

        return p;

    };

    vector<int> cnt(n, 0);

    for(int i = 0; i < n; i++){

        cnt[i] = (i ? cnt[i - 1] : 0);

        cnt[i] += (s[i] == '0');

    }

    auto get0 = [&](int l, int r){

        return cnt[r] - (l ? cnt[l - 1] : 0);

    };

    int q;

    cin >> q;

    for(int i = 0; i < q; i++){

        int l1, l2, len;

        cin >> l1 >> l2 >> len;

        l1--; l2--;

        if(len <= 2){

            cout << (s.substr(l1, len) == s.substr(l2, len) ? "Yes\n" : "No\n");

            continue;

        }

        int r1 = l1 + len - 1;

        int r2 = l2 + len - 1;

        if(get0(l1, r1) != get0(l2, r2)){

            cout << "No\n";

            continue;

        }

        if(!get0(l1, r1)){

            cout << "Yes\n";

            continue;

        }

        int pr1 = pr[r1], nl1 = nxt[l1];

        int pr2 = pr[r2], nl2 = nxt[l2];

        int dl1 = (nl1 - l1) % 2, dl2 = (nl2 - l2) % 2, dr1 = (r1 - pr1) % 2, dr2 = (r2 - pr2) % 2;

        if(dl1 != dl2 || dr1 != dr2){

            cout << "No\n";

            continue;

        }

        if(get0(l1, r1) == 1){

            cout << "Yes\n";

            continue;

        }

        nl1 = nxt[nl1 + 1];

        nl2 = nxt[nl2 + 1];

        cout << (gethash(to[nl1], to[pr1]) == gethash(to[nl2], to[pr2]) ? "Yes\n" : "No\n");

    }

}



void brute(){

    int n;

    cin >> n;

    string s;

    cin >> s;

    vector<int> cnt(n, 0);

    for(int i = 0; i < n; i++){

        cnt[i] = (i ? cnt[i - 1] : 0);

        cnt[i] += (s[i] == '0');

    }

    auto get0 = [&](int l, int r){

        return cnt[r] - (l ? cnt[l - 1] : 0);

    };

    vector<int> nxt(n);

    int lst = n;

    for(int i = n - 1; i >= 0; i--){

        nxt[i] = lst;

        if(s[i] == '0') lst = i;

    }

    int q;

    cin >> q;

    for(int i = 0; i < q; i++){

        //cout << "query: " << i << '\n';

        int l1, l2, len;

        cin >> l1 >> l2 >> len;

        l1--; l2--;

        int r1 = l1 + len - 1;

        int r2 = l2 + len - 1;

        if(get0(l1, r1) != get0(l2, r2)){

            cout << "No\n";

            continue;

        }

        if(get0(l1, r1) == 0){

            cout << "Yes\n";

            continue;

        }

        bool no = 0;

        int kol = get0(l1, r1) - 1;

        int cur1 = (s[l1] == '0' ? l1 : nxt[l1]), cur2 = (s[l2] == '0' ? l2 : nxt[l2]);

        if((cur1 - l1) % 2 != (cur2 - l2) % 2){

            cout << "No\n";

            continue;

        }

        for(int j = 0; j < kol; j++){

            int new1 = nxt[cur1], new2 = nxt[cur2];

            if(new1 == n) new1 = r1 + 1;

            if(new2 == n) new2 = r2 + 1;

            int d1 = (new1 - cur1 - 1) % 2, d2 = (new2 - cur2 - 1) % 2;

            //cout << i << ' ' << j << ' ' << cur1 << ' ' << cur2 << ' ' << new1 << ' ' << new2 << ' ' << d1 << ' ' << d2 << '\n';

            if(d1 != d2){

                cout << "No\n";

                no = 1;

                break;

            }

            cur1 = new1;

            cur2 = new2;

        }

        if(no) continue;

        int new1 = r1 + 1, new2 = r2 + 1;

        int d1 = (new1 - cur1 - 1) % 2, d2 = (new2 - cur2 - 1) % 2;

        if(d1 != d2){

            cout << "No\n";

        } else cout << "Yes\n";

    }

}



int main() {

    ios_base::sync_with_stdio(0);

    cin.tie(0);

    #ifdef LOCAL

        freopen("input.txt", "r", stdin);

        //freopen("output.txt", "w", stdout);

    #endif

	int tt;

    //cin >> tt;

    tt = 1;

    while(tt--){

        solve();

        //brute();

		#ifdef LOCAL

            cout << "__________________________________" << endl;

		#endif

	}

	#ifdef LOCAL

        cout << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << "sec" << '\n';

	#endif

	return 0;

}