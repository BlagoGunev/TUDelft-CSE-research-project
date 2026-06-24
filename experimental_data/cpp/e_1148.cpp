#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
inline int read(){
	int x=0,f=1;char ch;
	do{ch=getchar();if(ch=='-')f=-1;}while(ch<'0'||ch>'9');
	do{x=x*10+ch-'0';ch=getchar();}while(ch>='0'&&ch<='9');
	return x*f;
}
typedef long long ll;
const int N=3e5+10;
struct Data{
	int v,id;
}p[N];
inline bool operator<(const Data&t1,const Data&t2){
	return t1.v<t2.v;
}
int a[N],b[N],tans[5*N][3],lt,n;
bool solve(){
	int l=1,r=1;
	while (a[r]<=b[r]&&r<=n) ++r;
	while (l<=n){
		while (a[r]<=b[r]&&r<=n) ++r;
		while (a[l]==b[l]&&l<=n) ++l;
		if (l>n) break;
		if (a[l]>b[l]) return 0;
		int d=min(b[l]-a[l],a[r]-b[r]);
		++lt,tans[lt][0]=p[l].id,tans[lt][1]=p[r].id,tans[lt][2]=d;
		a[l]+=d,a[r]-=d;
	}
	return 1;
}
int main(){
	n=read();
	ll sa=0,sb=0;
	for (int i=1;i<=n;++i) p[i].v=read(),sa+=p[i].v,p[i].id=i;
	for (int i=1;i<=n;++i) b[i]=read(),sb+=b[i];
	sort(p+1,p+n+1);
	sort(b+1,b+n+1);
	for (int i=1;i<=n;++i) a[i]=p[i].v;
	if (sa!=sb||!solve()){
		puts("NO");
		return 0;
	}
	puts("YES");
	printf("%d\n",lt);
	for (int i=1;i<=lt;++i) printf("%d %d %d\n",tans[i][0],tans[i][1],tans[i][2]);
	return 0;
}