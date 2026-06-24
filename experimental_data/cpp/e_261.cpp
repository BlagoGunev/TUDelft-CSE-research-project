#include <iostream>

#include <cstdio>

#include <vector>

#include <set>

#include <deque>

#include <algorithm>

#include <queue>

#include <cmath>

#include <map>

#include <complex>

#include <cstring>

#include <bitset>

//#include "sdf.hpp"



using namespace std;

#define rep(i, a, b) for(int i = (a); i < (b); i++)

#define repd(i, a, b) for(int i = (a); i > (b); i--)

#define forIt(it, a) for(__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)

#define forRev(it, a) for(__typeof((a).rbegin()) it = (a).rbegin(); it != (a).rend(); it++)

#define ft(a) __typeof((a).begin())

#define ll long long

#define ld long double

#define fi first

#define se second

#define mk make_pair

#define pb push_back

#define sz(a) (a).size()

#define all(a) (a).begin(), (a).end()

#define Rep(i,n) for(int i = 0; i < (n); ++i)



typedef complex<ld> cplex;

typedef vector<int> vi;

typedef pair<int, int> ii;

typedef pair<ii, int> iii;

typedef vector<ii> vii;

typedef vector<iii> viii;



const int N = 300000 + 7;

const int M = 59;

const int mid = M / 2;

const int mod = 1e9 + 9;

const int inf = 1e9 + 7;

const ll linf = 1ll * inf * inf;

const double pi = acos(-1);

const double eps = 1e-7;

const double ep = 1e-5;

const int maxn = 1e5 + 7;

const double PI = acos(-1);





map<int, char> ans;



bitset<1000000001> res;



void solve() {

    ans.insert(mk(1, 0));

    int l, r, p;

    cin >> l >> r >> p;

    //p -= 2;

    rep(i, 2, p + 1) {

        while (!ans.empty() && (ll)ans.rbegin()->first * i > r) ans.erase(ans.rbegin()->first);

        forIt(it, ans) {

            int z = it->first * i;

            char can = it->second + 1;

            if (z >= l && can + i <= p) {

                res[z] = 1;

            }

            

            if (can + i <= p && (ll) z * i <= r) {

                ft(ans) jt = ans.insert(mk(z, 120)).first;

                jt->second = min(jt->second, can);

            }

            

        }

    }

    

    cout << res.count();

    

}







int main() {

            #ifndef ONLINE_JUDGE

                freopen("in.txt", "r", stdin); //freopen("out.txt", "w", stdout);

            #endif

    int T = 1;

    //cin >>T;

    //cout << T << "\n";

    rep(i, 1, T + 1) {

        //printf("Case #%d: ", i);

        //        m = i;

        solve();

        //cout << prime.size() << "\n";

    }

    

}