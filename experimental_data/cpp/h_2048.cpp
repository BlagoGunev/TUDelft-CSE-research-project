//Mashiro
#include<bits/stdc++.h>

#define vc vector
#define db double
#define fi first
#define se second
#define ll long long
#define mk make_pair
#define pb push_back
#define RI register int
#define PI pair<int,int>
#define ull unsigned long long
#define err cerr << "   -_-   " << endl
#define debug cerr << " ------------------- " << endl

#define input(x) freopen(#x".in","r",stdin)
#define output(x) freopen(#x".out","w",stdout)

#define NO puts("No")
#define YES puts("Yes")

//#define OccDreamer
//#define int long long

using namespace std;

namespace IO{
	inline ll read(){
		ll X=0, W=0; char ch=getchar();
		while(!isdigit(ch)) W|=ch=='-', ch=getchar();
		while(isdigit(ch)) X=(X<<1)+(X<<3)+(ch^48), ch=getchar();
		return W?-X:X;
	}
	inline void write(ll x){
		if(x<0) x=-x, putchar('-');
		if(x>9) write(x/10);
		putchar(x%10+'0');
	}
	inline void sprint(ll x){write(x), putchar(31);}
	inline void eprint(ll x){write(x), putchar(10);}
}using namespace IO;

const int MAXN = 2e6 + 6;
const int mod = 998244353;

char s[MAXN];

int L, R, n, dpl, dpr;
int tree[MAXN<<2], pre[MAXN], lst[MAXN];

inline void psu(int p){return tree[p]=(tree[p<<1]+tree[p<<1|1])%mod, void();}

inline void build(int p, int l, int r){
	if(l==r){
		if(l==n+1) return tree[p]=1, void();
		return tree[p]=0, void();
	}
	int mid=(l+r)>>1;
	build(p<<1,l,mid), build(p<<1|1,mid+1,r);
	return psu(p);
}

inline int ask(int p, int l, int r, int L, int R){
	if(L>R) return 0;
	if(L<=l && r<=R) return tree[p];
	int mid=(l+r)>>1, res=0;
	if(L<=mid) res=(res+ask(p<<1,l,mid,L,R))%mod;
	if(R>mid) res=(res+ask(p<<1|1,mid+1,r,L,R))%mod;
	return res;
}

inline void add(int p, int l, int r, int pos, int v){
	if(l==r) return (tree[p]+=v)%=mod, void();
	int mid=(l+r)>>1;
	if(pos<=mid) add(p<<1,l,mid,pos,v);
	else add(p<<1|1,mid+1,r,pos,v);
	return psu(p);
}

inline void solve(){
	scanf("%s",s+1);
	n=strlen(s+1); L=1, R=(n<<1)+1;
	dpl=1, dpr=n+1; int pos=0;
	for(int i=1;i<=n;++i) lst[i]=0;
	for(int i=1;i<=n;++i){
		if(s[i]=='1') pos=i;
		lst[i]=pos;
		pre[i]=pre[i-1]+(s[i]=='1');
	}
	build(1,L,R);
	int ans=0;
	for(int i=n;i>=1;--i){
		int las=lst[i];
		//las+1 ~ i+1
		int s=ask(1,1,R,dpl+las+1,dpl+i);
		dpl++, dpr++;
//		cerr << "add:" << dpl+las << ' ' << dpl+i << "   sum=" << s << ' ' << dpl+las-1 << endl;
		add(1,1,R,dpl+las-1,s);
		(ans+=ask(1,1,R,dpl,dpr))%=mod;
//		cerr << "ans=" << ans << endl;
	}
	eprint(ans);
}

int main(){
	int t=read();
	while(t--) solve();
	return 0;
}