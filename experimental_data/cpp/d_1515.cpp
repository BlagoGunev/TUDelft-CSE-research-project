//  D. Phoenix and Socks



#include<bits/stdc++.h>



#define fast ios_base::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);

#define stki stack<int>

#define pqi priority_queue<int>

#define pqpii priority_queue<pii>

#define minpqi priority_queue<int,vi,greater<>>

#define psi pair<string,int>

#define pii pair<int,int>

#define pll pair<ll,ll>

#define tri pair<int,pii>

#define trll pair<ll,pll>

#define qi queue<int>

#define li list<int>

#define vi vector<int>

#define vll vector<ll>

#define vs vector<string>

#define vb vector<bool>

#define vc vector<char>

#define vvi vector<vector<int>>

#define vvb vector<vector<bool>>

#define vvc vector<vector<char>>

#define vvll vector<vector<ll>>

#define vvpll vector<vector<pll>>

#define vpii vector<pii>

#define vpll vector<pll>

#define mp(a, b) make_pair(a,b)

#define si set<int>

#define mlsi multiset<int>

#define sll set<ll>

#define sull set<ull>

#define mii map<int,int>

#define mll map<ll,ll>

#define mss map<string,string>

#define msi map<string,int>

#define mci map<char,int>

#define umii unordered_map<int,int>

#define umill unordered_map<int,ll>

#define umsi unordered_map<string,int>

#define umsll unordered_map<string,ll>

#define umss unordered_map<string,string>

#define ull unsigned long long

#define ll long long

#define endl '\n'

#define all(a) a.begin(), a.end()

#define alln(a, n) a, a + n

#define yes "YES"

#define no "NO"

#define spc ' '

#define INF INT_MAX

#define LLINF LONG_LONG_MAX

#define NINF INT_MIN

#define LLNINF LONG_LONG_MIN

#define pb push_back

#define eb emplace_back

#define F first

#define S second

#define cin(a) for(auto &_x:(a)) cin>>_x

#define cin2(a) for(auto &_x:(a))for(auto &__x:_x) cin>>__x

#define cout(a) for(auto &_x:(a)) cout<<_x



const int MOD = 1e9 + 7;



using namespace std;



template<typename T>

string genKey(T num, ...) {

    va_list valist;

    va_start(valist, num);

    string key = to_string(va_arg(valist, T));

    for (int i = 1; i < num; i++) {

        key += '|' + to_string(va_arg(valist, T));

    }

    va_end(valist);

    return key;

}



struct custom_hash {

    static uint64_t splitmix64(uint64_t x) {

        // http://xorshift.di.unimi.it/splitmix64.c

        x += 0x9e3779b97f4a7c15;

        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;

        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;

        return x ^ (x >> 31);

    }



    size_t operator()(uint64_t x) const {

        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();

        return splitmix64(x + FIXED_RANDOM);

    }

};





void solve() {

    int n, ln, rn;

    cin >> n >> ln >> rn;

    vi cntl(n + 1, 0), cntr(n + 1, 0);

    for (int i = 0; i < ln; ++i) {

        int x;

        cin >> x;

        cntl[x]++;

    }

    for (int i = 0; i < rn; ++i) {

        int x;

        cin >> x;

        cntr[x]++;

    }

    for (int i = 1; i <= n; ++i) {

        int mn = min(cntl[i], cntr[i]);

        cntl[i] -= mn;

        cntr[i] -= mn;

        ln -= mn;

        rn -= mn;

    }

    if (ln < rn) {

        swap(ln, rn);

        swap(cntl, cntr);

    }

    int ans = 0;

    for (int i = 1; i <= n; ++i) {

        int need = ln - rn;

        int can = cntl[i] / 2;

        int mn = min(need, can * 2);

        ans += mn / 2;

        ln -= mn;

    }

    ans += (ln - rn) / 2 + (ln + rn) / 2;

    cout << ans;

}



bool multi = true;



int main() {

    fast;

    int t = 1;

    multi && cin >> t;

    while (t--) {

        solve();

        multi && cout << endl;

    }

}

/*



 */