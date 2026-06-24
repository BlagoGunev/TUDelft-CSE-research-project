#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <sstream>
#include <set>
#include <map>
#include <algorithm>
#include <cstdio>
#include <cstdlib>

#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define iter(a) __typeof(a.begin())
#define FOR(it,a) for(iter(a)it=a.begin();it!=a.end();++it)
#define F first
#define S second
#define SZ(a) (int)((a).size())
#define sz(a) SZ(a)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define ALL(a) (a).begin(),(a).end()
using namespace std;

typedef long long ll;
typedef pair<int,int> PI;
typedef unsigned long long ull;
char a[210000];
char b[210000];



int geti(){
    int ch;
    while(!isdigit(ch=getchar()));
    int ret = ch&15;
    while(isdigit(ch=getchar()))
        ret = ret*10 + (ch&15);
    return ret;
}

ll co[2000][2000];

vector<PI> G[2000];

ll cost[2000][2000];

void dfs(int cv,ll cc,int p,int s){
    if(cost[s][cv] != -1){
        puts("NO");
        exit(0);
    }

    cost[s][cv] = cc;
    for(auto e : G[cv]){
        if(e.S==0){
            puts("NO");
            exit(0);
        }
        if(e.F != p)
            dfs(e.F,cc+e.S,cv,s);
    }
}

int main(int argc, char *argv[])
{
    int n=geti();
    rep(i,n)rep(j,n) co[i][j] = geti();

    ll maxe = 0;
    rep(i,n)
        maxe = max(maxe, *max_element(co[i],co[i]+n));
    
    int bidx;
    rep(i,n)rep(j,n)if(co[i][j]==maxe){
        bidx = i;
    }

    vector<PI> cov;
    rep(i,n) cov.pb(mp(co[bidx][i],i));
    sort(ALL(cov));
    
    int e = 0;
    for(int i = 1; i < n; ++i){
        for(int j = i-1; j >= 0; --j){
            if(co[bidx][cov[j].S] + co[cov[j].S][cov[i].S] == co[bidx][cov[i].S]){
                G[cov[j].S].pb(mp(cov[i].S,co[cov[j].S][cov[i].S]));
                G[cov[i].S].pb(mp(cov[j].S,co[cov[j].S][cov[i].S]));
                break;
            }
        }
    }
    
    memset(cost,-1,sizeof(cost));
    
    rep(i,n) dfs(i,0,-1,i);
    
    rep(i,n)rep(j,n)if(co[i][j] != cost[i][j]){
        puts("NO");
        return 0;
    }

    
    puts("YES");

    
    return 0;
}