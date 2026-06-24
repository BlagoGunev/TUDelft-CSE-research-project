// LUOGU_RID: 101049321
//Linkwish's code

#include<bits/stdc++.h>

#define si static inline

#define int long long

#define fi first

#define se second

using namespace std;

typedef const int ci;

typedef long long ll;

typedef	__int128 i128;

typedef pair<int,int> pii;

const int iinf=0x7fffffff;

const ll linf=4e18;

using namespace std;

ci N=500005,mod=998244353;

int n,K,m;

int ans=1;

struct T{

	int l,r,x;

}a[N];

int f[N],pos[N],c[N];

inline void solve(int now){

	memset(c,0,sizeof c);

	memset(f,0,sizeof f);

	memset(pos,0,sizeof pos);

	for(int i=1;i<=m;i++){

		if(a[i].x&(1<<now))c[a[i].l]++,c[a[i].r+1]--;

		else pos[a[i].r+1]=max(pos[a[i].r+1],a[i].l);

	}

	f[0]=1;

	int sum=0,pre=1,cur=0;

	for(int i=1;i<=n+1;i++){

		sum+=c[i];

		while(cur<pos[i])pre=(pre-f[cur++]+mod)%mod;

		if(!sum)f[i]=pre;

		pre=(pre+f[i])%mod;

	}

	ans=ans*f[n+1]%mod;

}

signed main(){

	ios::sync_with_stdio(0);

	cin.tie(0),cout.tie(0);

	cin>>n>>K>>m;

	for(int i=1;i<=m;i++)cin>>a[i].l>>a[i].r>>a[i].x;

	for(int i=0;i<K;i++)solve(i);

	cout<<ans;

	return 0;

}