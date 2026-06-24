#include<bits/stdc++.h>
#define LL long long
#define F(x,y,z) for(LL x=y;x<=z;++x)
#define D(x,y,z) for(LL x=y;x>=z;--x)
using namespace std;
const LL Mod=998244353;
const LL N=200010;
LL n,m;
LL Min(LL x,LL y){return x<y?x:y;}
LL Max(LL x,LL y){return x>y?x:y;}
LL R(){
    LL ans=0,f=1;char c=' ';
    for(;c<'0'||c>'9';c=getchar()) if (c=='-') f=-1;
    for(;c>='0'&&c<='9';c=getchar()) ans=ans*10+c-'0';
    return ans*f;
}
LL a[N];
struct Bit{
	LL t[N];
	void Add(LL x,LL z){for(LL i=x;i<N;i+=i&-i)t[i]+=z;}
	LL Ask(LL x){LL an=0;for(LL i=x;i;i-=i&-i)an+=t[i];return an;}
}T;
LL Pow(LL x,LL bs){
	LL an=1,now=x;
	while(bs){
		if(bs&1)an=(an*now)%Mod;
		now=(now*now)%Mod;
		bs>>=1;
	}
	return an;
}
LL aa,a2,ans,a3;
LL h[N],s[N],ken[N];
int main(){
	n=R();
	F(i,1,n)a[i]=R(),h[a[i]]=1;
	F(i,1,n){
		if(a[i]==-1)continue;
		aa+=T.Ask(N-2)-T.Ask(a[i]);
		aa%=Mod;
		T.Add(a[i],1);
	}
	F(i,1,n)s[i]=s[i-1]+(h[i]==0);
	F(i,1,n)ken[i]=ken[i-1]+(a[i]==-1);
	F(i,1,n){
		if(a[i]==-1)continue;
		a2+=ken[i]*(s[n]-s[a[i]]);
		a2+=(ken[n]-ken[i])*s[a[i]];
		a2%=Mod;
		a3+=ken[i]*s[a[i]];
		a3+=(ken[n]-ken[i])*(s[n]-s[a[i]]);
		a3%=Mod;
	}
	//LL fa=1;
	//F(i,1,ken[n])fa=(fa*i)%Mod;
	ans=a2*Pow(ken[n],Mod-2)%Mod;
	ans+=Pow(2,Mod-2)*ken[n]%Mod*(ken[n]-1)%Mod*Pow(2,Mod-2)%Mod;
	ans%=Mod;
	ans+=aa;ans%=Mod;
	cout<<ans<<endl;
    return 0;
}