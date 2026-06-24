#include <bits/stdc++.h>
#define ll long long
#define scn(n) scanf("%d", &n)
#define lscn(n) scanf("%lld", &n)
#define lpri(n) printf("%lld", n)
#define pri(n) printf("%d", n)
#define pln() printf("\n")
#define priln(n) printf("%d\n", n)
#define lpriln(n) printf("%lld\n", n)
#define rep(i, init, n) for (int i = init; i < n; i++)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define gcd _gcd
using namespace std;
const ll mod = 1e9 + 7;
const int N = 998244353;
using namespace std;
int main(){
    int n, count[6] = {0}, min = INT_MAX;
    scn(n);
    rep(i, 0, n){
        int x;
        scn(x);
        if(x == 4) count[0]++;
        if(x == 8) count[1]++;
        if(x == 15) count[2]++;
        if(x == 16) count[3]++;
        if(x == 23) count[4]++;
        if(x == 42) count[5]++;
        rep(i, 1, 6){
            if(count[i] > count[i - 1]){
                count[i]--;
                break;
            }
        }
    }
    rep(i, 0, 6) if(count[i] < min) min = count[i];
    pri(n - 6 * min);
    return 0;
}