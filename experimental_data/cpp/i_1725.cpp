#include <bits/stdc++.h>

#pragma GCC optimize("Ofast")

#define AquA cin.tie(0);ios_base::sync_with_stdio(0);

#define fs first

#define sc second

#define p_q priority_queue

using namespace std;



const int mod=998244353;

void add(int& a,int b){

    a+=b;

    a-=mod*(a>=mod);

}

int mul(int a,int b){

    return 1ll*a*b%mod;

}

struct DSU{

    vector<int> bo,ss;

    void init(int a){

        bo.resize(a);

        ss.resize(a,1);

        iota(bo.begin(),bo.end(),0);

    }

    int find(int x){

        return bo[x]==x?x:bo[x]=find(bo[x]);

    }

    int merge(int x,int y){

        x=find(x);

        y=find(y);

        long long u=mul(ss[x],ss[y]);

        bo[x]=y;

        ss[y]+=ss[x];

        return u;

    }

};

int main(){

    AquA;

    int n;

    cin >> n;

    DSU dsu;

    dsu.init(n);

    int ans=1;

    for(int i=0;i<n-1;i++){

        int a,b;

        cin >> a >> b;

        a--;

        b--;

        int x=dsu.merge(a,b);

        ans=mul(ans,mul(x,x));

        ans=mul(ans,2*n-2-2*i-1);

    }

    cout << ans << "\n";

    return 0;

}