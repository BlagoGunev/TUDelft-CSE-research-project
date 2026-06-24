#include "bits/stdc++.h"
#ifdef DEBUG
#include "PrettyDebug.hpp"
#else
#define debug(...) [](auto...){}(__VA_ARGS__)
#define debuga(...) [](auto...){}(__VA_ARGS__)
#endif
#define For(i,a,b) for(int i=a;i<=b;i++)
#define Rev(i,a,b) for(int i=a;i>=b;i--)
#define Fin(file) freopen(file,"r",stdin)
#define Fout(file) freopen(file,"w",stdout)
using namespace std; typedef long long ll;
constexpr int N=1e6+5,mod=998244353;
int n; char s[N];
void solve(){
    cin>>n>>(s+1);
    int x=0,y=0,ans=-1; For(i,1,n) y+=s[i]=='1';
    For(i,0,n){
        if(i){
            x+=s[i]=='0'; y-=s[i]=='1';
        }
        if(x*2>=i&&y*2>=n-i){
            if(ans==-1||abs(2*i-n)<abs(2*ans-n)||(abs(2*i-n)==abs(2*ans-n)&&i<ans)) ans=i;
        }
    }
    cout<<ans<<'\n';
}
signed main(){
    atexit([](){cerr<<"Time = "<<clock()<<" ms"<<endl;});
    int T=1;
    cin>>T;
    while(T--) solve();
    return 0;
}

// CONTINUE, NON-STOPPING, FOR CHARLIEY
// START TYPING IF YOU DON'T KNOW WHAT TO DO
// STOP TYPING IF YOU DON'T KNOW WHAT YOU'RE DOING

// Started Coding On: March 19 Tue, 16 : 03 : 25