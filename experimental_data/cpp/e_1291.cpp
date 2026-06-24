#include<cstdio>
#include<iostream>
#include<fstream>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
#define Set(a) memset(a,0,sizeof(a))
#define F(i,a,b) for(register int i=a,i##end=b;i<=i##end;++i)
#define UF(i,a,b) for(register int i=a,i##end=b;i>=i##end;--i)
#define openf(a) freopen(#a".in","r",stdin);freopen(#a".out","w",stdout)
#define re register
#define ri re int
#define il inline
typedef long long ll;
typedef unsigned long long ull;
template<typename T> inline T rd(T& x)
{
	T f=1;x=0;char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
	for(; isdigit(c);c=getchar()) x=(x<<3)+(x<<1)+(T)(c-'0');
	x*=f;
	return x;
}
ll rd(){ll x;rd(x);return x;}
inline int max(int a,int b){return a>b?a:b;}
inline int min(int a,int b){return a<b?a:b;}
const int inf=1<<30;

const int N=300005;
int fa[N],siz[N],ans[N],typ[N],typ2[N],typ3[N];
//ans->what if choose i
//typ->what if not choose his father
//typ2->0:both ok;1:mustn't do;2:must do
//typ3->what chosen to min
int get(int x)
{
	if(fa[x]==x) return x;
	int t=get(fa[x]);
	typ[x]^=typ[fa[x]];
	fa[x]=t;
	return t;
}
int a[N][3],n,k,aans=0;
char on[N];
//#define debug
int main()
{
	rd(n);rd(k);
	scanf("%s",on+1);
	F(i,1,k)
	{
		int c=rd();
		while(c--) {int x=rd();a[x][++a[x][0]]=i;}
	}
	F(i,1,k) fa[i]=i,ans[i]=1,siz[i]=1;
	F(i,1,n)
	{
		if(on[i]=='0'&&a[i][0]==1)
		{
			int c=a[i][1];
			int f=get(c);
			if(typ3[f]) aans-=ans[f];else aans-=siz[f]-ans[f];
			#ifdef debug
			printf("qwq:%d\n",aans);
			#endif
			typ2[f]=(typ[c]^1)+1;typ3[f]=typ[c]^1;
			if(typ3[f]) aans+=ans[f];else aans+=siz[f]-ans[f];
		}
		if(on[i]=='1'&&a[i][0]==1)
		{
			int c=a[i][1];
			int f=get(c);
			if(typ3[f]) aans-=ans[f];else aans-=siz[f]-ans[f];
			#ifdef debug
			printf("qwq:%d\n",aans);
			#endif
			typ2[f]=typ[c]+1;typ3[f]=typ[c];
			if(typ3[f]) aans+=ans[f];else aans+=siz[f]-ans[f];
		}
		if(on[i]=='0'&&a[i][0]==2)
		{
			int c=a[i][1],d=a[i][2];
			int f1=get(c),f2=get(d);
			if(f1!=f2){
			if(siz[f1]<siz[f2]) swap(f1,f2);
			if(typ3[f1]) aans-=ans[f1];else aans-=siz[f1]-ans[f1];
			if(typ3[f2]) aans-=ans[f2];else aans-=siz[f2]-ans[f2];
			#ifdef debug
			printf("qwq:%d\n",aans);
			#endif
			fa[f2]=f1;typ[f2]=typ[c]^typ[d]^1;
			if(typ2[f2]) typ2[f1]=((typ2[f2]-1)^typ[f2])+1;
			if(typ[f2]) ans[f1]+=siz[f2]-ans[f2];else ans[f1]+=ans[f2];
			siz[f1]+=siz[f2];
			if(typ2[f1]) typ3[f1]=typ2[f1]-1;
			else if(ans[f1]<siz[f1]-ans[f1]) typ3[f1]=1;else typ3[f1]=0;
			if(typ3[f1]) aans+=ans[f1];else aans+=siz[f1]-ans[f1];
			}
		}
		if(on[i]=='1'&&a[i][0]==2)
		{
			int c=a[i][1],d=a[i][2];
			int f1=get(c),f2=get(d);
			if(f1!=f2){
			if(siz[f1]<siz[f2]) swap(f1,f2);
			if(typ3[f1]) aans-=ans[f1];else aans-=siz[f1]-ans[f1];
			if(typ3[f2]) aans-=ans[f2];else aans-=siz[f2]-ans[f2];
			#ifdef debug
			printf("qwq:%d\n",aans);
			#endif
			fa[f2]=f1;typ[f2]=typ[c]^typ[d];
			if(typ2[f2]) typ2[f1]=((typ2[f2]-1)^typ[f2])+1;
			if(typ[f2]) ans[f1]+=siz[f2]-ans[f2];else ans[f1]+=ans[f2];
			siz[f1]+=siz[f2];
			if(typ2[f1]) typ3[f1]=typ2[f1]-1;
			else if(ans[f1]<siz[f1]-ans[f1]) typ3[f1]=1;else typ3[f1]=0;
			if(typ3[f1]) aans+=ans[f1];else aans+=siz[f1]-ans[f1];
			}
		}
		#ifdef debug
		printf("%d:",i);
		F(t,1,a[i][0]) cout<<a[i][t]<<' ';
		cout<<endl;
		#endif
		printf("%d\n",aans);
	}
	return 0;
}