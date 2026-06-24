//This sourcecode is under GPLv3
//http://yeguanghao.xyz
#include <bits/stdc++.h>
#define rep(name,start,end,step) for(int name=start;name<=end;name+=step)
using namespace std;
#define Pn(x) printf("%d\n",x)
#define Ps(x) printf("%d ",x)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define PROB
inline void R(int &x) {
	x=0; int f=1; char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-')f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
void Redirect() {
	freopen(PROB".in","r",stdin);
#ifndef YGHDEBUG
	freopen(PROB".out","w",stdout);
#endif
}
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int maxn=2000100;
int f[maxn];
char ans[maxn];
char buf[maxn];
int getf(int x) {
	if(f[x]==x) return x;
	else {
		f[x]=getf(f[x]);
		return f[x];
	}
}
int n;
int pos;
int main() {
	R(n);
	rep(i,1,2000000,1) {
		f[i]=i;
	}
	rep(i,1,n,1) {
		scanf("%s",buf+1);
		int len=strlen(buf+1);
		int k; R(k);
		rep(j,1,k,1) {
			int cur; R(cur);
			int cf=getf(cur);
			while(cf+1<=cur+len) {
				pos=max(pos,cf);
				f[cf]=getf(cf+1);
				ans[cf]=buf[cf-cur+1];
				cf=getf(cf);
			}
		}
	}
	rep(i,1,pos,1) {
		if(ans[i]) putchar(ans[i]);
		else putchar('a');
	}
}