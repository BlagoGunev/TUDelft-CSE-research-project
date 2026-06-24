#include<bits/stdc++.h>

namespace header{

//definitions

#define For(i,j,k) for(int i=(j);i<=(k);i++)

#define Rof(i,j,k) for(int i=(j);i>=(k);i--)

#define eb emplace_back

#define pb push_back

#define mkp make_pair

#define fir first

#define sec second

#define ll long long

#define ull unsigned long long

#define lll __int128

#define ulll unsigned __int128

#define db double

#define ldb long double

#define uint unsigned int

#define pii pair<int,int>

#define pll pair<ll,ll>

#define pil pair<int,ll>

#define pli pair<ll,int>

#define vi vector<int>

#define vl vector<ll>

#define dbg std::cout<<"Line "<<__LINE__<<": "

//functions

template<class T>inline void mem(T *a,int b){memset(a,b,sizeof(a));}

inline void fin(std::string s){freopen(s.data(),"r",stdin);}

inline void fout(std::string s){freopen(s.data(),"w",stdout);}

inline void fio(std::string s){fin(s+".in"),fout(s+".out");}

template<class T>inline T mins(T a,T b){return a<b?a:b;}

template<class T1,class ...T2>inline T1 mins(T1 a,T1 b,T2 ...args){return mins(a,mins(b,args...));}

template<class T>inline T maxs(T a,T b){return a<b?b:a;}

template<class T1,class ...T2>inline T1 maxs(T1 a,T1 b,T2 ...args){return maxs(a,maxs(b,args...));}

template<class T1,class ...T2>inline void ckmin(T1 &a,T2 ...args){a=mins(a,args...);}

template<class T1,class ...T2>inline void ckmax(T1 &a,T2 ...args){a=maxs(a,args...);}

template<class T>inline T lowbit(T a){return a&-a;}

template<class T>inline void addlowbit(T &a){a=a+lowbit(a);}

template<class T>inline void sublowbit(T &a){a=a-lowbit(a);}

//modulo operation

template<class T>inline T modadd(T m,T a,T b){return (a+b)%m;}

template<class T1,class ...T2>inline T1 modadd(T1 m,T1 a,T1 b,T2 ...args){return modadd(m,a,modadd(m,b,args...));}

template<class T>inline T modmul(T m,T a,T b){return 1ll*a*b%m;}

template<class T1,class ...T2>inline T1 modmul(T1 m,T1 a,T1 b,T2 ...args){return modmul(m,a,modmul(m,b,args...));}

template<class T>inline T modposit(T m,T a){return (a%m+m)%m;}

template<class T>inline T ckmodposit(T m,T &a){a=modposit(m,a);}

template<class T1,class ...T2>inline void ckmodadd(T1 m,T1 &a,T2 ...args){a=modadd(m,a,args...);}

template<class T1,class ...T2>inline void ckmodmul(T1 m,T1 &a,T2 ...args){a=modmul(m,a,args...);}

template<class T1,class T2>inline T1 modpow(T1 m,T1 a,T2 b){T1 ret=1;while(b){if(b&1)ckmodmul(m,ret,a);ckmodmul(m,a,a);b>>=1;}return ret;}

template<class T1>inline T1 modinv(T1 m,T1 a){return modpow(m,a,m-2);}

#define mod 998244353ll

#define madd(a...) modadd(mod,a)

#define mmul(a...) modmul(mod,a)

#define mposit(a) modposit(mod,a)

#define ckmposit(a) (a=mposit(a))

#define ckmadd(a,b...) (a=madd(a,b))

#define ckmmul(a,b...) (a=mmul(a,b))

#define minv(a) modinv(mod,a)

#define mpow(a,b) modpow(mod,a,b)

//io

#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)

//io reader

inline lll readlll(){int f=0,ch=getchar();lll x=0;while(!isdigit(ch))f=ch=='-',ch=getchar();while(isdigit(ch))x=x*10+ch-48,ch=getchar();return (1-2*f)*x;}

inline int readint(){int f=0,ch=getchar();uint x=0;while(!isdigit(ch))f=ch=='-',ch=getchar();while(isdigit(ch))x=x*10+ch-48,ch=getchar();return (1-2*f)*x;}

inline ll readll(){int f=0,ch=getchar();ull x=0;while(!isdigit(ch))f=ch=='-',ch=getchar();while(isdigit(ch))x=x*10+ch-48,ch=getchar();return (1-2*f)*x;}

inline uint readuint(){int ch=getchar();uint x=0;while(!isdigit(ch))ch=getchar();while(isdigit(ch))x=x*10+ch-48,ch=getchar();return x;}

inline ull readull(){int ch=getchar();ull x=0;while(!isdigit(ch))ch=getchar();while(isdigit(ch))x=x*10+ch-48,ch=getchar();return x;}

inline void read(int &x){x=readint();}

inline void read(uint &x){x=readuint();}

inline void read(ll &x){x=readll();}

inline void read(lll &x){x=readlll();}

inline void read(ull &x){x=readull();}

inline void read(char &x){x=getchar();}

inline void read(char* &x){scanf("%s",x);}

inline void read(ldb &x){scanf("%Lf",&x);}

inline void read(float &x){scanf("%f",&x);}

inline void read(db &x){scanf("%lf",&x);}

inline db readdb(){db x;read(x);return x;}

inline ldb readldb(){ldb x;read(x);return x;}

inline float readfloat(){float x;read(x);return x;}

template<class T>inline void read(T &x){std::cin>>x;}

template<class T1,class ...T2>inline void read(T1 &x,T2 &...args){read(x),read(args...);}

//io writer

inline void write(lll x){if(x<0)putchar('-'),x=-x;if(x>9)write(x/10);putchar(48+x%10);}

inline void write(int x){if(x==INT_MIN){printf("%d",x);return;}if(x<0)putchar('-'),x=-x;if(x>9)write(x/10);putchar(48+x%10);}

inline void write(ll x){if(x==LLONG_MIN){printf("%lld",x);return;}if(x<0)putchar('-'),x=-x;if(x>9)write(x/10);putchar(48+x%10);}

inline void write(uint x){if(x>9)write(x/10);putchar(48+x%10);}

inline void write(ull x){if(x>9)write(x/10);putchar(48+x%10);}

inline void write(char x){putchar(x);}

inline void write(char *x){printf("%s",x);}

inline void write(db x){printf("%lf",x);}

inline void write(ldb x){printf("%Lf",x);}

inline void write(float x){printf("%f",x);}

template<class T>inline void write(T x){std::cout<<x;}

template<class T1,class ...T2>inline void write(T1 x,T2 ...args){write(x),write(args...);}

template<class T>inline void writespace(T x){write(x);}

template<class T1,class ...T2>inline void writespace(T1 x,T2 ...args){write(x),write(' '),writespace(args...);}

template<class T>inline void writeenter(T x){write(x);}

template<class T1,class ...T2>inline void writeenter(T1 x,T2 ...args){write(x),write('\n'),writeenter(args...);}

};

using namespace header;

using namespace std;

#define int long long

int n,m,a[1010][1010];

struct node{int x,y,val;};

vector<node> ans;

void paint(int x,int y){

	if(x==0||x==n||y==0||y==m) return;

	int val[]={a[x][y],a[x+1][y],a[x][y+1],a[x+1][y+1]};

	sort(val,val+4);

	if(val[3]==0) return;

	bool flag=true;

	For(i,0,2) if(val[i]!=0&&val[i]!=val[3]) flag=false;

	if(!flag) return;

	ans.pb((node){x,y,val[3]});

	For(i,x,x+1) For(j,y,y+1) a[i][j]=0;

	For(i,x-1,x+1) For(j,y-1,y+1) paint(i,j);

}

signed main(){

	read(n,m);

	For(i,1,n) For(j,1,m) read(a[i][j]);

	For(i,1,n-1) For(j,1,m-1) paint(i,j);

	reverse(ans.begin(),ans.end());

	For(i,1,n) For(j,1,m) if(a[i][j]!=0){write(-1,'\n');return 0;}

	write(ans.size(),'\n');

	for(auto p:ans) write(p.x,' ',p.y,' ',p.val,'\n');

}