#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
#include <cmath>
#include <cstring>
#include <string>
#include <iostream>
#include <complex>
#include <sstream>
using namespace std;
 
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef vector<int> VI;
typedef pair<int,int> PII;
 
#define REP(i,n) for(int i=0;i<(n);++i)
#define SIZE(c) ((int)((c).size()))
#define FOR(i,a,b) for (int i=(a); i<(b); ++i)
#define FOREACH(i,x) for (__typeof((x).begin()) i=(x).begin(); i!=(x).end(); ++i)
#define FORD(i,a,b) for (int i=(a)-1; i>=(b); --i)
#define ALL(v) (v).begin(), (v).end()
 
#define pb push_back
#define mp make_pair
#define st first
#define nd second

int food[222222];
PII pairs[111111];
int p[222222];

int main() {
    ios_base::sync_with_stdio(0);

    int N;
    scanf("%d", &N);
    REP(i,N) {
        scanf("%d%d", &pairs[i].st, &pairs[i].nd);
        --pairs[i].st;
        --pairs[i].nd;
        p[pairs[i].st] = pairs[i].nd;
        p[pairs[i].nd] = pairs[i].st;
    }

    REP(i,2*N) if (!food[i]) {
        food[i] = 1;
        food[i+1] = 2;
        int c = p[i+1];
        while (c != i) {
            food[c] = 1;
            food[c^1] = 2;
            c = p[c^1];
        }
    }
    
    REP(i,N) printf("%d %d\n", food[pairs[i].st], food[pairs[i].nd]);
}