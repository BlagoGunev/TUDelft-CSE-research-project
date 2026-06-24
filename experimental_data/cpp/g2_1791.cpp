#define _CRT_SECURE_NO_WARNINGS

#pragma warning(disable: 6031)

#include <bits/stdc++.h>

#include <uchar.h>



using namespace std;



#define rp(i,n) for(auto i = 0; i<n; i++)

#define Rp(i,n) for(auto i = n-1; i>=0; i--)

#define loop(i, a, b) for(auto i = a; i!=b; i+= (a<b?1:-1))

#define trv(i, a) for(auto &i:a)

#define rep(i, a, b) for(auto i = a; i<=b; i++)

#define Rep(i, a, b) for(auto i = a; i>=b; i--)

#define all(a) a.begin(), a.end()

#define all1(a) a.begin() + 1, a.end()

#define dbg(n) cerr<< "<! "<<n<<" !>\n"

#define dbg2(n, m) cerr<< "<! "<<n << " - " << m <<" !>\n"

#define dbga(a)  cerr<< "\n\t<! "; rp(i, a.size()) cerr<< a[i] <<" "; cout<<"!>\n"

#define F first

#define S second

#define el cout << "\n"

#define sz(a) a.size()



using ll = long long;

using pll = pair<ll, ll>;

using ii = pair<int, int>;

using iii = pair<int, ii>;

using si = set<int>;

using mii = map<int, int>;

using mll = map<ll, ll>;

using vi = vector<int>;

using vvi = vector<vi>;

using vb = vector<bool>;

using vvb = vector<vb>;

using vl = vector<long long>;

using vvl = vector<vl>;

using vll = vector<pll>;

using vii = vector<ii>;

using vs = vector<string>;

using ui = unsigned int;



const string yno[2] = { "NO\n", "YES\n" };

const int MOD = int(1e9 + 7);

const int INF = int(2e9);

const int N = int(1e5) + 5;





int mostRBit(int n) { rep(i, 0, 31) if ((n >> i) & 1) return i; return -1; }

int mostLBit(int n) { Rep(i, 31, 0) if ((n >> i) == 1) return i; return -1; }

int hmW(int n) { int cnt = 0; while (n) n &= (n - 1), cnt++; return cnt; }

bool getBit(int n, int i) { return ((n >> i) & 1); }

vi fac(int n) { vi res(1, 1); rep(i, 1, n) res.push_back(res[i - 1] * i); return res; }

int binToInt(string s) { int k = 0, n = sz(s); Rep(i, n - 1, 0) k |= (s[i] - 48) << (n - 1 - i); return k; }



template<typename T> void maximize(T& cm, T c) { cm = max(cm, c); }

template<typename T> void minimize(T& cm, T c) { cm = min(cm, c); }

template<typename T> bool in_range(T x, T a, T b) { return a <= x && x <= b; }



ostream& operator << (ostream& os, ii p) {

    os << p.first << ' ' << p.second;

    return os;

}



bool solve() {



    int n, c; cin >> n >> c;

    vii a(n);

    vl s(n+1, 0);

    trv(i, a) 

        cin >> i.first, 

        i.second = i.first;

    rp(i, n) 

        a[i].first += min(i + 1, n - i), 

        a[i].second += i + 1;



    sort(all(a));

    rp(i, n) 

        s[i + 1] = s[i] + a[i].first;



    

    int ans = 0;

    rp(i, n) {

        int l = 0, r = n;

        int remain = c-a[i].second;

        if (remain < 0) continue;

        int cur = 0;

        while (l <= r) {

            int mid = (l + r) >> 1;

            if (remain >= s[mid]) {

                cur = mid;

                l = mid + 1;

            }

            else r = mid - 1;

        }

        if (cur - 1 < i) maximize(ans, cur + 1);

        else {

            remain += a[i].first;

            while (cur+1 <= n && s[cur + 1] <= remain) cur++;

            maximize(ans, cur);

        }

        

    }



    cout << ans;



    return 0;



}



int main() {

    ios_base::sync_with_stdio(false);

    cin.tie(NULL);

#ifndef ONLINE_JUDGE

    freopen("input.txt", "r", stdin);

    //freopen("output.txt", "w", stdout);

#endif // !ONLINE_JUDGE



    int t = 1;

    cin >> t;

    int T = 1;

    while (t--) {

        //dbg(T++);

        //cout << "Case #" << T++ << ": ";

        solve(); el;

        //cout << yno[solve()];

    }



}