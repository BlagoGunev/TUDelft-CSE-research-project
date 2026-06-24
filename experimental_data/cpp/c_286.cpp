#include<algorithm>
#include<cassert>
#include<complex>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<map>
#include<queue>
#include<set>
#include<sstream>
#include<stack>
#include<string>
#include<vector>
#include<iostream>
#define FOR(i, a, b) for(int i = (a); i <= (b); ++i)
#define FORD(i, a, b) for(int i = (a); i >= (b); --i)
#define REP(i, n) for(int i = 0; i < (n); ++i)
#define VAR(v, i) __typeof(i) v = (i)
#define FORE(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define CLR(x) memset((x), 0, sizeof(x))
#define PB push_back
#define MP make_pair
#define FI first 
#define SE second
#define SQR(a) ((a) * (a))
#define DEBUG 1
#define debug(x) { if(DEBUG) cerr << #x << " = " << x << endl; }
#define debugv(x) { if (DEBUG) cerr << #x << " = "; FORE(it, (x)) cerr << *it << ", "; cout << endl; }

using namespace std;
typedef long long LL;
typedef long double LD;
typedef pair<int, int> PII;
typedef vector<int> VI;
const int INF=((LL)1E9 + 7);
template<class C> void mini(C&a, C b) { a = min(a, b); }
template<class C> void maxi(C&a, C b) { a = max(a, b); }
const int MAXN = 1000100;
int a[MAXN];
bool q[MAXN];
bool res[MAXN];
int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    REP(i, n) cin >> a[i]; 
    int t;
    cin >> t; 
    REP(i, t) {
        int x;
        cin >> x;
        --x;
        q[x] = true;
    }
    stack<int> S;
    FORD(i, n-1,0) {
        if (S.empty() || S.top() != a[i] || q[i]) S.push(a[i]);
        else {
            S.pop();
            res[i] = true;
        }
    }
    if (!S.empty()) {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    REP(i, n) {
        if (res[i]) cout << a[i] << " ";
        else cout << -a[i] << " ";
    }
    cout << endl;
    return 0;
}