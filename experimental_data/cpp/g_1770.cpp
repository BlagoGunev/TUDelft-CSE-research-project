///d&c

#include <bits/stdc++.h>

using namespace std;



using ll = long long;

using ld = long double;



#define pb push_back

#define si(x) int(x.size())

#define all(x) x.begin(), x.end()



const int N = 500000;

const int MOD = 998244353;



int add(int a, int b){ a += b; if(a >= MOD) a -= MOD; return a; }

int mul(int a, int b){ return (1LL*a*b)%MOD; }

int sub(int a, int b){ return add(a, MOD - b); }



int pw(int a, int b){

    if(b == 0) return 1;

    int res = pw(a, b/2);

    res = mul(res, res);

    if(b%2) res = mul(res, a);

    return res;

}



const int root = pw(3, 119);

const int root_1 = pw(root, MOD - 2);

const int root_pw = 1 << 23;



void fft(vector<int> &a, bool invert) {

    int n = a.size();



    for (int i = 1, j = 0; i < n; i++) {

        int bit = n >> 1;

        for (; j & bit; bit >>= 1)

            j ^= bit;

        j ^= bit;



        if (i < j)

            swap(a[i], a[j]);

    }



    for (int len = 2; len <= n; len <<= 1) {

        int wlen = invert ? root_1 : root;

        for (int i = len; i < root_pw; i <<= 1)

            wlen = (int)(1LL * wlen * wlen % MOD);



        for (int i = 0; i < n; i += len) {

            int w = 1;

            for (int j = 0; j < len / 2; j++) {

                int u = a[i+j], v = (int)(1LL * a[i+j+len/2] * w % MOD);

                a[i+j] = u + v < MOD ? u + v : u + v - MOD;

                a[i+j+len/2] = u - v >= 0 ? u - v : u - v + MOD;

                w = (int)(1LL * w * wlen % MOD);

            }

        }

    }



    if (invert) {

        int n_1 = pw(n, MOD - 2);

        for (int & x : a)

            x = mul(x, n_1);

    }

}



void multiply(vector <int> &va, vector <int> &vb){

    int ns = si(va) + si(vb);

    int j = 1;

    while(j < ns) j *= 2;

    while(si(va) < j) va.pb(0);

    while(si(vb) < j) vb.pb(0);

    fft(va, 0);

    fft(vb, 0);

    for(int i=0; i<si(va); i++){

        va[i] = mul(va[i], vb[i]);

    }

    fft(va, 1);

    while(si(va) && va.back() == 0) va.pop_back();

}



int fact[N+5], invfact[N+5];



int choose(int n, int k){

    int res = fact[n];

    res = mul(res, invfact[k]);

    res = mul(res, invfact[n-k]);

    return res;

}



int pref[N+5];



void solve(int l, int r, vector <int> &p){

    if(l == r){

        if(pref[r] - pref[l-1]){

            for(int i=0; i<si(p)-1; i++){

                p[i] = add(p[i], p[i+1]);

            }

        }

        else{

            p.pb(0);

            for(int i=si(p)-1; i>0; i--){

                p[i] = add(p[i], p[i-1]);

            }

        }

        while(si(p) && p.back() == 0) p.pop_back();

        return;

    }

    int sz = r - l + 1;

    vector <int> va, vb;

    vector <int> jump;

    for(int i=sz; i<si(p); i++) va.pb(p[i]);

    for(int i=0; i<=sz; i++){

        jump.pb(choose(sz, i));

    }

    vector <int> res;

    for(int i=0; i<min(si(p), sz); i++){

        vb.pb(p[i]);

    }

    multiply(va, jump);

    p.clear();

    for(int i=0; i<sz; i++) p.pb(0);

    for(auto c : va) p.pb(c);

    int sp = pref[r] - pref[l-1];

    for(int i=0; i+sp<si(p); i++){

        p[i] = p[i+sp];

    }

    for(int i=si(p)-sp; i<si(p); i++) p[i] = 0;

    int mid = (l+r)/2;

    solve(l, mid, vb);

    solve(mid+1, r, vb);

    while(si(p) < si(vb)) p.pb(0);

    for(int i=0; i<si(vb); i++) p[i] = add(p[i], vb[i]);

    while(si(p) && p.back() == 0) p.pop_back();

}



int solve_part(string s){

    int n = si(s);

    if(n == 0) return 1;

    int bal = 0;

    int mn = 0;

    vector <int> sn;

    for(int i=0; i<n; i++){

        if(s[i] == '(') bal++;

        else{

            bal--;

            sn.pb(0);

        }

        if(bal < mn){

            mn = bal;

            sn.back() = 1;

        }

    }

    n = si(sn);

    for(int i=1; i<=n; i++){

        pref[i] = pref[i-1];

        if(sn[i-1]) pref[i]++;

    }

    vector <int> poc = {1};

    solve(1, n, poc);

    return poc[0];

}



int main(){

    ios_base::sync_with_stdio(false), cin.tie(0);

    cout.precision(10);

    cout << fixed;



    string s;

    cin >> s;

    int n = si(s);

    fact[0] = 1;

    for(int i=1; i<=n; i++) fact[i] = mul(fact[i-1], i);

    invfact[n] = pw(fact[n], MOD - 2);

    for(int i=n-1; i>=0; i--) invfact[i] = mul(invfact[i+1], i + 1);

    int bal = 0;

    int mn = 0;

    int pos = -1;

    for(int i=0; i<si(s); i++){

        char c = s[i];

        if(c == '(') bal++;

        else bal--;

        if(bal < mn){

            mn = bal;

            pos = i;

        }

    }

    string s1, s2;

    for(int i=0; i<=pos; i++) s1.pb(s[i]);

    for(int i=si(s)-1; i>pos; i--) s2.pb(s[i]);

    for(auto &c : s2){

        if(c == '(') c = ')';

        else c = '(';

    }

    cout << mul(solve_part(s1), solve_part(s2)) << "\n";

    return 0;

}