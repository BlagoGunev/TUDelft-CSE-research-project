#ifndef LOCAL
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#endif

#include <bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll

#define rng(i,a,b) for(int i=int(a);i<int(b);i++)
#define rep(i,b) rng(i,0,b)
#define gnr(i,a,b) for(int i=int(b)-1;i>=int(a);i--)
#define per(i,b) gnr(i,0,b)
#define pb push_back
#define eb emplace_back
#define a first
#define b second
#define bg begin()
#define ed end()
#define all(x) x.bg,x.ed
#define si(x) int(x.size())
#ifdef LOCAL
#define dmp(x) cerr<<__LINE__<<" "<<#x<<" "<<x<<endl
#else
#define dmp(x) void(0)
#endif

template<class t,class u> bool chmax(t&a,u b){if(a<b){a=b;return true;}else return false;}
template<class t,class u> bool chmin(t&a,u b){if(b<a){a=b;return true;}else return false;}

template<class t> using vc=vector<t>;
template<class t> using vvc=vc<vc<t>>;

using pi=pair<int,int>;
using vi=vc<int>;

template<class t,class u>
ostream& operator<<(ostream& os,const pair<t,u>& p){
	return os<<"{"<<p.a<<","<<p.b<<"}";
}

template<class t> ostream& operator<<(ostream& os,const vc<t>& v){
	os<<"{";
	for(auto e:v)os<<e<<",";
	return os<<"}";
}

#define mp make_pair
#define mt make_tuple
#define one(x) memset(x,-1,sizeof(x))
#define zero(x) memset(x,0,sizeof(x))
#ifdef LOCAL
void dmpr(ostream&os){os<<endl;}
template<class T,class... Args>
void dmpr(ostream&os,const T&t,const Args&... args){
	os<<t<<" ";
	dmpr(os,args...);
}
#define dmp2(...) dmpr(cerr,__LINE__,##__VA_ARGS__)
#else
#define dmp2(...) void(0)
#endif

using uint=unsigned;
using ull=unsigned long long;

template<class t,size_t n>
ostream& operator<<(ostream&os,const array<t,n>&a){
	return os<<vc<t>(all(a));
}

template<int i,class T>
void print_tuple(ostream&,const T&){
}

template<int i,class T,class H,class ...Args>
void print_tuple(ostream&os,const T&t){
	if(i)os<<",";
	os<<get<i>(t);
	print_tuple<i+1,T,Args...>(os,t);
}

template<class ...Args>
ostream& operator<<(ostream&os,const tuple<Args...>&t){
	os<<"{";
	print_tuple<0,tuple<Args...>,Args...>(os,t);
	return os<<"}";
}

template<class t>
void print(t x,int suc=1){
	cout<<x;
	if(suc==1)
		cout<<"\n";
	if(suc==2)
		cout<<" ";
}

ll read(){
	ll i;
	cin>>i;
	return i;
}

vi readvi(int n,int off=0){
	vi v(n);
	rep(i,n)v[i]=read()+off;
	return v;
}

pi readpi(int off=0){
	int a,b;cin>>a>>b;
	return pi(a+off,b+off);
}

template<class t,class u>
void print(const pair<t,u>&p,int suc=1){
	print(p.a,2);
	print(p.b,suc);
}

template<class t,class u>
void print_offset(const pair<t,u>&p,ll off,int suc=1){
	print(p.a+off,2);
	print(p.b+off,suc);
}

template<class T>
void print(const vector<T>&v,int suc=1){
	rep(i,v.size())
		print(v[i],i==int(v.size())-1?suc:2);
}

template<class T>
void print_offset(const vector<T>&v,ll off,int suc=1){
	rep(i,v.size())
		print(v[i]+off,i==int(v.size())-1?suc:2);
}

template<class T,size_t N>
void print(const array<T,N>&v,int suc=1){
	rep(i,N)
		print(v[i],i==int(N)-1?suc:2);
}

string readString(){
	string s;
	cin>>s;
	return s;
}

template<class T>
T sq(const T& t){
	return t*t;
}

void YES(bool ex=true){
	cout<<"YES\n";
	if(ex)exit(0);
	#ifdef LOCAL
	cout.flush();
	#endif
}
void NO(bool ex=true){
	cout<<"NO\n";
	if(ex)exit(0);
	#ifdef LOCAL
	cout.flush();
	#endif
}
void Yes(bool ex=true){
	cout<<"Yes\n";
	if(ex)exit(0);
	#ifdef LOCAL
	cout.flush();
	#endif
}
void No(bool ex=true){
	cout<<"No\n";
	if(ex)exit(0);
	#ifdef LOCAL
	cout.flush();
	#endif
}
//#define CAPITAL
/*
void yes(bool ex=true){
	#ifdef CAPITAL
	cout<<"YES"<<"\n";
	#else
	cout<<"Yes"<<"\n";
	#endif
	if(ex)exit(0);
	#ifdef LOCAL
	cout.flush();
	#endif
}
void no(bool ex=true){
	#ifdef CAPITAL
	cout<<"NO"<<"\n";
	#else
	cout<<"No"<<"\n";
	#endif
	if(ex)exit(0);
	#ifdef LOCAL
	cout.flush();
	#endif
}*/
void possible(bool ex=true){
	#ifdef CAPITAL
	cout<<"POSSIBLE"<<"\n";
	#else
	cout<<"Possible"<<"\n";
	#endif
	if(ex)exit(0);
	#ifdef LOCAL
	cout.flush();
	#endif
}
void impossible(bool ex=true){
	#ifdef CAPITAL
	cout<<"IMPOSSIBLE"<<"\n";
	#else
	cout<<"Impossible"<<"\n";
	#endif
	if(ex)exit(0);
	#ifdef LOCAL
	cout.flush();
	#endif
}

constexpr ll ten(int n){
	return n==0?1:ten(n-1)*10;
}

const ll infLL=LLONG_MAX/3;

#ifdef int
const int inf=infLL;
#else
const int inf=INT_MAX/2-100;
#endif

int topbit(signed t){
	return t==0?-1:31-__builtin_clz(t);
}
int topbit(ll t){
	return t==0?-1:63-__builtin_clzll(t);
}
int botbit(signed a){
	return a==0?32:__builtin_ctz(a);
}
int botbit(ll a){
	return a==0?64:__builtin_ctzll(a);
}
int botbit(ull a){
	return a==0?64:__builtin_ctzll(a);
}
int popcount(signed t){
	return __builtin_popcount(t);
}
int popcount(ll t){
	return __builtin_popcountll(t);
}
int popcount(ull t){
	return __builtin_popcountll(t);
}
bool ispow2(int i){
	return i&&(i&-i)==i;
}
ll mask(int i){
	return (ll(1)<<i)-1;
}

bool inc(int a,int b,int c){
	return a<=b&&b<=c;
}

template<class t> void mkuni(vc<t>&v){
	sort(all(v));
	v.erase(unique(all(v)),v.ed);
}

ll rand_int(ll l, ll r) { //[l, r]
	#ifdef LOCAL
	static mt19937_64 gen;
	#else
	static mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());
	#endif
	return uniform_int_distribution<ll>(l, r)(gen);
}

template<class t>
void myshuffle(vc<t>&a){
	rep(i,si(a))swap(a[i],a[rand_int(0,i)]);
}

template<class t>
int lwb(const vc<t>&v,const t&a){
	return lower_bound(all(v),a)-v.bg;
}

vvc<int> readGraph(int n,int m){
	vvc<int> g(n);
	rep(i,m){
		int a,b;
		cin>>a>>b;
		//sc.read(a,b);
		a--;b--;
		g[a].pb(b);
		g[b].pb(a);
	}
	return g;
}

vvc<int> readTree(int n){
	return readGraph(n,n-1);
}

vc<ll> presum(const vi&a){
	vc<ll> s(si(a)+1);
	rep(i,si(a))s[i+1]=s[i]+a[i];
	return s;
}

//copy-constructor を使うと破壊される(unique_ptr にしたのでそもそも使えない)
//find は lazy と組み合わせても動く (Petrozavodsk 2020w Day9 C)
//reverse は未知数
//erase,insert は動く
//split_cmp も動く

//AOJ DSL2G
template<class N>
struct splaytree{
	struct Node{
		using np=Node*;
		np l,r,p;
		bool rev;
		N x;
		Node():l(0),r(0),p(0),rev(false),x(){}
		void clear(){
			l=0;
			r=0;
			p=0;
			rev=0;
		}
		void reverse(){
			rev^=true;
			swap(l,r);
			x.reverse();
		}
		void push(){
			if(rev){
				if(l)l->reverse();
				if(r)r->reverse();
				rev=false;
			}
			if(l)x.push(l->x);
			if(r)x.push(r->x);
			x.clear();
		}
		np update(){
			x.single();
			if(l)x.updatel(l->x);
			if(r)x.updater(r->x);
			return this;
		}
		int pos(){
			if(p&&p->l==this)return -1;
			if(p&&p->r==this)return 1;
			return 0;
		}
		void prepare(){
			if(pos())
				p->prepare();
			push();
		}
		void rotate(){
			np q=p,c;
			if(pos()==1){
				c=l;
				l=p;
				p->r=c;
			}else{
				c=r;
				r=p;
				p->l=c;
			}
			if(c)c->p=p;
			p=p->p;
			q->p=this;
			if(p&&p->l==q)p->l=this;
			if(p&&p->r==q)p->r=this;
			q->update();
		}
		np splay(){
			prepare();
			while(pos()){
				int a=pos(),b=p->pos();
				if(b&&a==b)p->rotate();
				if(b&&a!=b)rotate();
				rotate();
			}
			return update();
		}
		/* deprecated
		template<class F,class...Args>
		np find(F f,Args&&...args){
			if(!(x.*f)(forward<Args>(args)...))return 0;
			push();
			x.single();
			np a=0;
			if(l)a=l->find(f,forward<Args>(args)...);
			if(a)return a;
			if((x.*f)(forward<Args>(args)...))return splay();
			return r->find(f,forward<Args>(args)...);
		}*/
		np left(){
			if(l)return l->left();
			else return splay();
		}
		np right(){
			if(r)return r->right();
			else return splay();
		}
		np root(){
			if(p)return p->root();
			else return this;
		}
		np cutl(){
			if(l){
				l->p=0;
				l=0;
			}
			return update();
		}
		np linkl(np c){
			assert(!l);
			l=c;
			if(c)c->p=this;
			return update();
		}
		np cutr(){
			if(r){
				r->p=0;
				r=0;
			}
			return update();
		}
		//XIX Opencup GP of Zhejiang A
		np get_next(){
			splay();
			if(!r)return 0;
			else return r->left();
		}
	};
	using np=Node*;
	vc<np> ps;
	unique_ptr<Node[]> buf;
	splaytree(int n):buf(new Node[n]){
		rep(i,n)ps.pb(buf.get()+i);
	}
	//int head=0;
	template<class...Args>
	np nn(Args&&...args){
		np a=ps.back();
		ps.pop_back();
		a->l=0;
		a->r=0;
		a->p=0;
		a->x=N(forward<Args>(args)...);
		return a;
	}
	np merge(np a,np b){
		if(!a)return b;
		if(!b)return a;
		return b->splay()->left()->linkl(a->splay());
	}
	//GCJ2022 Round2 D
	template<class...Args>
	np merge(np a,np b,Args...args){
		return merge(merge(a,b),args...);
	}
	//CF Dytechlab Cup 2022 G
	template<class F,class...Args>
	pair<np,np> max_right(np a,F f,Args&&...args){
		N cur;
		np x=0,y=0;
		while(a){
			a->push();
			N nx=a->x;nx.single();
			if(a->l)nx.updatel(a->l->x);
			nx.updatel(cur);
			if((nx.*f)(forward<Args>(args)...)){
				cur=nx;
				x=a;
				a=a->r;
			}else{
				y=a;
				a=a->l;
			}
		}
		if(x)x->splay();
		if(y){
			y->splay();
			y->cutl();
		}
		return mp(x,y);
	}
	//XX Opencup GP of Wroclaw D
	//分けた列の右端と左端が返ってくる
	//CF740 D (lazy あり)
	//CF Dytechlab Cup 2022 G (lazy あり)
	template<class F,class T>
	pair<np,np> split_cmp(np a,F cmp,T v){
		if(!a)return {0,0};
		np x=0,y=0;
		while(a){
			a->push();
			if(cmp(a->x,v)){
				x=a;
				a=a->r;
			}else{
				y=a;
				a=a->l;
			}
		}
		if(x)x->splay();
		if(y){
			y->splay();
			y->cutl();
		}
		return mp(x,y);
	}
	//XX Opencup GP of Wroclaw D
	template<class F,class...Args>
	np insert_cmp(np r,F f,Args&&...args){
		np x=nn(forward<Args>(args)...);
		np a,b;tie(a,b)=split_cmp(r,f,x->x);
		return merge(merge(a,x),b);
	}
	//XIX Opencup GP of Zhejiang A
	template<class F>
	np insert_cmp(np r,np x,F f){
		np a,b;tie(a,b)=split_cmp(r,f,x->x);
		return merge(merge(a,x),b);
	}
	//XX Opencup GP of Wroclaw D
	pair<np,np> erase_sub(np x){
		x->splay();
		if(x->l)x->l->p=0;
		if(x->r)x->r->p=0;
		ps.pb(x);
		return mp(x->l,x->r);
	}
	//CF Dytechlab Cup 2022 G
	np erase(np x){
		np a,b;
		tie(a,b)=erase_sub(x);
		return merge(a,b);
	}
	//Petrozavodsk 2020w Day9 H
	np isolate(np x){
		x->splay();
		if(x->l)x->l->p=0;
		if(x->r)x->r->p=0;
		np res=merge(x->l,x->r);
		x->x.single();
		x->clear();
		return res;
	}
	template<class t>
	np build(vc<t> v){
		vc<np> cur;
		for(auto z:v)cur.pb(nn(z));
		while(cur.size()>1){
			int s=cur.size();
			vc<np> nx((s+1)/2);
			for(int i=0;i<s;i+=2){
				if(i+1<s)nx[i/2]=merge(cur[i],cur[i+1]);
				else nx[i/2]=cur[i];
			}
			swap(nx,cur);
		}
		return cur[0];
	}
	/*
	//NOT VERIFIED
	//lower_bound したものを根に移して node を返す．
	//lower_bound の結果が end だと空が返ってくるらしい
	//USACO2021 USOPEN Platinum A
	template<class F>
	np lower_bound_cmp(np a,F cmp,N v){
		auto [x,y]=split_cmp(a,cmp,v);
		np res=nullptr;
		if(y)res=y->left();
		merge(x,res);
		if(res)res->splay();
		return res;
	}
	*/
	//XIX Opencup GP of Zhejiang A
	//a-b なる部分を取り出し，x,y(a-b),z を返す
	//a と b が異なる木に属する，また，a と b の順序がおかしい場合，何が起きるかは不明
	tuple<np,np,np> split_range(np a,np b){
		{//debug
			a->splay();
			b->splay();
			int lastpos;
			auto c=a;
			while(c&&c!=b){
				lastpos=c->pos();
				c=c->p;
			}
			assert(c==b);
			assert(lastpos==-1);
		}
		a->splay();
		np x=a->l;
		a->cutl();
		b->splay();
		np z=b->r;
		b->cutr();
		return mt(x,b,z);
	}
	//Petrozavodsk 2020w Day9 C
	template<class F>
	np weighted_merge_rec(np x,np tar,F f){
		if(!x)return tar;
		x->push();
		tar=weighted_merge_rec(x->l,tar,f);
		tar=weighted_merge_rec(x->r,tar,f);
		x->x.single();
		x->clear();
		return insert(tar,x,f);
	}
	//Petrozavodsk 2020w Day9 C
	template<class F>
	np weighted_merge(np a,np b,F f){
		if(!a)return b;
		if(!b)return a;
		if(a->x.sz<b->x.sz)swap(a,b);
		return weighted_merge_rec(b,a,f);
	}
	//CF743F(TLE)
	template<class F>
	np weighted_merge_rec_cmp(np x,np tar,F f){
		if(!x)return tar;
		x->push();
		tar=weighted_merge_rec_cmp(x->l,tar,f);
		tar=weighted_merge_rec_cmp(x->r,tar,f);
		x->x.single();
		x->clear();
		return insert_cmp(tar,x,f);
	}
	template<class F>
	np weighted_merge_cmp(np a,np b,F f){
		if(!a)return b;
		if(!b)return a;
		if(a->x.len<b->x.len)swap(a,b);
		return weighted_merge_rec_cmp(b,a,f);
	}
	//Petrozavodsk 2020w Day9 C
	void enumerate(np x,vc<N>&dst){
		if(!x)return;
		x->push();
		enumerate(x->l,dst);
		dst.pb(x->x);
		enumerate(x->r,dst);
	}
	/* deprecated
	//Petrozavodsk 2020w Day9 H
	template<class F>
	np insert(np r,np x,F f){
		np a,b;tie(a,b)=split(r,f,x->x);
		return merge(merge(a,x),b);
	}
	template<class F,class...Args>
	np insert(np r,F f,Args&&...args){
		np x=nn(forward<Args>(args)...);
		np a,b;tie(a,b)=split(r,f,x->x);
		return merge(merge(a,x),b);
	}
	//左の列の根は右端とは限らない！
	//右の列の根は左端だと思う
	template<class F,class...Args>
	pair<np,np> split(np a,F f,Args&&...args){
		if(!a)return {0,0};
		np b=a->find(f,forward<Args>(args)...);
		if(b){
			np c=b->l;
			return {c,b->cutl()};
		}
		return {a,0};
	}
	//GCJ2022 Round2 D
	tuple<np> split_by_len(np a){
		return a;
	}
	template<class...Args>
	auto split_by_len(np a,int len,Args...args){
		assert((!a&&len==0)||inc(0,len,a->x.len));
		auto [b,c]=split(a,&N::find_by_len,len);
		assert(len==0);
		return tuple_cat(tuple{b},split_by_len(c,args...));
	}
	*/
};
//デフォルトコンストラクターが null node になっているべき (例えば len=0)
//N::reverse
//N::push
//副作用なし,１個の子にpush
//N::clear
//lazy tagを消去
//N::single
//ノード単体の情報を元に部分木情報を初期化
//N::updatel,updater
//N::find
//find はその部分木内に目標とするノードがあるかどうかを返す
//split のやり方を変えたい
//max_right のノリで split をする
//↓は古い split の仕様
//split は find で見つけたものが右の部分木の left になるように分離する
//split_cmp は cmp(x,v) が true になる最大の x を見つけてそれで分離
//普通に a<b を渡すと lower_bound と同じ効果が得られる
//split_by_len で左 len 個とそれ以外に分離する
//find_by_len という比較関数が定義されていないと破壊

struct N{
	int lz,x,t,len,has;
	N():lz(0),x(0),t(0),len(0),has(0){}
	N(int a,int b):lz(0),x(a),t(b),len(1),has(b){}
	void add(int v){
		lz+=v;
		x+=v;
	}
	void reverse(){}
	void push(N&a){
		a.add(lz);
	}
	void clear(){
		lz=0;
	}
	void single(){
		assert(lz==0);
		len=1;
		has=t;
	}
	void upd(const N&a){
		assert(lz==0);
		len+=a.len;
		has|=a.has;
	}
	void updatel(const N&a){
		upd(a);
	}
	void updater(const N&a){
		upd(a);
	}
	bool ok_len(int v){
		return len<=v;
	}
	bool ok_have(){
		return !has;
	}
	/*bool operator<(const N&r)const{
		return x<r.x;
	}*/
	static bool cmp(const N&a,int v){
		return a.x<v;
	}
};

void slv(){
	int n,d,q;cin>>n>>d>>q;
	vi ini=readvi(n);
	vc<bool> mv(n);
	{
		string s;cin>>s;
		rep(i,n)mv[i]=s[i]=='1';
	}
	vc<tuple<int,int,int>> qs;
	rep(i,q){
		int k,m;cin>>k>>m;
		m--;
		qs.eb(k,m,i);
	}
	sort(all(qs));
	splaytree<N> t(n);
	using np=splaytree<N>::np;
	np root=nullptr;
	int cur=0,ih=0,qh=0;
	vi done;
	rep(i,n)if(mv[i]){
		root=t.nn(ini[i],0);
		ih=i+1;
		break;
	}else{
		done.pb(ini[i]);
	}
	vi ans(q);
	while(1){
		assert(root);
		int mn=inf;
		while(qh<q){
			auto [k,m,i]=qs[qh];
			if(cur<k){
				mn=k-cur;
				break;
			}
			qh++;
			dmp2(k,m,i);
			if(m<si(done)){
				ans[i]=done[m];
			}else{
				m-=si(done);
				if(m<root->x.len){
					auto [l,r]=t.max_right(root,&N::ok_len,m);
					assert(r);
					ans[i]=r->x.x;
					root=t.merge(l,r);
				}else{
					m-=root->x.len;
					ans[i]=ini[ih+m];
				}
			}
		}
		if(qh==q)break;
		int c=d+root->x.len-1;
		np spare;
		tie(root,spare)=t.max_right(root,&N::ok_have);
		if(!root){
			spare=spare->left();
			done.pb(spare->x.x);
			root=t.erase(spare);
			continue;
		}
		if(ih<n){
			int tar=ini[ih]-c;
			auto [l,r]=t.split_cmp(root,&N::cmp,tar);
			root=l;
			spare=t.merge(r,spare);
		}
		{
			auto [l,r]=t.max_right(root,&N::ok_len,mn);
			root=l;
			spare=t.merge(r,spare);
		}
		if(!root){
			assert(ih<n);
			root=t.merge(spare,t.nn(ini[ih],!mv[ih]));
			ih++;
			continue;
		}
		if(spare){
			cur+=root->x.len;
			root->x.add(c);
			root=t.merge(spare,root);
			continue;
		}
		int step=mn/root->x.len;
		if(ih<n){
			root=root->right();
			chmin(step,(ini[ih]-root->x.x-1)/c);
		}
		assert(step>0);
		cur+=step*root->x.len;
		root->x.add(step*c);
	}
	for(auto v:ans)print(v);
}

signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	
	//int t;cin>>t;rep(_,t)
	slv();
}