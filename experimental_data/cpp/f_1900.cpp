// Problem: Local Deletions
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1900F
// Memory Limit: 250 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
namespace my_std{
#define mems(x,y) memset(x,y,sizeof x)
#define Mp make_pair
#define eb emplace_back
#define gc getchar
#define pc putchar
#define fi first
#define se second
#define il inline
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define drep(i,a,b) for(int i=(a);i>=(b);i--)
#define go(i,u) for(int i=head[u];i;i=e[i].nxt)
	typedef long long ll;
	typedef pair<int,int> pii;
	template<typename T>il void read(T &x){
		int f=1;x=0;char c=gc();
		while(c<'0'||c>'9'){if(c=='-')f=-1;c=gc();}
		while(c>='0'&&c<='9')x=x*10+c-48,c=gc();
		x*=f;
	}
	template<typename T,typename ...Args>
	void read(T &x,Args &...args){
		read(x),read(args...);
	}
	template<typename T>
	il void write(T x){
		char buf[43];int len=0;
		if(x<0)pc('-'),x=-x;
		do buf[++len]=x%10,x/=10;while(x);
		while(len)pc(buf[len--]+'0');
	}
}
using namespace my_std;
const int N=1e5+7,M=-1,inf=0x3f3f3f3f,mod=0;
int n,m,a[N];
vector<int> f[23];
void solve(vector<int> &g,int op){
	vector<int> h;
	rep(i,0,(int)g.size()-1){
		if(!op){
			if((!i||a[g[i-1]]<a[g[i]])&&(i==(int)g.size()-1||a[g[i+1]]<a[g[i]])){
				h.eb(g[i]);
			}
		}else{
			if((!i||a[g[i-1]]>a[g[i]])&&(i==(int)g.size()-1||a[g[i+1]]>a[g[i]])){
				h.eb(g[i]);
			}
		}
	}
	swap(g,h);
}
void Yorushika(){
	read(n,m);
	rep(i,1,n){
		read(a[i]);
	}
	rep(i,1,n){
		f[0].eb(i);
	}
	rep(i,1,22){
		f[i]=f[i-1];
		solve(f[i],i&1);
	}
	while(m--){
		int l,r;read(l,r);
		l--,r--;
		int p=0;
		vector<int> L,R;
		while(l<r){
			L.eb(f[p][l]),L.eb(f[p][l+1]);
			R.insert(R.begin(),f[p][r]),R.insert(R.begin(),f[p][r-1]);
			solve(L,(p+1)&1),solve(R,(p+1)&1);
			if(L.back()==f[p][l+1]){
				L.pop_back();
			}
			if(*R.begin()==f[p][r-1]){
				R.erase(R.begin());
			}
			int x=f[p][l],y=f[p][r];
			p++;
			l=upper_bound(f[p].begin(),f[p].end(),x)-f[p].begin();
			r=lower_bound(f[p].begin(),f[p].end(),y)-f[p].begin()-1;
		}
		rep(i,l,r){
			L.eb(f[p][i]);
		}
		for(int i:R){
			L.eb(i);
		}
		while(L.size()>1){
			solve(L,(++p)&1);
		}
		printf("%d\n",a[L.back()]);
	}
}
signed main(){
	int t=1;
		 // t=read();
	while(t--){
		Yorushika();
	}
}