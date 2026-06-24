#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long
#define N 200005
#define inf 0x7fffffff
#define mod 1000000007
inline ll read(){
    ll x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

ll n;
ll bin[N];
ll head[N],nxt[N],to[N],sz[N];
ll xb[N],yb[N],x[N],y[N];
ll cntx,cnty;
ll point,sum,cnt,ans;
bool vis[N];

ll erfenx(ll x){
	ll l = 1,r = cntx;
	while(l <= r){
		ll mid = (l+r)>>1;
		if(xb[mid] == x)
			return mid;
		else if(xb[mid] > x)
			r = mid-1;
		else l = mid+1;
	}
}

ll erfeny(ll x){
	ll l = 1,r = cnty;
	while(l <= r){
		ll mid = (l+r)>>1;
		if(yb[mid] == x)
			return mid;
		else if(yb[mid] > x)
			r = mid-1;
		else l = mid+1;
	}
}

void insert(ll x,ll y){
	to[++cnt] = y; nxt[cnt] = head[x]; head[x] = cnt;
	to[++cnt] = x; nxt[cnt] = head[y]; head[y] = cnt;
}

void dfs(ll x){
	if(x <= cntx)
		point += sz[x];
	sum++;
	vis[x] = true;
	for(ll i = head[x];i;i = nxt[i])
		if(!vis[to[i]])
			dfs(to[i]);
}

signed main(){
	bin[0] = 1;
	for(ll i = 1;i <= 200000;i++)
		bin[i] = (bin[i-1]*2)%mod;
	n = read(); ans = 1;
	for(ll i = 1;i <= n;i++){
		xb[i] = x[i] = read();
		yb[i] = y[i] = read();
	}
	sort(xb+1,xb+n+1);
	sort(yb+1,yb+n+1);
	cntx = 1; cnty = 1;
	for(ll i = 2;i <= n;i++)
		if(xb[i] != xb[i-1])
			xb[++cntx] = xb[i];
	for(ll i = 2;i <= n;i++)
		if(yb[i] != yb[i-1])
			yb[++cnty] = yb[i];
	for(ll i = 1;i <= n;i++){
		x[i] = erfenx(x[i]);
		y[i] = erfeny(y[i]);
		sz[x[i]]++;
		sz[y[i]+cntx]++;
	}
	for(ll i = 1;i <= n;i++)
		insert(x[i],y[i]+cntx);
	for(ll i = 1;i <= cntx;i++)
		if(!vis[i]){
			point = 0; sum = 0;
			dfs(i);
			if(point+1 == sum) ans = (ans*(bin[sum]-1))%mod;
			else ans = (ans*bin[sum])%mod;
		}
	printf("%I64d\n",ans);
	return 0;
}