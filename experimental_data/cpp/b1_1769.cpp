#include <bits/stdc++.h>

using namespace std;



#define ll long long

#define endl "\n"

#define FOR(i,n) for(long long i = 0; i < n; i++)

#define FOR1(i,s,e,d) for(long long i = s; i < e; i += d)

#define FOR2(i,s,e,d) for(long long i = s; i > e; i -= d)

#define FOR3(x,v) for (auto x : v)

#define pll pair<long long, long long>

#define vl vector<long long>

#define vll vector<pair<long long, long long>>

#define vvl vector<vector<long long>>

#define vs vector<string>

#define vc vector<char>

#define mll map<long long, long long>

#define mlc map<long long,char>

#define mls map<long long,string>

#define mlvl map<long long, vector<long long>>

#define pql priority_queue<long long>



const ll INF = 1e9;

const ll mod = 998244353;



void display(vl vect) {

    FOR3(x, vect) cout << x << ' ';

    cout << "\n";

}



void display(vvl vect2d) {

    FOR3(x, vect2d) display(x);

}



void display(mll m) {

    FOR3(x, m) cout << x.first << ' ' << x.second << endl;

}



void display(mlvl  m) {

    FOR3(x, m) {

        cout << x.first << " : ";

        display(x.second);

    }

}



vl vin(int n) {

    vl v(n);

    FOR(i,n) cin >> v[i];

    return v;

}



int to_int(string s) {

    return stoi(s);

}



int to_int(char c) {

    string s = {c};

    return stoi(s);

}



char to_char(int i) {

    return char('0' + i);

}



int is_prime(ll n) {

    if (n == 1) return 0;

    if (n == 2 || n == 3) return 1;

    if ( n % 6 == 1 || n % 6 == 5) {

        for (ll k = 5; k*k <= n; k += 2) if (n % k == 0) return 0;

        return 1;

    }

    return 0;

}



ll gcd(ll a, ll b) {

    return b == 0 ? a : gcd(b, a % b);   

}



ll inv(ll a, ll b){

    return 1<a ? b - inv(b%a,a)*b/a : 1;

}



ll power(ll a, ll b) {

    if (b == 0) return 1;

    if (b%2) return a * power(a, b-1);

    else return power(a, b/2) * power(a, b/2);

}



template<class T, class T1> bool ckmin(T& a, const T1& b) { return b < a ? a = b, 1 : 0; }

template<class T, class T1> bool ckmax(T& a, const T1& b) { return a < b ? a = b, 1 : 0; }



// (condition ? value if yes : value if no)

// sort(v.begin(), v.end(), [](data_type x, data_type y) -> bool {

//     return condition;

// });



void solve() {

    ll n; cin >> n;

    vl v = vin(n);

    ll total_prog = 0;

    ll data = 0;

    vl ans(101, 0);

    ans[0] = 1;

    FOR(i, n) data += v[i];

    FOR(i, n) {

        ll temp_prog = 0;

        FOR(j, v[i]) {

            temp_prog += 1;

            total_prog++;

            if ((ll)(100 * (temp_prog)/v[i]) == (ll)(100 * (total_prog)/data)) ans[(ll)(100 * (temp_prog)/v[i])] = 1;

        }

    }

    FOR(i, 101) if (ans[i]) cout << i << endl;    

}



int main() {

    ios::sync_with_stdio(false);

    cin.tie(NULL);

    ll t = 1;

    // cin >> t;

    FOR(i,t) {

        // cout << "Case #" << i+1 << ": ";

        solve();

    }

}