// LUOGU_RID: 161889366
#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);i++)
#define dF(i,a,b) for(int i=a;i>=(b);i--)
const int MAXN=2e5+5;
const int T=19;
namespace Read{
    #define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
    char buf[1<<21],*p1=buf,*p2=buf;
    const int OUT=20;
    static char outp[OUT];
    int out;
    template<typename T>inline void read(T& t){
        int c=getchar(),f=1;t=0;
        while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
        while(isdigit(c))t=t*10+c-48,c=getchar();t*=f;
    }
    template<typename T,typename ...Args>inline void read(T& t,Args&... args){
        read(t),read(args...);
    }
    template<typename T>inline void write(T x){
        if(typeid(x)==typeid(1)||typeid(x)==typeid(long long)){
            out=0; x<0&&(x=-x,putchar('-'));
            if(!x){ putchar(48); return; }
            while(x) outp[++out]=x%10+48,x/=10;
            while(out) putchar(outp[out--]);
        }
        else if(typeid(x)==typeid(char))putchar(x);
    }
    template<typename T,typename ...Args>inline void write(T t,Args ...args){
        write(t);
        write(args...);
    }
}
using namespace Read;
int n,k,a[MAXN],ans=1e9;
basic_string <int> app[MAXN];
#define All(x) x.begin(),x.end()
inline int findnxt(int cnt,int id){return app[cnt][upper_bound(All(app[cnt]),id)-app[cnt].begin()];}
inline int findlst(int cnt,int id){return app[cnt][lower_bound(All(app[cnt]),id)-app[cnt].begin()-1];}
int LstU[T+1][MAXN],NxtU[T+1][MAXN];
int LstD[T+1][MAXN],NxtD[T+1][MAXN];
inline bool checked(int x){return 1<=x&&x<=n;}
inline void init(){
    F(i,0,n+1)app[i].push_back(0);
    F(i,1,n)app[a[i]].push_back(i);
    F(i,0,n+1)app[i].push_back(n+1);
    F(i,1,n){
        LstU[0][i]=findlst(a[i]-1,i);
        LstD[0][i]=findlst(a[i]+1,i);
        NxtU[0][i]=findnxt(a[i]+1,i);
        NxtD[0][i]=findnxt(a[i]-1,i);
    }
    F(k,1,T)F(i,1,n){
        LstU[k][i]=!checked(LstU[k-1][i])?LstU[k-1][i]:LstU[k-1][LstU[k-1][i]];
        NxtU[k][i]=!checked(NxtU[k-1][i])?NxtU[k-1][i]:NxtU[k-1][NxtU[k-1][i]];
        LstD[k][i]=!checked(LstD[k-1][i])?LstD[k-1][i]:LstD[k-1][LstD[k-1][i]];
        NxtD[k][i]=!checked(NxtD[k-1][i])?NxtD[k-1][i]:NxtD[k-1][NxtD[k-1][i]];
    }
}
inline int findLstU(int x,int mid){dF(i,T,0)if(LstU[i][x]>=mid)x=LstU[i][x];return a[x];}
inline int findLstD(int x,int mid){dF(i,T,0)if(LstD[i][x]>=mid)x=LstD[i][x];return a[x];}
inline int findNxtU(int x,int mid){dF(i,T,0)if(NxtU[i][x]<=mid)x=NxtU[i][x];return a[x];}
inline int findNxtD(int x,int mid){dF(i,T,0)if(NxtD[i][x]<=mid)x=NxtD[i][x];return a[x];}
inline int make_ans(int p,int q,int fir,int sec,int thd,int fur){
    int L=-1,R=-1;
    int l=1,r=p;while(l<=r){int mid=l+r>>1;if(findLstD(fir,mid)-findLstU(sec,mid)>=k/2-1)L=mid,l=mid+1;else r=mid-1;}
    l=q,r=n;while(l<=r){int mid=l+r>>1;if(findNxtU(thd,mid)-findNxtD(fur,mid)>=k/2-1)R=mid,r=mid-1;else l=mid+1;}
    if(L==-1||R==-1)return 1e9;
    return R-L;
}
signed main(){
    read(n,k);if(k&1)return write(-1),0;
    F(i,1,n)read(a[i]);init();
    F(i,1,n){
        int p=i,q=findnxt(a[i],i);
        if(!checked(q))continue;
        ans=min({ans,make_ans(p,q,p,p,p,q),make_ans(p,q,q,p,q,q),make_ans(p,q,p,q,q,q),make_ans(p,q,p,p,q,p)});
    }
    if(ans>n)ans=-1;
    write(ans);
}