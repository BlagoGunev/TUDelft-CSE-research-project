#include <bits/stdc++.h>
#include <stdlib.h>
#include <time.h> 
 
using namespace std;
double EPS = 1e-12;
typedef long long int lld;
typedef pair<lld,lld> PA;
long double tick(){static clock_t oldt; clock_t newt=clock();
    long double diff=1.0L*(newt-oldt)/CLOCKS_PER_SEC; oldt = newt; return diff; }
#define rep(i,a,n) for(long long int i = (a); i <= (n); ++i)
#define repI(i,a,n) for(int i = (a); i <= (n); ++i)
#define repD(i,a,n) for(long long int i = (a); i >= (n); --i)
#define repDI(i,a,n) for(int i = (a); i >= (n); --i)
#define all(c) (c).begin(), (c).end()
#define sz(a) ((int)a.size())
#ifdef LOCAL_RUN
#define Error(x...) { cout << "(" << #x << ")" << " = ( "; printIt(x); }
#else
#define Error(x...) 42
#endif
template <typename T1> void printIt(T1 t1) { cout << t1 << " )" << endl; }
template <typename T1, typename... T2>
void printIt(T1 t1, T2... t2) { cout << t1 << " , "; printIt(t2...); }
// Ab :)
#define popcount __builtin_popcountll


#define lim 300010
#define lim2 200010


lld A[lim];


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while(tt--) {
        lld n, k;
        cin >> n >> k;
        auto sumFromXToY = [&](lld x, lld y) {
            return (y * (y + 1) - x * (x - 1)) / 2;
        };
        lld minDiff = sumFromXToY(k, k + n - 1);
        lld low = 1, high = n;
        while(low <= high) {
            lld mid = (low + high) / 2;
            lld diffAtMid = abs(sumFromXToY(k, k + mid - 1) - sumFromXToY(k + mid, k + n - 1));
            lld diffAtMidMinusOne = abs(sumFromXToY(k, k + mid - 2) - sumFromXToY(k + mid - 1, k + n - 1));
            if(diffAtMid < diffAtMidMinusOne) {
                minDiff = diffAtMid;
                low = mid + 1;
            } else {
                minDiff = diffAtMidMinusOne;
                high = mid - 1;
            }
        }
        cout << minDiff << "\n";
    }
    return 0;
}