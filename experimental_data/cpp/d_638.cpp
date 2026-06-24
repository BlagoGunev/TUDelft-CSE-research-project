#include <iostream>
#include <fstream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <cstring>
#include <cmath>
#include <stack>
#include <deque>
#include <iomanip>
#include <cassert>
#include <bitset>
#include <tuple>
using namespace std;

inline void operator delete(void * A) {}
inline void operator delete[](void * A) {}

#define _U unsigned
#define ll long long

typedef pair<int,int> pii;
typedef pair<pii,int> ppi;
typedef pair<ll,ll> pll;


#define F first
#define S second

#define  FOR(I,N) for (auto I=0;I <N;++I)
#define BFOR(I,N) for (auto I=N;I>=0;--I)

int DATE[]= {-1,31,29,31,30,31,30,31,31,30,31,30,31};

#define ld double
#define _FL_ setprecision

const ld PI = 3.14159265358979323846;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

typedef
tree<
  int,  //!
  null_type,
  less<int>, //!
  rb_tree_tag,
  tree_order_statistics_node_update>
ordered_set;

ordered_set t;

// t.order_of_key(2)
// *t.find_by_order(0)


char PR[105][105][105];

inline bool GG(int i,int j,int k){
    if (!PR[i][j][k]) return false;
    if (!PR[i-1][j][k] && !PR[i][j-1][k] && !PR[i][j][k-1]) return false;
    if (!PR[i+1][j][k] && !PR[i][j+1][k] && !PR[i][j][k+1]) return false;

    if (PR[i-1][j][k] && PR[i+1][j][k]) return true;
    if (PR[i][j-1][k] && PR[i][j+1][k]) return true;
    if (PR[i][j][k-1] && PR[i][j][k+1]) return true;

    if (PR[i-1][j][k] && PR[i][j+1][k] && !PR[i-1][j+1][k]) return true;
    if (PR[i-1][j][k] && PR[i][j][k+1] && !PR[i-1][j][k+1]) return true;
    if (PR[i][j-1][k] && PR[i+1][j][k] && !PR[i+1][j-1][k]) return true;
    if (PR[i][j-1][k] && PR[i][j][k+1] && !PR[i][j-1][k+1]) return true;
    if (PR[i][j][k-1] && PR[i+1][j][k] && !PR[i+1][j][k-1]) return true;
    if (PR[i][j][k-1] && PR[i][j+1][k] && !PR[i][j+1][k-1]) return true;
    return false;
}

int main(){
    iostream::sync_with_stdio(0);
    cin.tie(0);
    int N,M,K;
    cin >> N >> M >> K;
    FOR(i,N)
        FOR(j,M)
            cin >> (PR[i+1][j+1] + 1);
    int ans = 0;
    for (int i=1;i<=N;i++)
        for (int j=1;j<=M;j++)
            for (int k=1;k<=K;k++)
                PR[i][j][k] -='0';
    for (int i=1;i<=N;i++)
        for (int j=1;j<=M;j++)
            for (int k=1;k<=K;k++)
                ans+= GG(i,j,k);
    cout<< ans;
    return 0;
}