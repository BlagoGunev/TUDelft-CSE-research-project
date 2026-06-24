#include "bits/stdc++.h"
using namespace std;

typedef long long           lol;
typedef pair<int,int>       pii;
#define pb                  push_back
#define ub                  upper_bound
#define lb                  lower_bound
#define fo(i,l,r,d)         for(auto i=(l); (d)<0?i>(r):((d)>0?i<(r):0); i+=(d))
#define all(x)              x.begin(), x.end()
#define ff                  first
#define ss                  second

mt19937 rng (chrono::high_resolution_clock::now().time_since_epoch().count());
template <typename A, typename B> ostream& operator<< (ostream &cout, pair<A, B> const &p) { return cout << "(" << p.first << ", " << p.second << ")"; }
template <typename A, typename B> istream& operator>> (istream& cin, pair<A, B> &p) {cin >> p.first; return cin >> p.second;}
template <typename A> ostream& operator<< (ostream &cout, vector<A> const &v) {cout << "["; for(int i = 0; i < v.size(); i++) {if (i) cout << ", "; cout << v[i];} return cout << "]";}
template <typename A> istream& operator>> (istream& cin, vector<A> &x){for(int i = 0; i < x.size()-1; i++) cin >> x[i]; return cin >> x[x.size()-1];}
template <typename A, typename B> A amax (A &a, B b){ if (b > a) a = b ; return a; }
template <typename A, typename B> A amin (A &a, B b){ if (b < a) a = b ; return a; }


int main () {
    ios_base::sync_with_stdio(0), cin.tie(0);

    int n; cin >> n;

    if (n < 3) return cout << -1, 0;

    vector a(n, vector(n, 0));

    vector p{8,4,9,1,2,5,3,7,6};

    fo(i,0,3,1) fo(j,0,3,1)
        a[i][j] = p[i * 3 + j] + n*n - 9;

    int cr = 1;

    fo(i,3,n,2) {
        fo(x,0,i+1,1)
            a[x][i] = cr++;
        fo(y,i-1,-1,-1)
            a[i][y] = cr++;

        if (i + 1 < n) {
            fo(y,0,i+2,1)
                a[i + 1][y] = cr++;
            fo(x,i,-1,-1)
                a[x][i + 1] = cr++;
        }
    }

    if (n > 3) {
        if (n & 1)
            swap(a[0][n-1], a[1][n-1]);
    }

    fo(i,0,n,1) fo(j,0,n,1)
        cout << a[i][j] << " \n"[j == n-1];
}