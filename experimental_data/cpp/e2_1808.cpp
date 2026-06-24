#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#include<bits/stdc++.h>
#define N 205
#define ll long long
#define pb push_back
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
int K,M,vs[N],ans; ll n;
void inc(int &x,int y){x+=y; x%=M;}
int to(int x){return (x>=M)?(x-M):x;}
struct node{
	int p[N];
	node(){memset(p,0,sizeof(p));}
	friend node	operator * (const node& x,const node& y){
		node c; for(int i=0;i<K;i++) for(int j=0;j<K;j++)
			c.p[(i+j)%K]=to(c.p[(i+j)%K]+1ll*x.p[i]*y.p[j]%M); return c;
	}
}; node trans,A; node Fast(node x,ll y){
	node ret; ret.p[0]=1;
	while(y){
		if(y&1ll) ret=ret*x;
		x=x*x,y>>=1ll;
	}return ret;
}void clc(){
	memset(A.p,0,sizeof(A.p)),A.p[0]=1;
	memset(trans.p,0,sizeof(trans.p));
	for(int j=0;j<K;j++) trans.p[j]=(vs[j]^1);
	A=Fast(trans,n)*A;
}int can(int i){
	memset(vs,0,sizeof(vs));
	for(int j=0;j<K;j++) if((j*2)%K==i) vs[j]=1;
	clc(); return A.p[i];
}signed main(){
	scanf("%lld%d%d",&n,&K,&M);
	clc(); for(int i=0;i<K;i++) inc(ans,A.p[i]);
	for(int i=0;i<K;i++) inc(ans,(M-can(i))%M);
	return !printf("%d\n",(ans%M+M)%M);
}