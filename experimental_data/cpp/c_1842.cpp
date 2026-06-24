#include <algorithm>
#include <iostream>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <numeric>
#include <cstdio>
#include <string>
#include <vector>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include<bitset>
 
using namespace std;
 
typedef long long ll;
typedef pair < int, int > pii;
 
#define nd second
#define st first
#define mp make_pair
#define pb push_back
#define orta (((bas)+(son))/2)
#define sol (k+k)
#define sag (k+k+1)
 
const int N = 5e5 + 5;
const int M = 605;
const int inf = 1e9 + 5;
const ll linf = 1e18 + 5;
const int mod = 1e9 + 7;
const int logN = 17;

int t, a[N], nx[N], dp[N + 1], c, n, m, cur, x;;

int main() {
 
    scanf("%d", &t);

    while(t--) {
       scanf("%d", &n);
       for(int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            nx[i] = inf;
            dp[i] = inf;
       }
       dp[n + 1] = 0;
       for(int i = n; i >= 1; i--) {
            dp[i] = dp[i + 1] + 1;
            if(nx[a[i]] < inf) {
                dp[i] = min(dp[i], nx[a[i]]);
            }
            nx[a[i]] = min(dp[i + 1], nx[a[i]]);
       }
       cout << n - dp[1] << endl;
    }

    return 0;
}