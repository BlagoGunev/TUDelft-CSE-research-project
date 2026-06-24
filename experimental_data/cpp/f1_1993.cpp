//based on windows 10
//by xxqz
#include<bits/stdc++.h>
using namespace std;
#define printf BOOOOOOOOOOOOOOOOOOOOOM!!!!!!!!!!!!!!
#define puts BOOOOOOOOOOOOOOOOOOOOOM!!!!!!!!!!!!!!
#define putchar BOOOOOOOOOOOOOOOOOOOOOM!!!!!!!!!!!!!!
#define putc BOOOOOOOOOOOOOOOOOOOOOM!!!!!!!!!!!!!!
#define scanf BOOOOOOOOOOOOOOOOOOOOOM!!!!!!!!!!!!!!
#define getchar BOOOOOOOOOOOOOOOOOOOOOM!!!!!!!!!!!!!!
#define getc BOOOOOOOOOOOOOOOOOOOOOM!!!!!!!!!!!!!!
namespace def{
#define mem(a,b) memset(a,b,sizeof a)
#define mec(a,b) memcpy(a,b,sizeof a)
#define Re register
#define il inline
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef double db;
typedef long double ldb;
#define mkp(a,b) make_pair(a,b)
#define pii pair<int,int> 
#define lb(x) (x&-x)
#define TEM template<typename T>
TEM T Tmin(const T a,const T b){
    if(a>b) return b;
    else return a;
}
TEM T Tmax(const T a,const T b){
    if(a>b) return a;
    else return b;
}
template<typename T,typename...Args>
T Tmax(const T A,const Args... b){
    return Tmax(A,Tmax(b...));
}
template<typename T,typename...Args>
T Tmin(const T A,const Args... b){
    return Tmin(A,Tmin(b...));
}
#define max Tmax
#define min Tmin
TEM void ckm(T &a,const T b){
    if(b<a)a=b;
}
TEM void ckx(T &a,const T b){
    if(b>a)a=b;
}
void set_online_judge(int x){
    ios::sync_with_stdio(0);
    cin.tie(NULL),cout.tie(NULL);
}
}
using namespace def;

#define endl '\n'

namespace zhu{
#define int long long
int N,M;
int mod=998244353;
int qp(int x,int y){
    int ret=1;
    while(y){
        if(y&1) ret=ret*x%mod;
        x=x*x%mod;
        y>>=1;
    }
    return ret;
}
int ny(int x){
    return qp(x,mod-2);
}
void NO(){cout<<"NO"<<'\n';}
void YES(){cout<<"YES"<<'\n';}
int w,h,k;string s;
int sgn(int x){
    if(x<0) return -1;
    if(x==0) return 0;
    return 1;
}
map<pii,int>mp;
void solve(){
    cin>>N>>k>>w>>h;w<<=1,h<<=1;mp.clear();
    int ans=0;cin>>s;int nx=0,ny=0;
    for(auto c:s){
        if(c=='U') ny++;
        if(c=='D') ny--;
        if(c=='L') nx--;
        if(c=='R') nx++;
        nx=(nx+w)%w;
        ny=(ny+h)%h;
        mp[mkp(nx,ny)]++;
    }
    int X=0,Y=0;
    ans+=mp[mkp(0,0)];
    for(int i=2;i<=k;i++){
        X=(X+nx+w)%w;
        Y=(Y+ny+h)%h;
        ans+=mp[mkp((w-X)%w,(h-Y)%h)];
    }
    cout<<ans<<endl;
}

int MAIN(){
    int T;cin>>T;
    while(T--) 
    solve();
    return 0;
}
};
#undef int
using namespace zhu;
int main(){
    #ifdef ONLINE_JUDGE 
    set_online_judge(1);
    #endif
    return MAIN();
}