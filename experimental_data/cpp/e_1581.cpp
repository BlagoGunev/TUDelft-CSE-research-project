#include <bits/stdc++.h>

using namespace std;

 

#define fast_io         {ios::sync_with_stdio(0); cin.tie(0);}

#define all(v)          v.begin(),v.end()

#define pb              push_back

#define popb            pop_back

#define F               first

#define S               second

#define ccc             cout << " fuck " << endl;

#define prin(v)         {for(auto u : v) cout << u << ' '; cout << '\n';}

#define forn(i,n)       for(int i = 0; i < (n); i++)

#define len()           length()

#define fixed(n)        setprecision(n) << fixed

 

typedef long long ll;

typedef long double ld;

typedef vector<int> vint;

typedef vector<ll> vll;

typedef vector<bool> vbool;

typedef pair<int,int> pii;

typedef pair<ll,ll> pll;

const ll MOD = 998244353;

//mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());



vint pref;

vector<vint> lower;

vint last;



void init(int n, int m, int s) {

    pref.resize(m);

    last.resize(n);

    lower.resize(s + 1);

    for(int i = 1; i <= s; i++) {

        lower[i].resize(i);

    }

}



int get_ans(int day, int s) {

    int res = 0;

    for(int i = 1; i <= s; i++) {

        res += lower[i][day % i];

    }

    return res;

}



void add_pref(int x, int y, int day) {

    for(int i = day; i < pref.size(); i += x + y) pref[i]++;

    for(int i = day + x; i < pref.size(); i += x + y) pref[i]--;

}



void remove_pref(int x, int y, int day, int l) {

    int d1 = -1, d2 = -1;

    for(int i = l; i < pref.size(); i += x + y) {

        if(day <= i) pref[i]--;

        else d1 = i;

    }

    for(int i = l + x; i < pref.size(); i += x + y) {

        if(day <= i) pref[i]++;

        else d2 = i;

    }

    if(d1 > d2) pref[day]--;

}



void add_lower(int x, int y, int day, int k) {

    day = day % (x + y);

    for(int cnt = 0; cnt < x; cnt++) {

        lower[x + y][(day + cnt) % (x + y)] += k;

    }

}





int main()

{

    fast_io;

    int n, m; cin >> n >> m;

    vint x(n), y(n);

    forn(i, n) cin >> x[i] >> y[i];

    int s = sqrt(m);

    init(n, m, s);

    vint ans(m);



    vint cnt(m);

    forn(i, m) {

        int op, k; cin >> op >> k;

        k--;

        if(op == 1) last[k] = i;

        if(op == 2) op = -1;

        cnt[i] = (i == 0 ? 0 : cnt[i - 1]) + op;

        int sum = x[k] + y[k];



        if(sum <= s) {

            if(op == 1) add_lower(x[k], y[k], i, op);

            else add_lower(x[k], y[k], last[k], op);

        }

        else {

            if(op == 1) add_pref(x[k], y[k], i);

            else remove_pref(x[k], y[k], i, last[k]);

        }

        ans[i] = get_ans(i, s);

    }

    int cur = 0;

    for(int i = 0; i < m; i++) {

        cur += pref[i];

        cout << cnt[i] - (ans[i] + cur) << '\n';

    }

}

 

 

/*

 

*/