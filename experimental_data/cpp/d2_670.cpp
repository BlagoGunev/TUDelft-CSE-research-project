#include<cstring>
#include<cstdio>
#include<algorithm>
#include<map>
using namespace std;
#define nc() getchar()
inline int read(){
	int x=0;char ch=nc();for(;ch<'0'||ch>'9';ch=nc());
	for(;ch<='9'&&ch>='0';x=x*10+ch-48,ch=nc());return x;
}
#define ll long long
#define N 200010
ll n,m,ans1,ans2,now,i,a[N],k,x,b[N],p1[N],p2[N],fa[N];
map<int,int>mp;
inline bool cmp(int a,int b){
	if(p1[a]==p1[b])return p2[a]>p2[b];else return p1[a]>p1[b];
}
inline bool check(int m){
	int k=::k;
	for(int i=1;i<=n;++i){
		if(m*a[i]>b[i]){
			if(k<(m*a[i]-b[i]))return 0;
			k-=(m*a[i]-b[i]);
			if(k<0)return 0;
		}
	}
	return 1;
}
int main(){
/*	n=read();
	for(i=1,now=1;i<=n;++i){
		if(now==6||now==7)ans1++;
		if(now==7)now=1;else now++;
	}
	for(i=1,now=6;i<=n;++i){
		if(now==6||now==7)ans2++;
		if(now==7)now=1;else now++;
	}
	printf("%d %d\n",ans1,ans2);*/
/*	for(i=1;i<=n;++i)a[i]=read();
	int l=0,r=2000000000;
	while(l<=r){
		int m=l+r>>1;
		if(1ll*(1+m)*m/2>k)r=m-1;
		else l=m+1;
	}
	l=l-1;
	if(1ll*(l+1)*l/2==k)printf("%d",a[l]);
	else printf("%d",a[k-1ll*(l+1)*l/2]);*/
/*	for(n=read(),i=1;i<=n;++i)x=read(),++mp[x];
	for(m=read(),i=1;i<=m;++i)a[i]=read();
	for(i=1;i<=m;++i)b[i]=read();
	for(i=1;i<=m;++i)p1[i]+=mp[a[i]],p2[i]+=mp[b[i]];
	for(i=1;i<=m;++i)fa[i]=i;
	sort(fa+1,fa+m+1,cmp);
	printf("%d",fa[1]);*/
	for(n=read(),k=read(),i=1;i<=n;++i)a[i]=read();
	for(i=1;i<=n;++i)b[i]=read();
	ll l=0,r=2000000000;
	while(l<=r){
		int m=l+r>>1;
		if(check(m))l=m+1;else r=m-1;
	}
	printf("%d\n",l-1);
}