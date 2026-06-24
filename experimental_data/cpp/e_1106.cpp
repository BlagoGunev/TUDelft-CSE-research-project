//minamoto
#include<bits/stdc++.h>
#define R register
#define ll long long
#define ls (p<<1)
#define rs (p<<1|1)
#define fp(i,a,b) for(R int i=a,I=b+1;i<I;++i)
#define fd(i,a,b) for(R int i=a,I=b-1;i>I;--i)
#define go(u) for(int i=head[u],v=e[i].v;i;i=e[i].nx,v=e[i].v)
template<class T>inline bool cmax(T&a,const T&b){return a<b?a=b,1:0;}
template<class T>inline bool cmin(T&a,const T&b){return a>b?a=b,1:0;}
using namespace std;
char buf[1<<21],*p1=buf,*p2=buf;
inline char getc(){return p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++;}
int read(){
	R int res=1,f=1;R char ch;
	while((ch=getc())>'9'||ch<'0')(ch=='-')&&(f=-1);
	for(res=ch-'0';(ch=getc())>='0'&&ch<='9';res=res*10+ch-'0');
	return res*f;
}
const int N=1e5+5;
struct node{
    int w,d;
    node(){}
    node(R int w,R int d):w(w),d(d){}
    inline bool operator <(const node &b)const{return w==b.w?d<b.d:w<b.w;}
}tr[N<<2];
ll dp[N][205],res;int nxt[N],w[N];
int n,ql,qr,qd,qw,m,k;
void update(int p,int l,int r){
    if(ql<=l&&qr>=r)return cmax(tr[p],node(qw,qd)),void();
    int mid=(l+r)>>1;
    if(ql<=mid)update(ls,l,mid);
    if(qr>mid)update(rs,mid+1,r);
}
void build(int p,int l,int r,node res){
    if(l==r)return nxt[l]=res.d+1,w[l]=res.w,void();
    int mid=(l+r)>>1;
    build(ls,l,mid,max(res,tr[ls]));
    build(rs,mid+1,r,max(res,tr[rs]));
}
int main(){
//    freopen("testdata.in","r",stdin);
    n=read(),k=read(),m=read();
    fp(i,1,m)ql=read(),qr=read(),qd=read(),qw=read(),update(1,1,n);
    build(1,1,n,tr[1]);
    memset(dp,0x3f,sizeof(dp));
    dp[n+1][0]=0,res=dp[0][0];
//    fp(i,1,n)printf("%d %d\n",nxt[i],w[i]);
    fd(i,n,1)if(nxt[i]==1){
        memcpy(dp[i],dp[i+1],sizeof(dp[i]));
    }else{
        fp(j,1,k)dp[i][j]=min(dp[nxt[i]][j]+w[i],dp[i+1][j-1]);
        dp[i][0]=dp[nxt[i]][0]+w[i];
    }
    fp(i,0,k)cmin(res,dp[1][i]);
    printf("%I64d\n",res);
    return 0;
}