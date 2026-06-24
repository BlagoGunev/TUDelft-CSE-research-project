#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#define __ ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define rep(i,a,b) for(int i = a; i <= b; i++)
#define LOG1(x1,x2) cout << x1 << ": " << x2 << endl;
#define LOG2(x1,x2,y1,y2) cout << x1 << ": " << x2 << " , " << y1 << ": " << y2 << endl;
#define LOG3(x1,x2,y1,y2,z1,z2) cout << x1 << ": " << x2 << " , " << y1 << ": " << y2 << " , " << z1 << ": " << z2 << endl;
typedef long long ll;
typedef double db;
const int N = 2*1e5+100;
const int M = 1e5+100;
const db EPS = 1e-9;
using namespace std;

int n,m,k,tot,vis[N];
ll sum[N],dp[N],a[N];
struct Node{
	int x,y;
	bool operator < (Node xx) const {
		return x < xx.x;
	}
}e[N];

int main()
{
	scanf("%d%d%d",&n,&m,&k);
	rep(i,1,n) scanf("%lld",&a[i]);
	rep(i,1,m){
		int xx,yy; scanf("%d%d",&xx,&yy);
		if(yy > vis[xx]) vis[xx] = yy, e[++tot] = {xx,yy};
	}
	sort(a+1,a+1+n);
	sort(e+1,e+1+tot);
	rep(i,1,n) sum[i] = sum[i-1]+a[i];
	rep(i,1,k){
		dp[i] = dp[i-1]+a[i];
		rep(j,1,tot){
			if(e[j].x > i) break;
			int xx = i-e[j].x;
			dp[i] = min(dp[i],dp[xx]+sum[i]-sum[xx+e[j].y]);
		}
	}
	printf("%lld\n",dp[k]);
	return 0;
}