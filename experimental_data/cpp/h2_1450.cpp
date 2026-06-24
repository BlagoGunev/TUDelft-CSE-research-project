#include<bits/stdc++.h>

#define R register

#define N 1000201

#define ll long long

#define P 998244353

#define I2 499122177



int n,m,fac[N],ifac[N],inv[N],tj,to,sj,so,pw[N],pws[N];

char s[N],qwq[33];



inline int fc(const int &x){return x>=P?x-P:x;}

inline void Add(int &x,const int &y){x+=y-P,x+=(x>>31)&P;}

inline int C_(int x,int y){return (x<0||y<0||x<y)?(0):1LL*fac[x]*ifac[y]%P*ifac[x-y]%P;}



inline int F(int C,int t){

	if(C<0) return 0;

	if(C==0) return t%2==0;

	return pws[C-1];

}



struct QC{

	int ans,C,t;

	QC(){C=t=0,ans=1;}

	

	inline void giaC(){Add(ans,ans),Add(ans,P-C_(C,t)),++C;}

	inline void gianC(){Add(ans,C_(C-1,t)),ans=1LL*I2*ans%P,--C;}

	inline void giat(){Add(ans,C_(C,t+1)),++t;}

	inline void giant(){Add(ans,P-C_(C,t)),--t;}

	

	inline void trn(int nC,int nt){

		while(C>nC) gianC(); while(C<nC) giaC();

		while(t>nt) giant(); while(t<nt) giat();

	}

}aa,bb;



inline void wk(){

	R int A=tj-to,C=sj+so,t=A-so,an=0;

	if(C<=2){

		for(R int r=0;r<=C;++r) if((r-t)%2==0) Add(an,1LL*((t+r<0)?(-r-t):(r+t))*C_(C,r)%P);

		an=1LL*an*pw[C]%P; printf("%d\n",an);

		return ;

	}

	an=(1LL*C*F(C-1,t)+1LL*(t+P)*F(C,t))%P;

//	std::cerr<<an<<"!\n";

	R int an1=0,an2=0;

	aa.trn(C-1,-t);

	bb.trn(C-2,-t-1);

	an1=aa.ans,an2=bb.ans;

//	for(R int r=0;r<=-t;++r) if((r-t)%2==0) Add(an2,C_(C-1,r-1));

	an1=1LL*an1*(P-2LL)%P*(P+t)%P;

	an2=1LL*an2*(P-2LL)%P*C%P;

	Add(an,an1),Add(an,an2);

	an=1LL*an*pw[C]%P;

	printf("%d\n",an);

}



inline void shq(int x,int ju){

	if(x&1) (s[x]=='?')?(sj+=ju):((s[x]=='b')?(tj+=ju):(0));

	else (s[x]=='?')?(so+=ju):((s[x]=='b')?(to+=ju):(0));

}



inline void chg(int x,char va){

	shq(x,-1),s[x]=va,shq(x,1);

}



int main(){

	fac[0]=1; for(R int i=1;i<N;++i) fac[i]=1LL*fac[i-1]*i%P;

	inv[1]=1; for(R int i=2;i<N;++i) inv[i]=1LL*(P-P/i)*inv[P%i]%P;

	ifac[0]=1; for(R int i=1;i<N;++i) ifac[i]=1LL*ifac[i-1]*inv[i]%P;

	pw[0]=pws[0]=1; for(R int i=1;i<N;++i) pw[i]=1LL*pw[i-1]*I2%P,pws[i]=fc(pws[i-1]<<1);

	scanf("%d%d",&n,&m);

	scanf("%s",s+1);

	for(R int i=1;i<=n;i+=2) if(s[i]=='?') ++sj; else if(s[i]=='b') ++tj;

	for(R int i=2;i<=n;i+=2) if(s[i]=='?') ++so; else if(s[i]=='b') ++to;

	wk();

	for(R int i=1,x;i<=m;++i){

		scanf("%d%s",&x,qwq);

		chg(x,*qwq);

		wk();

	}

}