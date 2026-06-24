#pragma GCC optimize("Ofast")

#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>

// #define int             long long

#define all(a)          a.begin(),a.end()

#define endl            "\n"

#define fill(a,b) memset(a, b, sizeof(a))

#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))

using namespace std;

int d;

vector<vector<int>>adj;

vector<int>dp1;

vector<int>dp2; 

vector<int>m1;

vector<int>m2;

vector<int>mm1;

vector<int>mm2;



// map<int,int>m1;

// map<int,int>m2;

// map<int,int>mm1;

// map<int,int>mm2;

void rec(int u,int par){

    for(auto v:adj[u]){

        if(v!=par){

            rec(v,u);

            dp1[u]+=dp1[v];

            dp2[u]+=dp2[v];

        }

    }

    dp1[u]+=(m1[u]|mm1[u]);

    dp2[u]+=(m2[u]|mm2[u]);

}

int c=-1;

int rec1(int u,int par){

    int q=0,max1=-1,c1=0;

    for(auto v:adj[u]){

        if(v!=par&&dp1[v]!=0){

            q++;

            if(dp2[v])

            c=-1;

            c1=max(c1,rec1(v,u));

            max1=max(max1,c);

        }

    }

    c1++;

    if(c1-1>=d) mm2[u]=1;

    return c1;



}

int rec2(int u,int par){

    int q=0,c1=0;

    for(auto v:adj[u]){

        if(v!=par&&dp2[v]!=0){

            q++;

            c=-1;

            c1=max(c1,rec2(v,u));

        }

    }

    c1++;

    if(c1-1>=d) mm1[u]=1;

    return c1;

}

long long int ans=0;

int p1=0;

void rec01(int u,int par){

    int q=0;

    for(auto v:adj[u]){

        if(v!=par&&dp1[v]!=0){

            q++;

            p1++;

            rec01(v,u);

        }

    }

    if(dp1[u]==1&&q==0){

        ans+=2*p1;

        p1=0;

    }

}

void rec02(int u,int par){

    int q=0;

    for(auto v:adj[u]){

        if(v!=par&&dp2[v]!=0){

            q++;

            p1++;

            rec02(v,u);

        }

    }

    if(dp2[u]==1&&q==0){

        ans+=2*p1;

        p1=0;

    }

}

signed main (){

    ios_base::sync_with_stdio(false);

    cin.tie(NULL);

    cout.tie(NULL);

    int t=1;

    //cin>>t;

while(t--){

    int i,j,x=0,y=0,p=0,n,q=-1,u=0,v=0,k,c=0,m;

    cin>>n>>d;

    for(i=0;i<=n;i++){

        vector<int>v;

        adj.push_back(v);

        m1.push_back(0);

        m2.push_back(0);

        mm1.push_back(0);

        mm2.push_back(0);

    }

    for(i=0;i<n-1;i++){

        cin>>x>>y;

        adj[x].push_back(y);

        adj[y].push_back(x);

    }

    int n1,n2;

    cin>>n1;

    for(i=0;i<n1;i++){

        cin>>x;

        m1[x]=1;

    }

    cin>>n2;

    for(i=0;i<n2;i++){

        cin>>x;

        m2[x]=1;

    }

    m1[1]=1;

    m2[1]=1;

    for(i=0;i<=n;i++){

        dp1.push_back(0);

        dp2.push_back(0);

    }

    rec(1,0);

    c=-1;

    rec1(1,0);

    c=-1;

    rec2(1,0);

    for(i=0;i<=n;i++){

        dp1[i]=0;

        dp2[i]=0;

    }

    rec(1,0);

    p1=0;

    rec01(1,0);

    p1=0;

    rec02(1,0);



    cout<<ans<<endl;



    







    }

}