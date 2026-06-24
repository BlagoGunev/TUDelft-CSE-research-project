#include<bits/stdc++.h>

using namespace std;

const int N=2e5+10;

using ull=unsigned long long;

ull S[N],val[N];

const ull h1=1237123,h2=19260817;

ull H(ull x) {return x*x*x*h1+h2;}ull f(ull x){return H(x&((1<<31)-1))+H(x>>31);}

void solve()

{

    int n;scanf("%d",&n);

    vector<array<int,3>>a1,a2;

    for(int i=1;i<=n;++i)

    {

        val[i]=f(i);

        int a,b,c,d;scanf("%d%d%d%d",&a,&b,&c,&d);

        a1.push_back({a,0,i});a1.push_back({b,1,i});

        a2.push_back({c,0,i});a2.push_back({d,1,i});

    }

    sort(a1.begin(),a1.end());sort(a2.begin(),a2.end());

    ull now=0;

    for(auto [pos,type,id]:a1)if(type)now^=val[id];else S[id]^=now;

    reverse(a1.begin(),a1.end());now=0;

    for(auto [pos,type,id]:a1)if(!type)now^=val[id];else S[id]^=now;

    now=0;

    for(auto [pos,type,id]:a2)if(type)now^=val[id];else S[id]^=now;

    reverse(a2.begin(),a2.end());now=0;

    for(auto [pos,type,id]:a2)if(!type)now^=val[id];else S[id]^=now;

    for(int i=1;i<=n;++i)if(S[i]){printf("NO\n");return ;}

    printf("YES\n");

}

int main()

{

    int T=1; //scanf("%d",&T);

    while(T--)solve();

}