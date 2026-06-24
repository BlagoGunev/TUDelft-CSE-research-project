#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/hash_policy.hpp>
#define gt getchar
#define pt putchar
#define fst first
#define scd second
#define SZ(s) ((int)s.size())
#define all(s) s.begin(),s.end()
#define pb push_back
#define eb emplace_back
typedef long long ll;
typedef double db;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned int uint;
const int N=1e5+5;
const int V=1e6;
const ll inf=1e13;
using namespace std;
using namespace __gnu_pbds;
typedef pair<int,int> pii;
template<class T,class I> inline bool chkmax(T &a,I b){return b>a?a=b,1:0;}
template<class T,class I> inline bool chkmin(T &a,I b){return b<a?a=b,1:0;}
inline bool __(char ch){return ch>=48&&ch<=57;}
template<class T> inline void read(T &x){
	x=0;bool sgn=0;static char ch=gt();
	while(!__(ch)&&ch!=EOF) sgn|=(ch=='-'),ch=gt();
	while(__(ch)) x=(x<<1)+(x<<3)+(ch&15),ch=gt();
	if(sgn) x=-x;
}
template<class T,class ...I> inline void read(T &x,I &...x1){
	read(x);
	read(x1...);
}
template<class T> inline void print(T x){
	static char stk[70];short top=0;
	if(x<0) pt('-');
	do{stk[++top]=x>=0?(x%10+48):(-(x%10)+48),x/=10;}while(x);
	while(top) pt(stk[top--]);
}
template<class T> inline void printsp(T x){
	print(x);
	putchar(' ');
}
template<class T> inline void println(T x){
	print(x);
	putchar('\n');
}
int q;
ll m;
// [l,r+1)
struct Line{
	ll k,b;
	Line(ll _k=0,ll _b=-inf):k(_k),b(_b){}
	inline db operator()(const db &x){
		return 1.0*k*x+b;
	}
};
int rt,tot;
struct Node{
	int lc,rc;
	Line w;
}node[N<<5];
#define ls(p) node[p].lc
#define rs(p) node[p].rc
void ins(int &p,int l,int r,Line w){
	if(!p) p=++tot;
	int mid=l+((r-l)>>1);
	if(node[p].w(mid)<w(mid)) swap(node[p].w,w);
	if(l==r) return;
	if(node[p].w(l)<w(l)) ins(ls(p),l,mid,w);
	if(node[p].w(r+1)<w(r+1)) ins(rs(p),mid+1,r,w);
}
db query(int p,int l,int r,db x){
	db ans=node[p].w(x);
	if(l==r) return ans;
	db mid=l+((r-l)>>1);
	if(x<mid+1) chkmax(ans,query(ls(p),l,mid,x));
	else chkmax(ans,query(rs(p),mid+1,r,x));
	return ans;
}
signed main(){
	read(q,m);
	int lst=0;
	for(int opt,x,y,_=1;_<=q;++_){
		read(opt,x,y);
		x=(x+lst)%V+1,y=(y+lst)%V+1;
		if(opt==1) ins(rt,0,V,Line(-y,x));
		else{
			db t=x,h=y;
			auto calc=[&](db p1){
				db p2=max(0.0,query(rt,0,V,p1));
				return p1*m+p2*t;
			};
			db l=0,r=V;
			for(int i=1;i<=100;++i){
				db lmid=l+(r-l)/3;
				db rmid=r-(r-l)/3;
				if(calc(lmid)>calc(rmid)) l=lmid;
				else r=rmid;
			}
			db ans=calc(l);
			if(ans>=h) lst=_,printf("YES\n");
			else printf("NO\n");
		}
	}
	return 0;
}