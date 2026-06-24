#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define inf 1000000000
#define inf64 1000000000000000000
#define F first
#define S second
#define ll int
#define N 1010
#define M 5010
using namespace std;
ll n,k,a[N][N],f[N][M],g[N][M],totf[N],totg[N],curto[N];
int main(){
	ll t;
	scanf("%d",&t);
	for(int testcases=0;testcases<t;testcases++){
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;i++) for(int j=i;j<=n;j++) scanf("%d",&a[i][j]);
		totg[0]=1,totf[0]=0;
		g[0][0]=0;
		for(int i=1;i<=n+1;i++){
			//g
			{
				curto[0]=curto[1]=0;
				priority_queue<pair<ll,ll> > pq;
				if(curto[0]<totf[i-1]) pq.push(make_pair(f[i-1][0],0));
				if(curto[1]<totg[i-1]) pq.push(make_pair(g[i-1][0],1));
				totg[i]=0;
				while(totg[i]<k&&(!pq.empty()))
				{
					ll w=pq.top().F,x=pq.top().S;
					pq.pop();
					g[i][totg[i]++]=w;
					curto[x]++;
					if(curto[x]<(x?totg[i-1]:totf[i-1])) pq.push(make_pair(x?g[i-1][curto[x]]:f[i-1][curto[x]],x));
				}
			}
			//f
			{
				priority_queue<pair<ll,ll> > pq;
				for(int j=0;j<i;j++){
					curto[j]=0;
					if(curto[j]<totg[j]) pq.push(make_pair(g[j][0]+a[j+1][i],j));
				}
				totf[i]=0;
				while(totf[i]<k&&(!pq.empty()))
				{
					ll w=pq.top().F,x=pq.top().S;
					pq.pop();
					f[i][totf[i]++]=w;
					curto[x]++;
					if(curto[x]<totg[x]) pq.push(make_pair(g[x][curto[x]]+a[x+1][i],x));
				}
			}
		}
		for(int i=0;i<k;i++) printf("%d ",g[n+1][i]);
		puts("");
	}
	return 0;
}