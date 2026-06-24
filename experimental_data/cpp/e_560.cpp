//只用维护左上角到每一个点的不经过其他黑点的方案数即可

//根本不需要容斥 

#include<bits/stdc++.h>

#define N 200005

#define LL long long

using namespace std;

const int mod=1e9+7;

//---------------

int fac[N],rvfac[N],rv[N];

void pre(){

	rv[1]=1;fac[0]=1;rvfac[0]=1;

	for(int i=2;i<N;i++) rv[i]=((-(LL)rv[mod%i]*(mod/i))%mod+mod)%mod;

	for(int i=1;i<N;i++) fac[i]=(LL)fac[i-1]*i%mod,rvfac[i]=(LL)rvfac[i-1]*rv[i]%mod;

}

int C(int r,int n){

	if(r>n) return puts("WA"),0;

	return (LL)fac[n]*rvfac[r]%mod*rvfac[n-r]%mod;

}

//---------------

struct point{

	int h,l,ans;

	bool operator <(const point &b)const{

		return h+l<b.h+b.l;

	}

}p[2005];int n,h,w;

int main(){

	pre();

	scanf("%d%d%d",&h,&w,&n);

	for(int i=1;i<=n;i++) scanf("%d%d",&p[i].h,&p[i].l);

	p[++n]=(point){h,w,0};

	sort(p+1,p+n+1);

	for(int i=1;i<=n;i++){

		LL ans=C(p[i].l-1,p[i].h+p[i].l-2);

		for(int j=1;j<i;j++){

			if(p[j].h<=p[i].h&&p[j].l<=p[i].l){

				ans-=C(p[i].l-p[j].l,p[i].l+p[i].h-p[j].l-p[j].h)*(LL)p[j].ans%mod;

			}

		}

		p[i].ans=(ans%mod+mod)%mod;

	}

	cout<<p[n].ans<<endl;

	return 0;

}