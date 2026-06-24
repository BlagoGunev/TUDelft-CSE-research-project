#include <bits/stdc++.h>

using namespace std;

typedef complex<double> point;

#define fast cin.tie(0), cout.tie(0), cin.sync_with_stdio(0), cout.sync_with_stdio(0);

#define ll long long

#define ld long double

#define EPS 1e-9

#define INF INT_MAX

#define pb push_back

#define pf push_front

#define F first

#define S second

#define all(x) x.begin(),x.end()

#define allr(x) x.rbegin(),x.rend()

#define rep(i, k, n) for(int i=k; i < n ; i++)

#define rev(i, n, k) for(int i = n; i>= k; i--)

#define yes cout << "YES" << endl;

#define no cout << "NO" << endl;

#define NIL -1



// alt + ctrl + l

// يا رب

const ll MOD = 1e9+7;

const ll N = 2e5 + 5;

const ll K = 5;

//const ll M = 100;

double const pi = 3.14159265359;

const int OO=0x3f3f3f3f;

const ll LOO=0x3f3f3f3f3f3f3f3f;

int dx8[] = {+0, +0, -1, +1, +1, +1, -1, -1};

int dy8[] = {-1, +1, +0, +0, +1, -1, +1, -1};

int dx4[] = {+0, +0, -1, +1};

int dy4[] = {-1, +1, +0, +0};

//struct cmp {

//    bool operator()(M const& p1, M const& p2)

//    {

//        return p1.dis > p2.dis;

//    }

//};



int main() {

    fast

    ll T = 1;

//    cin >> T;

    while(T--){

        ll n;

        string s;

        cin >> n >> s;

        ll cnt = 0;

        for (int i = 0; i < n; ++i) {

            cnt += s[i] == 'W';

        }

        ll ans = cnt;

        for (int i = n; i < s.size(); ++i) {

            cnt += s[i] == 'W';

            cnt -= s[i - n] == 'W';

            ans = max(ans, cnt);

        }

        cout << ans << endl;

    }

}