#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return true; } return false; }
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define mp make_pair
#define si(x) int(x.size())
const int mod=998244353,MAX=300005,INF=1<<30;

vector<int> G[MAX];
int dis[MAX][3];
vector<int> diameter;

void pre(int u,int p,int k){
    for(int to:G[u]){
        if(to==p) continue;
        dis[to][k]=dis[u][k]+1;
        pre(to,u,k);
    }
}

void make(int u,int p,int goal,bool &flag){
    if(u==goal){
        diameter.push_back(u);
        flag=true;
        return;
    }
    for(int to:G[u]){
        if(to==p) continue;
        make(to,u,goal,flag);
        if(flag){
            diameter.push_back(u);
            return;
        }
    }
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        int N;cin>>N;
        for(int i=0;i<N;i++){
            G[i].clear();
        }
        diameter.clear();
        for(int i=0;i<N-1;i++){
            int a,b;cin>>a>>b;
            a--;b--;
            G[a].push_back(b);
            G[b].push_back(a);
        }
        
        for(int i=0;i<N;i++){
            dis[i][0]=dis[i][1]=dis[i][2]=INF;
        }
        dis[0][0]=0;
        pre(0,-1,0);
        pair<int,int> ma={0,0},ma2={0,0};
        for(int i=0;i<N;i++) chmax(ma,{dis[i][0],i});
        dis[ma.second][1]=0;
        pre(ma.second,-1,1);
        for(int i=0;i<N;i++) chmax(ma2,{dis[i][1],i});
        dis[ma2.second][2]=0;
        pre(ma2.second,-1,2);
        bool flag=false;
        make(ma.se,-1,ma2.se,flag);
        
        int D=si(diameter);
        
        if(D&1){
            cout<<(D+1)/2<<"\n";
            for(int i=0;i<(D+1)/2;i++) cout<<diameter[D/2]+1<<" "<<i<<"\n";
        }else if(D%4==2){
            cout<<D/2+1<<"\n";
            for(int i=0;i<D/2+1;i++) cout<<diameter[D/2-1]+1<<" "<<i<<"\n";
        }else{
            cout<<D/2<<"\n";
            for(int i=0;i<D/4;i++) cout<<diameter[D/2-1]+1<<" "<<(2*i+1)<<"\n";
            for(int i=0;i<D/4;i++) cout<<diameter[D/2]+1<<" "<<(2*i+1)<<"\n";
        }
    }
    
}