#include<bits/stdc++.h>

#define rep(i,x,y) for(int i=x;i<=y;i++)

#define per(i,x,y) for(int i=x;i>=y;i--)

using namespace std;

const int N=2e5+10;

const int mod=1e9+7;

//#define int long long

vector<int>e[N];

int n,m,n1,n2,n3,col[5010],tot,sz[5010][2],u,v,pre[5010][5010],ans[5010];

void dfs(int u){

    sz[tot][0]+=(col[u]==2),sz[tot][1]+=(col[u]==1);

    for(auto v:e[u]){

        if(col[v]==0)col[v]=3-col[u],dfs(v);

        else if(col[v]+col[u]!=3){

            cout<<"NO\n";

            exit(0);

        }

    }

}

void solve(){

    cin>>n>>m>>n1>>n2>>n3;

    rep(i,1,m)cin>>u>>v,e[u].push_back(v),e[v].push_back(u);

    rep(i,1,n)if(!col[i])col[i]=1,tot++,dfs(i);

    pre[0][0]=1;

    rep(i,1,tot)rep(j,0,n){

        if(j>=sz[i][0] and pre[i-1][j-sz[i][0]])pre[i][j]=1;

        if(j>=sz[i][1] and pre[i-1][j-sz[i][1]])pre[i][j]=2;

    }

    if(!pre[tot][n2]){

        cout<<"NO\n";

    }else{

        cout<<"YES\n";

        int now=n2;

        per(i,tot,1){

            ans[i]=pre[i][now];

            //cout<<ans[i]<<" ";

            if(pre[i][now]==1)now-=sz[i][0];

            else now-=sz[i][1];

        }

        rep(i,1,n)col[i]=0;

        tot=0;

        rep(i,1,n)if(!col[i]){

            tot++;

            col[i]=ans[tot];

            dfs(i);

        }

        rep(i,1,n){

            if(col[i]==1){

                if(n1)cout<<1,n1--;

                else cout<<3;

            }else cout<<2;

        }

    }

}

signed main() {

    cin.tie(0)->sync_with_stdio(0);

    int tc = 1;

    //cin>>tc;

    for (int i = 1; i <= tc; i++) {

        solve();

    }

}