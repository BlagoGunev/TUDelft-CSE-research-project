#include <bits/stdc++.h>

using namespace std;

#define pb  push_back

#define coud(a) cout<<fixed << setprecision((a))

#define F first

#define S second

#define clr(v, d)  memset(v, d, sizeof(v))

#define all(v) (v).begin(), (v).end()

#define  EPS 1e-7

#define popcnt(a) __builtin_popcount(a)

typedef long long ll;

typedef pair<int,int>pii;

typedef vector<int> vi;

typedef vector<ll> vll;

typedef vector<pii> vii;

typedef vector< vi > vvi;

int dx8[] = {-1, -1, -1, 0, 0, 1, 1, 1};

int dy8[] = {-1, 0, 1, -1, 1, -1, 0, 1};

int dx4[] = {0, 0, 1, -1}, dy4[] = {1, -1, 0, 0};

int dcmp(double x, double y) {	return fabs(x-y) <= EPS ? 0 : x < y ? -1 : 1; }

bool valid(int r, int c, int n, int m){return r>=0&& c>=0 && r < n&& c < m;}

ll gcd(ll a, ll b) { if (b == 0) return a;return gcd(b, a % b); }

inline ll LCM(ll a,ll b){ return a*b/ gcd(a,b);}





int main() {

    cin.tie(0);

    std::ios_base::sync_with_stdio(false);

    int t; cin >> t;

    while (t--){

        int n, k; cin >> n >> k;

        string s; cin >> s;

        int l = -1, r = -1;

        for(int i = 0; i < s.size(); i++){

            if(s[i] == '*'){

                l = i; break;

            }

        }

        for(int i =s.size()-1; i>=0; i--){

            if(s[i] == '*') {r = i; break;}

        }

        if(l == -1 && r == -1){ cout << 0 << endl; continue;}

        if(l == r ){cout << 1 << endl; continue;}

        ll ans = 1;

        int j = l, last = l;

        for(int i = l; i < r; i+= k){

            while (s[i] == '.') {

                i--;

            }

            ans++;

        }

        cout << ans << endl;

    }

    return 0;

}