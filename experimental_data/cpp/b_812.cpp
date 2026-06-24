#include <iostream>
#include <sstream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <climits>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <stack>
#include <deque>
#include <queue>
#include <utility>
using namespace std;

#define FOR(i,a,b) for(int i = (a); i <= (b); i++)
#define DOW(i,a,b) for(int i = (a); i >= (b); i--)
#define REP(i,a) for(int i=0,_a=(a); i<_a; ++i)
#define FORI(it, x) for (__typeof((x).begin()) it = (x).begin(); it != (x).end(); it++)
#define RESET(c,val) memset(c,val,sizeof(c))

#define ALL(x) x.begin(), x.end()
#define UNIQUE(c) (c).resize(unique(ALL(c)) - (c).begin())

#define sz(a) int(a.size())
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define inf(t) numeric_limits<t>::max()

// bitmask
#define isOn(S, j) (S & (1 << j))
#define setBit(S, j) (S |= (1 << j))
#define clearBit(S, j) (S &= ~(1 << j))
#define toggleBit(S, j) (S ^= (1 << j))
#define lowBit(S) (S & (-S))
#define setAll(S, n) (S = (1 << n) - 1)

// other manipulation
#define modulo(S, N) ((S) & (N - 1)) // return S % N, where N = 2^k
#define isPowerOfTwo(S) (!(S & (S - 1))
#define nearestPowerOfTwo(S) ((int)pow(2.0, (int)((log((double)S) / log(2.0)) + 0.5)))
#define turnOffLastBit(S) ((S) & (S-1))
#define turnOnLastZero(S) ((S) | (S+1))
#define turnOffLastConsecutiveBits(S) ((S) & (S + 1))
#define turnOnLastConsecutiveZeroes(S) ((S) & (S - 1))


typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

/*---------------------------*/

//    freopen("/Users/apple/Desktop/inp.txt", "r", stdin);
//    freopen("/Users/apple/Desktop/out.txt", "w", stdout);

int n, m, lm[100], rm[100], minL, minR;
int endstage = 0;
vector<string> v;

void rec(int stage, char side, int cost) {
//    cout << stage << ' ' << side << ' ' << cost << '\n';
    
    if (stage == endstage) {
        if (side == 'L') minL = min(minL, cost);
        else minR = min(minR, cost);
        return;
    }
    
    if (side == 'L') {
        if (lm[stage] == 0) rec(stage - 1, 'L', cost + (stage != 1));
        else rec(stage - 1, 'L', cost + 2*(rm[stage] - 1) + (stage != 1));
        
        rec(stage - 1, 'R', cost + m-1 + (stage != 1));
    }
    else if (side == 'R') {
        if (rm[stage] == 0) rec(stage - 1, 'R', cost + (stage != 1));
        else rec(stage - 1, 'R', cost + 2*(m - lm[stage]) + (stage != 1));
        
        rec(stage - 1, 'L', cost + m-1 + (stage != 1));
    }
}

int main() {
    
    cin >> n >> m;
    m += 2;
    v.pb("");
    REP(i,n) {
        string s; cin >> s; s = " " + s;
        v.pb(s);
    }
    
    memset(lm, 0, sizeof lm);
    memset(rm, 0, sizeof rm);
    FOR(i,1,n) {
        FOR(j,1,m) if (v[i][j] == '1') { lm[i] = j; break; }
        DOW(j,m,1) if (v[i][j] == '1') { rm[i] = j; break; }
    }
    
    FOR(i,1,n)
        if (lm[i] != 0) { endstage = i; break; }
    
    if (endstage == 0) { cout << 0; return 0; }
    
    if (endstage == n) { cout << rm[n] - 1; return 0; }
        
    minL = minR = 1e9;
    if (lm[n] == 0) rec(n-1, 'L', (n != 1));
    else rec(n-1, 'L', (n != 1) + 2*(rm[n] - 1));
    rec(n-1, 'R', m-1 + (n != 1));
    
    if (rm[endstage] != 0) minL += (rm[endstage] - 1);
    if (lm[endstage] != 0) minR += (m - lm[endstage]);
    cout << min(minL, minR);
    
    return 0;
}