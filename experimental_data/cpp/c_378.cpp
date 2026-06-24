#include <cstdio>
#include <vector>
#include <cstring>
#include <functional>
#include <algorithm>
#include <math.h>
#include <bitset>
#include <set>
#include <queue>
#include <iostream>
#include <string>
#include <sstream>
#include <stack>
#include <complex>
#include <numeric>
#include <map>
#include <time.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<int,pii> pip;
typedef pair<pii,int> ppi;
typedef pair<ll,ll> pll;
typedef pair<double,int> pdi;
typedef pair<double,double> pdd;
typedef vector<ll> vec;
typedef vector<vec> mat;
#define rep(i,n) for (int (i) = 0; (i) < (n); (i)++)
#define repn(i,a,n) for (int (i) = (a); (i) < (n); (i)++)
#define ALL(x) (x).begin(),(x).end()
#define pb push_back
#define SORT(x) sort((x).begin(),(x).end())
#define SORTN(x,n) sort((x),(x)+(n))
#define ERASE(x) (x).erase(unique((x).begin(),(x).end()),(x).end())
#define COUNT(x,c) count((x).begin(),(x).end(),(c))
#define REMOVE(x,c) (x).erase(remove((x).begin(),(x).end(),(c)),(x).end())
#define REVERSE(x) reverse((x).begin(),(x).end())
#define FORIT(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)
#define LB(x,a) lower_bound((x).begin(),(x).end(),(a))-(x).begin()
#define lb(x,a) lower_bound((x).begin(),(x).end(),(a))
#define LBN(x,a,n) lower_bound((x),(x)+(n),(a))-(x)
#define lbN(x,a,n) lower_bound((x),(x)+(n),(a))
#define UB(x,a) upper_bound((x).begin(),(x).end(),(a))-(x).begin()
#define ub(x,a) upper_bound((x).begin(),(x).end(),(a))
#define BS(x,a) binary_search((x).begin(),(x).end(),(a))
#define NB(x) (((x)&~((x)+((x)&-(x))))/((x)&-(x))>>1)|((x)+((x)&-(x)))
#define NP(x) next_permutation((x).begin(),(x).end())
#define MM(x,p) memset((x),(p),sizeof(x))
#define SQ(x) (x)*(x)
#define SC(c1,c2) strcmp(c1,c2)==0
#define mp make_pair
#define INF (1<<30)
#define INFL (1LL<<61)
#define fi first
#define se second
#define MOD 1000000007
#define EPS 1e-10

int N,M,K;
char m[500][501];
int dx[4]={1,-1,0,0},dy[4]={0,0,1,-1};

int main()
{
    scanf("%d%d%d",&N,&M,&K);
    rep(i,N)scanf("%s",&m[i]);
    int sx=0,sy=0,s=0;
    rep(i,N)rep(j,M)if(m[i][j]=='.')s++,sx=i,sy=j;
    queue<pii> q;
    q.push(mp(sx,sy));
    m[sx][sy]='X';
    int sz=1;
    while(!q.empty())
    {
        int x=q.front().fi,y=q.front().se;q.pop();
        if(sz==s-K)break;
        rep(d,4)
        {
            int nx=x+dx[d],ny=y+dy[d];
            if(0<=nx&&nx<N&&0<=ny&&ny<M&&m[nx][ny]=='.')
            {
                sz++;
                m[nx][ny]='X';
                if(sz==s-K)goto out;
                q.push(mp(nx,ny));
            }
        }
    }
    out:;
    rep(i,N)
    {
        rep(j,M)
        {
            if(m[i][j]=='X')putchar('.');
            else if(m[i][j]=='.')putchar('X');
            else putchar(m[i][j]);
        }
        puts("");
    }
}