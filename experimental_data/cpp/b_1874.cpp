#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int a,b,c,d,m;
struct ST {
    int val[256][256];
    int vis[256][256];
    int T ;
    ST() {
        memset(val,0,sizeof(val)) ;
        memset(vis,0,sizeof(vis)) ;T = 0;
    }
    void clear() {
        T++;
    }
    bool count(pii x) {
        if(vis[x.first][x.second] == T) return 1;
        return 0;
    }
    int& operator [](pii x) {
        
        vis[x.first][x.second] = T;
        return val[x.first][x.second];
    }
}mp ;
void expand(int x,int y)
{
    queue<pii> q;
    q.push({x , y}) ; mp[{x,y}] = 0;
    int cnt = 0;
    while(q.size()) {
        auto [x,y] = q.front() ; q.pop() ; cnt++;
        // if(x == c && y == d) break ;
        int v = mp[{x,y}] ;
        if(!mp.count({x & y , y})) {
            mp[{x & y , y}] = v + 1;
            q.push({x & y , y}) ;
        }
        if(!mp.count({x | y , y})) {
            mp[{x | y , y}] = v + 1;
            q.push({x | y , y}) ;
        }
        if(!mp.count({x , y ^ x})) {
            mp[{x , y ^ x}] = v + 1;
            q.push({x , y ^ x}) ;
        }
        if(!mp.count({x , y ^ m})) {
            mp[{x  , y ^ m}] = v + 1;
            q.push({x  , y ^ m}) ;
        }
    }
    // cout << cnt << '\n' ;
    return ;
}
vector<array<int,3> > ans;
void solv()
{
    cin >> a >> b >> c >> d >> m;
    mp.clear() ;
    map<array<int,3>,pii> mu ;
    int D = (1<<30) - 1;
    int cc = 0;
    for(int i = 0;i < 30;i++) {
        int x = ((a >> i) & 1) , y = ((b >> i) & 1) , z = ((m >> i) & 1) ;
        array<int,3> p ; p[0] = x;p[1] = y ;p[2] = z;
        int u = ((c >> i) & 1) , v = ((d >> i) & 1);
        if(mu.count(p)) {
            if(mu[p] != (pii){u,v}) {
                cout << -1 << '\n' ; return ;
            }
        }
        else {
            mu[p] = {u,v};
            // printf("A %d %d , %d %d %d %d %d\n",a,cc,x,y,u,v<<cc,z);
            cc++;
        }
    }
    int valid = 0;
    int op[] = {4 , 7 , 6 , 5 , 0 , 3 , 2 , 1};
    int na =0, nb =0, nc =0, nd=0;
    for(auto &[s,t] : mu) {
        int vv = (s[2]<<2) + (s[0]<<1) + (s[1]) ;
        valid |= (1 << op[vv]) ;
        nc |= (t.first << op[vv]) ;
        nd |= (t.second << op[vv]) ;
    }
    int ss = 1e9;
    for(auto &sol : ans) {
        if((sol[0]&valid)==nc && (sol[1]&valid) == nd) ss = min(ss , sol[2]) ;
    }
    if(ss == (1000000000)) ss = -1;
    cout<<ss<<'\n';
    // printf("%d %d %d %d %d\n",a,b,c,d,m);
    
    return;
}

int main()
{
    ios::sync_with_stdio(false) ; cin.tie(0) ; cout.tie(0) ;
    int T;cin >> T;
    a = 102 , b = 170 , m = 15; mp.clear() ;
    expand(a , b) ;
    for(int i = 0;i < 256;i++) {
        for(int j = 0;j < 256;j++) {
            if(mp.vis[i][j] == mp.T) {
                ans.push_back((array<int,3>){i,j,mp.val[i][j]}) ;
            }
        }
    }
    while(T--) solv();
    return 0;
}