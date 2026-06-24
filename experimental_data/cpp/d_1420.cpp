#include<bits/stdc++.h>
using namespace std;
#define I inline int
#define V inline void
#define P pair<int,int>
#define ll long long int
#define isnum(ch) ('0'<=ch&&ch<='9')
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define ROF(i,a,b) for(int i=a;i>=b;i--)
#define REP(u) for(int i=h[u],v;v=e[i].t,i;i=e[i].n)
#define gc (_op==_ed&&(_ed=(_op=_buf)+fread(_buf,1,100000,stdin),_op==_ed)?EOF:*_op++)
char _buf[100000],*_op(_buf),*_ed(_buf);
I getint(){
	int _s=0,_f=1;char _ch=gc;
	while(!isnum(_ch))(_ch=='-')&&(_f=-1),_ch=gc;
	while(isnum(_ch))_s=_s*10+_ch-48,_ch=gc;
	return _s*_f;
}
const int N=2e6+10,mod=998244353;
P t[N];
int n,k,tot,ans;
int a[N],L[N],R[N],fac[N],inv[N];
V check(int&x){x-=mod,x+=x>>31&mod;}
I C(int x,int y){
	if(x<y)return 0;
	return 1ll*fac[x]*inv[y]%mod*inv[x-y]%mod;
}
V input(){
	n=getint(),k=getint();
	FOR(i,1,n)L[i]=getint(),R[i]=getint()+1;
}
V init(){
	inv[0]=inv[1]=fac[0]=1;
	FOR(i,1,n)t[++tot]=P(L[i],1),t[++tot]=P(R[i],-1);
	FOR(i,2,n)inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;
	FOR(i,1,n)inv[i]=1ll*inv[i-1]*inv[i]%mod,fac[i]=1ll*fac[i-1]*i%mod;
	sort(t+1,t+1+tot);
}
V work(int now=0){
	FOR(i,1,tot)
		if(t[i].second==1)now++;
		else check(ans+=C(now-1,k-1)),now--;
	cout<<ans;
}
int main(){
	input();
	init();
	work();
	return 0;
}