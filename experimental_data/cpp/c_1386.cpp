#include<bits/stdc++.h>
#define F(i,l,r) for(int i=(l),i##end=(r);i<=i##end;++i)
using namespace std;
const int N=2e5+5;
int n,m,q,l,r,u[N],v[N],lim[N],fa[N<<1],sz[N<<1];
stack<pair<int,int> >st;
template<typename T>inline void readmain(T &n){T sum=0,x=1;char ch=getchar();while (ch<'0'||ch>'9'){if (ch=='-')x=-1;ch=getchar();}while (ch>='0'&&ch<='9'){sum=sum*10+ch-'0';ch=getchar();}n=sum*x;}
template<typename T>inline T& read(T &x){readmain(x);return x;}
template<typename T,typename ...Tr>inline void read(T &x,Tr&... r){readmain(x);read(r...);}
template<typename T>inline void write(T x){if (x<0){putchar('-');x=-x;}if (x>9)write(x/10);putchar(x%10+'0');return;}
template<typename T>inline void writesc(T x){write(x);putchar(' ');}
template<typename T>inline void writeln(T x){write(x);putchar('\n');}
inline int find(int x){return fa[x]==x?x:find(fa[x]);}
inline void merge(int u,int v)
{
	int fu=find(u),fv=find(v);
	if (fu==fv)return;
	if (sz[fu]>sz[fv])fu^=fv^=fu^=fv;
	sz[fv]+=sz[fu];fa[fu]=fv;st.push({fu,fv});
}
inline bool add(int x,int y)
{
	merge(x,y+n);merge(x+n,y);
	return find(x)==find(y);
}
inline void undo(int x)
{
	while (st.size()>x)
	{
		int u=st.top().first;
		int v=st.top().second;
		st.pop();fa[u]=u;
		sz[v]-=sz[u];
	}
}
inline void work(int l,int r,int L,int R,bool f)
{
	if (l>r)return;
	if (L==R||f)
	{
		F(i,l,r)lim[i]=R;
		return;
	}
	int mid=(l+r)>>1,s=R,tmp=st.size();
	F(i,l,mid-1)f|=add(u[i],v[i]);
	while (s>=L&&!f)
	{
		f|=add(u[s],v[s]);
		--s;
	}
	lim[mid]=s;
	undo(tmp);f=0;
	F(i,s+1,R)f|=add(u[i],v[i]);
	work(l,mid-1,L,s,f);
	undo(tmp);f=0;
	F(i,l,mid)f|=add(u[i],v[i]);
	work(mid+1,r,s,R,f);
}
int main()
{
	read(n,m,q);
	F(i,1,n<<1)fa[i]=i,sz[i]=1;
	F(i,1,m)read(u[i],v[i]);
	work(1,m,0,m,0);while (q--)
	{
		read(l,r);
		puts(lim[l]>=r?"YES":"NO");
	}
	return 0;
}