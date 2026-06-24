#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>

using namespace std;

typedef vector<int> VI;
typedef long long LL;

#define FOR(x, b, e) for(int x=b; x<=(e); ++x)
#define FORD(x, b, e) for(int x=b; x>=(e); --x)
#define REP(x, n) for(int x=0; x<(n); ++x)
#define VAR(v, n) __typeof(n) v = (n)
#define ALL(c) (c).begin(), (c).end()
#define SIZE(x) ((int)(x).size())
#define FOREACH(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define PB push_back
#define ST first
#define ND second

class Solver {

    public:
    
    void readInput() {
        int q, n;
        cin >> q;
        REP(x, q) {
            int sum = 0;
            cin >> n;
            REP(y, n) {
                int tmp;
                cin >> tmp;
                if(tmp <= 2048) sum += tmp;
            }
            cout << (sum >= 2048 ? "YES\n" : "NO\n");
        }
    }

    void solve() {

    }
};

int main() {
	ios_base::sync_with_stdio(0);
    Solver solver;
    solver.readInput();
    solver.solve();
    return 0;
}