#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
inline void ju() {
	freopen("***.in","r",stdin);
	freopen("***.out","w",stdout);
}
inline ll rd() {
	ll x=0,f=1; char c=getchar();
	while((c<'0'||c>'9')&&(c!='-')) c=getchar();
	if(c=='-') f=-1,c=getchar();
	while(c>='0'&&c<='9') {
		x=(x<<3)+(x<<1)+c-'0';
		c=getchar();
	}
	return x*f;
}
const int N=2e5+10;
int c[N];
int main() {
	int n=rd(),a=rd(),b=rd(),k=rd(),ans=0;
	for(int i=1;i<=n;++i) {
		int x=rd()%(a+b);
		if(!x) x=a+b;
		c[i]=(x-1)/a;
	}
	sort(c+1,c+n+1);
	for(int i=1;i<=n;++i)
		if(k>=c[i])
			++ans,k-=c[i];
	printf("%d\n",ans);
	return 0;
}