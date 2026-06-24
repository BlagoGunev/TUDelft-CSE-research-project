#include<bits/stdc++.h>

#define ll long long

using namespace std;

const ll M=1e5+7;

int T,n,k; ll f[M][27],sigphi[M];

ll c(int l,int r){

	ll ans=0,nw;

	while(l<=r){

		nw=r/(r/l);

		ans+=sigphi[r/l]*(nw-l+1);

		l=nw+1;

	}

	return ans;

}

void solve(int k,int l,int r,int tl,int tr){

	if(l>r) return;

	int mid=(l+r)>>1,tmid;

	ll cost=c(min(tr+1,mid),mid);

	f[mid][k]=1e18;

	for(int i=min(tr,mid-1);i>=tl;i--){

		if(cost+f[i][k-1]<f[mid][k])

			f[mid][k]=cost+f[i][k-1],tmid=i;

		cost+=sigphi[mid/i];

	}

	solve(k,l,mid-1,tl,tmid);

	solve(k,mid+1,r,tmid,tr);

}

int main(){

	scanf("%d",&T);

	for(int i=1;i<M;i++){

		sigphi[i]+=i;

		for(int j=i+i;j<M;j+=i) sigphi[j]-=sigphi[i];

	}

	for(int i=1;i<M;i++)

		sigphi[i]+=sigphi[i-1],f[i][1]=(ll)i*(i+1)/2;

	for(int i=2;i<=20;i++) solve(i,i,M-1,i-1,M-1);

	while(T--){

		scanf("%d%d",&n,&k);

		printf("%lld\n",(k>20||(1<<k)>n)?n:f[n][k]);

	}

	return 0;

}