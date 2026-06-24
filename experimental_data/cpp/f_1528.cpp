#include<bits/stdc++.h>

using namespace std;

const int P=998244353,G=3,iG=332748118,imG=86583718;//大模数:P = 4179340454199820289, G = 3 

const int N=3e5+10;//1e5:3e5,1e6:3e6

const int INIT=18;//1e5:18,1e6:21



typedef vector<int> poly;

int qpow(int x,int q,int p=P){

	int res=1;

	while(q){

		if(q&1) res=1ll*res*x%p;

		x=1ll*x*x%p,q>>=1;

	}

	return res;

} 



int fac[N],ifac[N],inv[N],rev[N],Cn[N];

void fac_init(int t, int n){

	Cn[0]=fac[0]=fac[1]=inv[1]=1;

	for(int i=2;i<=t;++i)  fac[i]=1ll*fac[i-1]*i%P,inv[i]=1ll*inv[P%i]*(P-P/i)%P;

	ifac[t]=qpow(fac[t],P-2);

	for(int i=t-1;i>=0;--i) ifac[i]=1ll*(i+1)*ifac[i+1]%P;

	for(int i=1;i<=t;++i) Cn[i]=1ll*Cn[i-1]*(n-i+1)%P*inv[i]%P;

}



namespace NTT{

int ntt_init(int n){

	int lim=1,l=0;

	while(lim<=n) lim<<=1,++l;

	for(int i=0;i<lim;i++) rev[i]=(rev[i>>1]>>1)|((i&1)<<(l-1));

	return lim;

}



void ntt(poly &y,int lim,int type){

	y.resize(lim);

	for(int i=0;i<lim;i++) if(i<rev[i]) swap(y[i],y[rev[i]]);

	for(int h=2;h<=lim;h<<=1){

		int wn=qpow(type==1 ? G : iG,(P-1)/h);

		for(int j=0;j<lim;j+=h){

			int w=1;

			for(int k=j;k<j+h/2;k++,w=1ll*w*wn%P){

				int u=y[k],v=1ll*w*y[k+h/2]%P;

				y[k]=(u+v)%P,y[k+h/2]=(u-v+P)%P;

			}

		}

	}

	if(!type){

		int inv=qpow(lim,P-2);

		for(int i=0;i<lim;++i) y[i]=1ll*y[i]*inv%P;

	}

}

}using namespace NTT;



poly poly_mul(poly f,poly g,bool siz=true){

	int deg=f.size()+g.size()-1;

	int lim=ntt_init(deg);

	ntt(f,lim,1),ntt(g,lim,1);

	for(int i=0;i<lim;++i) f[i]=1ll*f[i]*g[i]%P;

	ntt(f,lim,0);

	if(siz) f.resize(deg);

	return f;

}



poly Stirling_2_row(int n){

	poly A,B;

	for(int i=0;i<=n;++i){

		A.push_back(1ll*qpow(i,n)*ifac[i]%P);

		B.push_back(i&1?P-ifac[i]:ifac[i]);

	}

	A=poly_mul(A,B);

	A.resize(n+1);

	return A;

}



int main(){

	int n, k, ans = 0; cin>>n>>k;

	fac_init(k, n);

	poly S = Stirling_2_row(k);

	for(int i = 0; i<=min(n, k); ++i){

		ans = ((ans + 1ll * fac[i] * Cn[i] % P * S[i] % P * qpow(n+1, n-i) % P) % P + P)%P;

	}

	cout << ans;

}