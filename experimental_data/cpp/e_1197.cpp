#include <bits/stdc++.h>
using namespace std;
#define il inline
#define re register
#define rep(i,n) for(re int (i)=1;(i)<=(n);++(i))
typedef long long ll;
const int maxn=5e5+5;
ll n,g=0,ans,x=2000000000,s=1,m,a[maxn];
il ll read(){
	re char ch(getchar());
	re ll f(1),x(0);
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
ll q[maxn],p[maxn],y[maxn],v[maxn];
struct node{
	int d;
	int v;
	int ff;
}f[(maxn<<1)];

bool cmp(const node &a, const node &b)
{
	if(a.v==b.v)
	{
		return a.ff<b.ff;
	}
	return a.v>b.v;
}

int main()
{
	n=read();
	rep(i,n) f[++g].v=read(),f[g].d=i,f[g].ff=1,p[i]=f[g].v,f[++g].v=read(),f[g].d=i,f[g].ff=0,q[i]=f[g].v;
	sort(f+1,f+g+1,cmp);
	rep(i,(n<<1)) if(!f[i].ff) { if(x>y[f[i].d]) {x=y[f[i].d];s=v[f[i].d];} else if(x==y[f[i].d])s=(s+v[f[i].d])%1000000007;}
		else
		{
			if(x==2000000000) y[f[i].d]=q[f[i].d]; else y[f[i].d]=x-p[f[i].d]+q[f[i].d];
			v[f[i].d]=s;
		}
	cout<<s<<endl;
	return 0;
}