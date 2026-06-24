#include <cstdio>

#include <iostream>

#include <queue>

#include <cmath>

#include <cstring>

#include <algorithm>

#include <cstdlib>

#include <vector>

#include <set>

#include <stack>

#include <cctype>

#include <fstream>

#include <sstream>

#include <bitset>

#include <utility>

#include <map>

#include <list>

 

using namespace std;

 

#define loop(x,y,z) for(int x=y;x<=z;x++)

#define pi acos(-1.0)

#define sz(a) (int)(a).size()

#define NMAX 2147483647

#define LMAX 9223372036854775807LL

#define pb push_back

#define mp make_pair

#define ll long long

#define pf printf

#define mem(x,y) memset(x,y,sizeof(x))

#define rep(x,y) for(int x=1;x<=y;x++)

#define pii pair<int,int>

#define pll pair<ll,ll>

#define gi(k) scanf("%d",&k)

#define gl(k) scanf("%lld",&k)

#define PI acos(-1.0)

#define eps 1e-8

#define fi first

#define sc second

#define inf 1e13

#define endl "\n"

#define FO(i,n) for(int i = 0; i < n; i++)

#define debug(x) cout << #x << ": " << x << endl

#define gcd(a,b) __gcd(a,b)

#define lcm(a,b) (a*b)/gcd(a,b)

 

const int INF = (int) 1e9;

const long long INF64 = (long long) 1e18;

 

#pragma comment (linker,"/STACK:16777216")

#pragma warning(disable:4786)

 

int Set(int N , int pos){return N = N | (1 << pos); }

int Reset(int N , int pos){return N = N & ~(1 << pos); }

bool check(int N, int pos){return (bool) (N & (1<<pos)); }

double dis(int x1, int y1, int x2, int y2) {return hypot(x1-x2, y1-y2);}

 

const int mx=1<<29;

int ans,sum,t,n,k,m,ar[102],mat[102][102],x,y;

 

int dx[] = {0,1,-1,0,0};

int dy[] = {0,0,0,1,-1};

 

int main()

{

//ios::sync_with_stdio(false);cin.tie(0);

//freopen("00_input.txt", "r", stdin);freopen("00_output.txt", "w", stdout);

 

 ans = NMAX;

 cin >> n >> m;



 rep(i,n) gi(ar[i]);



 rep(i,m)

 {

 	gi(x); gi(y);



 	mat[x][y] = mat[y][x] = 1;

 }



 rep(i,n)

 {

 	loop(j,i+1,n)

 	{

 		loop(p,j+1,n)

 		{

 			if(mat[i][j] == 1 && mat[j][p] == 1 && mat[p][i] == 1)

 			{

 				ans = min(ans, ar[i]+ar[j]+ar[p]);

 			}

 		}

 	}

 }



 if(ans == NMAX) ans = -1;



 cout << ans << endl;

 

return 0;

}