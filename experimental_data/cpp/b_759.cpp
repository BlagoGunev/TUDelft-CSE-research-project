#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <iomanip>
#include <cassert>
using namespace std;

#define GET_ARG(a,b,c,F,...) F
#define REP3(i,s,e) for (i = s; i <= e; i++)
#define REP2(i,n) REP3 (i,0,(int)(n)-1)
#define REP(...) GET_ARG (__VA_ARGS__,REP3,REP2) (__VA_ARGS__)
#define RREP3(i,s,e) for (i = s; i >= e; i--)
#define RREP2(i,n) RREP3 (i,(int)(n)-1,0)
#define RREP(...) GET_ARG (__VA_ARGS__,RREP3,RREP2) (__VA_ARGS__)
#define DEBUG(x) cerr << #x ": " << x << endl

int main(void) {
    int i, n;
    scanf("%d",&n);
    queue<pair<int,int>> q2, q3;
    int sum2 = 0, sum3 = 0;
    REP (i,n) {
        int t;
        scanf("%d",&t);
        while (!q2.empty() && q2.front().first <= t-90) {
            sum2 -= q2.front().second;
            q2.pop();
        }
        while (!q3.empty() && q3.front().first <= t-1440) {
            sum3 -= q3.front().second;
            q3.pop();
        }
        if (sum2 >= 50 || sum3 >= 120)
            puts("0");
        else {
            int x = min({20,50-sum2,120-sum3});
            q2.push({t,x});
            q3.push({t,x});
            sum2 += x;
            sum3 += x;
            printf("%d\n",x);
        }
    }
    return 0;
}