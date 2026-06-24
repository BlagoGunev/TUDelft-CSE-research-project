#include<cstdio>
#include<cctype>
#include<algorithm>
#define ll long long
using namespace std;
inline char gc(){
	static char now[1<<16],*S,*T;
	if (T==S){T=(S=now)+fread(now,1,1<<16,stdin);if (T==S) return EOF;}
	return *S++;
}
inline int read(){
	int x=0,f=1;char ch=gc();
	while(!isdigit(ch)) {if (ch=='-') f=-1;ch=gc();}
	while(isdigit(ch)) x=x*10+ch-'0',ch=gc();
	return x*f;
}
const int N=1e6+10;
int s[N],n,a[N];ll ans;
inline void add(int x,int v){
	while(x<=n) s[x]+=v,x+=x&-x;
}
inline int query(int x){
	ll tmp=0;
	while(x) tmp+=s[x],x-=x&-x;return tmp;
}
int main(){
//	freopen("e.in","r",stdin);
	n=read();
	for (int i=1;i<=n;++i) a[i]=read();
	for (int i=n;i;--i){
		ans+=query(a[i]);
		add(a[i],1);
	}
	ans&=1;n&=1;
	if (ans==n) puts("Petr");
	else puts("Um_nik");
	return 0;
}