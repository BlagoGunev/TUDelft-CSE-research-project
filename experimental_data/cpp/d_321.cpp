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

int a[40][40],b[40][40];

int func(int N, int X, int flip){
    int i,j,k,l;
    
    REP(i,N) REP(j,N) a[i][j] = b[i][j];
    REP(i,X+1) if(flip&(1<<i)) REP(k,X+1) REP(l,X+1) a[X+k][i+l] = -a[X+k][i+l];
    
    int ans = 0;
    REP(i,N) ans += a[X][i];
    
    REP(i,X) REP(j,N) a[i][j] += a[X+1+i][j];
    
    REP(i,X){
        int type0 = a[i][X];
        REP(j,X) type0 += max(a[i][j]+a[i][X+1+j], -a[i][j]-a[i][X+1+j]);
        int type1 = -a[i][X];
        REP(j,X) type1 += max(a[i][j]-a[i][X+1+j], -a[i][j]+a[i][X+1+j]);
        ans += max(type0, type1);
    }
    
    return ans;
}

int main(void){
    int N,X,i,j;
    
    cin >> N;
    REP(i,N) REP(j,N) cin >> b[i][j];
    X = N / 2;
    
    int ans = -(1<<29);
    
    int mask;
    REP(mask,(1<<(X+1))){
        int tmp = func(N, X, mask);
        ans = max(ans, tmp);
    }
    
    cout << ans << endl;
    
    return 0;
}