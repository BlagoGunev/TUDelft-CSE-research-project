#include <iostream>
#include <cstdio>
#include <cctype>
#include <cmath>
#include <complex>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <list>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <stack>
#include <sstream>
#include <utility>

using namespace std;
//using namespace __gnu_cxx;

typedef long long LL;
typedef double DB;
typedef unsigned int uint;
typedef vector<int> VI;
typedef vector<vector<int> > VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef istringstream IS;
typedef ostringstream OS;

#define INF (1<<30)
#define INFLL (1LL<<61LL)
#define EPS (1e-9)
#define PB push_back
#define MP make_pair
#define FI first
#define SE second
#define ALL(v) (v).begin(),(v).end()
#define REP(i,n) for(int (i)=0;(i)<(n);++(i))
#define FUP(i,a,b) for(int (i)=(a);(i)<=(b);++(i))
#define FDN(i,a,b) for(int (i)=(a);(i)>=(b);--(i))
#define FORS(i,a) for(int (i)=0;(i)<(int)(a).size();++(i))
#define FORE(i,a) for(__typeof((a).begin()) i=(a).begin();i!=(a).end();++i)
#define PRINT(v) for(int (i)=0;(i)<(int)(v).size();(i)++) cerr<<v[i]<<" "; cerr<<endl;

int main(){
    ios::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<PII> tab;
    int x;
    REP(i,n){
        cin >> x;
        tab.PB(MP(x,i+1));
    }
    REP(i,n){
        cin >> x;
        tab.PB(MP(x,i+1));
    }
    int m;
    cin >> m;

    sort(ALL(tab));

    LL res = 1LL;
    int k = 0;
    int d = 0;
    tab.PB(MP(INF,INF));
    FORS(i,tab){
        if(i == 0 || tab[i].FI != tab[i-1].FI) {
            LL g = 1LL;
            REP(i,k) {
                int j = i + 1;
                while(d && j % 2 == 0) {
                    j /= 2;
                    --d;
                }
                g *= j;
                g %= m;
            }
            res *= g;
            res %= m;
            d = k = 0;
        }
        ++k;
        if(i != 0 && tab[i] == tab[i-1])
            ++d;
    }
    cout << res << endl;
    return 0;
}