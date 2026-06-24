#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int gi()
{
	char c; int x=0,f=1;
	for(;c<'0'||c>'9';c=getchar())if(c=='-')f=-1;
	for(;c>='0'&&c<='9';c=getchar())x=(x<<1)+(x<<3)+c-'0';
	return x*f;
}
const int N=200005;
int a[N],n,p[35],sze,x;
bool ins(int x)
{
	for(int i=31;i>=0;--i)
	{
		if(!(x>>i)) continue;
		if(!p[i]) {
			p[i]=x; ++sze; return true;
		}
		x^=p[i];
	}
	return false;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("g.in","r",stdin);
#endif
	n=gi();
	for(int i=1;i<=n;++i) a[i]=gi(),ins(a[i]),x^=a[i];
	if(!x) puts("-1");
	else printf("%d\n",sze);
}