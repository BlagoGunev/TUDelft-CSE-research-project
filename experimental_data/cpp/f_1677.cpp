#include<cmath>

#include<queue>

#include<cstdio>

#include<cstring>

#include<assert.h>

#include<iostream>

#include<algorithm>

using namespace std;

#define LL long long

#define int long long

const int MAXN=4e5+5;

const int MAXNN=1e5+5;

int n,k,P,fac[MAXN],ifac[MAXN],Inv[MAXN],rev[MAXN],x[MAXN],y[MAXN],K[MAXN],B[MAXN],g[MAXN],F[MAXN],Q[MAXN],val[MAXN]; 

int a[MAXNN],b[MAXNN],W[21][MAXN*2];

const int mod=998244353;

vector<int>G[MAXNN];

inline int mul(int a,int b){return 1ll*a*b%mod;}

inline int dec(int a,int b){return ((a-b)%mod+mod)%mod;}

inline int add(int a,int b){return ((a+b)%mod+mod)%mod;}

inline int qkpow(int a,int b){

	int ans=1,base=a;

	while(b){

		if(b&1)ans=mul(ans,base);

		base=mul(base,base);

		b>>=1;

	}

	return ans;

}

namespace IO{

	const int sz=1<<22;

	char a[sz+5],b[sz+5],*p1=a,*p2=a,*t=b,p[105];

	inline char gc(){

		return p1==p2?(p2=(p1=a)+fread(a,1,sz,stdin),p1==p2?EOF:*p1++):*p1++;

	}

	template<class T> void gi(T& x){

		x=0; char c=gc();

		for(;c<'0'||c>'9';c=gc());

		for(;c>='0'&&c<='9';c=gc())

			x=x*10+(c-'0');

	}

	inline void flush(){fwrite(b,1,t-b,stdout),t=b; }

	inline void pc(char x){*t++=x; if(t-b==sz) flush(); }

	template<class T> void pi(T x,char c='\n'){

		if(x==0) pc('0'); int t=0;

		for(;x;x/=10) p[++t]=x%10+'0';

		for(;t;--t) pc(p[t]); pc(c);

	}

	struct F{~F(){flush();}}f; 

}

using IO::gi;

using IO::pi;

using IO::pc;

const int S=4;

struct Matrix{

	int a[4][4];

	Matrix(){memset(a,0,sizeof a);}

	void clear(){memset(a,0,sizeof a);}

	void init(){for(int i=0;i<S;i++)a[i][i]=1;}

	int* operator [] (int x){return a[x];}

	Matrix friend operator +(Matrix A,Matrix B){

		Matrix ret=Matrix();

		for(int i=0;i<S;i++)

			for(int j=0;j<=i;j++)

				ret[i][j]=add(A[i][j],B[i][j]);	

		return ret;

	}

	Matrix friend operator -(Matrix A,Matrix B){

		Matrix ret=Matrix();

		for(int i=0;i<S;i++)

			for(int j=0;j<=i;j++)

				ret[i][j]=dec(A[i][j],B[i][j]);	

		return ret;

	}

	Matrix friend operator *(Matrix A,Matrix B){

		Matrix ret=Matrix();

		for(int k=0;k<S;k++)

			for(int j=0;j<=k;j++)

				if(B[k][j])

					for(int i=k;i<S;i++)

						ret[i][j]=1ll*(ret[i][j]+1ll*A[i][k]*B[k][j])%mod;	

		return ret;

	}

	Matrix friend operator *(Matrix A,int x){

		Matrix ret=Matrix();

		for(int i=0;i<S;i++)

				for(int j=0;j<=i;j++)

					ret[i][j]=1ll*A[i][j]*x%mod;

		return ret;

	}

}d[MAXNN],dp[MAXNN],ans;

Matrix operator += (Matrix &p,Matrix q){return p=p+q;}

Matrix operator -= (Matrix &p,Matrix q){return p=p-q;}

Matrix operator *= (Matrix &p,Matrix q){return p=p*q;}

inline int C(int n,int m){

	if(n<m||m<0)return 0;

	return 1ll*fac[n]*ifac[m]%mod*ifac[n-m]%mod;

}

void init(){

	fac[0]=ifac[0]=Inv[0]=Inv[1]=1;

	for(int i=1;i<MAXN;i++)fac[i]=1ll*fac[i-1]*i%mod; 

	ifac[MAXN-1]=qkpow(fac[MAXN-1],mod-2);

	for(int i=MAXN-2;i>=1;i--)ifac[i]=1ll*ifac[i+1]*(i+1)%mod;

    for(int i=2;i<MAXN;i++)Inv[i]=1ll*(mod-mod/i)*Inv[mod%i]%mod;

    int wn;

    for(int i=0,x=1;x<MAXN;i++,x<<=1){

        W[i][x]=1;

        wn=qkpow(3,(mod-1)/(x<<1));

        for(int j=1;j<x;j++)W[i][x+j]=1ll*wn*W[i][x+j-1]%mod;

        wn=qkpow(wn,mod-2);

        for(int j=1;j<x;j++)W[i][x-j]=1ll*wn*W[i][x-j+1]%mod;

    } 

} 

inline void NTT(int *a,int type,int n){

    for(int i=0;i<n;i++)if(i<rev[i])swap(a[i],a[rev[i]]);

    LL x,y;

    for(int i=1,cnt=0;i<n;cnt++,i<<=1){

        for(int j=0;j<n;j+=(i<<1)){

            for(int t=0,k=j;k<j+i;k++,t+=type){

                x=a[k],y=1ll*W[cnt][i+t]*a[k+i];

                a[k]=(x+y)%mod;

                a[k+i]=(x-y)%mod;

            }

        }

    }

    if(type==-1)for(int i=0;i<n;i++)a[i]=mul(a[i],Inv[n]);

}

void Polyinv(int *a,int *b,int len){

	static int c[MAXN];

	if(len==1){

		b[0]=qkpow(a[0],mod-2);

		return ;

	}

	Polyinv(a,b,(len+1)>>1);

	int l=0,m=(len<<1),n=1;

	for(;n<=m;n<<=1,l++);

	for(int i=0;i<n;i++)rev[i]=(rev[i>>1]>>1)|((i&1)<<(l-1));

	for(int i=0;i<len;i++)c[i]=a[i];

	for(int i=len;i<n;i++)c[i]=0;

	NTT(c,1,n),NTT(b,1,n);

	for(int i=0;i<n;i++)b[i]=1ll*(2-1ll*b[i]*c[i])%mod*b[i]%mod;

	NTT(b,-1,n);

	for(int i=len;i<n;i++)b[i]=0;

}

inline void Polydao(int *Aa,int *Bb,int len){

	Bb[len-1]=0;

	for(int i=1;i<len;i++)Bb[i-1]=1ll*i*Aa[i]%mod;

}

int init_NTT(int L){

	int l=0,m=L,n=1;

	for(;n<=m;n<<=1,l++);

	for(int i=0;i<n;i++)rev[i]=(rev[i>>1]>>1)|((i&1)<<(l-1));

	return n;

}

void MUL(int *a,int *b,int *c,int n,int m,int lim){

	static int t1[MAXN],t2[MAXN],t3[MAXN];

	for(int i=0;i<n;i++)t1[i]=a[i];

	for(int i=0;i<m;i++)t2[i]=b[i];

	for(int i=n;i<lim;i++)t1[i]=0;

	for(int i=m;i<lim;i++)t2[i]=0;

	NTT(t1,1,lim),NTT(t2,1,lim);

	for(int i=0;i<lim;i++)t3[i]=1ll*t1[i]*t2[i]%mod;

	NTT(t3,-1,lim);

	for(int i=0;i<n+m-1;i++)c[i]=t3[i]; 

}

namespace Evaluation{

	#define ls(p) p<<1

	#define rs(p) p<<1|1

	int *T1[MAXN],*T2[MAXN],T3[MAXN],T4[MAXN],flow[MAXN*32],*now=flow;

	void clear(){now=flow;}

	inline void MUL2(int *a,int *b,int *c,int n,int m,int lim){

		static int t1[MAXN],t2[MAXN],t3[MAXN];

		for(int i=0;i<n;i++)t1[i]=a[i];

		for(int i=0;i<m;i++)t2[i]=b[i];

		reverse(t2,t2+m);

		for(int i=n;i<lim;i++)t1[i]=0;

		for(int i=m;i<lim;i++)t2[i]=0;

		NTT(t1,1,lim),NTT(t2,1,lim);

		for(int i=0;i<lim;i++)t3[i]=1ll*t1[i]*t2[i]%mod;

		NTT(t3,-1,lim);

		for(int i=m-1;i<n;i++)c[i-m+1]=t3[i]; 

	}

	void pre(int *Q,int p,int l,int r){

		T1[p]=now,now+=r-l+2;

		T2[p]=now,now+=r-l+2;

		for(int i=0;i<=r-l+1;i++)T1[p][i]=T2[p][i]=0;

		if(l==r){

			T1[p][0]=1;

			T1[p][1]=(mod-Q[l])%mod;

			return ; 

		}

		int mid=(l+r)>>1;

		pre(Q,ls(p),l,mid);

		pre(Q,rs(p),mid+1,r);

		if(r-l+1<=256){

			for(int i=0;i<=mid-l+1;i++)

				for(int j=0;j<=r-mid;j++)

					T1[p][i+j]=add(T1[p][i+j],1ll*T1[ls(p)][i]*T1[rs(p)][j]%mod);

		}else{

			int lim=init_NTT(r-l+1);

			MUL(T1[ls(p)],T1[rs(p)],T1[p],mid-l+2,r-mid+1,lim); 

		}

	}

	void Solve(int *S,int p,int l,int r){

		if(l==r){

			S[l]=T2[p][0];

			return ;

		}

		int mid=(l+r)>>1;

		int lim=init_NTT(r-l+1);

		MUL2(T2[p],T1[rs(p)],T2[ls(p)],r-l+1,r-mid+1,lim);

		MUL2(T2[p],T1[ls(p)],T2[rs(p)],r-l+1,mid-l+2,lim);

		Solve(S,ls(p),l,mid);

		Solve(S,rs(p),mid+1,r);

	}

	//opt0/1 区分多点求值/快速插值 

	void evaluation(int *F,int *Q,int *S,int n,int m,int opt){

		clear();

		static int AF[MAXN];

		n=max(n,m+1),m=max(m,n-1);

		pre(Q,1,1,m);

		if(opt){

			for(int i=0;i<n;i++)AF[i]=T1[1][i];

			reverse(AF,AF+n); 

			Polydao(AF,AF,n+1);

		}

		Polyinv(T1[1],T3,m+1);

		reverse(T3,T3+m+1);

		int lim=init_NTT(n+m+1); 

		if(!opt)MUL(F,T3,T4,n,m+1,lim);

		else MUL(AF,T3,T4,n,m+1,lim);

		for(int i=n;i<n+m;i++)T2[1][i-n]=T4[i];

		Solve(S,1,1,m);

		for(int i=1;i<=m;i++)S[i]=(1ll*S[i]*Q[i]%mod+(!opt?F[0]:AF[0]))%mod;

		for(int i=0;i<=n+m+1;i++)T3[i]=T4[i]=0;

	}

};

namespace Lagrange_Interpolation{

	#define ls(p) p<<1

	#define rs(p) p<<1|1

	int S[MAXN],*T[MAXN],flow[MAXN*32],*now=flow,tmp1[MAXN],tmp2[MAXN],e1[MAXN],e2[MAXN];

	void solve(int p,int l,int r){

		T[p]=now,now+=r-l+2;

		if(l==r){

			T[p][0]=S[l];

			return ;

		}

		int mid=(l+r)>>1;

		solve(ls(p),l,mid);

		solve(rs(p),mid+1,r);

		for(int i=0;i<mid-l+1;i++)tmp1[i]=T[ls(p)][i];

		for(int i=0;i<r-mid;i++)tmp2[i]=T[rs(p)][i];

		for(int i=0;i<r-mid+1;i++)e1[i]=Evaluation::T1[rs(p)][i];

		reverse(e1,e1+r-mid+1);

		for(int i=0;i<mid-l+2;i++)e2[i]=Evaluation::T1[ls(p)][i];

		reverse(e2,e2+mid-l+2);

		int lim=init_NTT(r-l+1); 

		MUL(tmp1,e1,e1,mid-l+1,r-mid+1,lim);

		MUL(tmp2,e2,e2,r-mid,mid-l+2,lim);

		for(int i=0;i<=r-l;i++)T[p][i]=add(e1[i],e2[i]);

	}

	void Interpolation(int *x,int *y,int *ans,int n){

		Evaluation::evaluation(x,x,S,n+1,n,1);

		for(int i=1;i<=n;i++)S[i]=1ll*y[i]*qkpow(S[i],mod-2)%mod;

		solve(1,1,n);

		for(int i=0;i<n;i++)ans[i]=T[1][i];

	}

}

void Pre(int P){

	int	invP=qkpow(P,mod-2),kk=0,bb=0;

	K[0]=1,B[0]=0;

	for(int i=1;i<=k+1;i++){

		K[i]=1ll*K[i-1]*invP%mod;

		B[i]=1ll*(B[i-1]+qkpow(i,k))*invP%mod;

		int Num=C(k+1,i);

		if(i&1)kk=dec(kk,1ll*Num*K[i]%mod),bb=dec(bb,1ll*Num*B[i]%mod);

		else kk=add(kk,1ll*Num*K[i]%mod),bb=add(bb,1ll*Num*B[i]%mod);

	} 

	kk=(kk+1),kk=(kk==mod?0:kk);

	g[0]=1ll*(mod-bb)*qkpow(kk,mod-2)%mod;

	for(int i=1;i<=k;i++)g[i]=add(1ll*g[0]*K[i]%mod,B[i]);

	for(int i=1;i<=k+1;i++)x[i]=i-1,y[i]=(g[i-1]+mod)%mod;

	Lagrange_Interpolation::Interpolation(x,y,F,k+1);

	for(int i=0;i<=k;i++)F[i]=(F[i]+mod)%mod; 

//	cout<<endl;

	for(int i=1;i<=n;i++)Q[i]=b[i];

	Evaluation::evaluation(F,Q,val,k+1,n,0);

	for(int i=1;i<=n;i++)val[i]=(val[i]+mod)%mod;

}

inline void makeit(int Id,int y,Matrix& S){

	//[S1S2,S1,S2,product of b]

	int X=dec(1ll*qkpow(P,y+1)*val[Id]%mod,1ll*P*g[0]%mod);

	S.a[0][0]=add(y,1),S.a[1][0]=y,S.a[2][0]=X,S.a[3][0]=X;

	S.a[1][1]=add(y,1),S.a[3][1]=X;

	S.a[2][2]=add(y,1),S.a[3][2]=y; 

	S.a[3][3]=add(y,1);

} 

signed main(){

	gi(n),gi(k),gi(P);

	init();

	for(int i=1;i<=n;i++)gi(b[i]);

	Pre(P);

	for(int i=1;i<=n;i++)makeit(i,b[i],d[i]);

	dp[1]=d[1];

	for(int i=2;i<=n;i++)dp[i]=dp[i-1]*d[i]+d[i];

	for(int i=1;i<=n;i++)ans+=dp[i];

	pi(ans.a[3][0],'\n');

	return 0;

}