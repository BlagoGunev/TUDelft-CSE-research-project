#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>

using namespace std;

#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define snuke(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)

typedef long long ll;
#define MOD 1000000007ll

int N;
int a[100010];
int sum[100010];
ll F[100010],inv[100010],Finv[100010];

ll comb(int X, int Y){
    return F[X+Y] * Finv[X] % MOD * Finv[Y] % MOD;
}

ll func(int L, int R){
    int i;
    
    if(sum[L] == sum[R]){
        ll two = 1;
        REP(i,R-L-1) two = two * 2 % MOD;
        return two;
    }
    
    int p,q;
    for(p=L;p<R;p++) if(a[p] != 0) break;
    for(q=R-1;q>=L;q--) if(a[q] != 0) break;
    
    if(p == q && a[p] == 1) return comb(p-L, R-p-1);
    
    ll ans = 0;
    
    if(a[p] >= a[q]){
        int L2 = p;
        int R2 = L2 + a[p];
        if(R2 > q && R2 <= R) ans += func(L2+1, R2) * comb(L2-L, R-R2);
    }
    
    if(a[p] <= a[q]){
        int R2 = q + 1;
        int L2 = R2 - a[q];
        if(L2 >= L && L2 <= p) ans += func(L2, R2-1) * comb(L2-L, R-R2);
    }
    
    // cout << L << ' ' << R << ' ' << ans << endl;
    
    return ans % MOD;
}

int main(void){
    int i;
    
    cin >> N;
    REP(i,N) scanf("%d", &a[i]);
    
    REP(i,N) sum[i+1] = sum[i] + ((a[i] == 0) ? 0 : 1);
    inv[1] = 1;
    for(i=2;i<100010;i++) inv[i] = (MOD - MOD/i) * inv[MOD%i] % MOD;
    F[0] = Finv[0] = 1;
    for(i=1;i<100010;i++){
        F[i] = F[i-1] * i % MOD;
        Finv[i] = Finv[i-1] * inv[i] % MOD;
    }
    
    ll ans = func(0, N);
    cout << ans << endl;
    
    return 0;
}