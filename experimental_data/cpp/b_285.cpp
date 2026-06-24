#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <time.h>
#include <cctype>
#include <functional>
#include <deque>
#include <iomanip>
#include <bitset>
#include <assert.h>
#include <numeric>
#include <sstream>
#include <utility>

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(a) (a).begin(),(a).end()
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define FORD(i,a,b) for (int i=(a); i>=(b); i--)
#define REP(i,b) FOR(i,0,b)
#define ll long long
#define sf scanf
#define pf printf
#define Maxn 100010
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

int n, s, t;
int p[Maxn];
bool vis[Maxn];
int main() {
    ios::sync_with_stdio(false);
    cin >>n >>s >>t;
    FOR(i, 1, n+1) cin >>p[i];
    memset(vis, false, sizeof(vis));
    int ans = 0;
    bool flag = false;
    while (true) {
        vis[s] = true;
        if (s == t) {
            flag = true;
            break;
        }
        int v = p[s];
        if (vis[v]) break;
        else s = v, ans++;
    }
    if (!flag) ans = -1;
    cout <<ans <<endl;
    return 0;
}