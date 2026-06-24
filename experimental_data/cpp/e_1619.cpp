#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define fer(i,a,b) for(int i=a;i<=b;++i)
#define der(i,a,b) for(int i=a;i>=b;--i)
#define all(x) (x).begin(),(x).end()
#define pll pair<int,int>
#define et  cout<<'\n'
#define xx first
#define yy second
using namespace std;
inline void ct(auto x) {cout<<x<<'\n' ;}
inline void ctn(int n,auto a[]) {fer(i,1,n) cout<<a[i]<<" "; cout<<'\n';}
const int N=1e6+10;
vector<int> S;
int p[N];
signed main(){
	ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    while(n--){
        vector<int> S;
        int ans=0;
        int n,x;
        cin>>n;
        fer(i,0,n) p[i]=0;
        fer(i,1,n) {
            cin>>x;
            p[x]++;
        }
        cout<<p[0]<<" ";
        if(p[0]>1){
            S.pb(0);
        }
        fer(i,1,n){
            if(!p[i-1]){
              if(S.empty()) ans=-1;
            else{
                p[S.back()]--;
                p[i-1]++;
                ans+=i-1-S.back();
                if(p[S.back()]==1) S.pop_back();
            }
        }
        if(ans!=-1&&p[i]>1) S.push_back(i);
        if(ans!=-1) cout<<ans+p[i]<<" ";
        else cout<<-1<<" ";
        }
         cout<<endl;

    }
}
/*
#                                                    __----~~~~~~~~~~~------___
#                                   .  .   ~~//====......          __--~ ~~
#                   -.            \_|//     |||\\  ~~~~~~::::... /~
#                ___-==_       _-~o~  \/    |||  \\            _/~~-
#        __---~~~.==~||\=_    -_--~/_-~|-   |\\   \\        _/~
#    _-~~     .=~    |  \\-_    '-~7  /-   /  ||    \      /
#  .~       .~       |   \\ -_    /  /-   /   ||      \   /
# /  ____  /         |     \\ ~-_/  /|- _/   .||       \ /
# |~~    ~~|--~~~~--_ \     ~==-/   | \~--===~~        .\
#          '         ~-|      /|    |-~\~~       __--~~
#                      |-~~-_/ |    |   ~\_   _-~            /\
#                           /  \     \__   \/~                \__
#                       _--~ _/ | .-~~____--~-/                  ~~==.
#                      ((->/~   '.|||' -_|    ~~-/ ,              . _||
#                      --------------_---  ~\      ~~---l__i__i__i--~~_/
#                     /           _-~-__   ~)  \--______________--~~
#                    /          //.-~~~-~_--~- |-------~~~~~~~~
#                   /                  //.-~~~--\
#                  神兽保佑
#                代码无BUG!
*/