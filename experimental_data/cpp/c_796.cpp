#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for (int i = a; i <= b; i++)
#define FORD(i,a,b) for (int i = a; i >= b; i--)
#define REP(i,a) for (int i = 0; i < a; i++)
#define REPD(i,a) for (int i = a; i > 0; i--)
 
#define ll long long
#define fi first
#define se second
 
#define inf 0x3f3f3f3f
#define linf 0x3f3f3f3f3f3f3f3fLL
 
#define debug(x) { cout << "---> " << #x << " = " << x << endl;  }
#define sqr(x) ((x)*(x))
#define all(x) x.begin(), x.end()
 
ll read(){
    char r;
    bool start = false, neg = false;
    ll res = 0;
    while( true ) {
	r = getchar();
	if((r - '0' < 0 or r - '0' > 9) and r != '-' && !start) {
	    continue;
	}
	if((r - '0' < 0 or r - '0' > 9) and r != '-' && start) {
	    break;
	}
	if(start) res *= 10;
	    start = true;
	    if(r == '-') neg = true;
	    else res += r - '0';
    }
    if(!neg) return res;
    else return -res;
}

const int MN = 3e5+5;

int test;
int a[MN];

vector<int> V[MN];

int n, m;
int res = -inf - MN;
bool mark[MN];

void DFS(int x) {
    mark[x] = true;
    res = max(res, a[x]);

    REP(i,V[x].size()) {
        int t = V[x][i];
        if(!mark[t]) {
            a[t]++;
            REP(j,V[t].size()) {
                int v = V[t][j];
                if(!mark[v]) {
                    a[v]++;
                }
            }
        }
    }
    REP(i,V[x].size()) {
        int t = V[x][i];
        if(!mark[t]) DFS(t);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    n = read();
    int p;
    int mxi = -inf - 10;
    FOR(i,1,n) {
        a[i] = read();
        if(mxi < a[i]) {
            mxi = a[i];
            p = i;
        }
    }
    FOR(i,1,n-1) {
        int u, v;
        u = read();
        v = read();
        V[u].push_back(v);
        V[v].push_back(u);
    }
    res = mxi;
    int mxCnt = 0;
    FOR(i,1,n) {
        int cnt = 0;
        REP(j,V[i].size()) {
            int u = V[i][j];
            if(a[u] == mxi) ++cnt;
        }

        if(cnt > 1) {
            if(mxCnt < cnt) {
                mxCnt = cnt;
                p = i;
            }
        }
    }
    DFS(p);
    cout << res << endl;

    return 0;
}