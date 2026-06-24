#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
#define ALL(v) v.begin(),v.end()
#define For(i,_) for(int i=0,i##end=_;i<i##end;++i) // [0,_)
#define FOR(i,_,__) for(int i=_,i##end=__;i<i##end;++i) // [_,__)
#define Rep(i,_) for(int i=(_)-1;i>=0;--i) // [0,_)
#define REP(i,_,__) for(int i=(__)-1,i##end=_;i>=i##end;--i) // [_,__)
typedef long long ll;
typedef unsigned long long ull;
#define V vector
#define pb push_back
#define pf push_front
#define qb pop_back
#define qf pop_front
#define eb emplace_back
typedef pair<int,int> pii;
typedef pair<ll,int> pli;
#define fi first
#define se second
const int dir[4][2]={{-1,0},{0,1},{1,0},{0,-1}},inf=0x3f3f3f3f,mod=1e9+7;
const ll infl=0x3f3f3f3f3f3f3f3fll;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
int init=[](){return cin.tie(nullptr)->sync_with_stdio(false),0;}();
template<class T1,class T2>
inline V<T1> pre1d(const V<T2> &v,const function<T1(T1,T2)> &f=[](const T1 &x,const T2 &y){return x+y;}){
    V<T1>ret(v.size());
    For(i,v.size())ret[i]=f((i?ret[i-1]:T1()),v[i]);
    return ret;
}
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
struct undo_dsu{
    V<int>fa,mn,mx,siz;
    V<array<int,4>>q;
    unordered_set<int,custom_hash>s;
    inline void resize(int n){
		V<int>(n).swap(fa),V<int>(n).swap(mn),V<int>(n).swap(mx),iota(ALL(fa),0),iota(ALL(mn),0),iota(ALL(mx),0),decltype(q)().swap(q),V<int>(n,1).swap(siz);
		decltype(s)().swap(s);For(i,n)s.insert(i);
	}
    inline undo_dsu(int n=0){resize(n);}
    int find(int k){return k==fa[k]?k:find(fa[k]);}
    inline bool merge(int x,int y){
		x=find(x),y=find(y);
		if(x!=y){
			if(siz[x]<siz[y])swap(x,y);
			q.pb({x,y,mn[x],mx[x]});
			fa[y]=x,ckmin(mn[x],mn[y]),ckmax(mx[x],mx[y]),siz[x]+=siz[y];
			s.erase(y);
		}
		return x!=y;
	}
	inline void undo(int k){
		while(q.size()>k){
			auto p=q.back();q.qb();
			fa[p[1]]=p[1],mn[p[0]]=p[2],mx[p[0]]=p[3],siz[p[0]]-=siz[p[1]];
			s.insert(p[1]);
		}
	}
	inline bool same(int x,int y){return find(x)==find(y);}
	inline int size(int k){return siz[find(k)];}
};
int main(){
	int t_case=1;
	scanf("%d",&t_case);
	while(t_case--){
		int n;
		scanf("%d",&n);
		V<int>cnt(n);
		V<V<pii>>evt(n<<2);
		function<void(int,int,int,int,int,int,int)>add=[&](int p,int l,int r,int ql,int qr,int x,int y){
			if(ql<=l&&r<=qr){
				evt[p].eb(x,y);
				return;
			}
			int mid=l+r>>1;
			if(ql<=mid)add(p<<1,l,mid,ql,qr,x,y);
			if(qr>mid)add(p<<1|1,mid+1,r,ql,qr,x,y);
		};
		For(i,n-1){
			int x,y;
			scanf("%d%d",&x,&y),--x,--y;
			if(x>y)swap(x,y);
			if(x)add(1,0,n-1,0,x-1,x,y);
			if(x+1<y)add(1,0,n-1,x+1,y-1,x,y),++cnt[x+1],--cnt[y];
			if(y+1<n)add(1,0,n-1,y+1,n-1,x,y);
		}
		cnt=pre1d<int>(cnt);
		undo_dsu d(n);
		function<void(int,int,int)>solve=[&](int p,int l,int r){
			int tmp=d.q.size();
			for(const pii &i:evt[p])d.merge(i.fi,i.se);
			if(l==r){
				int ans=0;
				V<pii>e;
				if(l&&l<n-1&&!cnt[l]){
					ans+=2;
					d.merge(l-1,l+1);
					e.eb(l-1,l+1);
				}
				d.s.erase(l);
				while(d.s.size()>1){
					for(int x:d.s){
						int y=d.mn[x],z=d.mx[x];
						if(y&&y-1!=l&&d.merge(x,y-1)){++ans,e.eb(y,y-1);goto skip;}
						else if(z<n-1&&z+1!=l&&d.merge(x,z+1)){++ans,e.eb(z,z+1);goto skip;}
					}
					assert(0);
					skip:;
				}
				d.s.insert(l);
				printf("%d %d\n",ans,(int)e.size());
				for(const pii &i:e)printf("%d %d\n",i.fi+1,i.se+1);
				putchar(10);
			}
			else{
				int mid=l+r>>1;
				solve(p<<1,l,mid);
				solve(p<<1|1,mid+1,r);
			}
			d.undo(tmp);
		};
		solve(1,0,n-1);
	}
	return 0;
}