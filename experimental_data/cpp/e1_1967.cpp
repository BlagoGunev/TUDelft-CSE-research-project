#include<bits/stdc++.h>
#define mod 998244353
#define poly vector<int>
#define N 20
using namespace std;
void output(poly a){
	for(auto cu:a)printf("%d ",cu);
	printf("\n");
}
poly mul(int k,poly a){
	int sz=a.size();
	poly b;
	for(int i=0;i<sz;++i)b.emplace_back(1ll*k*a[i]%mod);
	return b;
}
poly plu(poly a,poly b){
	poly c;
	int s1=a.size(),s2=b.size();
	c.resize(max(s1,s2));
	for(int i=0;i<s1;++i)c[i]=(c[i]+a[i])%mod;
	for(int i=0;i<s2;++i)c[i]=(c[i]+b[i])%mod;
	return c;
}
int powdv(int x,int y=mod-2){
	int ans=1;
	while(y){
		if(y&1)ans=1ll*ans*x%mod;
		y>>=1,x=1ll*x*x%mod;
	}
	return ans;
}
int a[1<<N],b[1<<N],ap[1<<N],bp[1<<N];
int rev[1<<N];
void getrev(int l){
	rev[0]=0;
	for(int i=1;i<=l;++i){
		for(int j=0;j<(1<<(i-1));++j){
			rev[j^(1<<(i-1))]=rev[j]^(1<<(l-i));
		}
	}
}
void ntt(int l,int *c,int *d,int cd){
	for(int i=0;i<(1<<l);++i)d[i]=c[rev[i]];
	for(int i=1;i<(1<<l);i<<=1){
		int o1=powdv(3,(mod-1)/i/2);
		if(cd==-1)o1=powdv(o1);
		for(int j=0;j<(1<<l);j+=i+i){
			int o=1;
			for(int k=j;k<j+i;++k){
				int A=d[k],B=d[k+i];
				d[k]=(A+1ll*o*B)%mod,d[k+i]=(A-1ll*o*B)%mod;
				o=1ll*o*o1%mod;
			}
		}
	}
	if(cd==-1){
		int ny=powdv(1<<l);
		for(int i=0;i<(1<<l);++i)d[i]=1ll*d[i]*ny%mod;
	}
}
poly multi(vector<poly>g){
	int sz=0;
	for(auto p:g)sz+=p.size()-1;
	int ss=sz+1;
	while(ss&(ss-1))++ss;
	int l=__builtin_ctz(ss);
	getrev(l);
	for(int i=0;i<(1<<l);++i)ap[i]=1;
	for(auto p:g){
		int zz=p.size();
		for(int i=0;i<(1<<l);++i){
			a[i]=(i<zz?p[i]:0);
		}
		ntt(l,a,bp,1);
		for(int i=0;i<(1<<l);++i)ap[i]=1ll*ap[i]*bp[i]%mod;
	}
	ntt(l,ap,b,-1);
	poly ans;
	for(int i=0;i<=sz;++i)ans.emplace_back((b[i]+mod)%mod);
	return ans;
}
poly deri(poly a){
	int sz=a.size();
	poly b;
	for(int i=1;i<sz;++i)b.emplace_back(1ll*i*a[i]%mod);
	return b;
}
int id[1<<N],di[1<<N],ny[1<<N];
void init(int sz){
	di[0]=1;
	for(int i=1;i<=sz;++i)di[i]=1ll*i*di[i-1]%mod;
	id[sz]=powdv(di[sz]);
	for(int i=sz-1;i>=0;--i)id[i]=1ll*id[i+1]*(i+1)%mod;
	for(int i=1;i<=sz;++i)ny[i]=1ll*id[i]*di[i-1]%mod;
}
int C(int n,int m){
	if(n<0||m<0||n<m)return 0;
	return 1ll*di[n]*id[m]%mod*id[n-m]%mod;
}
poly inte(poly a){
	int sz=a.size();
	init(sz);
	poly b;
	b.emplace_back(0);
	for(int i=0;i<sz;++i)b.emplace_back(1ll*ny[i+1]*a[i]%mod);
	return b;
}
poly mo(poly a,int n){
	poly b;
	int sz=min((signed)a.size(),n);
	for(int i=0;i<sz;++i)b.emplace_back(a[i]);
	return b;
}
poly inver(poly a,poly b,int n,int cs){
	if(cs==0)return b;
	int zz=min(2*(signed)b.size(),n);
	b=mo(plu(mul(2,b),mul(mod-1,multi({b,b,mo(a,2*b.size())}))),zz);
	return inver(a,b,n,cs-1);
}
poly inv(poly a,int n){
	poly b={1};
	int cc=1,gs=1;
	while(cc<=n)cc*=2,++gs;
	return inver(a,b,n,gs);
}
poly ln(poly a){
	poly pp=mo(multi({deri(a),inv(a,a.size())}),a.size()-1);
	return inte(pp);
}
poly youyi(poly a,int x){
	poly aa(max(0,(signed)a.size()-x));
	for(int i=0;i<(signed)a.size()-x;++i)aa[i]=a[i+x];
	return aa;
}
poly zuoyi(poly a,int x){
	poly aa(a.size()+x);
	for(int i=0;i<(signed)a.size();++i)aa[i+x]=a[i];
	return aa;
}
int n,m,b0;
pair<poly,pair<int,int>>solve(int c,poly a,int l,int r){
	if(c==1){
		int L=max(l-1,0),R=min(m,r+1);
		poly aa(R-L+1);
		for(int i=l;i<=r;++i){
			int ii=min(m,i+1);
			aa[ii-L]=(aa[ii-L]+1ll*(m-(i<m))*a[i-l])%mod;
			if(i)aa[i-1-L]=(aa[i-1-L]+(i<m)*a[i-l])%mod;
		}
		return make_pair(aa,make_pair(L,R));
	}
	if(c<=3){
		int c1=c>>1,c2=c-c1;
		auto a1=solve(c1,a,l,r);
		return solve(c2,a1.first,a1.second.first,a1.second.second);
	}
	int c1=c>>1,c2=c-c1;
	auto a1=solve(c1,a,l,r);
	poly p1=a1.first;
	int l2=a1.second.first,r2=a1.second.second;
	int ll=max(l2,c2),rr=min(r2,m-c2);
	if(ll>rr){
		auto a2=solve(c2,p1,l2,r2);
		return a2;
	}
	int dl=max(0,l2-c2),dr=min(m,r2+c2);
	poly an(dr-dl+1);
	int cj=1;
	poly o1(2*c2+1);
	for(int i=0;i<=c2;++i){
		o1[2*i]=1ll*C(c2,i)*cj%mod;
		cj=1ll*cj*(m-1)%mod;
	}
	poly o2(rr-ll+1);
	for(int i=ll;i<=rr;++i)o2[i-ll]=p1[i-l2];
	poly o=multi({o1,o2});
	for(int i=0;i<(signed)o.size();++i){
		int ii=i-c2+ll;
		an[ii-dl]=(an[ii-dl]+o[i])%mod;
	}
	if(l2<ll){
		poly pp1(ll-l2);
		for(int i=l2;i<=ll-1;++i)pp1[i-l2]=p1[i-l2];
		auto ad=solve(c2,pp1,l2,ll-1);
		int al=ad.second.first,ar=ad.second.second;
		for(int i=al;i<=ar;++i)an[i-dl]=(an[i-dl]+ad.first[i-al])%mod;
	}
	if(r2>rr){
		poly pp1(r2-rr);
		for(int i=rr+1;i<=r2;++i)pp1[i-rr-1]=p1[i-l2];
		auto ad=solve(c2,pp1,rr+1,r2);
		int al=ad.second.first,ar=ad.second.second;
		for(int i=al;i<=ar;++i)an[i-dl]=(an[i-dl]+ad.first[i-al])%mod;
	}
	return make_pair(an,make_pair(dl,dr));
}
int sol(){
	if(b0>=m)return powdv(m,n);
	init(n);
	poly dx(1);
	dx[0]=1;
	poly pp=solve(n,dx,b0,b0).first;
	int he=0;
	for(auto cu:pp)he=(he+cu)%mod;
	return he;
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&n,&m,&b0);
		printf("%d\n",sol());
	}
	return 0;
}