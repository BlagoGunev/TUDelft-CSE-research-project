//based on windows 10
//by xxqz
#include<bits/stdc++.h>
using namespace std;
namespace def{
#define mem(a,b) memset(a,b,sizeof a)
#define mec(a,b) memcpy(a,b,sizeof a)
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef double db;
typedef long double ldb;
#define mkp(a,b) make_pair(a,b)
#define pii pair<int,int> 
#define lb(x) (x&-x)
#define TEM template<typename T>
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
// #define int long long
int N,M;
constexpr int mod=998244353;
int qp(int x,int y){
    int ret=1;
    while(y){
        if(y&1) ret=1ll*ret*x%mod;
        x=1ll*x*x%mod;
        y>>=1;
    }
    return ret;
}
int ny(int x){
    return qp(x,mod-2);
}
void NO(){cout<<"NO"<<'\n';}
void YES(){cout<<"YES"<<'\n';}
constexpr int maxn(2e5+5);
int val[maxn];
void solve(){
    cin>>N>>M;
    for(int i=1;i<=M;i++){
        int b,c;
        cin>>b>>c;
        val[b]+=c;
    }
    int ans=0;
    std::sort(val+1,val+M+1,std::greater<int>());
    for(int i=1;i<=N;i++) ans+=val[i];
    cout<<ans<<endl;
    for(int i=1;i<=M;i++) val[i]=0;
}
int MAIN(){
    int T;cin>>T;while(T--)
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