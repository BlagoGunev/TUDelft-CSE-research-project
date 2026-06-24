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

#define eb emplace_back

#define a first

#define b second

#define bg begin()

#define ed end()

#define all(x) x.bg,x.ed

#define si(x) int(x.size())

template<class t> using vc=vector<t>;

template<class t> using vvc=vc<vc<t>>;

using pi=pair<int,int>;

using vi=vc<int>;

#define mp make_pair

#define mt make_tuple

#define one(x) memset(x,-1,sizeof(x))

#define zero(x) memset(x,0,sizeof(x))

using uint=unsigned;

using ull=unsigned long long;

template<class t>

void print(t x,int suc=1){

	cout<<x;

	if(suc==1)

		cout<<"\n";

	if(suc==2)

		cout<<" ";

}

const ll infLL=LLONG_MAX/3;

#ifdef int

const int inf=infLL;

#else

const int inf=INT_MAX/2-100;

#endif

int popcount(signed t){

	return __builtin_popcount(t);

}

int popcount(ll t){

	return __builtin_popcountll(t);

}

int popcount(ull t){

	return __builtin_popcountll(t);

}

bool inc(int a,int b,int c){

	return a<=b&&b<=c;

}

struct modinfo{uint mod,root;

#ifdef DYNAMIC_MOD

constexpr modinfo(uint m,uint r):mod(m),root(r),im(0){set_mod(m);}

ull im;

#endif 

};

template<modinfo const&ref>

struct modular{

	static constexpr uint const &mod=ref.mod;

	static modular root(){return modular(ref.root);}

	uint v;

	modular(ll vv=0){s(vv%mod+mod);}

	modular& s(uint vv){

		v=vv<mod?vv:vv-mod;

		return *this;

	}

	modular operator-()const{return modular()-*this;}

	modular& operator+=(const modular&rhs){return s(v+rhs.v);}

	modular&operator-=(const modular&rhs){return s(v+mod-rhs.v);}

	modular&operator*=(const modular&rhs){

		#ifndef DYNAMIC_MOD

		v=ull(v)*rhs.v%mod;

		#else

		v=ref.product(v,rhs.v);

		#endif

		return *this;

	}

	modular&operator/=(const modular&rhs){return *this*=rhs.inv();}

	modular operator+(const modular&rhs)const{return modular(*this)+=rhs;}

	modular operator-(const modular&rhs)const{return modular(*this)-=rhs;}

	modular operator*(const modular&rhs)const{return modular(*this)*=rhs;}

	modular operator/(const modular&rhs)const{return modular(*this)/=rhs;}

	modular pow(ll n)const{

		if(n<0)return inv().pow(-n);

		modular res(1),x(*this);

		while(n){

			if(n&1)res*=x;

			x*=x;

			n>>=1;

		}

		return res;

	}

	modular inv()const{return pow(mod-2);}

	friend modular operator+(ll x,const modular&y){

		return modular(x)+y;

	}

	friend modular operator-(ll x,const modular&y){

		return modular(x)-y;

	}

	friend modular operator*(ll x,const modular&y){

		return modular(x)*y;

	}

	friend modular operator/(ll x,const modular&y){

		return modular(x)/y;

	}

	friend ostream& operator<<(ostream&os,const modular&m){

		return os<<m.v;

	}

	friend istream& operator>>(istream&is,modular&m){

		ll x;is>>x;

		m=modular(x);

		return is;

	}

	bool operator<(const modular&r)const{return v<r.v;}

	bool operator==(const modular&r)const{return v==r.v;}

	bool operator!=(const modular&r)const{return v!=r.v;}

	explicit operator bool()const{

		return v; 

	}

}; 

#ifndef DYNAMIC_MOD

extern constexpr modinfo base{998244353,3};

#ifdef USE_GOOD_MOD

static_assert(base.mod==998244353);

#endif

#else

modinfo base(1,0);

extern constexpr modinfo base107(1000000007,0);

using mint107=modular<base107>;

#endif

using mint=modular<base>;

mint parity(int i){

	return i%2==0?1:-1;

}

pi readpos(){

	int r,c;cin>>r>>c;

	return pi(r-1,c-1);

}

const int smax=205;

bool need[smax][smax],pre[smax][smax],nx[smax][smax];

mint dp[smax][smax][2];

void slv(){

	int h,w,k;cin>>h>>w>>k;

	pi z[2];

	rep(i,k)z[i]=readpos();

	if(k==2&&z[0]>z[1])swap(z[0],z[1]);

	if(k==2&&z[0].b>z[1].b){

		z[0].b=w-1-z[0].b;

		z[1].b=w-1-z[1].b;

	}

	if(k==2){

		assert(z[0].a<=z[1].a);

		assert(z[0].b<=z[1].b);

	}

	mint ans=0;

	{

		ans+=mint(2).pow(h*w);

		ans-=mint(2).pow((h-1)*w);

		ans-=mint(2).pow(h*(w-1));

		ans+=mint(2).pow((h-1)*(w-1));

	}

	rng(a,1,h+1)rng(b,1,w+1){

		rep(i,a)rep(j,b){

			need[i][j]=false;

			pre[i][j]=false;

			nx[i][j]=false;

		}

		bool ok=true;

		rep(i,h-a+1)rep(j,w-b+1){

			int cnt=0;

			rep(q,k){

				auto [x,y]=z[q];

				x-=i;

				y-=j;

				if(inc(0,x,a-1)&&inc(0,y,b-1))

					cnt++;

			}

			if(cnt==0){

				ok=false;

				break;

			}

			rep(q,k){

				auto [x,y]=z[q];

				x-=i;

				y-=j;

				if(inc(0,x,a-1)&&inc(0,y,b-1)){

					if(cnt==0){

					}else if(cnt==1){

						need[x][y]=true;

					}else{

						if(q==0)nx[x][y]=true;

						else pre[x][y]=true;

					}

				}

			}

		}

		if(ok){

			int dx=0,dy=0;

			if(k==2){

				dx=z[1].a-z[0].a;

				dy=z[1].b-z[0].b;

			}

			mint buf[16][16];

			rep(bit,16)rep(bit2,16)if((bit&bit2)==0)buf[bit][bit2]=1;

			rep(i,a)rep(j,b)if(!pre[i][j]){

				int unko=0;

				for(int x=i,y=j;;x+=dx,y+=dy){

					if(x==0)unko|=1;

					if(x==a-1)unko|=2;

					if(y==0)unko|=4;

					if(y==b-1)unko|=8;

					if(!nx[x][y])break;

				}

				int rem=15-unko,bit=unko;

				do{

					for(int x=i,y=j;;x+=dx,y+=dy){

						if(pre[x][y]){

							dp[x][y][0]=dp[x-dx][y-dy][1];

							dp[x][y][1]=dp[x-dx][y-dy][0]+dp[x-dx][y-dy][1];

						}else{

							dp[x][y][0]=1;

							dp[x][y][1]=1;

						}

						if(need[x][y])dp[x][y][0]=0;

						if((bit&1)&&x==0)dp[x][y][1]=0;

						if((bit&2)&&x==a-1)dp[x][y][1]=0;

						if((bit&4)&&y==0)dp[x][y][1]=0;

						if((bit&8)&&y==b-1)dp[x][y][1]=0;

						if(!nx[x][y]){

							buf[rem][bit]*=(dp[x][y][0]+dp[x][y][1]);

							break;

						}

					}

					bit=(bit-1)&unko;

				}while(bit!=unko);

			}

			mint tot[16];

			rep(bit,16)tot[bit]=1;

			rep(bit,16)rep(bit2,16)if((bit&bit2)==0){

				int sub=bit;

				do{

					tot[sub|bit2]*=buf[bit][bit2];

					sub=(sub-1)&bit;

				}while(sub!=bit);

			}

			rep(bit,16)ans-=tot[bit]*parity(popcount(bit));

		}

	}

	print(ans);

}

signed main(){

	cin.tie(0);

	ios::sync_with_stdio(0);

	cout<<fixed<<setprecision(20);

	int t;cin>>t;rep(_,t)

	slv();

}