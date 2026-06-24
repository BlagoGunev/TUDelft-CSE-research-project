#include<bits/stdc++.h>

using namespace std;

const long long N=6e5+5,M=110,O=2e5+5,mod=998244353,inv2=499122177,g=3;

long long mul[N],inv[N],invv[N],pw[N];

long long ksm(long long f,long long x){

	long long tot=1;

	while(x){

		if(x & 1ll) tot=tot*f%mod;

		f=f*f%mod;

		x>>=1ll;

	}

	return tot;

}

long long ID(long long x){

	if(x & 1ll) return mod-1;

	else return 1;

}

long long C(long long m,long long n){

	if(m<0 || n<0 || m<n) return 0;

	return mul[m]*inv[n]%mod*inv[m-n]%mod;

}

long long pr[N];

void init(long long lim){

	mul[0]=inv[0]=1;

	for(long long i=1;i<=lim;i++) mul[i]=mul[i-1]*i%mod;

	inv[lim]=ksm(mul[lim],mod-2);

	for(long long i=lim-1;i>=1;i--) inv[i]=inv[i+1]*(i+1)%mod;

	

	invv[1]=1;

	for(long long i=2;i<=lim;i++) invv[i]=(mod-mod/i)*invv[mod%i]%mod;

	

	pw[0]=1;

	for(long long i=1;i<=lim;i++) pw[i]=pw[i-1]*2%mod;

	

	for(long long mid = 1;mid < N/2;mid <<= 1){

		long long Wn = ksm(g, (mod-1)/(mid<<1)); pr[mid] = 1;

		for(long long i = 1;i < mid;++ i) pr[mid+i] = 1ll*pr[mid+i-1] * Wn % mod;

	}	

}



namespace NTT{

	long long qmod(long long x){

		if(x>=mod) x-=mod;

		return x;

	}

	void qmo(long long &x){x += x >> 31 & mod;}

	long long A[N],B[N],S[N],rev[N];

	long long init(long long n,long long m){

		long long lim=0;

		while((1ll<<lim)<=n+m) lim++;

		for(long long i=0;i<=(1<<lim)-1;i++)

			rev[i]=(rev[i>>1ll]>>1ll) | ((i & 1ll)<<(lim-1));

		return lim;

	}

	void ntt(long long *A,long long lim, long long op){

		for(long long i = 0;i < lim;++ i)

			if(i < rev[i]) swap(A[i], A[rev[i]]);

		for(long long mid = 1;mid < lim;mid <<= 1)

			for(long long i = 0;i < lim;i += mid<<1)

				for(long long j = 0;j < mid;++ j){

					long long y = 1ll*A[mid+i+j] * pr[mid+j] % mod;

					

					qmo(A[mid+i+j] = A[i+j] - y); 

					qmo(A[i+j] += y - mod);

				}

		if(op==-1){ reverse(A+1, A+lim); long long inv = ksm(lim, mod-2);

			for(long long i = 0;i < lim;++ i) A[i] = 1ll*A[i] * inv % mod;}

	}	

	void solve(long long *s,long long* f,long long* g,long long n,long long m){

		if(n+m<=100){

			for(long long i=0;i<=n+m;i++) A[i]=0;

			for(long long i=0;i<=n;i++){

				for(long long j=0;j<=m;j++){

					A[i+j]=qmod(A[i+j]+1ll*f[i]*g[j]%mod);

				}

			}

			for(long long i=0;i<=n+m;i++) s[i]=A[i];

			return ;

		}

		long long lim=init(n,m);

		for(long long i=0;i<=n;i++) A[i]=f[i];

		for(long long i=0;i<=m;i++) B[i]=g[i];

		for(long long i=n+1;i<=(1ll<<lim);i++) A[i]=0;

		for(long long i=m+1;i<=(1ll<<lim);i++) B[i]=0;

		ntt(A,(1<<lim),1);

		ntt(B,(1<<lim),1);

		for(long long i=0;i<=(1<<lim)-1;i++) S[i]=1ll*A[i]*B[i]%mod;

		ntt(S,(1<<lim),-1);

		for(long long i=0;i<=n+m;i++) s[i]=S[i];

	}

}

namespace INV{

	long long A[N],B[N],S[N];

	void solve(long long *s,long long *f,long long n){

		S[0]=ksm(f[0],mod-2);

		S[1]=0;

		long long len;

		for(len=2;len<=(n<<1ll);len<<=1ll){

			long long lim=len<<1ll;

			for(long long i=0;i<len;i++) A[i]=f[i],B[i]=S[i];

			for(long long i=len;i<lim;i++) A[i]=B[i]=0;

			NTT::init(len,0);

			NTT::ntt(A,lim,1);

			NTT::ntt(B,lim,1);

			for(long long j=0;j<lim;j++)

				S[j]=(2*B[j]+mod-A[j]*B[j]%mod*B[j]%mod)%mod;

			NTT::ntt(S,lim,-1);

			for(long long j=len;j<lim;j++) S[j]=0;

		}

		for(long long i=0;i<=n;i++) s[i]=S[i];

	}

}

namespace poly{

	void Deriv(long long *s,long long *f,long long n){

		long long A[N];

		A[n]=0;

		for(long long i=1;i<=n;i++) A[i-1]=f[i]*i%mod;

		for(long long i=0;i<=n;i++) s[i]=A[i];

	}

	//求导 

	void Limit(long long *s,long long *f,long long n){

		long long A[N];

		A[0]=0;

		for(long long i=0;i<=n-1;i++) A[i+1]=f[i]*ksm(i+1,mod-2)%mod;

		for(long long i=0;i<=n;i++) s[i]=A[i];

	}

	//极限 

	void Ln(long long *s,long long *f,long long n){

		long long A[N],B[N];

		long long lim=NTT::init(n,n);

		for(long long i=0;i<=n;i++) A[i]=f[i],B[i]=0;

		for(long long i=n+1;i<(1ll<<lim);i++) A[i]=B[i]=0;

		Deriv(B,A,n);

		INV::solve(A,A,n);

		NTT::solve(A,A,B,n,n);

		Limit(A,A,n);

		for(long long i=0;i<=n;i++) s[i]=A[i];

	}

	void Exp(long long *s,long long *f,long long n){

		long long A[N],B[N],C[N],S[N];

		S[0]=1;

		S[1]=0;

		long long len;

		for(len=2;len<=(n<<1ll);len<<=1ll){

			long long lim=len<<1ll;

			for(long long i=0;i<len;i++) A[i]=f[i],B[i]=S[i];

			for(long long i=len;i<lim;i++) A[i]=B[i]=C[i]=0;

			

			Ln(C,B,len-1);

			for(long long i=0;i<len;i++) C[i]=(mod-C[i]+A[i])%mod;

			C[0]=(C[0]+1)%mod;

			NTT::init(len,0);

			NTT::ntt(B,lim,1);

			NTT::ntt(C,lim,1);

			for(long long j=0;j<lim;j++) S[j]=B[j]*C[j]%mod;

			

			NTT::ntt(S,lim,-1);

			for(long long j=len;j<lim;j++) S[j]=0;

		}

		for(long long i=0;i<=n;i++) s[i]=S[i];

	}

}





long long n,m,ans;

char S[N];

bool ck(long long pos,bool id){

	if(pos>m) return 1;

	 return id==(S[pos]=='>');

}

long long a12[M][O],a21[M][O],a_1[N],a1_[N],b12[N],b21[N],b1_[N];

long long x[N],U[N],V[N],P[N],Q[N],F[N];



int main(){

	init(N-5);

	cin>>n>>m;

	scanf("\n%s",S+1);

	for(long long l=1;l<=n;l++){

		for(long long i=1;i+l-1<=n && i<=m+1;i++){

			long long j=i+l-1;

			if(j==i+1) a12[i][i+1]=ck(i,0);

			else if(j==i+2) a12[i][j]=ck(i,0)*ck(j-1,1);

			else a12[i][j]=(ck(i,0)*((i==m+1)?pw[j-(i+1)-2]:a21[i+1][j])%mod+ck(j-1,1)*a12[i][j-1]%mod)%mod;

			if(j==i+1) a21[i][i+1]=ck(i,1);

			else if(j==i+2) a21[i][j]=ck(i,0)*ck(j-1,1);

			else a21[i][j]=(ck(i,0)*((i==m+1)?pw[j-(i+1)-2]:a21[i+1][j])%mod+ck(j-1,1)*a12[i][j-1]%mod)%mod;

		}

	}

	for(long long i=1;i<=n-m;i++) b12[i]=a12[m+1][m+i],b21[i]=a21[m+1][m+i];

	x[0]=1;

	for(long long i=1;i<=m;i++){

		for(long long j=0;j<i;j++) x[i]=(x[i]+x[j]*a21[j+1][i+1]%mod%mod*inv[i-j-1]%mod)%mod;

		x[i]=x[i]*invv[i]%mod;

	}

	

	for(long long i=0;i<=n+1;i++){

		U[i]=b21[i+2]*inv[i]%mod;

		if(i) for(long long j=0;j<=min(i-1,m-1);j++)

				V[i-1]=(V[i-1]+x[j]*(a21[j+1][i+1]+mod-b21[i+1-j])%mod*inv[i-j-1]%mod)%mod;

	}

	

	poly::Limit(U,U,n);

	poly::Exp(P,U,n);

	INV::solve(Q,P,n);

	NTT::solve(V,V,Q,n,n);

	poly::Limit(V,V,n);

	V[0]=(V[0]+1)%mod;

	NTT::solve(F,P,V,n,n);

	

	for(int i=1;i<=n;i++) a_1[i]=F[i-1]*mul[i-1]%mod,b1_[i]=P[i-1]*mul[i-1]%mod;

	

	for(int i=m;i>=1;i--)

		for(long long t=i+1;t<=n;t++)

			a1_[i]=(a1_[i]+a12[i][t]*((t>m)?b1_[n-t+1]:a1_[t])%mod*C(n-i-1,t-i-1)%mod)%mod;

	for(int i=1;i<=n;i++) ans=(ans+a_1[i]*((i>m)?b1_[n-i+1]:a1_[i])%mod*C(n-1,i-1)%mod)%mod;

	cout<<ans;

}