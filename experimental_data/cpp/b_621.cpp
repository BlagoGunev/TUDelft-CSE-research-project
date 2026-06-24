//#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <stack>
#include <map>
#include <vector>
#include <set>
#include <bitset>
#include <string>
#include <queue>
using namespace std;
#define rep(i,l,r) for(i = l; i <= r; i++)
#define red(i,l,r) for(i=(l);i>=(r);i--)
#define u_long unsigned long long
#define fff(i, u) for(i = head[u]; i != -1; i = nxt[i])
#define fin() freopen("in.txt", "r", stdin)
#define fout() freopen("in2.txt", "w", stdout)
#define clr(vis, a) memset(vis, a, sizeof(vis))
#define LL long long
#define ls id << 1
#define rs id << 1 | 1
#define lson id << 1, l, mid
#define rson id << 1 | 1, mid + 1, r
#define mid ( (l + r) >> 1 )
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define X first
#define Y second
#define eps 1e-9
#define pi acos(-1.0)
const int maxn = 1e3 + 10;
const int maxm = 500 * 500 + 10;
const int inf = 1e9;
const int mod = 1e9 + 7;
int getint() {
    char c;
    while((c = getchar()) && !(c >= '0' && c <= '9') && c != '-');
    int ret = c - '0', sgn = 0;
    if(c == '-') sgn = 1, ret = 0;
    while((c = getchar()) && c >= '0' && c <= '9')
        ret = ret * 10 + c - '0';
    if(sgn) ret = -ret;
    return ret;
}
int vis1[maxn*4], vis2[maxn*4];;
vector<pii>g;
int main(){
    int n = getint();
    clr(vis1, 0);
    clr(vis2, 0);
    for(int i = 1; i <= n; i ++){
        int x = getint(), y = getint();
        vis1[x + y]++;
        vis2[x - y + 2001] ++;
    }
    LL ans = 0;
    for(int i = 0; i <= 4000; i ++){
        int temp = vis1[i];
        ans += (LL)temp * (temp - 1) / 2;
        temp = vis2[i];
        ans += (LL)temp * (temp - 1) / 2;
    }
    cout << ans << endl;
    return 0;
}