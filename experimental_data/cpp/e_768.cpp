#include <bits/stdc++.h>
#define mp make_pair
#define mt make_tuple
#define X first
#define Y second
#define ALL(x) x.begin(),x.end()
#define RALL(x) x.rbegin(),x.rend()
#define D double
#define ll long long
#define REP(i,a) for(int i=0;i<a;i++)
#define REP1(i,a,b) for(int i=a;i<b;i++)
#define REP2(i,a,b) for(int i=a;i<=b;i++)
#define RREP(i,a) for(int i=a-1;i>=0;i--)
#define RREP1(i,a,b) for(int i=a;i>b;i--)
#define RREP2(i,a,b) for(int i=a;i>=b;i--)
#define SREP(i,x) for(auto i:x)
#define MS0(x) memset((x),0,sizeof((x)))
#define MS1(x) memset((x),-1,sizeof((x)))
#define MSF(x) memset((x),127,sizeof(x))
#define pb push_back
#define LE(x) (int)((x).size())
#define PII pair<int,int>
#define PLL pair<ll,ll>
#define PDD pair<D,D>
#define im guagua
#define RI(x) x=rit()
#define RII(a,b) a=rit(),b=rit()
#define RIII(a,b,c) a=rit(),b=rit(),c=rit()
#define debug 0
const int INF = 0x7F7F7F7F;
const double EPS = 1e-10 ;
const ll mod7 = 1e9+7;
const ll mod9 = 1e9+9;
using namespace std;
inline ll rit(){
    ll f=0,key=1;
    char c;
    do{
        c=getchar();
        if(c=='-') key=-1;
    }while(c<'0' || c>'9');
    do{
        f=f*10+c-'0';
        c=getchar();
    }while(c>='0' && c<='9');
    return f*key;
}
inline void fprt(D f){
    printf("%.08lf",f);
}
void init(){
}
int n,tt;
int mem[100] = {0,1,
1,
2,
2,
2,
3,
3,
3,
3,
4,
4,
4,
4,
4,
5,
5,
5,
5,
5,
5,
6,
6,
6,
6,
6,
6,
6,
7,
7,
7,
7,
7,
7,
7,
7,
8,
8,
8,
8,
8,
8,
8,
8,
8,
9,
9,
9,
9,
9,
9,
9,
9,
9,
9,
10,
10,
10,
10,
10,
10};
// v,ector<set<int> > mex;
// map<pair<int,ll> ,int> mem;
// set<int> mex;
// int ask(int n,ll x){
//     if(n==0) return 0;
//     if(mem.find(mp(n,x))!=mem.end()) return mem[mp(n,x)];
//     int f = tt++,f2;
//     mex.resize(tt);

//     RREP2(i,n,1){
//         if(!(x&(1<<i))){
//             mex[f].insert(ask(n-i,x+(1<<i)));
//             // if(!ask(n-i,x+(1<<i))){
//             //     // cout<<"walk to "<<n-i<<endl;
//             //     return 1;
//             // }
//         }
//     }
//     f2 = 0;
//     while(mex[f].find(f2)!=mex[f].end()) f2++;
//     mem[mp(n,x)]=f2;
//     return f2;
// }
void read(){
    // REP2(i,1,60) cout<<ask(i,0)<<endl;
    int x,f;
    x = 0;
    RI(n);
    REP(i,n){
        RI(f);
        // cout<<"ask "<<f<<" = "<<ask(f,0)<<endl;
        x^=mem[f];
    }
    if(x==0) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    // cout<<x<<endl;
}
void solve(){
}
int main(){
    int nn=1;
    // nn=rit();
    while(nn--){
        // while(cin>>n) 
            init(),read(),solve();
    }
    return 0;
}