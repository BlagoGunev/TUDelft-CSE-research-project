#include<algorithm>
#include<bitset>
#include<cassert>
#include<complex>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<iostream>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<string>
#include<vector>
#define FOR(i, a, b) for(int i =(a); i <=(b); ++i)
#define FORD(i, a, b) for(int i = (a); i >= (b); --i)
#define REP(i, n) for(int i = 0;i <(n); ++i)
#define VAR(v, i) __typeof(i) v=(i)
#define FORE(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define PB push_back
#define MP make_pair
#define X first
#define Y second 
#define debug(x) {cerr <<#x <<" = " <<x <<endl; }
#define debugv(x) {{cerr <<#x <<" = "; FORE(itt, (x)) cerr <<*itt <<", "; cerr <<endl; }}
using namespace std;
typedef long long LL;
typedef long double LD;
typedef pair<int, int> PII;
typedef vector<int> VI;

template<class C> void mini(C&a4, C b4){a4=min(a4, b4); }
template<class C> void maxi(C&a4, C b4){a4=max(a4, b4); }
template<class T1, class T2>
ostream& operator<< (ostream &out, pair<T1, T2> pair) { return out << "(" << pair.X << ", " << pair.Y << ")";}

const int MX = 100100;
const int MZ = 300100;


struct iT {
    int n;
    VI delta, mx;
    iT(int _n) {
        n = 1;
        while(n < _n) n *= 2;
        delta = VI(2*n, 0);
        mx = VI(2*n, 0);
    }
    void _set(int l, int r, int d, int i, int L, int R) {
        assert(i > 0);
        if (l >= R || L >= r) return;
        if (l <= L && R <= r) {
            delta[i] += d;
            mx[i] += d;
        } else {
            _set(l,r,d,2*i, L, (L+R)/2);
            _set(l,r,d,2*i+1, (L+R)/2, R);
            mx[i] = delta[i] + max(mx[2*i], mx[2*i+1]);
        } 
    }
    void Set(int l, int r, int d) {
        _set(l,r,d,1,0, n);
    }
    PII get() {
        PII res = MP(mx[1], -1);
        int i = 1;
        int v = mx[i];
        while(i < n) {
            v -= delta[i];
            if (v == mx[2*i]) i = 2*i;
            else i = 2*i+1;
        }
        res.Y = i-n;
        return res;
    }
};
int l[MX], r[MX], v[MX];

VI L[MZ], V[MZ];


int main(){
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(10);
    int n;
    cin >> n;
    REP(i, n) cin >> l[i] >> v[i] >> r[i];
    int mx = 0;
    REP(i, n) {
        L[l[i]].PB(i);
        V[v[i]].PB(i);
        maxi(mx, r[i]);
    }
    PII best = MP(0,0);
    int bv = 0;
    iT T(mx+2);
    FORD(t, mx+1, 0) {
        FORE(it, L[t+1]) {
            int left = v[*it];
            int right = r[*it]+1;
            T.Set(left, right, -1); 
        }
        FORE(it, V[t]) {
            int left = v[*it];
            int right = r[*it]+1;
            T.Set(left, right, +1);
        }
        PII cur = T.get();
        if (cur.X > bv) {
            bv = cur.X;
            best = MP(t, cur.Y);
        }
    }
    VI res;
    REP(i, n) {
        if (l[i] <= best.X && r[i] >= best.Y && v[i] >= best.X && v[i] <= best.Y) res.PB(i);
    }
    assert(SZ(res) == bv);
    cout << bv << endl;
    FORE(it, res) cout << *it+1 << " ";
    cout << endl;
    return 0;
}