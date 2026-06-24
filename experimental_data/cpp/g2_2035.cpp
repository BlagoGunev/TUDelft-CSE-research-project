//#define NDEBUG
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#include<bits/stdc++.h>
#define For(i,j,k) for(int i=(j);i<=(k);++i)
#define ForD(i,j,k) for(int i=(j);i>=(k);--i)
#define int long long
#define endl '\n'
using namespace std;
bool Mbe;
#define ll long long
const int mod=998244353;
struct modint{
	int val;
	static int norm(const int &x){return x<0?x+mod:x;}
	modint():val(0) {}
    modint(const ll& m):val(norm(m%mod)) {}
	modint inv() const{
		int a=val,b=mod,u=1,v=0,t;
        while(b>0) t=a/b,swap(a-=t*b,b),swap(u-=t*v,v);
        return modint(u);
	}
	modint operator-() const{return modint(norm(-val));}
    bool operator==(const modint& o){return val==o.val;}
    bool operator<(const modint& o){return val<o.val;}
    modint& operator+=(const modint& o){return val=(1ll*val+o.val)%mod,*this;}
    modint& operator-=(const modint& o){return val=norm(1ll*val-o.val),*this;}
    modint& operator*=(const modint& o){return val=(1ll*val*o.val%mod),*this;}
    modint& operator/=(const modint& o){return *this*=o.inv();}
    modint& operator^=(const modint& o){return val^=o.val,*this;}
    modint& operator>>=(const modint& o){return val>>=o.val,*this;}
    modint& operator<<=(const modint& o){return val<<=o.val,*this;}
    modint operator-(const modint& o) const{return modint(*this)-=o;}
    modint operator+(const modint& o) const{return modint(*this)+=o;}
    modint operator*(const modint& o) const{return modint(*this)*=o;}
    modint operator/(const modint& o) const{return modint(*this)/= o;}
    modint operator^(const modint& o) const{return modint(*this)^= o;}
    modint operator>>(const modint& o) const{return modint(*this)>>=o;}
    modint operator<<(const modint& o) const{return modint(*this)<<=o;}
    friend modint qpow(const modint& a,const ll& b){
        modint x=a,res=1;
        for(ll p=b;p;x*=x,p>>=1) if (p&1) res*=x;
        return res;
    }
};
const int N=3e5+5;
struct Answer{
    int len;
    modint cnt;
    friend Answer operator+(const Answer x,const Answer y){
        if(x.len>y.len) return x;
        if(y.len>x.len) return y;
        return {x.len,x.cnt+y.cnt};
    }
    friend Answer operator-(const Answer x,const Answer y){assert(x.len==y.len); return {x.len,x.cnt-y.cnt};}
    friend Answer operator*(const Answer x,const modint y){return {x.len,x.cnt*y};}
}dp[N],f[N],g[N];
int n,m,invn;
int a[N],pos[N],nw[N];
modint val[N];
vector<int> L[N],R[N];
vector<modint> C[N];
void Clear(){
    For(i,1,n){
        a[i]=pos[i]=0;
        L[i].clear(),R[i].clear(),C[i].clear();
        dp[i]=f[i]=g[i]={-1,1};
        nw[i]=0,val[i]=1;
    }
}
#define pb push_back
void build(int l,int r,int p){
    if(l==r) return;
    int mid=(l+r)>>1;
    if(p==mid) return build(l,mid,p);
    if(p<mid) R[p].pb(mid),build(l,mid,p);
    else L[p].pb(mid),build(mid+1,r,p);
}
void solve(){
    cin>>n>>m;
    invn=(((modint)(n)).inv()).val;
    Clear();
    For(i,1,m){
        int x,k; cin>>x>>k;
        if(k!=1||x==1) a[x]=k,pos[k]=x;
    }
    For(i,1,n) build(1,n,i);
    For(i,1,n) reverse(L[i].begin(),L[i].end()),reverse(R[i].begin(),R[i].end());
    For(i,1,n){
        for(int j:L[i]){
            modint B=n-a[j]+1;
            B*=invn;
            while(nw[j]<(int)R[j].size()&&R[j][nw[j]]<i) val[j]*=B,nw[j]++;
            C[i].pb(val[j]);
        }
    }
    Answer ans={0,1};
    For(i,1,n) if(pos[i]){
        int x=pos[i];
        modint v=1,B=i-1;
        B*=invn;
        for(int j=0;j<(int)L[x].size();j++){
            int y=L[x][j];
            dp[x]=dp[x]+((f[y]*i)-g[y])*invn*v;
            if(a[y]) dp[x]=dp[x]+dp[y]*C[x][j]*v;
            v*=B;
        }
        dp[x]=dp[x]+((Answer){0,v});
        dp[x].len++;
        v=1,B=(n-i+1);
        B*=invn;
        for(int j=0;j<(int)R[x].size();j++){
            int y=R[x][j];
            f[y]=f[y]+dp[x]*v;
            g[y]=g[y]+dp[x]*v*i;
            v*=B;
        }
        ans=ans+(dp[x]*v);
    }
    modint Ans=ans.cnt*qpow((modint)n,n-ans.len);
    cout<<m-ans.len<<' '<<Ans.val<<endl;
}
bool Med;
signed main(){
	fprintf(stderr,"%.3lf MB\n",(&Mbe-&Med)/1048576.0);
	ios::sync_with_stdio(false); cin.tie(0),cout.tie(0);
	int _=1;
	cin>>_;
	while(_--) solve();
	cerr<<1e3*clock()/CLOCKS_PER_SEC<<" ms\n";
	return 0;
}