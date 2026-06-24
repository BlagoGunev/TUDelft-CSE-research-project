#include <bits/stdc++.h>
using namespace std;
namespace Le0{
#define LL long long
const int N=2e5+5;
int T,n,m,MX;
int l[N],in[N],f[N],tm[N];
vector<int> g[N];
void add(int x,int y){in[y]++;tm[y]++;g[x].push_back(y);}
int main(){
    cin>>T;
    while(T--){
        for(int i=0;i<=MX+1;i++){
            g[i].clear();
            in[i]=f[i]=0;
            tm[i]=0;
        }
        cin>>n>>m;
        MX=0;
        int res=0;
        for(int i=1;i<=n;i++){
            cin>>l[i];
            MX=max(l[i],MX);
            map<int,int> mp;
            for(int j=1,x;j<=l[i];j++){
                cin>>x;
                mp[x]=1;
            }
            int ct=0,x=0,y=0;
            for(int j=0;j<=l[i]+1;j++){
                if(mp.find(j)==mp.end()){
                    if(!ct) x=j;
                    else y=j;
                    ct++;
                    if(ct==2) break;
                }
            }
            // cout<<x<<' '<<y<<'\n';
            add(y,x);
            res=max(res,x);
        }
        queue<int> q;
        for(int i=0;i<=MX+1;i++){
            f[i]=i;
            if(!in[i]) q.push(i);
        }
        while(q.size()){
            int x=q.front();q.pop();
            for(int y:g[x]){
                f[y]=max(f[y],f[x]);
                if(!--in[y]) q.push(y);
            }
        }
        for(int i=0;i<=MX+1;i++){
            if(tm[i]>=2) res=max(res,f[i]);
        }
        LL ans=0;
        for(int i=0;i<=min(MX+1,m);i++){
            ans+=max(res,f[i]);
            // cout<<max(res,f[i])<<'\n';
        }
        if(MX+1<m){
            int as=MX+1;
            ans+=1ll*(as+1+m)*(m-as)/2;
        }
        cout<<ans<<"\n";
    }
    return 0;
}
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    return Le0::main();
}