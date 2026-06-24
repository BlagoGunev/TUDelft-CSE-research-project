#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<string>
#include<set>
#include<map>
#include<cmath>
#include<memory.h>
using namespace std;
typedef long long ll;

const int N = 1e6+6;

int t[N], d, inf = 1e9;

void upd(int i, int x){
    i+=d;
    t[i] = x;
    for(i>>=1;i;i>>=1) t[i]=min(t[i*2], t[i*2+1]);
}

int rmq(int i, int j){
    int res = inf;
    for(i+=d,j+=d;i<=j;++i>>=1,--j>>=1){
        if(i&1) res=min(res, t[i]);
        if(~j&1) res=min(res, t[j]);
    }
    return res;
}


bool ans1[N];
bool ans2[N];
struct rect{
    int x1,x2;
    int y1,y2;
    int k;
    rect(int X1, int Y1, int X2, int Y2, int K){
        x1 = X1;
        x2 = X2;
        y2 = Y2;
        y1 = Y1;
        k = K;
    }
};


void solve(int n, int m, vector<pair<int,int>>&p, vector<rect>&q, bool *ans){
    for(d=2;d<=n;d<<=1);
    for(int i=0;i<d*2;++i) t[i] = -inf;
    sort(p.begin(), p.end());
    sort(q.begin(), q.end(), [](const rect&a,const rect&b){return a.y2<b.y2;});
    
    
    for(int y = 1, i=0,j=0;y<=m; ++y){
        while(i<p.size() && p[i].first==y){
            upd(p[i].second, y);
            ++i;
        }
        while(j<q.size() && q[j].y2==y){
            int l = q[j].x1;
            int r = q[j].x2;
            int f = rmq(l,r);
            ans[q[j].k] = (f>=q[j].y1);
            ++j;
        }
    }
}

int main(){
    //freopen("input.txt","r",stdin);// freopen("output.txt","w",stdout);
    
    int n, m;
    int c,q;
    scanf("%d%d%d%d",&n,&m,&c,&q);
    vector<pair<int,int>> p1, p2;
    vector<rect> q1, q2;
    for(int i=0;i<c;++i){
        int x,y;
        scanf("%d%d",&x,&y);
        p1.push_back({y,x});
        p2.push_back({x,y});
    }
    for(int k=0;k<q;++k){
        int x1,x2,y1,y2;
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        q1.push_back(rect(x1,y1,x2,y2,k));
        q2.push_back(rect(y1,x1,y2,x2,k));
    }
    solve(n,m,p1,q1,ans1);
    solve(m,n,p2,q2,ans2);
    
    for(int i=0;i<q;++i) puts(ans1[i]||ans2[i] ? "YES" : "NO");
    
    
    return 0;
}